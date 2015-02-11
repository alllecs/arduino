#define RELAY2 7

#define RELAY2 6

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


int relay_number = 0;
int Byte = 0;

int relay_state[2];

void turn_relay(int relay_number, int on)
{
  digitalWrite(relay_number + 5, on);
  relay_state[relay_number] = on;
}

void toggle_relay(int relay_number)
{
        Serial.print("toggling relay_number=\n");
        Serial.println(relay_number);

        if (relay_state[relay_number] == LOW) {
                lcd.setCursor(0,2);
                lcd.print("on");
                turn_relay(relay_number, HIGH);
        } else {
                lcd.setCursor(0,2);
                lcd.print("off");
                turn_relay(relay_number, LOW);
        }
}
void setup() {
  Serial.begin(9600);

    for (int relay_number = 6; relay_number <= 8; relay_number++){
    pinMode(relay_number, OUTPUT);
  }
lcd.begin(16,2);

  for(int i = 0; i< 2; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

        turn_relay(0, LOW);
        turn_relay(1, LOW);

  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Relay number?       (1 or 2)");

}


void loop()
{
    if (Serial.available() > 0) {
         relay_number = Serial.read() - 48;
        if (relay_number == 1 || relay_number == 2) {
                lcd.clear();
                lcd.print("Relay number: ");       
                lcd.print(relay_number);
                
              toggle_relay(relay_number);
        }
  }
}
