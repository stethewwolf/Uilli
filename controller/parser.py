import sys , serial

sys.stdin.flush();
ser = serial.Serial('/dev/ttyUSB0', 9600)

while true :
    line = sys.stdin.readline();

    ser.writeline(line);
