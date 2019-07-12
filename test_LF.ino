 /*      
 *----------------------------------------------------------
 *Розпіновка робот-машинки Квант:
 *----------------------------------------------------------
 *Драйвер моторів:
   Left Motor Speed - 5
   Left Motor In1 - 6
   Left Motor In2 - 7
   Right Motor In1 - 8
   Right Motor In2 - 9
   Right Motor Speed - 10

   Bluetooth: 
   Rx - 2
   Tx - 3

   Tracker Sensor (лайнтрекери):
   Sensor 1 (left) - A0
   Sensor 2 - A1
   Sensor 3 - A2
   Sensor 4 - A3
   Sensor 5 (right) - A4
 */

#define leftMotor1 6
#define leftMotor2 7

#define rightMotor1 8
#define rightMotor2 9

#define leftMotorSpeed 5
#define rightMotorSpeed 10

//Порти до який підключено лайнтрекери з ліва на право
#define sensor1 A0
#define sensor2 A1
#define sensor3 A2
#define sensor4 A3
#define sensor5 A4


int forwardSpeed = 60; //Max 255
int elseSpeed = 40;
int turnSpeed = 230;     //Max 255
int turnDelay = 1;   //Кількість мілісекунд для реакції машинки
int t = 1;

void setup() {
  for(int i = 6; i < 10; i++)
  {
    pinMode(i, OUTPUT);
  }

 Serial.begin(9600);
}


void loop(){
 
SpeedCarElse();
if( analogRead(1) > 0 && analogRead(3) > 0 && analogRead(0) > 0 && analogRead(4) > 0 ) {
  SpeedCar();
  forward();
  delay(t);
}
else if (analogRead(1) > 0 && analogRead(3) == 0 || analogRead(3) > 0 && analogRead(4) == 0 || analogRead(2) > 0 && analogRead(3) == 0 && analogRead(4) == 0 ){
SpeedCarLeft();
left();
delay(t);
}

else if (analogRead(1) == 0 && analogRead(3) > 0 || analogRead(1) > 0 && analogRead(0) == 0 || analogRead(1) == 0 && analogRead(0) == 0 && analogRead(2) > 0 ){
SpeedCarRight();
right();
delay(t);
}

else if (analogRead(1) == 0 && analogRead(3) == 0 && analogRead(2) == 0 && analogRead(0) == 0 && analogRead(4) == 0){
SpeedCar();
forward();
delay(t);
}
}


void SpeedCar(){
  analogWrite(leftMotorSpeed, forwardSpeed);
  analogWrite(rightMotorSpeed, forwardSpeed);
}

void SpeedCarElse(){
  analogWrite(leftMotorSpeed, elseSpeed);
  analogWrite(rightMotorSpeed, elseSpeed);
}

void SpeedCarLeft(){
  analogWrite(leftMotorSpeed, turnSpeed);
  analogWrite(rightMotorSpeed, forwardSpeed);
}

void SpeedCarRight(){
  analogWrite(leftMotorSpeed, forwardSpeed);
  analogWrite(rightMotorSpeed, turnSpeed);
}

//Підпрограма для руху робот-машинки вперед
void forward()
{
  //Serial.println("going forward");
  
  digitalWrite(leftMotor1, 0);
  digitalWrite(leftMotor2, 1);
  digitalWrite(rightMotor1, 0);
  digitalWrite(rightMotor2, 1);

  delay(turnDelay);
}

//Підпрограма для руху робот-машинки назад
void backward()
{
  //Serial.println("going backward");
  
  digitalWrite(leftMotor1, 1);
  digitalWrite(leftMotor2, 0);
  digitalWrite(rightMotor1, 1);
  digitalWrite(rightMotor2, 0);

  delay(turnDelay);
}

//Підпрограма для руху робот-машинки ліворуч
void left()
{
  //Serial.println("tuning left");
  
  digitalWrite(leftMotor1, 0);
  digitalWrite(leftMotor2, 1);
  digitalWrite(rightMotor1, 1);
  digitalWrite(rightMotor2, 0);
 

  delay(turnDelay);
}


//Підпрограма для руху робот-машинки праворуч
void right()
{
  //Serial.println("tuning right");
  
  digitalWrite(leftMotor1, 1);
  digitalWrite(leftMotor2, 0);
  digitalWrite(rightMotor1, 0);
  digitalWrite(rightMotor2, 1);

  delay(turnDelay);
}

