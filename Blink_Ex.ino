#include "led7_595.h"
#include "speaker.h"

int alarm[2]={1,40}; // Test Code 


void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(DATACLOCK_PIN, OUTPUT);
  pinMode(STORAGECLOCK_PIN,OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  setAlarm(2);
}


unsigned long gTime=0;
int i=0;
//Create a example 
void loop() {
  if ( (millis()-gTime)>=1000 ) {i++;gTime=millis();}
  //dataSend(8);
  //dataLatch(0x00);
  ledDisplay(i,2*i);
  
  outputAlarm();

  if ( ( (i%10)==alarm[0]) ) setAlarm(2);
  
}
