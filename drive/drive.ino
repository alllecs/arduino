#include <Servo.h>

Servo servo;

int angle = 90;
int val;
 int IN1 = 4;
 int IN2 = 5;
 int EN1 = 6;
 int EN2 = 7;
 int SER = 8;
 int led = 13;
 void setup()
 {
 Serial.begin(9600);
 servo.write(angle);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(EN1, OUTPUT);
 pinMode(EN2, OUTPUT);
 pinMode(led, OUTPUT);

 servo.attach(SER);
 }
 void loop()
 {
 if (Serial.available())
 {
 val = Serial.read();

 // Задаём движение вперёд
 if (val == 'W') // При нажатии клавиши «W»
 {
 // Выводы конфигурируются согласно работе Motor Shield'а
 // Моторы крутятся вперед
 digitalWrite(EN1, HIGH);
 digitalWrite(EN2, LOW);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(led, HIGH);
 }

 // Задаём движение назад
 if ( val == 'S')
 {
 digitalWrite(EN1, LOW);
 digitalWrite(EN2, HIGH);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(led, LOW);
 }

 // Задаём движение вправо
 if ( val == 'D')
 {
 digitalWrite(EN1, HIGH);
 digitalWrite(EN2, HIGH);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 if (angle != 180) {
   angle = 180;
 } else {
   angle = 90;
 }
 servo.write(angle);
 digitalWrite(led, HIGH);
 }

 // Задаём движение влево
 if ( val == 'A')
 {
 digitalWrite(EN1, HIGH);
 digitalWrite(EN2, LOW);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 if (angle != 0) {
   angle = 0;
 } else {
   angle = 90;
 }
   servo.write(angle);
   digitalWrite(led, LOW);
 }

 // Стоп режим
 // При отпускании клавиш в программе в порт шлется «T»
 if ( val == 'T') // При нажатии клавиши «T»
 {
 // Выводы ENABLE притянуты к минусу, моторы не работают
 digitalWrite(EN1, LOW); 
 digitalWrite(IN2, LOW);
 }
 }
 }
