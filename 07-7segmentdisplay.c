#include <Wire.h>

#define DISPLAY_ADDRESS1 0x71
char cycles;
char tempString[10];
int i;

void setup()
{

          Wire.begin();
	  clearDisplayI2C();
	  Serial.begin(9600);
	  Serial.println("OpenSegment Example Code");
	  Wire.beginTransmission(DISPLAY_ADDRESS1);
	  Wire.endTransmission();
	}

void loop()
{
          if (Serial.available() > 0) {
              Serial.print("Cycle: ");
              i = 0;
              cycles = Serial.read();
              Serial.println(cycles);
              tempString[i] = cycles;
	      s7sSendStringI2C(tempString);
	}
}

void s7sSendStringI2C(String toSend)
{
  Wire.beginTransmission(DISPLAY_ADDRESS1);
  i=0;
  Wire.write(toSend[i]);
  Wire.endTransmission();

}

void clearDisplayI2C()
{
  Wire.beginTransmission(DISPLAY_ADDRESS1);
  Wire.write(0x76);
  Wire.endTransmission();
}
