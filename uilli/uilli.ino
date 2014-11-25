//UILLI CODE @ Isaac Team


//Possible directions
enum directions{
  up,
  down,
  left,
  right,
  stp
};

//Possible servo directions
enum servo_dir{
  SX,
  DX
};

void setup() {
  //configure motors
  setup_motors();
  setup_sensor();
  setup_servo();
  sensor_enable();

  //configure serial
  Serial.begin(9600);
}

int v = 6, sec = 500, tmp, max_dist = 20;

void loop() {
	char c;

	if(Serial.available()){
		c = (char) Serial.read();
                Serial.write(c);
                
                Serial.print(tmp = read_sensor());
                if(tmp < max_dist && c != 's')
                  motion(stp, v);
		switch (c)  {
			case 'w' :
        servo_center();
          if(read_sensor()>30)
            motion(stp, v);
				  motion(up, v); 
				break;

			case 'a' :
        servo_zero();
        if(read_sensor()>30)
            motion(stp, v);
        servo_center();
    		motion(left, v);
				break;
			
      case 'd' :
        servo_max();
        if(read_sensor()>30)
            motion(stp, v);
        servo_center();
        motion(right, v);
				break;
			
      case 's':
        Serial.print("move and pray XD\n\r");
        motion(down, v);
				break;

			case 'v' :  
        Serial.write('\r\n insert V [0 - 9 ]:');
				while(!Serial.available());
				v = (int)Serial.read();
				break;

			case 'r':
                                c=(char)48+v;
				Serial.write(c);
				break;
                        case 'q':
                                motion(stp, v);
                                break;
                        case 'j':
                                servo_zero();
                                break;
                        case 'k':
                                servo_center();
                                break;
                        case 'l':
                                servo_max();
                                break;
                                
			default:
				break;
		}
	}else{
            if(c == 's')
                motion(down, v);
            else if(read_sensor() < max_dist)
                motion(stp, v);
        }

}



