





#include <AccelStepper.h>


const int xyEn = 14;
const int zEn = 26;

const int xDir = 21;
const int xStep = 15;
const int yDir = 23;
const int yStep = 22;
const int zDir = 2;
const int zStep = 3;
const int eDir = 0;
const int eStep = 1;

int pace = 600;
int zip = 200;
int dataIn;
int m;


// Define some steppers and the pins the will use
AccelStepper LFwheel(1, yStep, yDir);  // (Type:driver, STEP, DIR)
AccelStepper RFwheel(1, eStep, eDir );
AccelStepper LRwheel(1, xStep, xDir );
AccelStepper RRwheel(1, zStep, zDir );


void setup()
{  
    pinMode(xyEn, HIGH);
    pinMode(zEn, HIGH);
  
    LFwheel.setMaxSpeed(pace);
    LFwheel.setAcceleration(zip);
    //LFwheel.moveTo(1000000);
    
    RFwheel.setMaxSpeed(pace);
    RFwheel.setAcceleration(zip);
   // RFwheel.moveTo(7000);

    LRwheel.setMaxSpeed(pace);
    LRwheel.setAcceleration(zip);

    RRwheel.setMaxSpeed(pace);
    RRwheel.setAcceleration(zip);

    Serial.begin(9600);
    Serial1.begin(9600);
    Serial.println("setup complete");
    //pwrChk();
    
    
}

void loop()
{
      
    RRwheel.runSpeed();
    LRwheel.runSpeed();
    LFwheel.runSpeed();
    RFwheel.runSpeed();
    
    look();

    switch (m){
      case 8:
        moveForw();
       break;

      case 0:
        rotLeft();
       break;

      case 9:
        forwRight();
       break;
       
      case 7:
        forwLeft();
       break;
       
      case 4:
        moveLeft();
       break;

      case 6:
        moveRight();
       break;

      case 1:
        backLeft();
       break;

      case 3:
        backRight();
       break;

      case 2:
        moveBack();
       break;
       
      case 5:
        rotRight();
       break;
      





      default:
        stap();
       break;  
    }
  //pwrChk();

}




void moveForw(){
  Serial.println("moving forward");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(pace);
  }
void moveBack(){
  Serial.println("moving backward");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(-pace);
  }
void moveLeft(){
  Serial.println("moving left");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(pace);
  }
void moveRight(){
  Serial.println("moving right");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(-pace);
  }
void rotLeft(){
  Serial.println("rotating left");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(-pace);
  }
void rotRight(){
  Serial.println("rotating right");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(pace);
  }
void forwLeft(){
  Serial.println("forward leftishly");
  LFwheel.setSpeed(0);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(0);
  LRwheel.setSpeed(pace);
  }
void forwRight(){
  Serial.println("forward rightish");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(0);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(0);
  }
void backLeft(){
  Serial.println("back leftish");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(0);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(0);
  }
void backRight(){
  Serial.println("back right");
  LFwheel.setSpeed(0);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(0);
  LRwheel.setSpeed(-pace);
  }

void stap(){
  LFwheel.setSpeed(0);
  RFwheel.setSpeed(0);
  RRwheel.setSpeed(0);
  LRwheel.setSpeed(0);
  }


void pwrChk(){
  // Monitor the battery voltage
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.00) * 3; // Convert the reading values from 5v to suitable 12V i
  Serial.println(voltage);
  // If voltage is below 11V turn on the LED
  if (voltage < 11) {
  
   }
  }

void look(){
  if (Serial1.available() > 0) {
    Serial.println("reading serial");
    dataIn = Serial1.read();
    Serial.println(dataIn);
    m = dataIn - 48;
    /*if (dataIn == 48) {
      m = 0;
    }
    if (dataIn == 1) {
      m = 1;
    }
    if (dataIn == 50) {
      m = 2;
    }
    if (dataIn == 3) {
      m = 3;
    }
    if (dataIn == 4) {
      m = 4;
    }
    if (dataIn == 5) {
      m = 5;
    }
    if (dataIn == 6) {
      m = 6;
    }
    if (dataIn == 7) {
      m = 7;
    }
    if (dataIn == 56) {
      m = 8;
    }
    if (dataIn == 9) {
      m = 9;
    }
    if (dataIn == 10) {
      m = 10;
    }
    if (dataIn == 11) {
      m = 11;
    }
    if (dataIn == 12) {
      m = 12;
    }
    if (dataIn == 14) {
      m = 14;
    }
*/
   }
   
  }
