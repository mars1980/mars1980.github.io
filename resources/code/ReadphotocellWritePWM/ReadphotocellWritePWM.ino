//    LED 200 ohm res in series to PWM pin 11, cathode to ground
// LDR voltage divider: one leg to pwr, the other to bus row with A0 and 
//10k ohm resistor to ground


void setup() {
  Serial.begin(9600);
}

void loop() {
  int photocell = analogRead(A0);

  Serial.print("photocell reads at:  ");
  Serial.println(photocell);
  //LED GETS BRIGHTER AS THE ROOM GETS DARKER  
  //invert the readings
  photocell = 1023 - photocell; 
  int brightness = map(photocell, 0,1023,0,255);
  //OR
  // int brightness = map(photocell, 1023,0,0,255);

  analogWrite(11, brightness);
}


