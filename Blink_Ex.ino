#include "led7_595.h"
#include "speaker.h"

int alarm[2]={1,40};

//uint8_t gLED[11]={0x05,0x7D,0x46,0x54,0x3C,0x94,0x84,0x5D,0x04,0x14,0xFF};

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(DATACLOCK_PIN, OUTPUT);
  pinMode(STORAGECLOCK_PIN,OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  setAlarm(2);
}


unsigned long gTime=0;
int i=0;
// the loop function runs over and over again forever
void loop() {
  if ( (millis()-gTime)>=1000 ) {i++;gTime=millis();}
  //dataSend(8);
  //dataLatch(0x00);
  ledDisplay(i,2*i);
  
  outputAlarm();

  if ( ( (i%10)==alarm[0]) ) setAlarm(2);
  
}
