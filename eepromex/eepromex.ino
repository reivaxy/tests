#include <EEPROMex.h>
#include <EEPROMvar.h>


#include <remoteNumber.h>

#define PHONE_NUMBER_LENGTH 15
#define MAX_PHONE_NUMBERS 4
#define CONFIG_ADDRESS 0

#define CONFIG_VERSION 1

struct phoneConfig {
  unsigned char serviceFlags;
  char number[PHONE_NUMBER_LENGTH + 1];
};

struct eepromConfig {
  unsigned char version; // Always keep it as first member when modifying this structure
  int temperatureAdjustment;
  int temperatureHighThreshold;
  int temperatureLowThreshold;
  int lightThreshold;
  phoneConfig registeredNumbers[MAX_PHONE_NUMBERS];
} config;


void setup()  {
  unsigned char i;
  delay(4000);
  EEPROM.setMaxAllowedWrites(10);
  Serial.begin(9600);
  EEPROM.readBlock(CONFIG_ADDRESS, config);

  // If config version changed, re-init config from scratch and save it
  if(config.version != CONFIG_VERSION) {
    Serial.println('Not init');
    config.version = CONFIG_VERSION;
    config.lightThreshold = 500;
    config.temperatureAdjustment = 0;
    config.temperatureHighThreshold = 2700;
    config.temperatureLowThreshold = 2100;
    // Reset all saved numbers
    // First one is main number, hardcoded, and subscribed to all services
    config.registeredNumbers[0].serviceFlags = 0xFF;
    strcpy(config.registeredNumbers[0].number, REMOTE_NUMBER);
    for(i=1 ; i < MAX_PHONE_NUMBERS; i++ ) {
      config.registeredNumbers[i].serviceFlags = 0;
      config.registeredNumbers[i].number[0] = 0;
    }

    Serial.println("Saving");
    EEPROM.writeBlock(CONFIG_ADDRESS, config);
    Serial.println("Saved");
  } else {
    Serial.println("Already init");
    // Display a few things for verification
    Serial.println(config.lightThreshold);
    Serial.println(config.registeredNumbers[0].number);
  }

}

void loop() {

}