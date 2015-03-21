/*
test

Testing some basic stuff

*/

int led1 = 3;           // the pin that the LED is attached to
int led2 = 6;           // the pin that the LED is attached to
int led3 = 5;           // the pin that the LED is attached to
int brightness = 5;  // how bright the LED is
int fadeAmount = 2;    // how many points to fade the LED by
int min = 5;
int max = 50;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  analogWrite(led1, brightness);    
  analogWrite(led2, brightness);    
  analogWrite(led3, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness <= min || brightness >= max) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 10 milliseconds to see the dimming effect    
  delay(10);                            
}

