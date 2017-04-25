#include <EasyTransfer.h>
#include <SoftwareSerial.h>
#include "TinyGPS++.h"
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

TinyGPSPlus gps;

SoftwareSerial g(2, 3);
//for detecting distance using 5 different ultrasonic sensors 
//left sensor
const int TRIG_PIN1= 11; //green wire
const int ECHO_PIN1= 12; //blue wire

// mid sensor
const int TRIG_PIN2= 8; //green wire
const int ECHO_PIN2= 13; //blue wire

//right sensor
const int TRIG_PIN3= 6; //green wire
const int ECHO_PIN3= 7; //blue wire


  unsigned long t1a;
  unsigned long t1b;

  unsigned long t2a;
  unsigned long t2b;

  unsigned long t3a;
  unsigned long t3b;



  unsigned long p_w1;
  unsigned long p_w2;
  unsigned long p_w3;
  
 float inches1;
 
  float inches2;
 
  float inches3;
  
 float obs_N;
  float obs_NE;
  float obs_NW;

const unsigned int MAX_DIST = 23200;
EasyTransfer tx; 


struct SEND_DATA_STRUCTURE{
  float latitude;
  float longitude;

  // obstacle sensors distance readings in cm
  float obs_N;
  float obs_NE;
  float obs_NW;
};

SEND_DATA_STRUCTURE loc;

void setup() {
   pinMode(TRIG_PIN1, OUTPUT);
  digitalWrite(TRIG_PIN1, LOW);

  pinMode(TRIG_PIN2, OUTPUT);
  digitalWrite(TRIG_PIN2, LOW);

  pinMode(TRIG_PIN3, OUTPUT);
  digitalWrite(TRIG_PIN3, LOW);
  MCUCR = _BV (BODS) | _BV (BODSE);
  MCUCR = _BV (BODS); 
  Serial.begin(9600);
  
  g.begin(9600);
  tx.begin(details(loc), &Serial);
}

void loop() {
//  GPStrans();
  sensortrans();
}

void GPStrans()
{
  while (g.available() > 0) {
    gps.encode(g.read());
  }
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  if (gps.location.isValid()){
    loc.latitude = gps.location.lat();
    loc.longitude = gps.location.lng();
    digitalWrite(4, HIGH);
    if (gps.location.age() < 2000) {
      //if (!tx.sendData()){
      //  
      //}
      tx.sendData();
    }
  }
  delay(50);
  digitalWrite(4, LOW);
}

void sensortrans()
{
   digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);

  while ( digitalRead(ECHO_PIN1) == 0 );
  t1a = micros();
  while ( digitalRead(ECHO_PIN1) == 1);
  t1b = micros();
  p_w1 = t1b - t1a;

  obs_N = p_w1 / 58.0;
  inches1 = p_w1 / 148.0;

  
  Serial.print("N \t");
  if ( p_w1 > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(obs_N);
    Serial.print(" cm \t");
    Serial.print(inches1);
    Serial.println(" in");
  }

  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  while ( digitalRead(ECHO_PIN2) == 0 );
  t2a = micros();
  while ( digitalRead(ECHO_PIN2) == 1);
  t2b = micros();
  p_w2 = t2b - t2a;

  obs_NE = p_w2 / 58.0;
  inches2 = p_w2 / 148.0;

  Serial.print("NE \t");
  if ( p_w2 > MAX_DIST ) {
    Serial.println("Out of range");
  } 
  else {
    Serial.print(obs_NE);
    Serial.print(" cm \t");
    Serial.print(inches2);
    Serial.println(" in");
  }

  digitalWrite(TRIG_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);

  while ( digitalRead(ECHO_PIN3) == 0 );
  t3a = micros();
  while ( digitalRead(ECHO_PIN3) == 1);
  t3b = micros();
  p_w3 = t3b - t3a;


  obs_NW = p_w3 / 58.0;
  inches3 = p_w3 / 148.0;

  Serial.print("NW \t");
  if ( p_w3 > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(obs_NW);
    Serial.print(" cm \t");
    Serial.print(inches3);
    Serial.println(" in");
  }

   Serial.println(" ");
    delay(600);


if (p_w1&&p_w2&&p_w3 < MAX_DIST) {
loc.obs_N = obs_N;
loc.obs_NE = obs_NE;
loc.obs_NW = obs_NW;
tx.sendData();
digitalWrite(5,HIGH);
}
else{
  digitalWrite(5,LOW);
}
delay(50);
digitalWrite(5,LOW);
}
   
