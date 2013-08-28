/*
Created by: Leonardo Merza
Version 0.7
*/

int val, zVal; 

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(11, OUTPUT);
} 

void loop()
{ 
  // check if enough data has been sent from the computer: 
  if (Serial.available()>3) 
  { 
    // Read the first value. This indicates the beginning of the communication. 
    val = Serial.read(); 
    // If the value is the event trigger character 'S' 
    if(val == 'S')
    { 
      // read the z-value
      zVal = Serial.read();
      Serial.write(zVal);
    } // if input is 'S' then read values
  } //if serial read on
  
  // write to led
  analogWrite(11,zVal); 
} // void loop
