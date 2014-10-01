//    LED 200 ohm res in series to PWM pin 11, cathode to ground


int fade = 5; 
int brightness = 0;

void setup() {

  pinMode (11, OUTPUT); 

}

void loop() {

  //start w/ the LED low,   
  analogWrite(11, brightness);
  
  //increment the brightness by 5 every loop
  brightness = brightness + fade;
  
  
  //once the brightness become 0 or 255
  //reverse the direction of the fading
  if (brightness == 0 || brightness == 255)
  {
   fade = -fade; 
  }
  //wait to see the dimming effect
  delay(50);
}




