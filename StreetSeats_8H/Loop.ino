
volatile boolean alarmIsrWasCalled = false;

void alarmIsr()
{
    alarmIsrWasCalled = true;
}

void loop()
{   
   alarmState();
  

   Serial.println(counter++);
   delay(1000);

    if (counter == 5){
      lap++;
      alarmCycle++;  //we use this counter to determine the next alarm setting (e.g. every 10 seconds or every 10 minutes)
                     //to quickly debug we use ALM1_MATCH_SECONDS and  10 second increments
                     //to check every 10 minutes, use ALM1_MATCH_MINUTES and 10 minute increments instead like so:
                     //RTC.setAlarm(ALM1_MATCH_MINUTES, 0, x, 0, 1) -- where on each hour x is minute 10, 20, 30...and so forth
                         
      Serial << "Lap: " << lap << ' ' << "alarmCycle: "  << alarmCycle << ' ';

        if (alarmCycle == 0){
        //RTC.setAlarm(ALM1_MATCH_SECONDS, 10, 0, 0, 1);    //daydate parameter should be between 1 and 7
        RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 10,0,1); 
       
        //Serial.println("Next alarm: 10 secs");
        Serial.println("Next alarm: 10 min mark");
        //delay (minutes); 
        
        }
    
        if (alarmCycle == 1){ 
        //RTC.setAlarm(ALM1_MATCH_SECONDS, 20, 0, 0, 1);
        RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 47,0,1);
        
        //Serial.println("Next alarm: 20 secs");
        Serial.println("Next alarm: 20 min mark");
        //delay (minutes);
        }
    
        if (alarmCycle == 2){
        //RTC.setAlarm(ALM1_MATCH_SECONDS, 30, 0, 0, 1);
        RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 48,0,1);
        //Serial.println("Next alarm: 30 secs");
        Serial.println("Next alarm: 30 min mark");
        //delay (minutes);
        }
    
        if (alarmCycle == 3){
        //RTC.setAlarm(ALM1_MATCH_SECONDS, 40, 0, 0, 1);
        RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 49,0,1);
        //Serial.println("Next alarm: 40 secs");
         Serial.println("Next alarm: 40 min mark");
         //delay (minutes);
        }
    
        if (alarmCycle == 4){
        //RTC.setAlarm(ALM1_MATCH_SECONDS, 50, 0, 0, 1);
        RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 50, 0, 1);
        //Serial.println("Next alarm: 50 secs");
         Serial.println("Next alarm: 50 min mark");
         //delay (minutes);
        }
    
        if (alarmCycle == 5){
        //RTC.setAlarm(ALM1_MATCH_SECONDS, 0, 0, 0, 1);
         RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 0,0,1);
        //Serial.println("Next alarm: 0 secs");
         Serial.println("Next alarm: 0 min mark");
        alarmCycle = -1;
        //delay (minutes); 
        } 

      
      counter = 0;
      lighTest(); 
      delay (frequency);
      sleep();
    }

//    if (lap == 3){
//      //After a number of loop statements (laps), switch to a daily alarm to wake up the arduino on a different schedule (e.g. every day at 3 pm).
//      RTC.setAlarm(ALM1_MATCH_HOURS, 0, 51, 12, 1);    //(SS, MM, HH, 1) daydate parameter should be between 1 and 7
//      RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
//      RTC.alarmInterrupt(ALARM_1, true); 
//      alarmCycle = -1;    //reset the counter uses to cycle through periodic checks while awake
//      lap = 0;            //reset the counter for number of loops
//      Serial.println("Changed to a daily alarm");
//      delay(200);
//      //sleep();
//
//    }
      
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


