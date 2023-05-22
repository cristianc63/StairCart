            // WiFiNINA_Generic - Version: Latest 
#include <WiFiNINA_Generic.h>

 /*

*/
#include<Servo.h>

#include <Wire.h>


#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int enR = 3;   //These are the pins for our motor driver IC
int inAR = 4;
int inBR = 5;
int enL = 6;
int inAL = 7;
int inBL = 8;

Servo lefty;
Servo righty;


void setup(){
{
    righty.attach(10);
    lefty.attach(9);
    
}

{
  pinMode(enR, OUTPUT);
  pinMode(inAR, OUTPUT); 
  pinMode(inBR, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(inAL, OUTPUT); 
  pinMode(inBL, OUTPUT);
  Serial.begin(9600);    
  Dabble.begin(9600);      
}
}

void loop() {
Dabble.processInput();  
  
  if (GamePad.isUpPressed())       
  {
    Serial.println("Forward");
    analogWrite(enR, 255);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, HIGH);
    analogWrite(enL, 255);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, HIGH);
    goforward();
    
  }

  else if (GamePad.isDownPressed())
  {
    Serial.println("Backward");
    analogWrite(enR, 255);
    digitalWrite(inAR, HIGH);
    digitalWrite(inBR, LOW);
    analogWrite(enL, 255);
    digitalWrite(inAL, HIGH);
    digitalWrite(inBL, LOW);
    gobackwards();
  }

  else if (GamePad.isLeftPressed())
  {
    Serial.println("Left");
    analogWrite(enR, 255);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, HIGH);
    analogWrite(enL, 255);
    digitalWrite(inAL, HIGH);
    digitalWrite(inBL, LOW);
    turnleft();
  }

  else if (GamePad.isRightPressed())
  {
    Serial.println("Right");
    analogWrite(enR, 255);
    digitalWrite(inAR, HIGH);
    digitalWrite(inBR, LOW);
    analogWrite(enL, 255);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, HIGH);
    turnright();
  }
    
  else 
  {
    Serial.println("Stopped");
    analogWrite(enR, 0);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, LOW);
    analogWrite(enL, 0);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, LOW);
    
    dawarldo();
  }

}



//MOVEMENT 



void goforward(){

   righty.write(-180);
    
    lefty.write(180);
    
    delay(10);
  
}
    
void gobackwards(){
   righty.write(180);
   
    lefty.write(-180);
    
    delay(10);
  
}
    
void turnleft(){
   righty.write(-180);
   
   lefty.write(-180);
   
   delay(10);
  
}

void turnright(){
   righty.write(180);
  
   lefty.write(180);
  
   delay(10);
  
}

void dawarldo(){
   righty.write(90);
   
   lefty.write(90);
   
   delay(10);
}


