
	#include <Wire.h>
	
	#define DISPLAY_ADDRESS1 0x71 //This is the default address of the OpenSegment with both solder jumpers open
	
	char cycles;
	char tempString[10];
        int i;

	void setup() 
	{

          Wire.begin(); //Join the bus as master
	  clearDisplayI2C();
	  //By default .begin() will set I2C SCL to Standard Speed mode of 100kHz
	  //Wire.setClock(400000); //Optional - set I2C SCL to High Speed Mode of 400kHz
	
	  Serial.begin(9600); //Start serial communication at 9600 for debug statements
	  Serial.println("OpenSegment Example Code");
	
	  //Send the reset command to the display - this forces the cursor to return to the beginning of the display
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
	      s7sSendStringI2C(tempString); //Send the four characters to the display
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
  Wire.write(0x76);  // Clear display command
  Wire.endTransmission();
}
