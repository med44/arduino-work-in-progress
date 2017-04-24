// **** INCLUDES *****
#include "LowPower.h"
#include <DS3232RTC.h>        //http://github.com/JChristensen/DS3232RTC
#include <Streaming.h>        //http://arduiniana.org/libraries/streaming/
#include <Time.h>             //http://playground.arduino.cc/Code/Time
#include <TimeLib.h>
#include <Wire.h>             //http://arduino.cc/en/Reference/Wire

int counter; //used to count seconds while awake
int lap; //used to count times the loop routine has been called

#define SQW_PIN 2             //Connect SQW from the DS323 to pin 2

void wakeUp()
{
    // Just a handler for the pin interrupt.
}

void setup()
{
    Serial.begin(115200);

    //setSyncProvider() causes the Time library to synchronize with the
    //external RTC by calling RTC.get() every five minutes by default.
    setSyncProvider(RTC.get);
    Serial << "RTC Sync";
    if (timeStatus() != timeSet){
        Serial << " FAIL!";
    }
    Serial << endl;

    printDateTime( RTC.get() );
    Serial << " --> Current RTC time." << endl;

    //Disable the default square wave of the SQW pin.
    RTC.squareWave(SQWAVE_NONE);

    //Attach an interrupt on the falling of the SQW pin.
    //digitalWrite(SQW_PIN, HIGH);    //redundant with the following line
    pinMode(SQW_PIN, INPUT_PULLUP);
    attachInterrupt(INT0, alarmIsr, FALLING);

    //Set an alarm at every 1st second of every minute.
    RTC.setAlarm(ALM1_MATCH_SECONDS, 0, 0, 0, 1);    //daydate parameter should be between 1 and 7
    RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
    RTC.alarmInterrupt(ALARM_1, true);

    //Set an alarm every minute.
//    RTC.setAlarm(ALM2_EVERY_MINUTE, 0, 0, 0, 1);    //daydate parameter should be between 1 and 7
//    RTC.alarm(ALARM_2);                   //ensure RTC interrupt flag is cleared
//    RTC.alarmInterrupt(ALARM_2, true);

    //Set a daily alarm.
    RTC.setAlarm(ALM2_MATCH_HOURS, 0, 18, 17, 1);    //daydate parameter should be between 1 and 7
    RTC.alarm(ALARM_2);                   //ensure RTC interrupt flag is cleared
    RTC.alarmInterrupt(ALARM_2, true);

   sleep();


}

volatile boolean alarmIsrWasCalled = false;

void alarmIsr()
{
    alarmIsrWasCalled = true;
}

void loop()
{   
   alarmState();

   //While awake, let's switch to ALARM_1 to wake the arduino for sensing every X minutes
   RTC.alarmInterrupt(ALARM_1, true);
   RTC.alarmInterrupt(ALARM_2, false);

  

   Serial.println(counter++);
   delay(1000);

    if (counter == 10){
      lap++;
      Serial << "Lap: " << lap << ' ';
      counter = 0;
      sleep();
    }
      
}

void printDateTime(time_t t)
{
    Serial << ((day(t)<10) ? "0" : "") << _DEC(day(t)) << ' ';
    Serial << monthShortStr(month(t)) << " " << _DEC(year(t)) << ' ';
    Serial << ((hour(t)<10) ? "0" : "") << _DEC(hour(t)) << ':';
    Serial << ((minute(t)<10) ? "0" : "") << _DEC(minute(t)) << ':';
    Serial << ((second(t)<10) ? "0" : "") << _DEC(second(t));
}

void alarmState() {
  
if (alarmIsrWasCalled){
        if (RTC.alarm(ALARM_1)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 1!" << endl;
        }
        if (RTC.alarm(ALARM_2)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 2!" << endl;
        }
        alarmIsrWasCalled = false;
    }
}


