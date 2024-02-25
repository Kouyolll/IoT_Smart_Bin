# IoT Smart Bin Log Book

<aside>
📖 **Table of contents**

</aside>

# Pre-work

The concept of the IoT Smart Bin originated with Junyi Ma during the AA meeting, where the initial idea was to design an automated bin equipped with fire detection and capacity monitoring functions. Following our collaborative brainstorming and research into available resources, we recognized that IoT products and smart city initiatives represent emerging trends within infrastructure development. Consequently, we elected to integrate this technology with a traditional waste bin to develop a home-use IoT Smart Bin. This marked the inception of our project's journey.

## Functions of Smart Bin

After finalizing the design concept for our product, we identified and compiled a list of the expected functionalities for the IoT Smart Bin:

- Human Detection
- Fire Detection
- Fire Alert
- Automated Lid
- Capacity Monitoring
- WiFi Function
- User Interaction
- Notification
- Independent Power

## Components Selection

We compiled a list of potential components and evaluated their features.

### 1. Human Detection

**Component**: Ultrasonic Sensor

<aside>
💡 **Evaluation:**

</aside>

**Cost-Effective**: Ultrasonic sensors are generally less expensive, making them suitable for budget-conscious projects. 

**Insensitive to Light Conditions**: Unlike optical sensors, ultrasonic sensors are not sensitive to changes in environmental lighting conditions and can work stably in dimly lit environments.

### 2. Fire Detection

**Component**: MQ2 Gas Sensor

<aside>
💡 **Evaluation:**

</aside>

**Advantages:**

**Multi-Gas Detection Capability**: The MQ2 sensor can detect a variety of gases, including butane, propane, methane, smoke, and other combustible gases. This means it can detect not only the smoke produced by a fire but also potentially leaked combustible gases before a fire occurs, providing more information for early fire warning.

**Cost-Effectiveness**: Compared to some specialized smoke sensors or gas detection equipment, the MQ2 sensor is generally less expensive and suitable for budget-conscious projects.

**Ease of Use and Integration**: The MQ2 sensor is widely used in various DIY projects and commercial products, with extensive community support and documentation, making it convenient for developers to use and integrate into different systems.

**Disadvantages:**

**Sensitivity and Selectivity**: Although the MQ2 can detect multiple gases, it may not accurately differentiate between these specific types of gases. In complex environments, such as the variety of volatile substances that might be present in a trash bin, the MQ2 could be subject to interference, leading to false alarms. However, in our project it is unnecessary to distinct a certain type of gas. Hence, MQ2 Gas sensor is still a good choice for daily use. 

**Comparison with Other Sensors:**

**Photoelectric Smoke Sensors**: These sensors work by detecting the scattering of light in smoke and are very sensitive to smoke produced by fires, but may not detect the early stages of a fire without noticeable smoke.

**Thermal Sensors**: Thermal sensors detect fires by sensing changes in temperature, responding quickly but may not provide an early warning if the fire has not yet caused a significant temperature increase.

**Infrared Sensors**: Infrared sensors can detect the infrared radiation from flames, making them highly effective for direct fire detection, but they might not detect early-stage fires that produce smoke without visible flames.

### 3. Fire Alert

**Component**: Buzzer

<aside>
💡 **Evaluation:**

</aside>

**Advantages:**

**Immediate Notification**: A buzzer can provide immediate audible alerts when a fire is detected, potentially saving valuable response time.

**Cost-Effective**: Buzzers are generally inexpensive, making them suitable for budget-conscious projects.

**Ease of Integration**: Buzzers can be easily integrated into a variety of systems, and their simplicity of use makes them a favorable choice for immediate alert mechanisms.

### 4. Automated Lid

**Component**: Servo Motor

<aside>
💡 **Evaluation:**

</aside>

**Advantages:**

**Precision Control**: Servo motors are known for their ability to provide precise control of angular or linear position, velocity and acceleration, which is crucial for the automatic operation of the bin lid.

**Reliability**: Servo motors are highly reliable and have a long service life, making them a suitable choice for the automated lid function of the smart bin.

**Ease of Integration**: Servo motors are widely used in various DIY projects and commercial products, with extensive community support and documentation, making it convenient for developers to use and integrate them into different systems.

### 5. Capacity Monitoring

**Component**: VL53L0X Distance Sensor

<aside>
💡 **Evaluation:**

</aside>

**Advantages:**

**Accuracy**:The VL53L0X is capable of measuring distances with high accuracy, typically within a range of up to 2 meters, depending on conditions and the object's reflectivity.

**Small Form Factor:** The sensor is compact, making it suitable for integration into our smart bin. 

**Low Power Consumption:** The VL53L0X is designed for efficiency, making it suitable for battery-operated devices.

**Disadvantages:** 

**Environment Factor:** Extreme lighting condition may impact the measurement performance. However, the VL53L0X Distance Sensor is placed inside the smart bin which can avoid the influence of light.

### 6. WiFi Function

**Component**: ESP32 WiFi Module

<aside>
💡 **Evaluation:**

</aside>

**Connectivity**: The ESP32 WiFi Module provides connectivity to the internet, enabling the IoT functionality of the Smart Bin.

**Cost-Effective**: This WiFi module is relatively inexpensive, making it a suitable choice for budget-conscious projects.

**Ease of Integration**: The ESP32 WiFi Module is widely used in various DIY projects and commercial products, with extensive community support and documentation, making it convenient for developers to use and integrate into different systems.

### 7. User Interaction

**Component**: Blynk Mobile Application

<aside>
💡 **Evaluation:**

</aside>

**Ease of Use**: A mobile application allows users to interact with the Smart Bin easily from their mobile devices.

**Accessibility**: As long as they have access to their mobile device, users can interact with the Smart Bin from anywhere.

**Customization**: Blynk mobile application can be customized to provide the specific functionality and user interface required for the Smart Bin.

### 8. Independent Power

**Component**: 18650 Battery and Lithium Battery Shield 18650 V8

<aside>
💡 **Evaluation:**

</aside>

**High Capacity:** 18650 batteries offer a high energy density, providing a significant amount of power in a compact form factor. This makes them ideal for projects requiring long-lasting power without frequent recharging or battery replacement.

**Recharge ability**: Being rechargeable, 18650 batteries can be used multiple times, reducing the need for disposable batteries and offering a more sustainable and cost-effective power solution for projects.

**Cost Savings**: While the initial cost of a solar panel and battery may be high, the long-term savings in energy costs can make this a cost-effective option.

**Cost-Effectiveness**: Given their longevity, capacity, and recharge ability, 18650 batteries offer a cost-effective power solution over the long term, especially when compared to disposable batteries.

**Safety Features**: Many 18650 batteries come with built-in protection circuits that prevent overcharging, deep discharge, and short-circuiting, enhancing the safety of your projects.

**Portability**: 18650 Lithium battery shield enables the creation of portable power solutions, allowing projects to be mobile and not tethered to a stationary power source.

**Built-in Protection**: The shield often features protection circuits that safeguard against overcharging, over-discharging, and short circuits, ensuring the safety and longevity of both the batteries and the connected devices.

**LED Indicators**: The presence of LED indicators for charging status and battery level provides immediate visual feedback, making it easier to monitor the power status without additional equipment.

### 9. Sensor Controller

**Components**: Arduino Uno R3

<aside>
💡 Evaluation

</aside>

**Ease of Use**: The Arduino Uno R3 is designed for beginners and experienced users alike, offering a simple and straightforward development environment. Its programming language and IDE  are easy to understand, making it accessible for people with varying levels of programming expertise.

**Extensive Community Support**: Arduino has a vast and active community. Users can find a plethora of tutorials, forums, project ideas, and open-source libraries, which significantly facilitates the learning process and project development.

**Analog and Digital I/O Pins**: It comes equipped with 14 digital input/output pins (of which 6 can be used as PWM outputs) and 6 analog inputs. This allows the board to connect to various sensors and other hardware components, making it highly adaptable to different project needs.

# Development Process

The development process was divided by two parts: Arduino and ESP32 

### Arduino Section

The foundational concept of the IoT Smart Bin System involves utilizing an Arduino to oversee all component operations, while the ESP32 is tasked with handling network connectivity.

<aside>
🧑🏻‍💻 Here is the first version of Arduino Code:

</aside>

