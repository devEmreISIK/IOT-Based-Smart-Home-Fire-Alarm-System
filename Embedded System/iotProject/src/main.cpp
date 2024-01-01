#include <Arduino.h>
#include <WiFi.h>
#include<Firebase_ESP_Client.h>
#include "DHT.h"

#define DHTPIN 25
#define DHTTYPE DHT22

#define MQPIN 32
#define PWMPIN 18

#define WIFI_SSID "SSID" 
#define WIFI_PASSWORD "PASSWORD" 

#define API_KEY "ENTER YOUR API KEY"
#define DATABASE_URL "ENTER YOUR FIREBASE DATA URL"

DHT dht(DHTPIN, DHTTYPE);

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
bool signupOK = false;

bool fan1MA = false;
String tSt;
String gSt;
float t;
int gasValue;

int fanSpeed = 0;
int fanPercent;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  if(Firebase.signUp(&config, &auth, "", "")){
    Serial.println("OK");
    signupOK = true;
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = TokenStatusCallback();

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  pinMode(MQPIN, INPUT);
  pinMode(PWMPIN, OUTPUT);
  dht.begin();

}


void loop() {
  
  // READING TEMPERATURE
  delay(2000);
  t = dht.readTemperature();
  tSt = String(t);
/*   if(isnan(t)){
    Serial.println("Failed to read from DHT sensor.");
    return;
  } */
  Serial.println("Temparature: " + tSt);


  // READING GAS
  gasValue = analogRead(MQPIN);
  gSt = String(gasValue);
  Serial.println("MQ Sensor Value: " + gSt);

  // FAN PERCENT ARRANGEMENT
  if(fan1MA == false){
    fanSpeed = 0;
    analogWrite(PWMPIN, fanSpeed);
    delay(100);
    digitalWrite(PWMPIN, LOW);
    if(t>30 || gasValue>1050) {
      fanSpeed=255;
      analogWrite(PWMPIN, fanSpeed);
      delay(100);
      digitalWrite(PWMPIN, HIGH);
      Serial.println("MAX");
    }else if(t>=24 && t<=30 && gasValue<1050) {
      fanSpeed = map(t, 24, 30, 125, 255);
      analogWrite(PWMPIN, fanSpeed);
    }else if(t<24 && gasValue<1050){
      fanSpeed=0;
      analogWrite(PWMPIN, fanSpeed);
      delay(100);
      digitalWrite(PWMPIN, LOW);
      Serial.println("CLOSED");
    }
    fanPercent = map(fanSpeed, 0, 255, 0, 100);
  }else if(fan1MA == true){
    analogWrite(PWMPIN, fanSpeed);
  }

  Serial.println("PWM Value: " + String(fanSpeed));


  // SENDING AND GETTING DATA (TO FIREBASE)
  if(Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 6200 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();

    if(Firebase.RTDB.setString(&fbdo, "gasppm1", gSt)){
      Serial.print("PASSED    ");
      Serial.print("PATH: " + fbdo.dataPath());
      Serial.println("      TYPE: " + fbdo.dataType());
    } else {
      Serial.println("FAILED!!");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    if(Firebase.RTDB.setString(&fbdo, "temperature1", tSt)){
      Serial.print("PASSED    ");
      Serial.print("PATH: " + fbdo.dataPath());
      Serial.println("      TYPE: " + fbdo.dataType());
    } else {
      Serial.println("FAILED!!");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    

    if(Firebase.RTDB.getBool(&fbdo, "fan1MA")) {
    if(fbdo.dataType() == "boolean") {
      fan1MA = fbdo.boolData();
      Serial.println("Successful Read From " + fbdo.dataPath() + ": " + fan1MA + " (" + fbdo.dataType() + ") ");
    } else {
      Serial.println("FAILED: " + fbdo.errorReason());
      }
    }


    if (fan1MA == false)
    {
      if(Firebase.RTDB.setString(&fbdo, "fanspeed1", String(fanPercent))){
      Serial.print("PASSED    ");
      Serial.print("PATH: " + fbdo.dataPath());
      Serial.println("      TYPE: " + fbdo.dataType());
    } else {
      Serial.println("FAILED!!");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    }

    if(fan1MA == true){
      if(Firebase.RTDB.getString(&fbdo, "fanspeed1")) {
      fanPercent = fbdo.to<int>();
      fanSpeed = map(fanPercent, 0, 100, 0, 255);
      Serial.println("Successful Read From " + fbdo.dataPath() + ": " + fanPercent + " (" + fbdo.dataType() + ") ");
    } else {
      Serial.println("FAILED: " + fbdo.errorReason());
      }
    }
    


    }
}


