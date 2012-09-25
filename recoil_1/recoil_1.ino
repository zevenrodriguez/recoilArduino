#include <Servo.h>

Servo redServo;
int redPos = 0;
boolean redServoReady = false;


long redSavedTime = 0;
long redTotalTime = 0;

long bluePassedTime = 0;
long blueSavedTime = 0;
long blueTotalTime = 0;

long greenPassedTime = 0;
long greenSavedTime = 0;
long greenTotalTime = 0;

long whitePassedTime = 0;
long whiteSavedTime = 0;
long whiteTotalTime = 0;

int randomMax = 5;
int randomMin = 10;

boolean redLight = true;

void setup(){

  randomSeed(analogRead(0));
  redServo.attach(2);
  /*
  redTotalTime = random(randomMax,randomMin) * 1000;
   blueTotalTime = random(randomMax,randomMin) * 1000; 
   greenTotalTime = random(randomMax,randomMin) * 1000;
   whiteTotalTime = random(randomMax,randomMin) * 1000;
   */
  redTotalTime = 10000;

  Serial.begin(9600);

  establishContact();  
  /*
  Serial.print("red: ");
   Serial.println(redTotalTime);
   
   Serial.print("blue: ");
   Serial.println(blueTotalTime);
   
   Serial.print("green: ");
   Serial.println(greenTotalTime);
   
   Serial.print("white: ");
   Serial.println(whiteTotalTime);
   */


}


void loop(){

  launch();

}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.write(9);   // send a capital A
  }
}



void launch(){
  //Red Section 

  if(Serial.read() == 5){ 

    redLight = true;


  }
  if(redLight == true ){
    int redPassedTime = millis() - redSavedTime;

    if (redPassedTime > redTotalTime) {

      //redServoReady = redServoMove();
      redServoMove();
      //if (redServoReady == true){
        for(int i = 0; i<10; i++){
          Serial.write(1);
      //  }
      }
      redSavedTime = millis();
      redLight = false;

    }

  }
  /*
  //Blue Section  
   int bluePassedTime = millis() - blueSavedTime;
   
   if (bluePassedTime > blueTotalTime) {
   
   //Serial.println("blue");
   Serial.write(2);
   
   blueSavedTime = millis();
   
   
   }
   else{
   
   Serial.write(10); 
   
   }
   
   //Green Section  
   int greenPassedTime = millis() - greenSavedTime;
   
   if (greenPassedTime > greenTotalTime) {
   
   // Serial.println("green");
   Serial.write(3);
   
   greenSavedTime = millis();
   
   }else{
   
   Serial.write(10); 
   
   }
   
   //White Section  
   int whitePassedTime = millis() - whiteSavedTime;
   
   if (whitePassedTime > whiteTotalTime) {
   
   //Serial.println("white");
   Serial.write(4);
   
   whiteSavedTime = millis();
   
   
   
   }else{
   
   Serial.write(10); 
   
   }
   */

}




boolean redServoMove(){

  redServo.write(0);
  delay(500);
  for(redPos = 0; redPos < 45; redPos += 1)  // goes from 0 degrees to 180 degrees 
  {  
    redServo.write(redPos);
    delay(10);
  }

  for(redPos = 45; redPos>=1; redPos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    redServo.write(redPos);              // tell servo to go to redPosition in variable 'redPos' 
    delay(15);                       // waits 15ms for the servo to reach the redPosition 
  }

  for(redPos = 0; redPos < 90; redPos += 1)  // goes from 0 degrees to 180 degrees 
  {  
    redServo.write(redPos);
    delay(5);
  }

  delay(1000);

  return true;

}










