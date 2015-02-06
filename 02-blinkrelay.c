#define RELAY1  6                        

#define RELAY2  7                         

int incomingByte = 0;

void setup()

{    

// Initialise the Arduino data pins for OUTPUT
  Serial.begin(9600);
  
  pinMode(RELAY1, OUTPUT);        

  pinMode(RELAY2, OUTPUT);

}

 

 void loop()

{

  
  if (Serial.available() > 0) {  
    
    incomingByte = Serial.read();
    
    if (incomingByte == '0') {
       digitalWrite(RELAY1,HIGH);
       delay(2000);
       digitalWrite(RELAY2,LOW);       // Turns ON Relays 1
    }
    
    if (incomingByte == '1') {
       digitalWrite(RELAY1,LOW);          // Turns Relay Off
       digitalWrite(RELAY2,HIGH);
       delay(2000);
    }
    
     if (incomingByte == '2') {
      digitalWrite(RELAY1,HIGH);           // Turns ON Relays 2
      digitalWrite(RELAY2,HIGH);          // Turns Relay Off

     } 
     if (incomingByte == '3') {
       
      digitalWrite(RELAY1,LOW);           // Turns ON Relays 2
      digitalWrite(RELAY2,LOW);          // Turns Relay Off
     }

    Serial.println(incomingByte, DEC);
  }

}

