#include <EEPROMex.h>
#include <EEPROMvar.h>


#define PHONE_NUMBER_LENGTH 15
#define MAX_PHONE_NUMBERS 5
#define CONFIG_ADDRESS 0

struct phoneConfig {
  unsigned char serviceFlags;
  char number[PHONE_NUMBER_LENGTH + 1];
};

struct eepromConfig {
  int temperatureAdjustment;
  int temperatureHighThreshold;
  int temperatureLowThreshold;
  int lightThreshold;
  phoneConfig registeredNumbers[MAX_PHONE_NUMBERS];
} config;


void setup()  {
  delay(4000);
  EEPROM.setMaxAllowedWrites(10);
  Serial.begin(9600);
  EEPROM.readBlock(CONFIG_ADDRESS, config);

  if(config.lightThreshold == -1) {
    Serial.println('Not init');
    config.lightThreshold = 500;
    config.temperatureAdjustment = 0;
    config.temperatureHighThreshold = 2700;
    config.temperatureLowThreshold = 2100;
    config.registeredNumbers[0].serviceFlags = 0xFF;
    strcpy(config.registeredNumbers[0].number, "0627333734");
    Serial.println("Saving");
    EEPROM.writeBlock(CONFIG_ADDRESS, config);
  } else {
    Serial.println("Already init");
    Serial.println(config.lightThreshold);
    Serial.println(config.registeredNumbers[0].number);
  }

}

void loop() {

}