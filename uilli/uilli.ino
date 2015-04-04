#include <Servo.h>
/*
   DEFINITIONS
*/

/* 
   Servo manager
*/
#define PIN_SERVO A0
#define START_POS_SERVO 90
Servo sensorServo;

void servo_setup(){
  pinMode(PIN_SERVO,OUTPUT);
  sensorServo.attach(PIN_SERVO);
  sensorServo.write(START_POS_SERVO);  
  return;
}

void servo_move(int pos){
  if(pos>=0 && pos <= 180 )
    sensorServo.write(pos);
  return;
}

void servo_reset(){
  sensorServo.write(START_POS_SERVO);
}

/*
   Ultrasonic Sensor
*/
#define USONIC_ECHO 13
#define USONIC_TRIG 12
int uSensorStat;

void uSonic_setup(){
  pinMode(USONIC_ECHO,INPUT);
  pinMode(USONIC_TRIG,OUTPUT);

  uSensorStat=0;
}

long uSonic_read(){
  long duration, distance;
      
  digitalWrite(USONIC_TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(USONIC_TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(USONIC_TRIG,LOW);
  duration = pulseIn(USONIC_ECHO,HIGH);
  distance = (duration / 2 ) / 38;
	    
  return distance;
}



/*
*   Final functions
*/
void setup(void){
  servo_setup();
  uSonic_setup();
  Serial.begin(9600);
}

void loop(void){
  int i;
  long dist;
  delay(500);
  for(i=0; i<180; i=i+2){
    servo_move(i);
    dist=uSonic_read();
    Serial.println(dist); 
    delay(25);
  }
  
  servo_reset();
}

