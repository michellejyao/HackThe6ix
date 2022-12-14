#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information
#include <SoftwareSerial.h>

int numRuns = 1;   // Execution count, so this doesn't run forever
int maxRuns = 5;   // Maximum number of times the Choreo should be executed
int trigPin = 2;
int echoPin = 4;
long duration, cm, inches;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // For debugging, wait until the serial console is connected
  delay(5000);
  Bridge.begin();
  Serial.println("Patrol Mode Initiated...");
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  inches = (duration / 2) / 74;
  Serial.println(".....");
  if (inches < 20 || inches > 500) {
  Serial.println("Intruder Detected!");
  Serial.println("Sending text Notification...");

  if (numRuns <= maxRuns) {
    Serial.println("Running SendSMS - Run #" + String(numRuns++));
    
    TembooChoreo SendSMSChoreo;

    // Invoke the Temboo client
    SendSMSChoreo.begin();

    // Set Temboo account credentials
    SendSMSChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // Set Choreo inputs
    SendSMSChoreo.addInput("AuthToken", "*******************************"); //  AUTH TOKEN 
    SendSMSChoreo.addInput("To", "+1**********"); // cell number that your want the text to go to 
    SendSMSChoreo.addInput("From", "+1**********"); // Twilio phone number 
    SendSMSChoreo.addInput("Body", "Intruder Detected!!!!!!"); // Message
    SendSMSChoreo.addInput("AccountSID", "*********************************"); // Account SID
    
    // Identify the Choreo to run
    SendSMSChoreo.setChoreo("/Library/Twilio/SMSMessages/SendSMS");
    
    // Run the Choreo; when results are available, print them to serial
    SendSMSChoreo.run();
    
    while(SendSMSChoreo.available()) {
      char c = SendSMSChoreo.read();
      Serial.print(c);
    }
    SendSMSChoreo.close();
  }

  Serial.println("Waiting...");
  delay(10000); // wait 10 seconds between SendSMS calls
  
  Serial.println("Patrol Mode Initiated...");
  
  }//end if statement 
  
}//ends loop
