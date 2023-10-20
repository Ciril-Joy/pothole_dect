#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

//Ultrasonic sensor variables
int Echo = A4;  
int Trig = A5; 

//motor controller pins
#define ENA1 5
#define ENA2 3
#define ENB1 6
#define ENB2 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define carSpeed 150
#define carSpeed2 150
int rightDistance = 0, leftDistance = 0;

void forward(){ 
  analogWrite(ENA1, carSpeed);
  analogWrite(ENA2, carSpeed);
  analogWrite(ENB1, carSpeed);
  analogWrite(ENB2, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA1, carSpeed);
  analogWrite(ENA2, carSpeed);
  analogWrite(ENB1, carSpeed);
  analogWrite(ENB2, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}
void left() {
  analogWrite(ENA1, carSpeed);
  analogWrite(ENA2, carSpeed);
  analogWrite(ENB1, carSpeed);
  analogWrite(ENB2, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("Left");
}
void right() {
  analogWrite(ENA1, carSpeed2);
  analogWrite(ENA2, carSpeed2);
  analogWrite(ENB1, carSpeed2);
  analogWrite(ENB2, carSpeed2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}
void stop() {
  digitalWrite(ENA1, LOW);
  digitalWrite(ENA2, LOW);
  digitalWrite(ENB1, LOW);
  digitalWrite(ENB2, LOW);
  Serial.println("Stop!");
} 

//Ultrasonic distance measurement method
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;   
  Serial.print(Fdistance);    
  return (int)Fdistance;
}  

void setup() { 
  myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(ENB1, OUTPUT);
  pinMode(ENB2, OUTPUT);
  stop();
} 

void loop() { 
  
    myservo.write(60);  //setservo position to right side
    delay(200); 
    rightDistance = Distance_test();

    myservo.write(120);  //setservo position to left side
    delay(200); 
    leftDistance = Distance_test();


    if((rightDistance > 70)&&(leftDistance > 70)){
      stop();
    }else if((rightDistance >= 20) && (leftDistance >= 20)) {     
      forward();
    }else if((rightDistance <= 10) && (leftDistance <= 10)) {
        back();
        delay(100);
    }else if(rightDistance - 3 > leftDistance) {
        left();
        delay(100);
    }else if(rightDistance + 3 < leftDistance) {
        right();
        delay(100);
    }else{
      stop();
    }
  
  
  forward();
  delay(2000);
  back();
  delay(2000);
  left();
  delay(2000);
  right();
  delay(2000);
  
}