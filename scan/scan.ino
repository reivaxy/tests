/*

Testing some basic stuff

*/

int leds[5] = {2,3,4,5,6};
int count = 5;

int brightness = 255;  // how bright the LED is
int offset = 0;
int led = 2;
int dir = 1;

void setup()  { 
  Serial.begin(9600);
  Serial.println("Initializing");
  int i = 0;
  for(i=0; i< count ; i++) {
    pinMode(leds[i], OUTPUT);
  }
} 

// the loop routine runs over and over again forever:
void loop()  { 
  Serial.println("Looping");
  Serial.println(offset);
  analogWrite(led, 0);    
  led = leds[offset];
  analogWrite(led, brightness);    
  offset += dir;
  if((offset >= count-1) || (offset <= 0)) {
    dir = - dir;
  }
  delay(30);                            
}

