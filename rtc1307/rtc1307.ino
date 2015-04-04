
#include <Wire.h>
#include "DS1307.h"

DS1307 clock;//define a object of DS1307 class
void setup()
{
  int hour, min, sec, day, month, year;
  char monthStr[5];

  Serial.begin(9600);
  clock.begin();
  /*
  sscanf(__DATE__, "%s %d %d", monthStr, &day, &year);
  sscanf(__TIME__, "%d:%d:%d", &hour, &min, &sec);
  clock.getTime();
  if(strncmp(monthStr, "Jan", 3) == 0)
    month = 1;
  if(strncmp(monthStr, "Feb", 3) == 0)
    month = 2;
  if(strncmp(monthStr, "Mar", 3) == 0)
    month = 3;
  if(strncmp(monthStr, "Apr", 3) == 0)
    month = 4;
  if(strncmp(monthStr, "May", 3) == 0)
    month = 5;
  if(strncmp(monthStr, "Jun", 3) == 0)
    month = 6;
  if(strncmp(monthStr, "Jul", 3) == 0)
    month = 7;
  if(strncmp(monthStr, "Aug", 3) == 0)
    month = 8;
  if(strncmp(monthStr, "Sep", 3) == 0)
    month = 9;
  if(strncmp(monthStr, "Oct", 3) == 0)
    month = 10;
  if(strncmp(monthStr, "Nov", 3) == 0)
    month = 11;
  if(strncmp(monthStr, "Dec", 3) == 0)
    month = 12;



  // Run this only once
  Serial.println("Setting time");
  Serial.println(__DATE__);
  Serial.println(__TIME__);
  clock.fillByYMD(year, month, day);
  clock.fillByHMS(hour, min, sec + 8);  // +8 for linking/uploading offset ;) Very experimental :)
  clock.setTime();
  */

}
void loop()
{
  printTime();
  delay(1000);
}
/*Function: Display time on the serial monitor*/
void printTime()
{
  clock.getTime();
  Serial.print(clock.hour, DEC);
  Serial.print(":");
  Serial.print(clock.minute, DEC);
  Serial.print(":");
  Serial.print(clock.second, DEC);
  Serial.print("  ");
  Serial.print(clock.month, DEC);
  Serial.print("/");
  Serial.print(clock.dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(clock.year+2000, DEC);
  Serial.print(" ");
  switch (clock.dayOfWeek)// Friendly printout the weekday
  {
    case MON:
      Serial.print("MON");
      break;
    case TUE:
      Serial.print("TUE");
      break;
    case WED:
      Serial.print("WED");
      break;
    case THU:
      Serial.print("THU");
      break;
    case FRI:
      Serial.print("FRI");
      break;
    case SAT:
      Serial.print("SAT");
      break;
    case SUN:
      Serial.print("SUN");
      break;
  }
  Serial.println(" ");
}