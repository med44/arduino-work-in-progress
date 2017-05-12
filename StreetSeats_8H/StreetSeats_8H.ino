
//SleepMode Library
//#include <LowPower.h>

//RTC Breakout Precision Timer Library
//#include "RTClib.h"

//RTC Timer Libraries 
#include "LowPower.h"
#include <DS3232RTC.h>        //http://github.com/JChristensen/DS3232RTC
#include <Streaming.h>        //http://arduiniana.org/libraries/streaming/
#include <Time.h>             //http://playground.arduino.cc/Code/Time
#include <TimeLib.h>
#include <Wire.h> 
    

//Lux Sensor Library
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>


//Area A Lighting 
#define setRelay1 13 //(solid green)
#define unsetRelay1 12 //(spotted green)

//Area B Lighting
#define setRelay2 11 //(solid green)
#define unsetRelay2 10 //(spotted green)

//Area C Lighting
#define setRelay3 9 //(solid green)
#define unsetRelay3 8 //(spotted green)

//Area D Lighting
#define setRelay4 7
#define unsetRelay4 6

//Area E Lighting 
#define setRelay5 5
#define unsetRelay5 4

//****RTC Additions...Timer Pin Definition 
#define SQW_PIN 2       


//additions, trying to get 10 minutes
//unsigned long seconds = 1000L;
//unsigned long minutes = seconds * 60;

int counter; //used to count seconds while awake
int lap; //used to count times the loop routine has been called
int alarmCycle = -1; 
//****END of RTC Additions...

int frequency = 1000; //for relay tests
int lighCheckTime = 30000; //how often we check light sensor. 10 minutes will be 600000 milliseconds
int lightVals[3]; //an array to store light readings (3 of them)
int lightReading = 0; //an index we use to cound numbers of readings in our lightTest loop
int lightTotal;
int lightAvg;
int darkVal = 80; //this is our night threshold value in lux
int nightCounter = 0; //this may be used to track how long the lights should be on
int nightCountMax = 3;//340 for 3 hours; // 18 times 10 minutes will be about 3 hours (10 miuntes / 60 = 6 light tests per hour)
boolean night = false; // it's night (true) or not (false) *** do i still need this? 


///*** Jeana's Light Sensor VARIABLE Additions BEGIN *///////

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void displaySensorDetails(void)
{
  sensor_t sensor;
  tsl.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void configureSensor(void)
{
  /* You can also manually set the gain or enable auto-gain support */
  // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
  // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
  tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */

  /* Update these values depending on what you've set above! */  
  Serial.println("------------------------------------");
  Serial.print  ("Gain:         "); Serial.println("Auto");
  Serial.print  ("Timing:       "); Serial.println("13 ms");
  Serial.println("------------------------------------");
}


///*** Jeana's Light Sensor Additions END *///////

void wakeUp()
{
    // Just a handler for the pin interrupt.
}


void setup() {

///*** Jeana's Setup RTC Sensor Additions BEGIN *///////
{
    Serial.begin(115200);
    Serial.println("Street Seats Beta 1.0 Initializing");

    //setSyncProvider() causes the Time library to synchronize with the
    //external RTC by calling RTC.get() every five minutes by default.
    setSyncProvider(RTC.get);
    Serial << "RTC Sync";
    if (timeStatus() != timeSet){
        Serial << " FAIL!";
    }
    Serial << endl;

    printDateTime ( RTC.get() );
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

//    RTC.setAlarm (ALM1_MATCH_HOURS, 0, 54, 3, 1); 
//    RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
//    RTC.alarmInterrupt(ALARM_1, true);
//    Serial.println ("Set initial daily alarm in Setup"); 

//    RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 10, 0, 1);    //daydate parameter should be between 1 and 7
//    RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
//    RTC.alarmInterrupt(ALARM_1, true);
    

    //Set an alarm every 10 minutes.
//    RTC.setAlarm(ALM2_EVERY_MINUTE, 0, 10, 0, 1);    //daydate parameter should be between 1 and 7
//    RTC.alarm(ALARM_2);                   //ensure RTC interrupt flag is cleared
//    RTC.alarmInterrupt(ALARM_2, true);

    //Set a daily alarm.
//    RTC.setAlarm(ALM2_MATCH_HOURS, 0, 49, 21, 1);    //daydate parameter should be between 1 and 7
//    RTC.alarm(ALARM_2);                   //ensure RTC interrupt flag is cleared
//    RTC.alarmInterrupt(ALARM_2, true);

      RTC.alarmInterrupt(ALARM_2,false);

//   sleep();
//   Serial.println ("Setup sending it to sleep loop >>");

  //Serial.println("Street Seats Beta is sleeping...zzz");

}

//RTC END----

  
  // put your setup code here, to run once:
pinMode (setRelay1, OUTPUT);
pinMode (unsetRelay1, OUTPUT);
pinMode (setRelay2, OUTPUT);
pinMode (unsetRelay2, OUTPUT);
pinMode (setRelay3, OUTPUT);
pinMode (unsetRelay3, OUTPUT);
pinMode (setRelay4, OUTPUT);
pinMode (unsetRelay4, OUTPUT);
pinMode (setRelay5, OUTPUT);
pinMode (unsetRelay5, OUTPUT);





////These will turn Relay1 lights OFF

//unsetRelays(); 
setRelays();
Serial.println ("All Relays are turned off"); 

///*Jeana's Set UP Additions*////
  Serial.println("Light Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!tsl.begin())
  {
    /* There was a problem detecting the TSL2561 ... check your connections */
    Serial.print("Ooops, no TSL2561 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
  
  /* Setup the sensor gain and integration time */
  configureSensor();
  
  /* We're ready to go! */
  Serial.println("");


///*End of SET UP Additions*//

Serial.println("============================");

delay(1000);
}

