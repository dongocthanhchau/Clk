int gAlarm;
unsigned long vTime;

void setAlarm(uint8_t data)
{   
  if (data==0) gAlarm=0;
  if (gAlarm==0)
  {
      vTime=0;
        if (data==1) gAlarm=1;
          else if (data==2) gAlarm=-4;
  }
}
void outputAlarm()
{
  Serial.println(gAlarm);
  if (gAlarm==0) return;
  
  if (gAlarm>0)
    {
      if ( (vTime==0) || ((millis()-vTime)>=TIMER) )
          {
              
              if ((gAlarm++ % 16)>=8) digitalWrite(SPEAKER_PIN,0);
              else
              digitalWrite(SPEAKER_PIN,!digitalRead(SPEAKER_PIN));
              vTime=millis();
          }
      
    }
  else
    {
      if ( (vTime==0) || ((millis()-vTime)>=PERIOD) )
          {
              digitalWrite(SPEAKER_PIN,!digitalRead(SPEAKER_PIN));
              vTime=millis();
              gAlarm++;
              
          }
    }
}

