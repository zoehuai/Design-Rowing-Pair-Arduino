/*
#include <Servo.h>
int trigPin=10;
int echoPin=11;
int lightPin = 9;
int pairLightPin = 6;
long duration;
long distance1 ;
long distance2 ;
long lightVal;
unsigned long myTime;
long speed;
Servo myservo1;
int pos = 0; 
void setup() {
 // put your setup code here, to run once:
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(lightPin,OUTPUT);
Serial.begin(9600);
myservo1.attach(12);
  distance1 = distance2;
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  distance2=(duration/2)/29.1;                //1/29.1=0.034 ~ speed of sound converted into centimeters per microsecond
  Serial.print("Distance :");
  Serial.print(distance2);
  lightVal=map(distance2,0,225,255,0);      //mapping the intensity as per distance

  Serial.print("\t");
  Serial.print(lightVal);
  Serial.println();
  
  //if the light value is within the range light it up
  if(0<=lightVal && lightVal<=255) { 
    Serial.println(lightVal);
    analogWrite(lightPin, lightVal);
  }
  else {
    analogWrite(lightPin,LOW);
  }
  Serial.print("Time: ");
  myTime = millis();
  Serial.println(myTime); // prints time since program started
 
  Serial.print("Speed = ");
   if (distance2 - distance1 >=0){
 speed = (distance2 - distance1)*0.01 /0.433;
  
    Serial.println(speed);}
  distance1 = distance2;
  /*
  if(speed > 3 ){
   for (pos = 0; pos <= 180; pos += 30) { // goes from 0 degrees to degrees
// in steps of 1 degree
myservo1.write(pos);      
 
}
for (pos = 180; pos >= 0; pos -= 30) { 
myservo1.write(pos);   

 //delay(100);
}
if(2<speed < 3 ){
   for (pos = 0; pos <= 180; pos += 20) { // goes from 0 degrees to degrees
// in steps of 1 degree
myservo1.write(pos); 
     
  // delay(1000);
}
for (pos = 180; pos >= 0; pos -= 20) { // goes from 180 degrees to 0 degrees
myservo1.write(pos);   
}
 //delay(1000);
}
if(1<speed <= 2 ) {
   for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to degrees
// in steps of 1 degree
myservo1.write(pos);  
  
  // delay(0.2);
}
for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
myservo1.write(pos); 
  
}
 //delay(0.2);
}
if(0<=speed <= 1 ) {
   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to degrees
// in steps of 1 degree
myservo1.write(pos);  

  // delay(10000);
}
for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
myservo1.write(pos);  
}
 */
