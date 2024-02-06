/*************************************************************************************
 * Arduino part of Smartbin
 *
 * This Arduino program is designed to control most of the components 
 * and receive the signals from the sensors. The main functions of this
 * part are bin lid control, human presence detection, fire detection and fire alert.
 * Besides, it equips ability to exchange data with ESP32 which allows user to change 
 * the gas threshold according to their preferences.
 *
 * Key components and techniques utilized in this code are outlined as follows:
 * 1. Ultrasonic Sensing: Uses an HC-SR04 ultrasonic sensor to detect
 *    the presence and distance of a user.
 * 2. Servo Motor Control: Utilizes a servo motor to open and close
 *    the bin lid.
 * 3. Gas Detection: Employs an MQ2 gas sensor for smoke detection.
 * 4. Buzzer Alarm: Activates an alarm when smoke is detected.
 * 5. UART Communication: Receives threshold values and commands
 *    via serial communication. For data exchange between the Arduino and 
 *    external devices (e.g.ESP32).
 * 6. State Machine: Manages the bin state (Idle, Detecting Human,
 *    Open, Closing, Fire Detected) based on sensor inputs.
 *
 * Note: 
 * This code represents the Arduino component of the entire project,
 * which works in conjunction with an ESP32 module for advanced functionalities.
 ************************************************************************************/

#include "NewPing.h" // Include the NewPing library for ultrasonic sensor
#include <Servo.h>  // Include the Servo library for servo motor control


//Declare the pins on arduino
#define TRIGGER_PIN  6     // Ultrasonic sensor trigger pin
#define ECHO_PIN   9       // Ultrasonic sensor echo pin
#define MAX_DISTANCE 400   // Maximum distance for ultrasonic sensor (in cm)
#define SERVO_PIN 3        // Servo motor control pin
#define BUZZER_PIN 10      // Buzzer pin
#define MQ2_ANALOG_PIN A1  // MQ2 gas sensor analog pin
#define READING_COUNTS 5   // Number of readings for distance averaging


Servo servo; // Servo object for lid control
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Ultrasonic sensor object

// Variables for functionality
static unsigned long binOpening;
static unsigned long lastCheckTime = 0;

int init_angle = 90; // Initial angle for servo (bin closed position）
float distance;      // Distance measured by ultrasonic sensor
const int numReadings = 5;// Number of readings for median calculation
int readings[numReadings]; // Array to store distance readings
int readingIndex = 0;       // Index for inserting readings
const int DETECTION_THRESHOLD = 10; // Distance threshold for user detection
const int LEAVE_THRESHOLD = 12;     //Minimum valid distance
const int MIN_DISTANCE = 2;         // Threshold for smoke detection (MQ2 sensor)

int SMOKE_THRESHOLD = 200; //The value of threshold can change as require

//int pos=30;

unsigned long binOpenedAt = 0;
const unsigned long WAIT_TIME_AFTER_OPEN = 1000; // Time to wait after opening bin

// Function to insert a new reading and sort the readings array
void insertReading(int newReading) {

  if (readingIndex >= numReadings) readingIndex = 0;
  readings[readingIndex ++] = newReading;
  

  int i, key, j;
  for (i = 1; i < numReadings; i++) {
    key = readings[i];
    j = i - 1;

    
    while (j >= 0 && readings[j] > key) {
      readings[j + 1] = readings[j];
      j = j - 1;
    }
    readings[j + 1] = key;
  }
}

// Function to calculate the median from readings array
int getMedian() {
  
  if (numReadings % 2 != 0)
    return readings[numReadings / 2];
  else
    return (readings[numReadings / 2] + readings[(numReadings / 2) - 1]) / 2;
}


// Function to read the gas sensor value
int readGasSensor() {
  return analogRead(MQ2_ANALOG_PIN);
}

// Function to check if gas (smoke) is detected
bool isGasDetected(int sensorValue) {
  return sensorValue > SMOKE_THRESHOLD;
}

// Active Buzzer
void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}

// Close buzzer
void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);
}

// Using state machine to make the structure clear
// Enumeration to represent different states of the smart bin
enum SmartBinState{
  BIN_IDLE,
  DETECTING_HUMAN,
  BIN_OPEN,
  WAIT_FOR_HUMAN_TO_LEAVE,
  BIN_CLOSING,
  FIRE_DETECTED
};

SmartBinState currentState = BIN_IDLE; // Initial state


void setup() {
  Serial.begin(115200);

 // Initialize servo
  servo.attach(SERVO_PIN);
  servo.write(init_angle);

 // Initialize buzzer
  pinMode(BUZZER_PIN,OUTPUT);

 // Initialize gas sensor
  pinMode(MQ2_ANALOG_PIN,INPUT);
 
  delay(1000);

}

void loop() {
  // Get the median value of the measured distance in a period
  // in order to prevent interference of extrem values
  unsigned long currentTime = millis();
  if(currentTime - lastCheckTime > 30){
    distance = sonar.ping_cm();
    lastCheckTime = currentTime;
  }
  insertReading(distance);
  int medianDistance = getMedian();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("; ");  

  int sensorValue = readGasSensor();
  bool gasDetected = isGasDetected(sensorValue);

  Serial.println("SMOKE_VALUE:" + String(sensorValue));
  
  // Read the new thereshold from esp32 by URTA communication
  if(Serial.available()){
    Serial.println("Reading from Serial...");
    String data = Serial.readStringUntil('\n');
    if(data.startsWith("NEW_THRESHOLD:")){
      SMOKE_THRESHOLD = data.substring(14).toInt();
      if(readGasSensor() > SMOKE_THRESHOLD){
        currentState = FIRE_DETECTED;
      }
    }
  }

  if(gasDetected){
    currentState = FIRE_DETECTED;
  }

  switch(currentState){
     case BIN_IDLE:
      if (medianDistance < DETECTION_THRESHOLD && distance > MIN_DISTANCE) {
        currentState = DETECTING_HUMAN;
      }
      break;

    case DETECTING_HUMAN:
      servo.write(0);
      binOpenedAt = millis();
      currentState = BIN_OPEN;
      break;

    case BIN_OPEN:
      if (millis() - binOpenedAt > WAIT_TIME_AFTER_OPEN) {
        currentState = WAIT_FOR_HUMAN_TO_LEAVE;
      }
      break;

    case WAIT_FOR_HUMAN_TO_LEAVE:
      if (medianDistance > LEAVE_THRESHOLD) {
        
        binOpenedAt = millis();
        currentState = BIN_CLOSING;
      }
      break;

    case BIN_CLOSING:
      if (millis() - binOpenedAt > WAIT_TIME_AFTER_OPEN) {
        servo.write(90);
        delay(1000);
        currentState = BIN_IDLE;
      }
      break;
    
    case FIRE_DETECTED:
      //Handle fire detection
      if (gasDetected) {
        activateBuzzer();
        Serial.println("FIRE_ALERT");
      }else if( !gasDetected ){
        deactivateBuzzer();
        Serial.println("FIRE CLEARED"); 
        currentState = BIN_IDLE;
      }
      break;

  }

}
