#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#define SPEAKER_PIN 14

#define TIMER 70
#define PERIOD 400

void setAlarm(uint8_t data);//use to set alarm
// data=1: set Timer Alarm (turn off until setAlarm(0))
// data=2: set period Alarm (turn off after 2 tone)
// data=0: turn off all sound
void outputAlarm(); //use this in loop function

#endif
