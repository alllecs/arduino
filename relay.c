#define RELAY2 7

#define RELAY2 6

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
                turn_relay(relay_number, HIGH);
        } else {
                turn_relay(relay_number, LOW);
        }
}


void setup() {
  Serial.begin(9600);

    for (int relay_number=6; relay_number<=8; relay_number++){
    pinMode(out, OUTPUT);
  }

        turn_relay(0, LOW);
        turn_relay(1, LOW);

  Serial.println("Hello...");
  Serial.println("Relay number? (1 or 2)");
}

void loop()
{
    if (Serial.available() > 0) {
         relay_number = Serial.read() - 48;
        if (relay_number == 1 || relay_number == 2) {
                toggle_relay(relay_number);
        }

  }
}
