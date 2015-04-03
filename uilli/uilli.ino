#include <Servo.h>

void setup(void){
  pinMode(13,OUTPUT);  
}

void loop(void){
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}

