#include <Servo.h>
Servo sg90;

int ldr_1 = A0; // lrd pin connected to A0
int ldr_2 = A1; // LDR pin connected to A1
int servo_pin = 9;
int pos = 90;// initial position
int servo_max=178;      // maximum position for servo
int servo_min=2;        // minimum position for servo

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr_1, INPUT);
  pinMode(ldr_2, INPUT);
  sg90.attach(servo_pin);// servo pin declared 9 Line no 5
  sg90.write(pos);

}

void loop() {
  double ldrStatus1 = analogRead(ldr_1);
  double ldrStatus2 = analogRead(ldr_2);
  Serial.print("LDR1 Status:");
  Serial.print(ldrStatus1);
  Serial.println("");
  Serial.print("LDR2 Status:");
  Serial.print(ldrStatus2);
  Serial.println("");
if(ldrStatus1>ldrStatus2){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sg90.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
  }
  }
if(ldrStatus1<ldrStatus2)
{
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    sg90.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
}
}
