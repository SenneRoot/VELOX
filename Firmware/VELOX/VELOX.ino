#include "src/Controller/MiviceC201.h"

constexpr pin_size_t speedHackEnabledoutputPin = 2;
constexpr byte speed = 32;
bool speedHackEnabled = false;

#include <EEPROMWearLevel.h>
// eeprom wearlevel setup
constexpr byte EEPROMLayoutVersion = 0;
constexpr byte EEPROMVars = 1;
constexpr byte EEPROMspeedHackEnabledVarIndex = 0;

void intercept();

void setup() 
{
    // to avoid unused variable warning
    (void) EEPROM;

    Serial.begin(1200);

    EEPROMwl.begin(EEPROMLayoutVersion, EEPROMVars);
    EEPROMwl.get(EEPROMspeedHackEnabledVarIndex, speedHackEnabled);

    pinMode(speedHackEnabledoutputPin, OUTPUT);
    digitalWrite(speedHackEnabledoutputPin, speedHackEnabled);
}

void loop() 
{
  if(Serial.available())
  {
    intercept();
  }

  digitalWrite(speedHackEnabledoutputPin, speedHackEnabled);
}

void intercept()
{
  byte bytes[16];
  size_t size = 0;
  Serial.readBytes(&bytes[size++], 1);
  
  if(bytes[size - 1] == static_cast<byte>(commandType::SET))
  {
    Serial.readBytes(&bytes[size++], 1);

    switch (bytes[size - 1])
    {
      case static_cast<byte>(SET::MaxRPM):
      {
        if(speedHackEnabled)
        {
          size_t nIntercept = 3;
          byte buffer[nIntercept];
          if(Serial.readBytes(buffer, nIntercept) == nIntercept)
          {
            size_t orginalSize = size;
            MiviceC102Driver::calculateRPM(speed, buffer[0], buffer[1]);

            bytes[size++] = buffer[0];
            bytes[size++] = buffer[1];
            bytes[size++] = MiviceC102Driver::calculateCRC(bytes, orginalSize + nIntercept - 1);
          }
        }
        break;
      }
      case static_cast<byte>(SET::PAS): // enable/disable speed hack by checking
      {
        Serial.readBytes(&bytes[size++], 1);
        if(bytes[size - 1] == static_cast<byte>(PAS::walking))
        {
          speedHackEnabled = !speedHackEnabled;
          EEPROMwl.update(EEPROMspeedHackEnabledVarIndex, speedHackEnabled);
        }
        break;
      }
    default:
      {
        break;
      }
    }
  }

  Serial.write(bytes, size);
}