```arduino
/*
 Arduino_UNO_Smartbin_Controller
  
  Project Description:
  This project aims to develop a smart bin using Arduino UNO.
  It features capacity detection, human presence detection, and fire detection.
  It utilizes the VL53L0X ToF sensor for capacity measurement,
  the HC-SR04 ultrasonic sensor for human detection,
  and the MQ2 gas sensor for detecting smoke of the potential fire.

  Note: 
  This code represents the Arduino component of the entire project,
  which works in conjunction with an ESP32 module for advanced functionalities.

*/

//Include "NewPing Library"
//Include Servo Library
#include "NewPing.h"
#include <Servo.h>
#include <Wire.h>
//Include the Library of tof sensor
#include <VL53L0X.h> 

//Declare the pins on arduino
#define TRIGGER_PIN  7
#define ECHO_PIN   7
#define MAX_DISTANCE 400
#define SERVO_PIN 3
#define BUZZER_PIN 4
#define MQ2_ANALOG_PIN A0 
//The value of threshold can change as require
#define SMOKE_THRESHOLD 300 
#define binFullDistance 20
#define binEmptyDistance 500

#define READING_COUNTS 5

Servo servo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

VL53L0X sensor;

int init_angle = 90;
float distance_2;
int readDistance_1[READING_COUNTS];
int readingIndex = 0;

void setup() {
  delay(1000);

 Serial.begin(9600);

 // Initialize servo
  servo.attach(SERVO_PIN);

 // Initialize buzzer
  pinMode(BUZZER_PIN,OUTPUT);

 // Initialize gas sensor
  pinMode(MQ2_ANALOG_PIN,INPUT);

 // Initialize VL53L0X ToF sensor
  Wire.begin();
  Serial.println("hello 1");
  sensor.init();
  Serial.println("hello 2");
  sensor.setTimeout(500);
  sensor.startContinuous();
  for(int i = 0; i < READING_COUNTS; i++){
    readDistance_1[i] = 0;
  }
  servo.write(init_angle);
  delay(1000);
}

// Read MQ2 sensor value
int readGasSensor() {
  return analogRead(MQ2_ANALOG_PIN);
}

// Detect whether there is gas
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

void loop() {
//Smart bin capacity dection
  int distance_1 = sensor.readRangeContinuousMillimeters();

  readDistance_1[readingIndex] = distance_1;
  readingIndex = (readingIndex + 1)% READING_COUNTS;

  int totalDistance = 0;
  for (int i = 0; i < READING_COUNTS; i++) {
    totalDistance += readDistance_1[i];
  }
  int averageDistance = totalDistance / READING_COUNTS;

  averageDistance = constrain(averageDistance, binFullDistance, binEmptyDistance);
  int capacityPercentage = map(averageDistance, binFullDistance, binEmptyDistance, 100, 0);
  Serial.println(capacityPercentage); // send the capacity percentage through serial  
  Serial.print("Average Distance: ");
  Serial.print(averageDistance);
  Serial.print("mm");
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.println();
  
 //Human detection 
  distance_2 = sonar.ping_cm();

  if (distance_2 < 20 && distance_2 > 2) {
    
    servo.write(0);
    delay(3000);
    servo.write(90);
  }
  
  Serial.print("Distance_2 = ");
  Serial.print(distance_2);
  Serial.println(" cm");
  
 //Fire detection and buzzer alarm
  int sensorValue = readGasSensor(); 
  Serial.println(sensorValue); 

  if (isGasDetected(sensorValue)) { 
    activateBuzzer(); 
    Serial.println("FIRE_ALERT");
  } 
  else {
    deactivateBuzzer(); 
  }
 
}
```

In **Arduino_UNO_Smartbin_Controller V1.0,** all the components work well at the beginning. To mitigate erroneous readings from distance sensors, both the ultrasonic sensor and the VL53L0X distance sensor are configured to compute the average value from multiple measurements. During testing, several problems were identified in Version 1.0. Notably, the servo mechanism exhibited significant delay in its response, and the automated lid functionality was unstable, the results of distance sensor was inaccurate as well. Furthermore, the code's structure was found to be unclear, leading to challenges in scalability and adaptability. Consequently, Version 2.0 of the code was developed, incorporating the concept of a state machine to address these issues. 

 As the test result below, when the distance is above 3cm ultrasonic sensor demonstrates excellent performances.

![b3f0fa10e483f44630ee7e684961543.jpg](IoT%20Smart%20Bin%20Log%20Book%204348c05ba3bf46efb9bcb27055f184dd/b3f0fa10e483f44630ee7e684961543.jpg)

Here is a reference tutorial:  

