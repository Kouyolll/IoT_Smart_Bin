
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
#define AUTHOR_PASSWORD "kklt wvdk zfzc qaup"

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