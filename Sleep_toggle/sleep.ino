void sleep() {

    Serial.println("Sleep");
    delay(500);
    
     // Allow wake up pin to trigger interrupt on low.
    attachInterrupt(2, wakeUp, LOW);
    
    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    
    // Disable external pin interrupt on wake up pin.
    detachInterrupt(2);

    
}

