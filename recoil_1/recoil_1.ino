

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

void setup(){

  randomSeed(analogRead(0));

  redTotalTime = random(randomMax,randomMin) * 1000;
  blueTotalTime = random(randomMax,randomMin) * 1000; 
  greenTotalTime = random(randomMax,randomMin) * 1000;
  whiteTotalTime = random(randomMax,randomMin) * 1000;

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
  int redPassedTime = millis() - redSavedTime;

  if (redPassedTime > redTotalTime) {

    //  Serial.println("red");
    //Start servo
    
    //is servo ready
    Serial.write(1);


    redSavedTime = millis();

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




void servoMove(int servo){
  
  //which servo do I move
  
  //move servo
  
 //run timer when done set to true

}




