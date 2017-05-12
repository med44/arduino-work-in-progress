
void setRelays () {
  digitalWrite (setRelay1, HIGH); 
  digitalWrite (unsetRelay1, LOW);
  digitalWrite (setRelay2, HIGH); 
  digitalWrite (unsetRelay2, LOW);
  digitalWrite (setRelay3, HIGH); 
  digitalWrite (unsetRelay3, LOW);
  digitalWrite (setRelay4, HIGH); 
  digitalWrite (unsetRelay4, LOW);
  digitalWrite (setRelay5, HIGH); 
  digitalWrite (unsetRelay5, LOW);
  Serial.println ("All Relays are OFF");
}

void unsetRelays () {
  digitalWrite (setRelay1, LOW); 
  digitalWrite (unsetRelay1, HIGH);
  digitalWrite (setRelay2, LOW); 
  digitalWrite (unsetRelay2, HIGH);
  digitalWrite (setRelay3, LOW); 
  digitalWrite (unsetRelay3, HIGH);
  digitalWrite (setRelay4, LOW); 
  digitalWrite (unsetRelay4, HIGH);
  digitalWrite (setRelay5, LOW); 
  digitalWrite (unsetRelay5, HIGH);
  Serial.println ("All Relays are ON");
}


//could change this to unsetRelays(); if we want to run
//twinkle once when it turns on... 

//void unsetRelays{
//Serial.println ("Solar Grace Starts");
//  digitalWrite (setRelay5, LOW);//E  
//  digitalWrite (unsetRelay5, HIGH);//E ON 
//  delay (1000);
//  digitalWrite (setRelay4, LOW);//D 
//  digitalWrite (unsetRelay4, HIGH);// D ON
//  delay (1000);
//  digitalWrite (setRelay3, LOW);//C 
//  digitalWrite (unsetRelay3, HIGH);//C ON
//  delay (1000);
//  digitalWrite (setRelay2, LOW); //B 
//  digitalWrite (unsetRelay2, HIGH);//B ON 
//  delay (1000);
//  digitalWrite (setRelay1, LOW); //A 
//  digitalWrite (unsetRelay1, HIGH);//A ON
//  Serial.println ("part 1 complete");
//  delay (2000);
//  digitalWrite (setRelay1, HIGH); //A OFF
//  digitalWrite (unsetRelay1, LOW);//A 
//  delay (1000);
//  digitalWrite (setRelay2, HIGH); //B OFF 
//  digitalWrite (unsetRelay2, LOW);//B 
//  delay (1000);
//  digitalWrite (setRelay3, HIGH);//C OFF
//  digitalWrite (unsetRelay3, LOW);//C 
//  delay (1000);
//  digitalWrite (setRelay4, HIGH);//D OFF
//  digitalWrite (unsetRelay4, LOW);// D 
//  delay (1000);
//  digitalWrite (setRelay5, HIGH);//E OFF  
//  digitalWrite (unsetRelay5, LOW);//E 
//  Serial.println ("Solar Grace Ends");
//  delay (1000);
//
//
////Twinkle 1 Begins 
//  Serial.println ("Twinkle 1 begins"); 
//  digitalWrite (setRelay1, LOW); //A 
//  digitalWrite (unsetRelay1, HIGH);//A ON
//  digitalWrite (setRelay3, LOW);//C 
//  digitalWrite (unsetRelay3, HIGH);//C ON
//  digitalWrite (setRelay5, LOW);//E  
//  digitalWrite (unsetRelay5, HIGH);//E ON 
//  digitalWrite (setRelay2, HIGH); //B OFF 
//  digitalWrite (unsetRelay2, LOW);//B 
//  digitalWrite (setRelay4, HIGH);//D OFF
//  digitalWrite (unsetRelay4, LOW);// D 
//  delay (2000);
//  digitalWrite (setRelay1, HIGH); //A OFF
//  digitalWrite (unsetRelay1, LOW);//A 
//  digitalWrite (setRelay3, HIGH);//C OFF
//  digitalWrite (unsetRelay3, LOW);//C 
//  digitalWrite (setRelay5, HIGH);//E  
//  digitalWrite (unsetRelay5, LOW);//E OFF 
//  digitalWrite (setRelay2, LOW); //B  
//  digitalWrite (unsetRelay2, HIGH);//B ON
//  digitalWrite (setRelay4, LOW);//D 
//  digitalWrite (unsetRelay4, HIGH);// D ON
//  delay (2000); 
//
////Twinkle 2 Begins 
//  Serial.println ("Twinkle 2 begins"); 
//  digitalWrite (setRelay1, LOW); //A 
//  digitalWrite (unsetRelay1, HIGH);//A ON
//  digitalWrite (setRelay3, LOW);//C 
//  digitalWrite (unsetRelay3, HIGH);//C ON
//  digitalWrite (setRelay5, LOW);//E  
//  digitalWrite (unsetRelay5, HIGH);//E ON 
//  digitalWrite (setRelay2, HIGH); //B OFF 
//  digitalWrite (unsetRelay2, LOW);//B 
//  digitalWrite (setRelay4, HIGH);//D OFF
//  digitalWrite (unsetRelay4, LOW);// D 
//  delay (2000);
//  digitalWrite (setRelay1, HIGH); //A OFF
//  digitalWrite (unsetRelay1, LOW);//A 
//  digitalWrite (setRelay3, HIGH);//C OFF
//  digitalWrite (unsetRelay3, LOW);//C 
//  digitalWrite (setRelay5, HIGH);//E  
//  digitalWrite (unsetRelay5, LOW);//E OFF 
//  digitalWrite (setRelay2, LOW); //B  
//  digitalWrite (unsetRelay2, HIGH);//B ON
//  digitalWrite (setRelay4, LOW);//D 
//  digitalWrite (unsetRelay4, HIGH);// D ON
//  delay (2000);
//
//  //Twinkle 3 Begins 
//  Serial.println ("Twinkle 3 begins"); 
//  digitalWrite (setRelay1, LOW); //A 
//  digitalWrite (unsetRelay1, HIGH);//A ON
//  digitalWrite (setRelay3, LOW);//C 
//  digitalWrite (unsetRelay3, HIGH);//C ON
//  digitalWrite (setRelay5, LOW);//E  
//  digitalWrite (unsetRelay5, HIGH);//E ON 
//  digitalWrite (setRelay2, HIGH); //B OFF 
//  digitalWrite (unsetRelay2, LOW);//B 
//  digitalWrite (setRelay4, HIGH);//D OFF
//  digitalWrite (unsetRelay4, LOW);// D 
//  delay (2000);
//  digitalWrite (setRelay1, HIGH); //A OFF
//  digitalWrite (unsetRelay1, LOW);//A 
//  digitalWrite (setRelay3, HIGH);//C OFF
//  digitalWrite (unsetRelay3, LOW);//C 
//  digitalWrite (setRelay5, HIGH);//E  
//  digitalWrite (unsetRelay5, LOW);//E OFF 
//  digitalWrite (setRelay2, LOW); //B  
//  digitalWrite (unsetRelay2, HIGH);//B ON
//  digitalWrite (setRelay4, LOW);//D 
//  digitalWrite (unsetRelay4, HIGH);// D ON
//  delay (2000);

