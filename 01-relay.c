ELAY1  6                        

#define RELAY2  7                         


void setup()

{    

// Initialise the Arduino data pins for OUTPUT

  pinMode(RELAY1, OUTPUT);        

  pinMode(RELAY2, OUTPUT);

}

 

 void loop()

{

   digitalWrite(RELAY1,LOW);           // Turns ON Relays 1

   delay(2000);                                      // Wait 2 seconds

   digitalWrite(RELAY1,HIGH);          // Turns Relay Off

 

   digitalWrite(RELAY2,LOW);           // Turns ON Relays 2

   delay(2000);                                      // Wait 2 seconds

   digitalWrite(RELAY2,HIGH);          // Turns Relay Off


 }

