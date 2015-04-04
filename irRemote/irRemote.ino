#include <LiquidCrystal.h>
#include <IRremote.h>
// LCD=======================================================
// initialize the library with the numbers of the interface pins
#define LCD_WIDTH 20
#define LCD_HEIGHT 2
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

int inPin = 2;
IRrecv reception_ir(inPin);
decode_results code;

void setup() 
{ 
  Serial.begin(9600); 
  lcd.begin(LCD_WIDTH, LCD_HEIGHT,1);
  
  print(0, 0, "Init IR");
  reception_ir.enableIRIn(); // init receiver
  print(0, 0, "Waiting for code");
}

void loop() 
{ 
  if (reception_ir.decode(&code)) 
  { 
    processCode(code);
    reception_ir.resume(); // reçoit le prochain code 
  } 
}

void processCode(decode_results code) {
  char buf[20];
  sprintf(buf, "%Xd", code.value);
  print(0, 1, buf);
  delay(500);
  print(0, 1, "");
}


void print(int col, int row, char* displayMsg) {
  char msg[25];
  Serial.println(displayMsg);
  strncpy(msg, displayMsg, 20);
  while(strlen(msg) < 20) {
    strcat(msg, " ");
  }
  lcd.setCursor(col, row);
  lcd.print(msg);
}

