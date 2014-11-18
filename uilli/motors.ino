//UILLI CODE @ Isaac Team

#define MSX 3 //ENB
#define SXUP 2 //+B IN1
#define SXDOWN 4 //-B IN2
#define DXUP 5 //+A IN3
#define DXDOWN 7 //-A IN4
#define MDX 6 //ENA



void setup_motors(){
  pinMode(MDX, OUTPUT);
  pinMode(MSX, OUTPUT);
  pinMode(SXUP, OUTPUT);
  pinMode(SXDOWN, OUTPUT);
  pinMode(DXUP, OUTPUT);
  pinMode(DXDOWN, OUTPUT);
}


void motion(int dir, int power)
{
        if(power < 0 || power > 9)
          return;
          
        //Return to range
	int dutydx = map(power, 0, 9, 0, 250);
        int dutysx = map(power, 0, 9, 0, 255);
        char c;
        
        switch(dir){
          case up: //go forward
            digitalWrite(SXUP, HIGH);
            digitalWrite(SXDOWN, LOW);
            digitalWrite(DXUP, LOW);
            digitalWrite(DXDOWN, HIGH);
            analogWrite(MDX, dutydx);
            analogWrite(MSX, dutysx);
            break;
            
          case down: //go backwards
            digitalWrite(SXUP, LOW);
            digitalWrite(SXDOWN, HIGH);
            digitalWrite(DXUP, HIGH);
            digitalWrite(DXDOWN, LOW);
            analogWrite(MDX, dutydx);
            analogWrite(MSX, dutysx);
            break;
            
          case left: //turn left
            digitalWrite(SXUP, HIGH);
            digitalWrite(SXDOWN, LOW);
            digitalWrite(DXUP, LOW);
            digitalWrite(DXDOWN, HIGH);
            analogWrite(MDX, dutydx);
            analogWrite(MSX, dutydx/2);
            break;
            
          case right: //turn right
            digitalWrite(SXUP, HIGH);
            digitalWrite(SXDOWN, LOW);
            digitalWrite(DXUP, LOW);
            digitalWrite(DXDOWN, HIGH);
            analogWrite(MDX, dutydx/2);
            analogWrite(MSX, dutydx);
            break;
            
          case stp: //stop
            analogWrite(MDX, 0);
            analogWrite(MSX, 0);
            digitalWrite(SXUP, LOW);
            digitalWrite(SXDOWN, LOW);
            digitalWrite(DXUP, LOW);
            digitalWrite(DXDOWN, LOW);
            break;  
	}
}