[https://www.youtube.com/watch?v=6F1B_N6LuKw](https://www.youtube.com/watch?v=6F1B_N6LuKw)

During the testing phase of the human detection feature, it was observed that the lid's opening and closing mechanism was not optimal. Specifically, when a person remained within the detection threshold, the bin lid would automatically close after a set time. To address this, the logic was adjusted to keep the lid open as long as a person is detected, moving away from the use of the **`delay()`** function, which causes blocking, to using the **`millis()`** function for non-blocking timing.

This adjustment allows for a more responsive and user-friendly interaction with the smart bin. The **`millis()`** function enables the program to check continuously for the presence of a person without halting the execution of other tasks, providing a more dynamic response to the detected presence.

<aside>
🧑🏻‍💻 **Arduino_UNO_Smartbin_Controller V2.0**

</aside>

```arduino
//Include "NewPing Library"
//Include Servo Library
#include "NewPing.h"
#include <Servo.h>
#include <Wire.h>
#include <VL53L0X.h> //Include the Library of tof sensor

//Declare the pins on arduino
#define TRIGGER_PIN  4
#define ECHO_PIN   7
#define MAX_DISTANCE 400
#define SERVO_PIN 3
#define BUZZER_PIN 4
#define MQ2_ANALOG_PIN A0 
#define SMOKE_THRESHOLD 200 //The value of threshold can change as require
#define minDistanceWhenFull 20
#define maxDistanceWhenEmpty 500

#define READING_COUNTS 5

Servo servo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

VL53L0X sensor;

static unsigned long binOpening;
int readDistance_1[READING_COUNTS];
int readingIndex = 0;
int averageDistance = 0;
int init_angle = 90;
float distance_2;
const int numReadings = 5;
int readings[numReadings]; 
int readingIndex_2 = 0; 
const int DETECTION_THRESHOLD = 10; 
const int LEAVE_THRESHOLD = 12; 
const int MIN_DISTANCE = 2; 

unsigned long binOpenedAt = 0;
const unsigned long WAIT_TIME_AFTER_OPEN = 1000; 

void insertReading(int newReading) {
  if (readingIndex_2 >= numReadings) readingIndex_2 = 0;
  readings[readingIndex_2 ++] = newReading;
  
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

int getMedian() {

  if (numReadings % 2 != 0)
    return readings[numReadings / 2];
  else
    return (readings[numReadings / 2] + readings[(numReadings / 2) - 1]) / 2;
}

int calculateCapacityPercentage() {
  int distance_1 = sensor.readRangeContinuousMillimeters();
  readDistance_1[readingIndex] = distance_1;
  readingIndex = (readingIndex + 1) % READING_COUNTS;

  int totalDistance = 0;
  for (int i = 0; i < READING_COUNTS; i++) {
    totalDistance += readDistance_1[i];
  }

  averageDistance = totalDistance / READING_COUNTS;
  averageDistance = constrain(averageDistance, minDistanceWhenFull, maxDistanceWhenEmpty);

  int capacityPercentage = map(averageDistance, minDistanceWhenFull, maxDistanceWhenEmpty, 100, 0);
  
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
    return -1; // or any other indication of error
  }

  return capacityPercentage;
}

// Read MQ2 sensor value
int readGasSensor() {
  return analogRead(MQ2_ANALOG_PIN);
}

// Detect whether there is gas
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

enum SmartBinState{
  BIN_IDLE,
  DETECTING_HUMAN,
  BIN_OPEN,
  WAIT_FOR_HUMAN_TO_LEAVE,
  BIN_CLOSING,
  FIRE_DETECTED
};

SmartBinState currentState = BIN_IDLE;

void setup() {
  Serial.begin(9600);
  Serial.println("hello 1");
 // Initialize servo
  servo.attach(SERVO_PIN);
  servo.write(init_angle);

 // Initialize buzzer
  pinMode(BUZZER_PIN,OUTPUT);

 // Initialize gas sensor
  pinMode(MQ2_ANALOG_PIN,INPUT);
  Serial.println("hello 2");
 // Initialize VL53L0X ToF sensor
  Wire.begin();
  delay(50);
  sensor.init();
  
  sensor.setTimeout(500);
  sensor.startContinuous();
  for(int i = 0; i < READING_COUNTS; i++){
    readDistance_1[i] = 0;
  }

  delay(1000);
  digitalWrite(BUZZER_PIN, HIGH);
}

void loop() {
  //Serial.println("hello");

  distance_2 = sonar.ping_cm();
  delay(30);
  insertReading(distance_2);
  int medianDistance = getMedian();
  Serial.print("Distance_2: ");
  Serial.print(distance_2);
  Serial.print("; ");
  switch(currentState){
     case BIN_IDLE:
      if (medianDistance < DETECTION_THRESHOLD && distance_2 > MIN_DISTANCE) {
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
      activateBuzzer();
      Serial.print("FIRE ALERT");
      if(!isGasDetected(readGasSensor())){
        deactivateBuzzer();
        Serial.println("FIRE CLEARED");
      }
      currentState = BIN_IDLE;
      break;

  }

  int sensorValue = readGasSensor();
  Serial.print(sensorValue);
  Serial.print('\t');
  if(isGasDetected(sensorValue)){
    currentState = FIRE_DETECTED;
    
  }

  int capacityPercentage = calculateCapacityPercentage();
  if (capacityPercentage != -1) {
    Serial.print("Average Distance: ");
    Serial.print(averageDistance);
    Serial.print("mm, Capacity: ");
    Serial.print(capacityPercentage);
    Serial.println("%");
    }
    

}
```

In **Arduino_UNO_Smartbin_Controller V2.0,** the significant change is on the structure. A state machine is implemented to this project which help to organize the code (enhance code structure, making it more modular, maintainable, and easier to debug) and improve the performance. Code of state machine and some learning material are attached below.  

```arduino
//State machine structure in arduino code 
enum SmartBinState{
  BIN_IDLE,
  DETECTING_HUMAN,
  BIN_OPEN,
  WAIT_FOR_HUMAN_TO_LEAVE,
  BIN_CLOSING,
  FIRE_DETECTED
};
```

[Multi-tasking the Arduino - Part 1](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all)

To optimize the result of distance sensor, Insertion Sort algorithm was used in our project for the capacity monitoring.  

```arduino
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

int getMedian() {

  if (numReadings % 2 != 0)
    return readings[numReadings / 2];
  else
    return (readings[numReadings / 2] + readings[(numReadings / 2) - 1]) / 2;
}

```

During subsequent inspection work, it was discovered that the VL53L0X distance sensor suddenly stopped functioning. After troubleshooting, it was determined that the issue stemmed from the Arduino's inability to supply a stable current due to the number of sensors connected to it. Consequently, it was decided to transfer the VL53L0X sensor from the Arduino to the ESP32 module. Additionally, it was noted that both the operating voltage of the VL53L0X distance sensor and the Arduino are 3.3V.

Moving the VL53L0X sensor to an ESP32, which is also 3.3V compatible, can ensure that the sensor receives a stable power supply, potentially resolving the issue. The ESP32 is known for its higher processing power and better power management capabilities compared to Arduino, making it a suitable platform for handling more power-demanding sensors like the VL53L0X.

<aside>
🧑🏻‍💻 **Arduino_UNO_Smartbin_Controller V2.1**

</aside>

```arduino
//Include "NewPing Library"
//Include Servo Library
#include "NewPing.h"
#include <Servo.h>

//Declare the pins on arduino
#define TRIGGER_PIN  6
#define ECHO_PIN   9
#define MAX_DISTANCE 400
#define SERVO_PIN 3
#define BUZZER_PIN 10
#define MQ2_ANALOG_PIN A1 
#define READING_COUNTS 5

Servo servo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

static unsigned long binOpening;
static unsigned long lastCheckTime = 0;

int init_angle = 90;
float distance;
const int numReadings = 5;
int readings[numReadings]; 
int readingIndex = 0; 
const int DETECTION_THRESHOLD = 10; 
const int LEAVE_THRESHOLD = 12; 
const int MIN_DISTANCE = 2; 

int SMOKE_THRESHOLD = 200; //The value of threshold can change as require

unsigned long binOpenedAt = 0;
const unsigned long WAIT_TIME_AFTER_OPEN = 1000; 

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

int getMedian() {
  
  if (numReadings % 2 != 0)
    return readings[numReadings / 2];
  else
    return (readings[numReadings / 2] + readings[(numReadings / 2) - 1]) / 2;
}

// Read MQ2 sensor value
int readGasSensor() {
  return analogRead(MQ2_ANALOG_PIN);
}

// Detect whether there is gas
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

enum SmartBinState{
  BIN_IDLE,
  DETECTING_HUMAN,
  BIN_OPEN,
  WAIT_FOR_HUMAN_TO_LEAVE,
  BIN_CLOSING,
  FIRE_DETECTED
};

SmartBinState currentState = BIN_IDLE;

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
        //fireAlertCount++;
      }else if( !gasDetected ){
        deactivateBuzzer();
        Serial.println("FIRE CLEARED"); 
        //fireAlertCount = 0;
        currentState = BIN_IDLE;
      }
      break;

  }

}
```

To finalize the integration process with the ESP32 module, focusing on data transmission and introducing a new feature allowing users to adjust the smoke threshold value according to their preference. Some actions were taken:

1. **Enhanced Data Transmission**:
    - Implemented UART communication between the Arduino and ESP32 module to facilitate seamless data exchange. This enhancement allows for real-time transmission of sensor readings and control commands, ensuring synchronized operation between the two components.
2. **User-Defined Smoke Threshold Adjustment**:
    - Introduced a functionality enabling users to dynamically adjust the MQ2 gas sensor's smoke threshold value. This was achieved by parsing commands received from the ESP32 through serial communication, specifically looking for a predefined command format (e.g., "NEW_THRESHOLD:").
3. **Code Modification for Dynamic Threshold Configuration**:
    - Integrated a section in the main loop to continuously monitor the serial buffer for incoming threshold adjustment commands from the ESP32. Upon receiving a valid command, the code updates the smoke threshold variable (**`SMOKE_THRESHOLD`**) to the new value specified by the user.
4. **Serial Command Processing**:
    - Developed a robust serial command processing mechanism to ensure that only valid commands trigger the threshold adjustment. This includes error checking to prevent incorrect data entry and feedback through serial communication to confirm the adjustment.
5. **Testing and Validation**:
    - Conducted comprehensive tests to validate the new data transmission capabilities and the functionality allowing for smoke threshold adjustment. This involved simulated scenarios to ensure the system responds accurately to varying smoke levels and user-defined threshold changes.

<aside>
🧑🏻‍💻 **Arduino_UNO_Smartbin_Controller V2.2**

</aside>

```arduino
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
const int DETECTION_THRESHOLD = 5; // Distance threshold for user detection
const int LEAVE_THRESHOLD = 10;     //Minimum valid distance
const int MIN_DISTANCE = 2;         // Threshold for smoke detection (MQ2 sensor)

int SMOKE_THRESHOLD = 300; //The value of threshold can change as require

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
```

## ESP32 Section

At the onset of developing the ESP32 component, we encountered an obstacle due to the lack of drivers for the CP2102 in the ESP32. It was only after resolving this issue that we were able to officially commence development. The guide was attached below:

[https://randomnerdtutorials.com/esp32-troubleshooting-guide/](https://randomnerdtutorials.com/esp32-troubleshooting-guide/)

In the ESP32 segment, our primary goal was to enable users to configure WiFi and email settings without the need for hard coding. Additionally, we aimed to allow users to monitor and interact with the Smart Bin on an IoT platform.

To facilitate user configuration of WiFi, using a local Access Point (AP) in conjunction with the ESP32 is an ideal approach. It allows the use of a smartphone, tablet, or any WiFi-enabled computer to set up the ESP32 WiFi credentials, along with any other configuration parameters you might need. For this functionality, we utilized the WiFiManager library.

Originally, this library was developed for use with the ESP8266 to perform this task, but it has now been extended to work with the ESP32.

The working principle of WiFiManager is as follows:

1 – The ESP32 boots up and checks if a WiFi network has been configured.

2 – If it does have WiFi credentials, it will log onto the network using them. Assuming it succeeds, no further action is required, and it can start running its sketch.

3 – If it doesn't have WiFi credentials, or if they are invalid, it sets itself up as an access point. The access point is where the ESP32 offers its own WiFi network for other devices to connect.

4 – It creates a web page at the address 192.168.4.1. This web page has a list of available WiFi networks that you can join, along with text boxes for entering the SSID and password. You can also configure it to have additional text boxes (or other HTML elements) to gather any other configuration information you might need.

5 – The user enters the appropriate information and presses the “save” button. This information is sent back to the ESP32.

6 – The ESP32 switches back to station mode and attempts to connect to the desired WiFi network using the provided credentials.

7 – Assuming the user provided the correct login credentials, the ESP32 will now be connected to the WiFi network.

***Guide for WM:***

[https://dronebotworkshop.com/wifimanager/](https://dronebotworkshop.com/wifimanager/)

To ensure that users don't have to reconfigure their WiFi and email settings on subsequent connections, we organize the data in JSON format. (JSON, which stands for JavaScript Object Notation, is a lightweight data interchange format that is easy for both machines and humans to read and write, facilitating data exchange between incompatible systems.) We then use SPIFFS to store this data. SPIFFS stands for Serial Peripheral Interface Flash File System, a file system designed for use with NOR flash memory, the type of memory included in the ESP32.

SPIFFS allows you to treat the memory almost as if it were SD or MicroSD card storage, with some differences. One such difference is that SPIFFS does not support directories, although you can mimic them to some extent.

The number of write operations to the flash is limited, so SPIFFS employs various techniques to maximize the lifespan of the memory. When memory is formatted or erased, all bits are set to 1. When data is written to memory, only the bits that need to be pulled to zero are affected. SPIFFS also uses "wear leveling" to distribute data evenly across the memory.

By using JSON and SPIFFS, we can store a significant amount of configuration information within the ESP32, with most ESP32 devices allocating about 1.5Mb for SPIFFS.

***Guide for email:***

[https://randomnerdtutorials.com/esp32-send-email-smtp-server-arduino-ide/#send-email](https://randomnerdtutorials.com/esp32-send-email-smtp-server-arduino-ide/#send-email)

<aside>
👨🏻‍💻 ESP32_Smartbin_Networking

</aside>

```arduino

// ----------------------------
// Library Defines - Need to be defined before library import
// ----------------------------

#define ESP_DRD_USE_SPIFFS true

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <WiFi.h>
#include <FS.h>
#include <SPIFFS.h>

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include <WiFiManager.h>
// Captive portal for configuring the WiFi

// Can be installed from the library manager (Search for "WifiManager", install the Alhpa version)
// https://github.com/tzapu/WiFiManager

#include <ESP_DoubleResetDetector.h>
// A library for checking if the reset button has been pressed twice
// Can be used to enable config mode
// Can be installed from the library manager (Search for "ESP_DoubleResetDetector")
//https://github.com/khoih-prog/ESP_DoubleResetDetector

#include <ArduinoJson.h>
// ArduinoJson is used for parsing and creating the config file.
// Search for "Arduino Json" in the Arduino Library manager
// https://github.com/bblanchon/ArduinoJson

//#include <Arduino.h>

#include <ESP_Mail_Client.h>

#define WIFI_SSID "REPLACE_WITH_YOUR_SSID"
#define WIFI_PASSWORD "REPLACE_WITH_YOUR_PASSWORD"

/** The smtp host name e.g. smtp.gmail.com for GMail or smtp.office365.com for Outlook or smtp.mail.yahoo.com */
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 587

/* The sign in credentials */
#define AUTHOR_EMAIL "·······@gmail.com"
#define AUTHOR_PASSWORD "kklt wvdk zfzc qaup"

bool isValidMail(char* str){
    int atpos = -1;
    int dotpos = -1;
    int length = 0;
    while(str[length] != '\0'){
        if(str[length] == '@'){
            if(atpos != -1){
                return false;
            }
            atpos = length;
        }
        if(str[length] == '.'){
            dotpos = length;
        }
        length++;
    }
    if(atpos != -1){
        return dotpos + 1 < length;
    }else{
        return false;
    }
}

/* Recipient's email*/
char RECIPIENT_EMAIL[10000] ="";

/* Declare the global used SMTPSession object for SMTP transport */
SMTPSession smtp;
/* Callback function to get the Email sending status */
void (*smtpCallback)(SMTP_Status status);

void sendMail(const String &subject,const String &htmlContent){
  /*  Set the network reconnection option */
  MailClient.networkReconnect(true);

  /** Enable the debug via Serial port
   * 0 for no debugging
   * 1 for basic level debugging
   *
   * Debug port can be changed via ESP_MAIL_DEFAULT_DEBUG_PORT in ESP_Mail_FS.h
   */
  smtp.debug(1);

  /* Set the callback function to get the sending results */
  smtp.callback(smtpCallback);

  /* Declare the Session_Config for user defined session credentials */
  Session_Config config;

  /* Set the session config */
  config.server.host_name = SMTP_HOST;
  config.server.port = SMTP_PORT;
  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;
  config.login.user_domain = "";

  /*
  Set the NTP config time
  For times east of the Prime Meridian use 0-12
  For times west of the Prime Meridian add 12 to the offset.
  Ex. American/Denver GMT would be -6. 6 + 12 = 18
  See https://en.wikipedia.org/wiki/Time_zone for a list of the GMT/UTC timezone offsets
  */
  config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  config.time.gmt_offset = 0;
  config.time.day_light_offset = 0;

  /* Declare the message class */
  SMTP_Message message;

  /* Set the message headers */
  message.sender.name = F("ESP");
  message.sender.email = AUTHOR_EMAIL;
  message.subject = subject;
  message.addRecipient(F("User"), RECIPIENT_EMAIL);
    
  /*Send HTML message*/
  message.html.content = htmlContent.c_str();
  message.text.charSet = "us-ascii";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

   
  /*Send raw text message
  String textMsg = "Hello World! - Sent from ESP board";
  message.text.content = textMsg.c_str();
  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/
  
  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
  message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;

  /* Connect to the server */
  if (!smtp.connect(&config)){
    ESP_MAIL_PRINTF("Connection error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
    return;
  }

  if (!smtp.isLoggedIn()){
    Serial.println("\nNot yet logged in.");
  }
  else{
    if (smtp.isAuthenticated())
      Serial.println("\nSuccessfully logged in.");
    else
      Serial.println("\nConnected with no Auth.");
  }

  /* Start sending Email and close the session */
  if (!MailClient.sendMail(&smtp, &message))
    ESP_MAIL_PRINTF("Error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());

}

// -------------------------------------
// -------   Other Config   ------
// -------------------------------------

const int PIN_LED = 2;

#define JSON_CONFIG_FILE "/esp32Smartbin_config.json"

// Number of seconds after reset during which a
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 10

// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

// -----------------------------

// -----------------------------

DoubleResetDetector *drd;

//flag for saving data
bool shouldSaveConfig = false;

void saveConfigFile()
{
  Serial.println(F("Saving config"));
  StaticJsonDocument<512> json;

  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    Serial.println("failed to open config file for writing");
  }

  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    Serial.println(F("Failed to write to file"));
  }
  configFile.close();
}

bool loadConfigFile()
{
  //clean FS, for testing
  // SPIFFS.format();

  //read configuration from FS json
  Serial.println("mounting FS...");

  // May need to make it begin(true) first time you are using SPIFFS
  // NOTE: This might not be a good way to do this! begin(true) reformats the spiffs
  // it will only get called if it fails to mount, which probably means it needs to be
  // formatted, but maybe dont use this if you have something important saved on spiffs
  // that can't be replaced.
  if (SPIFFS.begin(false) || SPIFFS.begin(true))
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        Serial.println("opened config file");
        StaticJsonDocument<512> json;
        DeserializationError error = deserializeJson(json, configFile);
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          Serial.println("\nparsed json");

          return true;
        }
        else
        {
          Serial.println("failed to load json config");
        }
      }
    }
  }
  else
  {
    Serial.println("failed to mount FS");
  }
  //end read
  return false;
}

//callback notifying us of the need to save config
void saveConfigCallback()
{
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

// This gets called when the config mode is launced, might
// be useful to update a display with this info.
void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entered Conf Mode");

  Serial.print("Config SSID: ");
  Serial.println(myWiFiManager->getConfigPortalSSID());

  Serial.print("Config IP Address: ");
  Serial.println(WiFi.softAPIP());
}

// Custom HTML WiFiManagerParameter don't support getValue directly
String getCustomParamValue(WiFiManager *myWiFiManager, String name)
{
  String value;

  int numArgs = myWiFiManager->server->args();
  for (int i = 0; i < numArgs; i++) {
    Serial.println(myWiFiManager->server->arg(i));
  }
  if (myWiFiManager->server->hasArg(name))
  {
    value = myWiFiManager->server->arg(name);
  }

  return value;
}

void setup()
{
  Serial.println("testmsg");
  pinMode(PIN_LED, OUTPUT);

  bool forceConfig = false;

  drd = new DoubleResetDetector(DRD_TIMEOUT, DRD_ADDRESS);
  if (drd->detectDoubleReset())
  {
    Serial.println(F("Forcing config mode as there was a Double reset detected"));
    forceConfig = true;
  }

  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }

  //WiFi.disconnect();
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  Serial.begin(115200);
  delay(10);

  //wm.resetSettings(); // wipe settings

  WiFiManager wm;

  //wm.resetSettings(); // wipe settings
  //set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  //--- additional Configs params --- 
  // Email Receiver Text box (String)
  WiFiManagerParameter mailReceiver("key_text", "Enter your email to reveive notifications", RECIPIENT_EMAIL, 10000); // 10000 == max length
    
  wm.addParameter(&mailReceiver);
  

  //if(isValidMail(mailReceiver.getValue())){
   // break;
  //}

  Serial.println("hello");

  digitalWrite(PIN_LED, LOW);
  if (forceConfig)
  {
    if (!wm.startConfigPortal("WifiTetris", "clock123"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }else {
        // verity the email address
        strncpy(RECIPIENT_EMAIL, mailReceiver.getValue(), sizeof(RECIPIENT_EMAIL) - 1);
        if (!isValidMail(RECIPIENT_EMAIL)) {
            Serial.println("Invalid email format. Please reset to configure again.");
            ESP.restart(); // restart the esp32 to allow configer again
        }
    }
  }
  else{
    if (!wm.autoConnect("WifiTetris", "clock123"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      // if we still have not connected restart and try all over again
      ESP.restart();
      delay(5000);
    }
  }

  // If we get here, we are connected to the WiFi
  digitalWrite(PIN_LED, HIGH);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  String welcomeHtml = R"(
<div style="font-family: Arial, sans-serif; color: #444;">
  <h1 style="color: green;">Welcome to Smart Bin!</h1>
  <p>Your smart bin is now connected to WiFi.</p>
  <div style="font-size: 50px; color: green;">🎉</div>
</div>
)";
  sendMail("I am your Smart Bin, nice to meet you!", welcomeHtml);

}

void loop()
{
  drd->loop();
  
 //Fire Alert email
if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    if (data == "FIRE_ALERT"){
 String fireAlertHtml = R"(
<div style="font-family: Arial, sans-serif; color: #444;">
  <h1 style="color: red;">Fire Alert!</h1>
  <p>A potential fire has been detected near the trash bin.</p>
  <div style="font-size: 50px; color: red;">🔥</div>
</div>
)";
 sendMail("Fire Alert", fireAlertHtml);
  }

 //Smart bin full notification

 String trashFullHtml = R"(
<div style="font-family: Arial, sans-serif; color: #444;">
  <h1 style="color: orange;">Trash Bin Full</h1>
  <p>The trash bin is full and needs to be emptied.</p>
  <div style="font-size: 50px; color: orange;">🗑️</div>
</div>
)";
 sendMail("Trash Bin Full", trashFullHtml);

}
}
```

As mentioned in the previous Arduino section, we have transitioned to using the ESP32 to control the VL53L0X distance sensor, leading to changes in the ESP32 section of the code.

In this new version, the primary change involves the addition of capacity monitoring code implemented using the VL53L0X sensor.

<aside>
👨🏻‍💻 ESP32_Smartbin_Networking_V2.0

</aside>

```arduino
/*******************************************************************
    It will enter config mode if
    - Cant connect to the Wifi
    - config doesnt exist on the FS
    - User has "double reset" (pressed the reset button twice)
 *******************************************************************/
// ----------------------------
// Library Defines - Need to be defined before library import
// ----------------------------

#define ESP_DRD_USE_SPIFFS true

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <WiFi.h>
#include <FS.h>
#include <SPIFFS.h>

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include <WiFiManager.h>
// Captive portal for configuring the WiFi

// Can be installed from the library manager (Search for "WifiManager", install the Alhpa version)
// https://github.com/tzapu/WiFiManager

#include <ESP_DoubleResetDetector.h>
// A library for checking if the reset button has been pressed twice
// Can be used to enable config mode
// Can be installed from the library manager (Search for "ESP_DoubleResetDetector")
//https://github.com/khoih-prog/ESP_DoubleResetDetector

#include <ArduinoJson.h>
// ArduinoJson is used for parsing and creating the config file.
// Search for "Arduino Json" in the Arduino Library manager
// https://github.com/bblanchon/ArduinoJson

#include <Arduino.h>

#include <ESP_Mail_Client.h>

#include "Adafruit_VL53L0X.h"

#define WIFI_SSID "REPLACE_WITH_YOUR_SSID"
#define WIFI_PASSWORD "REPLACE_WITH_YOUR_PASSWORD"

/** The smtp host name e.g. smtp.gmail.com for GMail or smtp.office365.com for Outlook or smtp.mail.yahoo.com */
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 587

/* The sign in credentials */
#define AUTHOR_EMAIL "·······@gmail.com"
#define AUTHOR_PASSWORD "kklt wvdk zfzc qaup"

#define EMPTY_DEPTH 150
#define FULL_DEPTH 20
#define DEBOUNCE_COUNT 3

int usedCapacity = 0;
int debounceCounter = 0;
bool trashFullNotified = false;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

bool isValidMail(char* str){
    int atpos = -1;
    int dotpos = -1;
    int length = 0;
    while(str[length] != '\0'){
        if(str[length] == '@'){
            if(atpos != -1){
                return false;
            }
            atpos = length;
        }
        if(str[length] == '.'){
            dotpos = length;
        }
        length++;
    }
    if(atpos != -1){
        return dotpos + 1 < length;
    }else{
        return false;
    }
}

/* Recipient's email*/
char RECIPIENT_EMAIL[10000] ="";

/* Declare the global used SMTPSession object for SMTP transport */
SMTPSession smtp;
/* Callback function to get the Email sending status */
void (*smtpCallback)(SMTP_Status status);

void sendMail(const String &subject,const String &htmlContent){
  /*  Set the network reconnection option */
  MailClient.networkReconnect(true);

  /** Enable the debug via Serial port
   * 0 for no debugging
   * 1 for basic level debugging
   *
   * Debug port can be changed via ESP_MAIL_DEFAULT_DEBUG_PORT in ESP_Mail_FS.h
   */
  smtp.debug(1);

  /* Set the callback function to get the sending results */
  smtp.callback(smtpCallback);

  /* Declare the Session_Config for user defined session credentials */
  Session_Config config;

  /* Set the session config */
  config.server.host_name = SMTP_HOST;
  config.server.port = SMTP_PORT;
  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;
  config.login.user_domain = "";

  /*
  Set the NTP config time
  For times east of the Prime Meridian use 0-12
  For times west of the Prime Meridian add 12 to the offset.
  Ex. American/Denver GMT would be -6. 6 + 12 = 18
  See https://en.wikipedia.org/wiki/Time_zone for a list of the GMT/UTC timezone offsets
  */
  config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  config.time.gmt_offset = 0;
  config.time.day_light_offset = 0;

  /* Declare the message class */
  SMTP_Message message;

  /* Set the message headers */
  message.sender.name = F("ESP");
  message.sender.email = AUTHOR_EMAIL;
  message.subject = subject;
  message.addRecipient(F("User"), RECIPIENT_EMAIL);
    
  /*Send HTML message*/
  message.html.content = htmlContent.c_str();
  message.text.charSet = "us-ascii";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

   
  /*Send raw text message
  String textMsg = "Hello World! - Sent from ESP board";
  message.text.content = textMsg.c_str();
  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/
  
  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
  message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;

  /* Connect to the server */
  if (!smtp.connect(&config)){
    ESP_MAIL_PRINTF("Connection error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
    return;
  }

  if (!smtp.isLoggedIn()){
    Serial.println("\nNot yet logged in.");
  }
  else{
    if (smtp.isAuthenticated())
      Serial.println("\nSuccessfully logged in.");
    else
      Serial.println("\nConnected with no Auth.");
  }

  /* Start sending Email and close the session */
  if (!MailClient.sendMail(&smtp, &message))
    ESP_MAIL_PRINTF("Error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());

}

// -------------------------------------
// -------   Other Config   ------
// -------------------------------------

const int PIN_LED = 2;

#define JSON_CONFIG_FILE "/esp32Smartbin_config.json"

// Number of seconds after reset during which a
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 10

// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

// -----------------------------

// -----------------------------

DoubleResetDetector *drd;

//flag for saving data
bool shouldSaveConfig = false;

void saveConfigFile()
{
  Serial.println(F("Saving config"));
  StaticJsonDocument<512> json;

  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    Serial.println("failed to open config file for writing");
  }

  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    Serial.println(F("Failed to write to file"));
  }
  configFile.close();
}

bool loadConfigFile()
{
  //clean FS, for testing
  // SPIFFS.format();

  //read configuration from FS json
  Serial.println("mounting FS...");

  // May need to make it begin(true) first time you are using SPIFFS
  // NOTE: This might not be a good way to do this! begin(true) reformats the spiffs
  // it will only get called if it fails to mount, which probably means it needs to be
  // formatted, but maybe dont use this if you have something important saved on spiffs
  // that can't be replaced.
  if (SPIFFS.begin(false) || SPIFFS.begin(true))
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        Serial.println("opened config file");
        StaticJsonDocument<512> json;
        DeserializationError error = deserializeJson(json, configFile);
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          Serial.println("\nparsed json");

          return true;
        }
        else
        {
          Serial.println("failed to load json config");
        }
      }
    }
  }
  else
  {
    Serial.println("failed to mount FS");
  }
  //end read
  return false;
}

//callback notifying us of the need to save config
void saveConfigCallback()
{
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

// This gets called when the config mode is launced, might
// be useful to update a display with this info.
void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entered Conf Mode");

  Serial.print("Config SSID: ");
  Serial.println(myWiFiManager->getConfigPortalSSID());

  Serial.print("Config IP Address: ");
  Serial.println(WiFi.softAPIP());
}

// Custom HTML WiFiManagerParameter don't support getValue directly
String getCustomParamValue(WiFiManager *myWiFiManager, String name)
{
  String value;

  int numArgs = myWiFiManager->server->args();
  for (int i = 0; i < numArgs; i++) {
    Serial.println(myWiFiManager->server->arg(i));
  }
  if (myWiFiManager->server->hasArg(name))
  {
    value = myWiFiManager->server->arg(name);
  }

  return value;
}

void setup(){
  // Set up for tof sensor
  while (! Serial) {
    delay(1);
  }
 
  Serial.println("VL53L0X Ininitial test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

   Serial.println("testmsg");
   pinMode(PIN_LED, OUTPUT);

  bool forceConfig = false;

  drd = new DoubleResetDetector(DRD_TIMEOUT, DRD_ADDRESS);
  if (drd->detectDoubleReset())
  {
    Serial.println(F("Forcing config mode as there was a Double reset detected"));
    forceConfig = true;
  }

  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }

  //WiFi.disconnect();
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  Serial.begin(115200);
  delay(10);

  //wm.resetSettings(); // wipe settings

  WiFiManager wm;

  //wm.resetSettings(); // wipe settings
  //set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  //--- additional Configs params --- 
  // Email Receiver Text box (String)
  WiFiManagerParameter mailReceiver("key_text", "Enter your email to reveive notifications", RECIPIENT_EMAIL, 10000); // 10000 == max length
    
  wm.addParameter(&mailReceiver);
  

  Serial.println("hello");

  digitalWrite(PIN_LED, LOW);
  if (forceConfig)
  {
    if (!wm.startConfigPortal("WifiTetris", "clock123"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }else {
        // verity the email address
        strncpy(RECIPIENT_EMAIL, mailReceiver.getValue(), sizeof(RECIPIENT_EMAIL) - 1);
        if (!isValidMail(RECIPIENT_EMAIL)) {
            Serial.println("Invalid email format. Please reset to configure again.");
            ESP.restart(); // restart the esp32 to allow configer again
        }
    }
  }
  else{
    if (!wm.autoConnect("WifiTetris", "clock123"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      // if we still have not connected restart and try all over again
      ESP.restart();
      delay(5000);
    }
  }

  // If we get here, we are connected to the WiFi
  digitalWrite(PIN_LED, HIGH);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  String welcomeHtml = R"(
  <div style="font-family: Arial, sans-serif; color: #444;">
  <h1 style="color: green;">Welcome to Smart Bin!</h1>
  <p>Your smart bin is now connected to WiFi.</p>
  <div style="font-size: 50px; color: green;">🎉</div>
  </div>
  )";
  sendMail("I am your Smart Bin, nice to meet you!", welcomeHtml);

}

void loop(){
  drd->loop();

  /* Measure and calculate the capacity && full notification */
  VL53L0X_RangingMeasurementData_t measure;
   
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    measure.RangeMilliMeter = constrain(measure.RangeMilliMeter, FULL_DEPTH, EMPTY_DEPTH);
    Serial.print("Distance (mm): "); 
    Serial.print(measure.RangeMilliMeter);
    Serial.print(";");
    usedCapacity = map(measure.RangeMilliMeter, FULL_DEPTH, EMPTY_DEPTH, 100, 0);
    Serial.print("Used Capacity (%): ");
    Serial.println(usedCapacity);
    if (usedCapacity == 100){
      debounceCounter ++;
    }else{
      debounceCounter = 0;
    }
    if (debounceCounter >= DEBOUNCE_COUNT){
      if (!trashFullNotified){
        String trashFullHtml = R"(
        <div style="font-family: Arial, sans-serif; color: #444;">
        <h1 style="color: orange;">Trash Bin Full</h1>
        <p>The trash bin is full and needs to be emptied.</p>
        <div style="font-size: 50px; color: orange;">🗑️</div>
        </div>
        )";
        sendMail("Trash Bin Full", trashFullHtml);
        trashFullNotified = true;
      }
    }else{
      trashFullNotified = false;
    }
  } else {
    Serial.println(" out of range ");
  }

 /*Fire Alert email*/
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    if (data == "FIRE_ALERT"){
      String fireAlertHtml = R"(
      <div style="font-family: Arial, sans-serif; color: #444;">
      <h1 style="color: red;">Fire Alert!</h1>
      <p>A potential fire has been detected near the trash bin.</p>
      <div style="font-size: 50px; color: red;">🔥</div>
      </div>
      )";
      sendMail("Fire Alert", fireAlertHtml);
    }
  }

}
```

In the new version, we expanded the code to enable data exchange with the Blynk platform. Data to be monitored is uploaded through virtual pins, and new smoke threshold values can be inserted. Additionally, to meet users' personalized needs, we introduced a feature to send timed reminders for taking out the trash and a switch to decide whether remind weekly. The code below will just demonstrate main changing part.

<aside>
👨🏻‍💻 ESP32_Smartbin_Networking_V2.1

</aside>

```arduino
BLYNK_CONNECTED() {
  rtc.begin();
  Blynk.syncVirtual(V3);
}

BLYNK_WRITE(V2) {  
  int newThreshold = param.asInt();
  Serial2.println("NEW_THRESHOLD:" + String(newThreshold));
}

BLYNK_WRITE(V3) {
  Serial.println("Time Input widget triggered");
  TimeInputParam t(param);
  reminderHour = t.getStartHour();
  reminderMinute = t.getStartMinute();
  reminderSent_2 = false; // Reset reminder flag

  // Clear previous day selections
  for (int i = 0; i < 7; i++) {
    reminderDays[i] = false;
  }

  // Set days based on widget input
  for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      reminderDays[i % 7] = true;
    }
  }
}

BLYNK_WRITE(V4){
  oneTimeReminder = param.asInt()==1; 
}

void checkReminder() {
  if (year() != 1970) {
    int currentDayOfWeek = weekday(); // Get current day of the week (1 for Sunday, 7 for Saturday)
    int currentHour = hour();
    int currentMinute = minute();

    // Debugging output
    Serial.print("Current time: ");
    Serial.print(currentHour);
    Serial.print(":");
    Serial.print(currentMinute);
    Serial.print(", Day of week: ");
    Serial.println(currentDayOfWeek);
    // Adjust currentDayOfWeek to match array index
    int adjustedDayOfWeek = (currentDayOfWeek + 6) % 7; // Convert to 0-6, with Monday as 0

    // Check if it's the right time and day
    if (reminderDays[adjustedDayOfWeek] && currentHour == reminderHour && currentMinute == reminderMinute) {
      Serial.println("Sending reminder email...");

      // Send reminder email                                                                                                                              
      String reminderHtml = R"(
        <div style="font-family: Arial, sans-serif; color: #444;">
        <h1 style="color: #FFD306;">Time to Empty Trash Bin</h1>
        <p>It's time to empty your trash bin. Please remember to do so.</p>
        <div style="font-size: 50px; color: green;">🔔</div>
        </div>
      )";
      sendMail("Trash Bin Reminder", reminderHtml);
      reminderSent_2 = true;
      if (oneTimeReminder){
        for(int i=0; i < 7; i++){
          reminderDays[i] = false;
        }
      }
    } else {
      // For debugging: Show why the reminder wasn't sent
      if (!reminderDays[currentDayOfWeek - 1]) {
        Serial.println("Today is not a reminder day.");
      }
      if (currentHour != reminderHour || currentMinute != reminderMinute) {
        Serial.println("It's not the reminder time yet.");
      }
    }
  } else {
    Serial.println("RTC not set. Current year is 1970.");
  }
```

The next version (which is also the final version) was developed to address the issue of the ESP32 continuously sending emails in the event of a potential fire. While constant notifications could serve as critical reminders in emergency situations, this approach could inevitably result in an overwhelming number of emails, potentially diminishing the urgency of each alert and leading to user inconvenience.

<aside>
👨🏻‍💻 ESP32_Smartbin_Networking_V2.2

</aside>

```arduino

/*******************************************************************
 * ESP32 part of Smart Bin Project
 * 
 * This section of code is part of a larger Smart Bin project, aiming to 
 * create an intelligent waste management system. The project utilizes 
 * various sensors and modules to monitor trash levels, detect potential fires,
 * and enable remote configurations via Wi-Fi.

 * This particular code segment is designed for the ESP32 . 
 * It incorporates features such as capacity monitor,Wi-Fi management, email notifications, 
 * and integration with the Blynk platform for remote monitoring and control. 
 * Additionally, it communicates with an Arduino controller for real-time 
 * smoke level data and fire alert management.

 * Key features include:
 * - Bin capacity monitor
 * - Wi-Fi configuration and management
 * - Email notifications for various alerts and reminders
 * - Integration with Blynk for remote data visualization and control
 * - Communication with Arduino for smoke detection and fire alerts
 *******************************************************************/
// ----------------------------
// Library Defines - Need to be defined before library import
// ----------------------------
// Configure for BLYNK IoT Platform
#define BLYNK_TEMPLATE_ID "TMPL557w-0nUJ"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "mQDaBT2-iy4D_sHPUjibGuziy8KxBRU2"

// Configure the ESP_DoubleResetDetector library
// It tells the library to use the SPIFFS (SPI Flash File System) 
// for storing the double reset detector's state.
#define ESP_DRD_USE_SPIFFS true

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <WiFi.h>
#include <FS.h>
#include <SPIFFS.h>

// ----------------------------
// Additional Libraries need to be installed.
// ----------------------------

// Captive portal for configuring the WiFi
#include <WiFiManager.h>

// A library for checking if the reset button has been pressed twice
// Can be used to enable config mode
#include <ESP_DoubleResetDetector.h>

// ArduinoJson is used for parsing and creating the config file.
#include <ArduinoJson.h>

#include <Arduino.h>

// Used for Email function
#include <ESP_Mail_Client.h>

// Used for VL53L0X sensor
#include "Adafruit_VL53L0X.h"

//Libraries for using in Blynk
#include <Blynk.h>
#include <BlynkSimpleEsp32.h> 

//Libraries for time input widget and accurate timekeeping
#include <TimeLib.h>
#include <WidgetRTC.h>

// The smtp host name e.g. smtp.gmail.com for GMail or smtp.office365.com for Outlook or smtp.mail.yahoo.com 
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 587

// The sign in credentials 
#define AUTHOR_EMAIL "lhyixx0629@gmail.com"
#define AUTHOR_PASSWORD "acxx kday nbkb tfhl"

// Sensor and control configurations
#define EMPTY_DEPTH 150
#define FULL_DEPTH 30
// Number of consistent readings required to confirm a state change, 
// set to 3 to reduce measurement errors. 
#define DEBOUNCE_COUNT 3

// Define the RX and TX pin for Serial2
#define RX2 16  
#define TX2 17  

// Variables for storing sensor data from arduino uno
int globalSmokeValue = 0;
String data;

int usedCapacity = 0;
int debounceCounter = 0;
bool trashFullNotified = false;

// This array holds the Blynk authorization token, 
// which is used to connect the device to the Blynk server.
char auth[] = BLYNK_AUTH_TOKEN;

// Variables for time input widget (the Rminder)
int reminderHour = -1;
int reminderMinute = -1;
bool reminderDays[7] = {false}; // Array to store the selected days (Sunday to Saturday)
bool reminderSent_2 = false;

// This boolean flag is used to determine whether the reminder should occur only once. 
// By default, the reminder widget in the Blynk app is set to repeat weekly. 
// When 'oneTimeReminder' is set to true, it overrides this behavior to trigger the reminder just once.
bool oneTimeReminder = false;

// 'fireAlertCount' tracks the number of fire alert emails sent. 
// 'maxFireAlerts' limits these to prevent email flooding
int fireAlertCount = 0;
const int maxFireAlerts = 3;

WidgetRTC rtc;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

BLYNK_CONNECTED() {
  rtc.begin();
  Blynk.syncVirtual(V3);
}

BLYNK_WRITE(V2) {  
  int newThreshold = param.asInt();
  Serial2.println("NEW_THRESHOLD:" + String(newThreshold));
}

BLYNK_WRITE(V3) {
  Serial.println("Time Input widget triggered");
  TimeInputParam t(param);
  reminderHour = t.getStartHour();
  reminderMinute = t.getStartMinute();
  reminderSent_2 = false; // Reset reminder flag

  // Clear previous day selections
  for (int i = 0; i < 7; i++) {
    reminderDays[i] = false;
  }

  // Set days based on widget input
  for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      reminderDays[i % 7] = true;
    }
  }
}

BLYNK_WRITE(V4){
  oneTimeReminder = param.asInt()==1; 
}

void checkReminder() {
  if (year() != 1970) {
    int currentDayOfWeek = weekday(); // Get current day of the week (1 for Sunday, 7 for Saturday)
    int currentHour = hour();
    int currentMinute = minute();

    // Debugging output
    Serial.print("Current time: ");
    Serial.print(currentHour);
    Serial.print(":");
    Serial.print(currentMinute);
    Serial.print(", Day of week: ");
    Serial.println(currentDayOfWeek);
    // Adjust currentDayOfWeek to match array index
    int adjustedDayOfWeek = (currentDayOfWeek + 6) % 7; // Convert to 0-6, with Monday as 0

    // Check if it's the right time and day
    if (reminderDays[adjustedDayOfWeek] && currentHour == reminderHour && currentMinute == reminderMinute) {
      Serial.println("Sending reminder email...");

      // Send reminder email                                                                                                                              
      String reminderHtml = R"(
        <div style="font-family: Arial, sans-serif; color: #444;">
        <h1 style="color: #FFD306;">Time to Empty Trash Bin</h1>
        <p>It's time to empty your trash bin. Please remember to do so.</p>
        <div style="font-size: 50px; color: green;">🔔</div>
        </div>
      )";
      sendMail("Trash Bin Reminder", reminderHtml);
      reminderSent_2 = true;
      if (oneTimeReminder){
        for(int i=0; i < 7; i++){
          reminderDays[i] = false;
        }
      }
    } else {
      // For debugging: Show why the reminder wasn't sent
      if (!reminderDays[currentDayOfWeek - 1]) {
        Serial.println("Today is not a reminder day.");
      }
      if (currentHour != reminderHour || currentMinute != reminderMinute) {
        Serial.println("It's not the reminder time yet.");
      }
    }
  } else {
    Serial.println("RTC not set. Current year is 1970.");
  }
}

//Check whether the input email is in correct format
bool isValidMail(char* str){
    int atpos = -1;
    int dotpos = -1;
    int length = 0;
    while(str[length] != '\0'){
        if(str[length] == '@'){
            if(atpos != -1){
                return false;
            }
            atpos = length;
        }
        if(str[length] == '.'){
            dotpos = length;
        }
        length++;
    }
    if(atpos != -1){
        return dotpos + 1 < length;
    }else{
        return false;
    }
}

/* Recipient's email*/
char RECIPIENT_EMAIL[10000] ="";

/* Declare the global used SMTPSession object for SMTP transport */
SMTPSession smtp;
/* Callback function to get the Email sending status */
void (*smtpCallback)(SMTP_Status status);

void sendMail(const String &subject,const String &htmlContent){
  /*  Set the network reconnection option */
  MailClient.networkReconnect(true);

  /** Enable the debug via Serial port
   * 0 for no debugging
   * 1 for basic level debugging
   *
   * Debug port can be changed via ESP_MAIL_DEFAULT_DEBUG_PORT in ESP_Mail_FS.h
   */
  smtp.debug(1);

  /* Set the callback function to get the sending results */
  smtp.callback(smtpCallback);

  /* Declare the Session_Config for user defined session credentials */
  Session_Config config;

  /* Set the session config */
  config.server.host_name = SMTP_HOST;
  config.server.port = SMTP_PORT;
  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;
  config.login.user_domain = "";

  /*
  Set the NTP config time
  For times east of the Prime Meridian use 0-12
  For times west of the Prime Meridian add 12 to the offset.
  Ex. American/Denver GMT would be -6. 6 + 12 = 18
  See https://en.wikipedia.org/wiki/Time_zone for a list of the GMT/UTC timezone offsets
  */
  config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  config.time.gmt_offset = 0;
  config.time.day_light_offset = 0;

  /* Declare the message class */
  SMTP_Message message;

  /* Set the message headers */
  message.sender.name = F("Smartbin");
  message.sender.email = AUTHOR_EMAIL;
  message.subject = subject;
  message.addRecipient(F("User"), RECIPIENT_EMAIL);
    
  /*Send HTML message*/
  message.html.content = htmlContent.c_str();
  message.text.charSet = "us-ascii";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
  message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;

  /* Connect to the server */
  if (!smtp.connect(&config)){
    ESP_MAIL_PRINTF("Connection error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
    return;
  }

  if (!smtp.isLoggedIn()){
    Serial.println("\nNot yet logged in.");
  }
  else{
    if (smtp.isAuthenticated())
      Serial.println("\nSuccessfully logged in.");
    else
      Serial.println("\nConnected with no Auth.");
  }

  /* Start sending Email and close the session */
  if (!MailClient.sendMail(&smtp, &message))
    ESP_MAIL_PRINTF("Error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());

}

// -------------------------------------
//            Other Config   
// -------------------------------------

const int PIN_LED = 2;

#define JSON_CONFIG_FILE "/esp32Smartbin_config.json"

// Number of seconds after reset during which a
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 10

// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

// -----------------------------

// -----------------------------

DoubleResetDetector *drd;

//flag for saving data
bool shouldSaveConfig = false;

void saveConfigFile()
{
  Serial.println(F("Saving config"));
  StaticJsonDocument<512> json;

  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    Serial.println("failed to open config file for writing");
  }

  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    Serial.println(F("Failed to write to file"));
  }
  configFile.close();
}

bool loadConfigFile()
{
  //clean FS, for testing
  //SPIFFS.format();

  //read configuration from FS json
  Serial.println("mounting FS...");

  // May need to make it begin(true) first time you are using SPIFFS
  // NOTE: This might not be a good way to do this! begin(true) reformats the spiffs
  // it will only get called if it fails to mount, which probably means it needs to be
  // formatted, but maybe dont use this if you have something important saved on spiffs
  // that can't be replaced.
  if (SPIFFS.begin(false) || SPIFFS.begin(true))
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        Serial.println("opened config file");
        StaticJsonDocument<512> json;
        DeserializationError error = deserializeJson(json, configFile);
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          Serial.println("\nparsed json");

          return true;
        }
        else
        {
          Serial.println("failed to load json config");
        }
      }
    }
  }
  else
  {
    Serial.println("failed to mount FS");
  }
  //end read
  return false;
}

//callback notifying us of the need to save config
void saveConfigCallback()
{
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

// This gets called when the config mode is launced, might
// be useful to update a display with this info.
void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entered Conf Mode");

  Serial.print("Config SSID: ");
  Serial.println(myWiFiManager->getConfigPortalSSID());

  Serial.print("Config IP Address: ");
  Serial.println(WiFi.softAPIP());
}

// Custom HTML WiFiManagerParameter don't support getValue directly
String getCustomParamValue(WiFiManager *myWiFiManager, String name)
{
  String value;

  int numArgs = myWiFiManager->server->args();
  for (int i = 0; i < numArgs; i++) {
    Serial.println(myWiFiManager->server->arg(i));
  }
  if (myWiFiManager->server->hasArg(name))
  {
    value = myWiFiManager->server->arg(name);
  }

  return value;
}

BlynkTimer timer; 

void setup(){
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RX2, TX2); // Set baud rate for Serial2 to 115200 and define pins
  delay(1500);

  //Connecting to Blynk Cloud
  Blynk.config(auth);  
  
  // Setting interval to send data to Blynk Cloud to 1000ms. 
  // It means that data will be sent every second
  timer.setInterval(1000L, []() {
    Blynk.virtualWrite(V0, usedCapacity); // send usedCapacity
  });

  // Timer to check the reminder every minute
  timer.setInterval(60000L, checkReminder);

  // Set up for tof sensor
  while (! Serial) {
    delay(1);
  }
 
  Serial.println("VL53L0X Ininitial test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

 
  Serial.println("testmsg");
  pinMode(PIN_LED, OUTPUT);

  bool forceConfig = false;

  drd = new DoubleResetDetector(DRD_TIMEOUT, DRD_ADDRESS);
  if (drd->detectDoubleReset())
  {
    Serial.println(F("Forcing config mode as there was a Double reset detected"));
    forceConfig = true;
  }

  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }

  //WiFi.disconnect();
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  
  delay(10);

  WiFiManager wm;

  wm.resetSettings(); // wipe settings
  //set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  //--- additional Configs params --- 
  // Email Receiver Text box (String)
  WiFiManagerParameter mailReceiver("key_text", "Enter your email to reveive notifications", RECIPIENT_EMAIL, 10000); // 10000 == max length
    
  wm.addParameter(&mailReceiver);
   

  digitalWrite(PIN_LED, LOW);
  if (forceConfig)
  {
    if (!wm.startConfigPortal("Wifi_Smartbin", "smartbin273"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }else {
        // verity the email address
        strncpy(RECIPIENT_EMAIL, mailReceiver.getValue(), sizeof(RECIPIENT_EMAIL) - 1);
        if (!isValidMail(RECIPIENT_EMAIL)) {
            Serial.println("Invalid email format. Please reset to configure again.");
            ESP.restart(); // restart the esp32 to allow configer again
        }
    }
  }
  else{
    if (!wm.autoConnect("Wifi_Smartbin", "smartbin273"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      // if we still have not connected restart and try all over again
      ESP.restart();
      delay(5000);
    }
  }

  // If we get here, we are connected to the WiFi
  digitalWrite(PIN_LED, HIGH);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  String welcomeHtml = R"(
  <div style="font-family: Arial, sans-serif; color: #444;">
  <h1 style="color: green;">Welcome to Smart Bin!</h1>
  <p>Your smart bin is now connected to WiFi.</p>
  <div style="font-size: 50px; color: green;">🎉</div>
  </div>
  )";
  sendMail("I am your Smart Bin, nice to meet you!", welcomeHtml);

}

void loop(){
  drd->loop();

  // Runs all Blynk stuff
  Blynk.run(); 

  // runs BlynkTimer
  timer.run(); 
  //obtain current time
  time_t currentTime = now();
  int currentHour = hour();
  int currentMinute = minute();

  /* Measure and calculate the capacity && full notification */
  VL53L0X_RangingMeasurementData_t measure;
   
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    measure.RangeMilliMeter = constrain(measure.RangeMilliMeter, FULL_DEPTH, EMPTY_DEPTH);
    Serial.print("Distance (mm): "); 
    Serial.print(measure.RangeMilliMeter);
    Serial.print(";");
    usedCapacity = map(measure.RangeMilliMeter, FULL_DEPTH, EMPTY_DEPTH, 100, 0);
    Serial.print("Used Capacity (%): ");
    Serial.println(usedCapacity);
    if (usedCapacity == 100){
      debounceCounter ++;
    }else{
      debounceCounter = 0;
    } 
    if (debounceCounter >= DEBOUNCE_COUNT){
      if (!trashFullNotified){
        String trashFullHtml = R"(
        <div style="font-family: Arial, sans-serif; color: #444;">
        <h1 style="color: green;">Trash Bin Full</h1>
        <p>The trash bin is full and needs to be emptied.</p>
        <div style="font-size: 50px; color: orange;">🗑️</div>
        </div>
        )";
        sendMail("Trash Bin Full", trashFullHtml);
        trashFullNotified = true;
      }
    }else{
      trashFullNotified = false;
    }
  } else {
    Serial.println(" out of range ");
  }

  if (Serial2.available()) {
    Serial.println("Reading from Serial2...");
    String data = Serial2.readStringUntil('\n');
    data.trim();
    Serial.print("Received: ");
    Serial.println(data);

    if(data.startsWith("SMOKE_VALUE:")){
      globalSmokeValue = data.substring(12).toInt();
      Serial.print("globalSmokeValue: ");
      Serial.println(globalSmokeValue);
      Blynk.virtualWrite(V1,globalSmokeValue);
    }

   /*Fire Alert email*/
    if (data == "FIRE_ALERT"){
      if (fireAlertCount < maxFireAlerts) {
        Serial.println("FIRE_ALERT (ESP32)");
        String fireAlertHtml = R"(
        <div style="font-family: Arial, sans-serif; color: #444;">
        <h1 style="color: red;">Fire Alert!</h1>
        <p>A potential fire has been detected near the trash bin.</p>
        <div style="font-size: 50px; color: red;">🔥</div>
        </div>
        )";
        sendMail("Fire Alert", fireAlertHtml);

        fireAlertCount++;
      }
    }
    if (data == "FIRE CLEARED"){
      fireAlertCount = 0;
    }
  }

}
```

# Data transmission

![Untitled](IoT%20Smart%20Bin%20Log%20Book%204348c05ba3bf46efb9bcb27055f184dd/Untitled.png)

The data transmission in the Smart Bin system, as depicted in the flowchart, occurs primarily through UART communication between the ESP32 and Arduino boards. Here's how it works:

1. **From ESP32 to Arduino**:
    - The ESP32 sends configuration data to the Arduino, such as new smoke threshold levels that the Arduino uses to detect whether the smoke concentration has reached a level indicating a potential fire.
    - This transmission allows the ESP32 to dynamically adjust the parameters that the Arduino uses for sensing and decision-making without needing to change the Arduino's programmed code.
2. **From Arduino to ESP32**:
    - The Arduino collects sensor data, like smoke values and distance measurements indicating the bin's capacity, and sends this information back to the ESP32.
    - In the event of a fire detection, the Arduino sends a fire alert to the ESP32. Similarly, when the situation is cleared, a fire cleared signal is transmitted.
3. **Email Notifications Triggered by ESP32**:
    - Upon receiving certain types of data, such as a fire alert or a full bin notification from the Arduino, the ESP32 initiates email notifications. These emails are sent through an SMTP server to the user's email address.
    - The ESP32 manages the content and triggering of these emails based on the data received from the Arduino and its own logic for reminders and alerts.
4. **Wi-Fi as the Backbone**:
    - The Wi-Fi connection on the ESP32 is essential for transmitting email notifications to the SMTP server. The ESP32 must be connected to a Wi-Fi network to send out these emails.
5. **State Transitions and Buzzer Control**:
    - While not a data transmission to an external system, the state transitions within the Arduino, such as changing from idle to fire detected state, dictate the internal data flow which may lead to actions like activating a buzzer.

In this setup, UART serves as a reliable, real-time communication protocol for sending and receiving sensor data and commands between the ESP32 and Arduino. The Wi-Fi connection is critical for enabling the ESP32 to communicate with external services, such as email servers, to notify users of various bin states and alerts. This dual-layered communication approach—UART for internal system interactions and Wi-Fi for external notifications—ensures that the Smart Bin operates efficiently and keeps the user informed.

***Guide for UART communication***

[UART: A Hardware Communication Protocol Understanding Universal Asynchronous Receiver/Transmitter | Analog Devices](https://www.analog.com/en/resources/analog-dialogue/articles/uart-a-hardware-communication-protocol.html)

# Workflow

![28dacfa5c36770690ef0bf28138bb03.png](IoT%20Smart%20Bin%20Log%20Book%204348c05ba3bf46efb9bcb27055f184dd/28dacfa5c36770690ef0bf28138bb03.png)

This flowchart details the operation of a Smart Bin system that integrates the functionalities of an ESP32 module with an Arduino board, as well as the Blynk platform for user interface and SMTP for sending emails. Here's a detailed walkthrough:

### ESP32 Workflow

1. **Initialization**:
    - The ESP32 components and Blynk are initialized.
2. **Wi-Fi Configuration**:
    - The Wi-Fi Manager is set up to connect the ESP32 to the internet. If no configuration exists, it starts a configuration portal for new credentials. If it fails, it retries. If an existing configuration is found, it attempts to auto-connect.
3. **Email Configuration**:
    - Reads email configuration from SPIFFS (onboard flash file system) and sets up the SMTP session for sending emails. If no configuration is found, it enters Wi-Fi config mode.
4. **Email Notification**:
    - Sends a welcome email upon successful configuration.
5. **Main Loop**:
    - The main loop obtains the current time from Blynk, measures the distance to calculate the used capacity of the bin, checks for full capacity, and sends a full notification email if necessary.
    - It reads smoke value data from the Arduino and checks for fire messages. If a fire alert is received, it sends a fire alert email.
6. **Blynk Platform Communication**:
    - Sends and receives data to and from the Blynk platform, including new smoke threshold settings and smoke value data. Also manages reminder settings and sends reminder emails accordingly.

### Arduino Workflow

1. **Initialization**:
    - The Arduino components are initialized and the Smartbin is set to the idle state.
2. **Loop**:
    - The main loop runs continuously, measuring distance for bin capacity and smoke values for fire detection.
3. **State Management**:
    - The state machine manages various states including detecting human presence, bin open/close, and fire detection.
    - When the bin lid is open, it records the time and switches to the appropriate state based on whether a person is detected or not and whether a fire is detected.
4. **Fire Detection**:
    - If a fire is detected, the Arduino activates a buzzer and sends a fire alert to the ESP32.
    - If gas is not detected and it's a false alarm, it sends a fire cleared message to the ESP32.
5. **Communication with ESP32**:
    - Uses UART communication to send smoke values to the ESP32 and to receive new smoke threshold values.

### General Operation

- The ESP32 is responsible for network communication, user interaction through Blynk, and sending out email notifications.
- The Arduino handles real-time sensing for bin capacity and smoke detection, as well as immediate local responses like activating a buzzer in case of fire.
- The two devices communicate through UART, allowing for real-time data exchange and coordinated actions.
- The Blynk platform serves as the user interface, allowing for remote monitoring and control, as well as user notifications through emails for events like the bin being full or a fire detected.

This system architecture allows for a separation of concerns, with the ESP32 handling connectivity and user interaction, while the Arduino focuses on real-time sensing and local actuation.
