void lighTest(){
  //paste your light sensr loop code here

  /* Get a new sensor event */ 
  sensors_event_t event;
  tsl.getEvent(&event);

  Serial.print(event.light);
  Serial.print("\t");

  if (lightReading == 3){
    lightReading = 0;
  }

  Serial.print(lightReading);
  Serial.print("\t");

  lightVals[lightReading] = event.light;


    for(int i = 0; i < 3; i++)
{
  Serial.print(lightVals[i]);
  Serial.print(", ");
}

  if (lightReading > 2) {
    lightReading = -1;
  }

//a bit of math...
lightTotal = lightVals[0] + lightVals[1] + lightVals[2]; //add the 3 light values...
lightAvg = lightTotal / 3; // divide them by 3
Serial.print(" Avg: ");
Serial.print(lightAvg);
Serial.print(" "); 

 
  /* Display the results (light is measured in lux) */
  if (lightAvg < darkVal) // NIGHT TIME: replace with average values from your array 
  {
    nightCounter++;
    Serial.print("Nighttime below: "); 
    Serial.print(darkVal);
    Serial.print(" ");
    Serial.print("nightCounter: "); //we're keeping a count of the loops to turn lights off after a while
    Serial.print(nightCounter);
    Serial.print(" ");

    unsetRelays();
    Serial.println ("Light avg is below dark value"); 

    //

//    if (nightCounter == 1,3,5) {
//    solarGrace();
  }

///  else {
// /   unsetRelays();
///  }
    //if (nightCounter == 1) {
      //unsetRelays();
  //}

//  if (nightCounter == 2) {
//    unsetRelays();
//  }
//
//  if (nightCounter ==3) {
//    solarGrace();
//   
//  }
//
//  if (nightCounter == 4) {
//    unsetRelays ();
//  }
//
//  if (nightCounter == 5) {
//     unsetRelays();
//  }
  

    if (nightCounter >= nightCountMax){ //check if it's time to turn lights off

      setRelays();
      Serial.println ("Night counter reached max. All Relays Off");
       //if (lap == 7){
      //After a number of loop statements (laps), switch to a daily alarm to wake up the arduino on a different schedule (e.g. every day at 3 pm).
      RTC.setAlarm(ALM1_MATCH_HOURS, 0, 43, 3, 1);    //(SS, MM, HH, 1) daydate parameter should be between 1 and 7
      RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
      RTC.alarmInterrupt(ALARM_1, true); 
      alarmCycle = -1;    //reset the counter uses to cycle through periodic checks while awake
      lap = 0;            //reset the counter for number of loops
      Serial.println("Changed to a daily alarm - ALARM_1B RESET");
      delay(200);
      nightCounter = 0;
      sleep();
    
    
  }
  else
  {
    /* If event.light = 0 lux the sensor is probably saturated
       and no reliable data could be generated! */
    //Serial.println("Sensor overload");
//set alarm 1B & sleep...
     //setRelays();
     //nightCounter = 0; //resets the counter when it's bright again
     
  //set alarm 1B & sleep...
  
  }

  lightReading++;
//  delay(lighCheckTime);

}


