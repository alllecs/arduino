unsigned char i;
unsigned char j;
unsigned char result; 

int Max7219_pinCLK = 10;
int Max7219_pinCS = 9;
int Max7219_pinDIN = 8;

char array1[90];

unsigned char blarg_xpm[8][8]={ 
"........",
"........",
"..*..*..",
"........",
".*....*.",
"..****..",
"........",
"........", 
};

void my_print(char *a)
{
 int i;
 
 for (i = 0; i < 8 && *a != '\0'; i++) {
   if (*a == '.') {
     result = (result << 1) | 0;
   } else {
     result = (result << 1) | 1;
   
   }  
 }
}
 
 
void Write_Max7219_byte(unsigned char DATA)
{
  unsigned char i;
  digitalWrite(Max7219_pinCS,LOW);
  for(i=8;i>=1;i--)
  {
    digitalWrite(Max7219_pinCLK,LOW);
    digitalWrite(Max7219_pinDIN,DATA&0x80);
    DATA = DATA<<1;
    digitalWrite(Max7219_pinCLK,HIGH);
  }
}
 
void Write_Max7219(unsigned char address,unsigned char dat)
{
  Write_Max7219_byte(address);
  Write_Max7219_byte(dat);
  digitalWrite(Max7219_pinCS,HIGH);
}
 
int a;

void setup()
{
 
  pinMode(Max7219_pinCLK,OUTPUT);
  pinMode(Max7219_pinCS,OUTPUT);
  pinMode(Max7219_pinDIN,OUTPUT);
  
}
 
void loop()
{

  for(j=0;j<8;j++)
  {
    for(i=1;i<9;i++)
      Write_Max7219(i,blarg_xpm[j][i-1]);
   }
  
}