//Twinkle 4 Begins 
// Serial.println ("Twinkle 4 Begins"); 
//  digitalWrite (setRelay1, LOW); //A 
//  digitalWrite (unsetRelay1, HIGH);//A ON
//  digitalWrite (setRelay3, LOW);//C 
//  digitalWrite (unsetRelay3, HIGH);//C ON
//  digitalWrite (setRelay5, LOW);//E  
//  digitalWrite (unsetRelay5, HIGH);//E ON 
//  digitalWrite (setRelay2, HIGH); //B OFF 
//  digitalWrite (unsetRelay2, LOW);//B 
//  digitalWrite (setRelay4, HIGH);//D OFF
//  digitalWrite (unsetRelay4, LOW);// D 
//  delay (1000);
//  digitalWrite (setRelay1, HIGH); //A OFF
//  digitalWrite (unsetRelay1, LOW);//A 
//  digitalWrite (setRelay3, HIGH);//C OFF
//  digitalWrite (unsetRelay3, LOW);//C 
//  digitalWrite (setRelay5, HIGH);//E  
//  digitalWrite (unsetRelay5, LOW);//E OFF 
//  digitalWrite (setRelay2, LOW); //B  
//  digitalWrite (unsetRelay2, HIGH);//B ON
//  digitalWrite (setRelay4, LOW);//D 
//  digitalWrite (unsetRelay4, HIGH);// D ON
//  delay (1000);


//digitalWrite (setRelay1, HIGH); 
//digitalWrite (unsetRelay1, LOW);
//digitalWrite (setRelay2, HIGH); 
//digitalWrite (unsetRelay2, LOW);
//digitalWrite (setRelay3, HIGH); 
//digitalWrite (unsetRelay3, LOW);
//digitalWrite (setRelay4, HIGH); 
//digitalWrite (unsetRelay4, LOW);
//digitalWrite (setRelay5, HIGH); 
//digitalWrite (unsetRelay5, LOW);
//Serial.println ("All Relays are OFF");
////delay(1000);
// 
//  Serial.println ("All Relays are ON");
//  digitalWrite (setRelay1, LOW); 
//  digitalWrite (unsetRelay1, HIGH);
//  digitalWrite (setRelay2, LOW); 
//  digitalWrite (unsetRelay2, HIGH);
//  digitalWrite (setRelay3, LOW); 
//  digitalWrite (unsetRelay3, HIGH);
//  digitalWrite (setRelay4, LOW); 
//  digitalWrite (unsetRelay4, HIGH);
//  digitalWrite (setRelay5, LOW); 
//  digitalWrite (unsetRelay5, HIGH);
//  Serial.println ("All Relays are ON");
// //delay (minutes); 
//}


