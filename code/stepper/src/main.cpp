#include <Arduino.h>

//#include <Stepper.h>
//
//
//const int stepsPerRevolution = 64;  // change this to fit the number of steps per revolution
//// for your motor
//
//// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution, PA8, PA9, PA10, PA11);
//
void setup() {
    Serial.begin(9600);
//    // set the speed at 60 rpm:
//    myStepper.setSpeed(60);
//    // initialize the serial port:
//    Serial.begin(9600);
}

//
void loop() {
    Serial.println("test");
    delay(100);
//    // step one revolution  in one direction:
//    Serial.println("clockwise");
//    myStepper.step(stepsPerRevolution);
//    delay(500);
//
//    // step one revolution in the other direction:
//    Serial.println("counterclockwise");
//    myStepper.step(-stepsPerRevolution);
//    delay(500);
}

