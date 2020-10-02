#include <Servo.h>
Servo motor1, motor2;
int ch1, ch2;
int throttle;
const int Mundurlow = -150;
const int Mundurhigh = 90; 
const int Nmin = 100;
const int Nmax = 130;
const int Ms = 220;
const int Ml = 270;
const int stirlow = 100;
const int stirhigh = 120;
const int kananlow = -20;
const int kananhigh = 50;
const int kirilow = 150;
const int kirihigh = 255;
int i;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  motor1.attach(5);
  motor2.attach(6);
  motor2.writeMicroseconds(1500);


}
 void loop() {
 
  ch1 = pulseIn(2, HIGH, 25000);
  ch2 = pulseIn(3, HIGH, 25000);
  ch1 = map(ch1, 950,2100,0,255);
  ch2 = map(ch2, 950,2045,0,255);
  Serial.print(ch2);
  Serial.print(", ");
  Serial.println(ch1);
  delay(10);
/*
 Serial.print("Channel 2 ");
 Serial.println(ch2);
 delay(100);

 Serial.print("Channel 1 ");
 Serial.println(ch1);
 delay(100);
*/
 // Normal
 if( ch2>=Nmin && ch2<=Nmax ) {
    motor1.writeMicroseconds(1500);
    motor2.writeMicroseconds(1500); 
    }
    
  // Maju Pelan
 if( ch2>=Nmax+20 && ch2<=Ms ){
    for(i=1500; i<= 1520; i +=10){
      motor1.writeMicroseconds(i);
      motor2.writeMicroseconds (i);
      delay(50);
    }
    while(ch2>=Nmax+20 && ch2<=Ms){
      ch2 = pulseIn(3, HIGH, 25000);
      ch2 = map(ch2, 950,2045,0,255);
      motor1.writeMicroseconds(1600);
      motor2.writeMicroseconds(1580);
    }
  }
  
  //Maju Cepat
  if(ch2>=Ms && ch2<=Ml){
   for(i=1550; i<=1570; i = i+10){
     motor1.writeMicroseconds(i);
     motor2.writeMicroseconds (i);
     Serial.println(i);
     delay(10);
   }
   while(ch2>=Ms && ch2<=Ml){
     ch2 = pulseIn(3, HIGH, 25000);
     ch2 = map(ch2, 950,2045,0,255);
     motor1.writeMicroseconds(1650);
     motor2.writeMicroseconds (1630);
     Serial.println(1600);
   }
  }
  
  //Mundur
  if(ch2>= Mundurlow + 10 & ch2 <= Mundurhigh){
   for(i=0; i<=1; i++){
     motor1.writeMicroseconds(900);
     motor2.writeMicroseconds (900);
     Serial.println(i);
     delay(10);
   }
   for(i=0; i<=2; i++){
     motor1.writeMicroseconds(1500);
     motor2.writeMicroseconds(1500);
     Serial.println(1500);
     delay(10);
   }
   for(i=1500; i>=1300; i=-10){
     motor1.writeMicroseconds(i);
     motor2.writeMicroseconds(i);
     delay(10);
   }
   while(ch2>= Mundurlow & ch2 <= Mundurhigh){
     ch2 = pulseIn(3, HIGH, 25000);
     ch2 = map(ch2, 950,2045,0,255);
     motor1.writeMicroseconds(980);
     motor2.writeMicroseconds(1350);
     delay(10);
   }
   }
 //kanan
 if(ch1>= kananlow && ch1 <= kananhigh){
   for(i=1500; i>=1570; i=+10){
     motor2.writeMicroseconds(1550);
     delay(10);
   }
   while(ch1>= kananlow && ch1 <= kananhigh){
    ch1 = pulseIn(2, HIGH, 25000);
    ch1 = map(ch1, 950,2100,0,255);
    motor2.writeMicroseconds(1570);
    delay(10);
   }
 }
 //kiri
  if(ch1>= kirilow && ch1 <= kirihigh){
   for(i=1500; i>=1600; i=+10){
     motor1.writeMicroseconds(i);
     delay(10);
   }
   while(ch1>= kirilow && ch1 <= kirihigh){
    ch1 = pulseIn(2, HIGH, 25000);
    ch1 = map(ch1, 950,2100,0,255);
    motor1.writeMicroseconds(1600);
    delay(10);
   }
   }
}
