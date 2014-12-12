//UILLI CODE @ Isaac Team

#include <Servo.h>

#define CTRL 10
#define SVCC A0
#define SERVO_MIN 0
#define SERVO_AVG 70
#define SERVO_MAX 150
//0 -> 70 -> 150
#define START_POS  SERVO_AVG

int servo_position;
Servo sensor_servo;


void setup_servo(){
 
  pinMode(SVCC,OUTPUT);
  digitalWrite(SVCC,HIGH);
  
  sensor_servo.attach(CTRL);
  
  servo_position = START_POS;

  sensor_servo.write(servo_position);    
}

//Return servo to start position
void servo_reset () {
  servo_position=START_POS;
  sensor_servo.write(servo_position);
}

//Turn servo in respect of the start position
int servo_rotate (int dir, int val){
  int pos;
  if(val < 0 || val > 90)
    return -1;
  if(dir == SX){
      pos = map(val, 0, 90, 70, 150);
  }else{
      pos = map(val, 0, 90, 70, 0);
  }
  
  sensor_servo.write(pos);
  return pos;
} 


//DEBUG FUNCTIONS
void servo_center(){
  sensor_servo.write(SERVO_AVG);
}

void servo_zero(){
  sensor_servo.write(SERVO_MIN);
}

void servo_max(){
  sensor_servo.write(SERVO_MAX);
}

void servo_mid_left(){
  sensor_servo.write(SERVO_AVG*1.5);
}

void servo_mid_right(){
  sensor_servo.write(SERVO_AVG/2);
}
