#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "FirebaseESP32.h"
//#include <ESP8266WiFi.h>
#include <Ticker.h>
#include "RTClib.h" 

//CARACTERES PERSONALIZADOS PARA DISPLAY LCD
byte charClock[8]   = {B00000,B00000,B01110,B10101,B10111,B10001,B01110,B00000}; //Caracter de Reloj
byte charGrados[8]  = {B01110, B01010, B01110, B00000, B00000, B00000, B00000, B00000 };
byte weed1[8] = {B00000,B00000,B00000,B10000,B11000,B11100,B01110,B01111,};
byte weed2[8] = {B00100,B01110,B01110,B11111,B11111,B11111,B11111,B01110,};
byte weed3[8] = {B00000,B00000,B00000,B00001,B00011,B00111,B01110,B11110,};
byte weed4[8] = {B00111,B00011,B11101,B01111,B00011,B00111,B01110,B00000,};
byte weed5[8] = {B11111,B11111,B11111,B11111,B10101,B00100,B00100,B00100,};
byte weed6[8] = {B11100,B11000,B10111,B11110,B11000,B11100,B01110,B00000,};
byte grados[8] = {B01110, B01010, B01110, B00000, B00000, B00000, B00000, B00000 };

#define FIREBASE_HOST "ejemploesp8266-533d5-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "sy1Ldul8ayYSW8NBNoLqutnmMcYTAsJr8ZlUXO9G"
#define WIFI_SSID "WIFI-GUERRERO"  //"CCM8200_4BA14B"  //   ALFA05....
#define WIFI_PASSWORD "daniel1085" //"L4CM434B"  //    ana30ma72

#define DATI 1
#define TICO 2
#define CORE 3
#define REEX 4
#define EXDA 5

#define TEMPO1   1 // LIGHTING1
#define TEMPO2   2 // LIGHTING2
#define TEMPO3   3  //INTRACTOR
#define TEMPO4   4  //EXTRACTOR

#define T1T2 1
#define T2T3 2
#define T3T4 3
#define T4EX 4
#define EXT1 5

#define R1R2 1
#define R2R3 2
#define R3R4 3
#define R4EX 4
#define EXR1 5

#define FECHA 1
#define HORA  2

#define HOFE 1
#define FEEX 2
#define EXHO 3

#define MANUAL 1
#define AUTOMATIC 2

#define DELAYMESAGGE 500
#define DELAYENCODER 300   //Delay antirrebote

#define RELE1 12
#define RELE2 13
#define RELE3 14
#define RELE4 27

String path = "/usuarios/OUucn52plrRjra0Vwi5BFf3IQcQ2";
String MSG_SETINGS = "";

FirebaseData firebaseData;
Ticker ticWifiLed;
Ticker ticDhtBand;
bool bandDht=false;

byte count_intent = 0;
byte max_intent = 50;

long int rotValue=0, btnValue=0, preValue=0;
uint8_t encoderState=0;

unsigned long t_LuzFondo=0;
bool bandLuz=false;

#define PINA 4	//DT			
#define PINB 5  //clk
#define PINBTN 18  //sw
#define PINLEDWIFI 2

#define BTN_INACTIVE  0   //STATE en el que no se presiono ningun boton
#define BTN_RIGHT     1 
#define BTN_LEFT      2
#define BTN_PUSH      3

#define S_HOME            1
#define S_LIST_SETTINGS   2
#define S_LIST_TIMERS     3

#define DATE      1
#define TIMERS    2
#define CONTROL   3
#define REGISTER  4
#define EXIT      9


//INICIALIZACION DE ESTADOS
  byte STATE = S_HOME;
  byte STATECONFIG = DATE;
  byte STATEDATE = HORA;
  byte STATETIMERS = TEMPO1;
  byte STATEMODE = MANUAL;
  byte STATEMANUAL = RELE1;
//  uint8_t STATETIMERS = LIGHTING1;
//  uint8_t STATECONTROL = TEMP;

portMUX_TYPE gpioMux = portMUX_INITIALIZER_UNLOCKED;

LiquidCrystal_I2C lcd(0x27,16,2);
RTC_DS3231 rtc;

void IRAM_ATTR isrEncoder(void);
byte readEncoder (void);
void connectionWifi(void);
void ConnectionFirebase(void);
void ledBlinkWifi(void);
//void showParameters(void);
void printResult(FirebaseData &data);
void CausaError(void);
void InforSetLuzSensor(void);
void InforGetLuzSensor(void);
void showDhtFirebase(void);
void readDhtBand(void);
void showTemperature(byte,byte);
void showHumidity(byte,byte);
void showH(byte,byte);
void showClock(byte,byte);
byte listConfigurations(void);
void showOptionsConfig(byte);
void cursorPosition(bool);
byte listDate(void);
void showOptionsDate(byte);
void hourSettings(void);
void print2digits(byte);
void showOptionsTimers(byte);
byte operationMode(void);
void welcome(void);
void timersSettings (byte);
void WateringSettings(void);
void timedWaterning(void);
void timedActuators(byte);
void dateSettings(void);

//void IRAM_ATTR isrBtnEncoder(void);

byte options = DATI;
bool flagCursor=false;  //Dermina la pocicion del Cursor FALSE=ARRIBA,TRUE=ABAJO
bool newflagCursor=false;


void connectionFirebase(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

    //Establezca el tiempo de espera de lectura de la base de datos en 1 minuto (máximo 15 minutos)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  
  //Tamaño y  tiempo de espera de escritura, tiny (1s), small (10s), medium (30s) and large (60s).
  //tiny, small, medium, large and unlimited.
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}

void connectionWifi(){
  ticWifiLed.attach(0.2,ledBlinkWifi);
  Serial.println();
  Serial.println("::::::: Conexion a red WiFi Local :::::::::");
  WiFi.begin(WIFI_SSID , WIFI_PASSWORD);  //"ALFA05" , "ana30ma72"    "Android_xiaomi" , "anamaria123"  "miLaptopAsus" , "samakistan"
  Serial.print("Conectando...");
  while(WiFi.status() != WL_CONNECTED and count_intent<max_intent){
    count_intent++;
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  if(count_intent<max_intent){
      Serial.println ( " ****************************************** " );
      Serial.print ( " Conectado a la red WiFi: " );
      Serial.println (WiFi. SSID ());
      Serial.print ( " IP: " );
      Serial.println (WiFi. localIP ());
      Serial.print ( " macAdress: " );
      Serial.println (WiFi. macAddress ());
      Serial.println ( " ******************************************* " ) ;
      digitalWrite(PINLEDWIFI,HIGH);
  } else {
      Serial.println ( " ------------------------------------ " );
      Serial.println ( " Error de conexión " );
      Serial.println ( " ------------------------------------ " );
      digitalWrite(PINLEDWIFI,LOW);
  }
  ticWifiLed.detach();
}



  
