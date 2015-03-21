/*

Testing some basic stuff

Display a countdown from 9 to 0
and loop
Multiplexing over 7 segments: only one segment lit at a time

2015/02/09 Xavier

*/

int count = 7;

/* declare pins */
int leds[7] = {2,3,4,5,6,7,8};
/* Segments:
A 7  pin 2
B 6  pin 3
C 4  pin 4
D 2  pin 5
E 1  pin 6
F 9  pin 7
G 10 pin 8
*/

/* pins used to display each digit */
const char *digits[10];

int periodHigh = 50;
int periodLow = 800;
int tic = 100;
int currentDigit = 9;

void setup()  { 
  digits[0] = "234567";
  digits[1] = "34";
  digits[2] = "23568";
  digits[3] = "23458";
  digits[4] = "3478";
  digits[5] = "24578";
  digits[6] = "245678";
  digits[7] = "234";
  digits[8] = "2345678";
  digits[9] = "234578";
  int i = 0;
  for(i=0; i< count ; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);    
  }
} 

void loop()  { 
  // Countdown
  displayDigit(currentDigit);

  if(currentDigit > 0) {
    currentDigit --;
  } else {
    currentDigit = 9;
  }
}

void displayDigit(int digit) {
  const char *segments = digits[digit];
  boolean keep = true;
  int offset = 0;
  int led;
  unsigned long start = millis();

  clear();
  while(keep) {
    led = segments[offset]-48  ;
    digitalWrite(led, HIGH);    
    delayMicroseconds(periodHigh);                            
    digitalWrite(led, LOW);    
    delayMicroseconds(periodLow);                            
    if((millis() - start) > tic) {
      keep = false;
    }
    offset += 1;
    if(segments[offset] == 0) {
      offset = 0;  
    }
    
  }
}

void clear() {
  int i;
  for(i=0; i<7; i++) {
    digitalWrite(leds[i], LOW); 
  }
}
