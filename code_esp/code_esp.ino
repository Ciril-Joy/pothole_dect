
//Ultrasonic sensor variables
int Trig = 23; 


//motor controller pins
#define ENA 13
#define ENB 25
#define IN1 12
#define IN2 14
#define IN3 27
#define IN4 26

// ECHO PINS OF ULT S
#define ECHO1 18
#define ECHO2 19
#define ECHO3 21

//Buzzer Pin
#define Buzz 32


#define carSpeed 150
#define carSpeed2 150

void forward(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
} 
void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}
void left() {
  analogWrite(ENA, carSpeed2);
  analogWrite(ENB, carSpeed2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("Left");
}
void right() {
  analogWrite(ENA, carSpeed2);
  analogWrite(ENB, carSpeed2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}
void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
} 

//Ultrasonic distance measurement method
void  get_distances(float &distance1, float &distance2, float &distance3) {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float raw1 = pulseIn(ECHO1, HIGH);  
  distance1= raw1 / 58; 
  float raw2 = pulseIn(ECHO2, HIGH);  
  distance2= raw2 / 58;
  float raw3 = pulseIn(ECHO1, HIGH);  
  distance3= raw3 / 58;      
  
}  

void setup() { 
  Serial.begin(115200);     
  pinMode(ECHO1, INPUT);
  pinMode(ECHO2, INPUT);    
  pinMode(ECHO3, INPUT);    
  pinMode(Buzz, OUTPUT); 
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
} 

void loop() { 
  float distance1, distance2, distance3;

  forward();

  get_distances(distance1, distance2, distance3);
   
  float total_dist = distance1 + distance2 + distance3;
  if ((total_dist > 0) || (total_dist<0)){
    digitalWrite(Buzz, HIGH);
  }
  delay(200);
}
