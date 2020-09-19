





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



// Define some steppers and the pins the will use
AccelStepper LFwheel(1, yStep, yDir);  // (Type:driver, STEP, DIR)
AccelStepper RFwheel(1, zStep, zDir );
AccelStepper LRwheel(1, xStep, xDir );
//AccelStepper RRwheel(1, );


void setup()
{  
    pinMode(xyEn, HIGH);
    pinMode(zEn, HIGH);
  
    LFwheel.setMaxSpeed(200.0);
    LFwheel.setAcceleration(100.0);
    LFwheel.moveTo(1000000);
    
    RFwheel.setMaxSpeed(200.0);
    RFwheel.setAcceleration(100.0);
    RFwheel.moveTo(1000000);

/*    LRwheel.setMaxSpeed(200.0);
    LRwheel.setAcceleration(100.0);

    RRwheel.setMaxSpeed(200.0);
    RRwheel.setAcceleration(100.0);
 */   
    
}

void loop()
{
    // Change direction at the limits
    
    //LFwheel.run();
    RFwheel.run();
}
