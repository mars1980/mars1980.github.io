//    LED 200 ohm res in series to PWM pin 11, cathode to ground
// LDR voltage divider: one leg to pwr, the other to bus row with A0 and 
//10k ohm resistor to ground
//add in an LED on 13 to show calibration

//THIS IS GOOD IF YOU WANT A CERTAIN THRESHOLD TO TRIGGER ON THE LED
int photocell; 
int maxVal = 0; 
int minVal = 1023;

void setup() {
  Serial.begin(9600);

  pinMode (13, OUTPUT); 
  digitalWrite(13,HIGH);

  //calibrate for 5 sec

  while (millis() < 5000){
    photocell = analogRead(A0);

    //record max val
    if (photocell > maxVal){
      maxVal = photocell;
    }
    if (photocell < minVal){
      minVal = photocell;
    }
  }

  digitalWrite (13,LOW);
}

void loop() {
  int photocell = analogRead(A0);
  
  photocell = map(photocell, minVal, maxVal, 0, 255);
  
  photocell = constrain(photocell, 0, 255);

  analogWrite(11, photocell);
}



