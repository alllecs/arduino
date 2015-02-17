/* Программа мигающей стрелки */


#define Rb5  9  // CS
#define Rb6  10  // DATA
#define Rb7  8  // CLK

// pattern for 8 X 8 LED matrix
char array1[] = { 
  0x00, 0x00, 0x81, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00 }; 

void setup()   {

  pinMode(Rb5, OUTPUT);
  pinMode(Rb6, OUTPUT);
  pinMode(Rb7, OUTPUT);
  digitalWrite(Rb5, LOW);
}

void loop()   {
  delay(1000);

  init_MAX7219();

  int k = 0;
  while(1)   {  
    for (int j=1; j<9; j++)   {
      writeMAX7219(j+k, array1[j]);
    }
    delay(50);
    k++;
    if (k > 8) k = 0;
  }
}

// shift data to MAX7219
// Rb7 -> CLK, Rb6 -> DATA, Rb5 -> CS not
void ssrOut(unsigned char val)  {  
  int j;
  for(j=1; j<=8; j++)  {   // shift out MSB first
    unsigned char  temp = val & 0x80; // MSB out first
    if (temp == 0x80) digitalWrite(Rb6, 1); // Rb6 DATA          
    else digitalWrite(Rb6, 0); 
    digitalWrite(Rb7, 1);
    delayMicroseconds(10);
    digitalWrite(Rb7, 0);
    val = val << 1; // shift one place left
  }  // next j
} 


void pulseCS(void)   {
  digitalWrite(Rb5, 1);
  delay(1);
  digitalWrite(Rb5, 0);
}


void init_MAX7219(void)   {
  digitalWrite(Rb5, 0); // CS NOT

  // set decode mode
  ssrOut(0x09);
  ssrOut(0x00); // no decode
  pulseCS();

  // set intensity
  ssrOut(0x0A);
  ssrOut(0x08); // 0 - F
  pulseCS();

  // set scan limit
  ssrOut(0x0B);
  ssrOut(0x07); // 8 digits
  pulseCS();
  
  // set for normal operation
  ssrOut(0x0C); 
  ssrOut(0x01);
  pulseCS();


} 

void writeMAX7219(char address, char data)   {
  if ((address < 1) || (address > 8)) return;
  ssrOut(address); // valid numbers 1-8
  ssrOut(data); 
  pulseCS();
}
