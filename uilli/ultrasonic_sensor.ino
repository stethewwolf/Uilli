//UILLI CODE @ Isaac Team

#define ECHO 13
#define TRIG 12
#define VCC  11

int sensor_stat;

void setup_sensor(){
  pinMode(ECHO,INPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(VCC,OUTPUT);
  
  sensor_stat = 0;
}


void sensor_enable (){
  sensor_stat = 1;
  digitalWrite(VCC,HIGH);
}

void sensor_disable(){
  sensor_stat = 0;
  digitalWrite(VCC,LOW);
}

int sensor_status(){
  return sensor_stat;
}

long read_sensor(){
  if(!sensor_stat)
    return -1;
  
  long duration, distance;
  
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = (duration / 2 ) / 38;
  
  return distance;
 }
