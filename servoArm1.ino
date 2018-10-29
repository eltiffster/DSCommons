/*
Rise from the Dead!
Moves a servo motor-powered arm up and down.

Created by Tiffany Chan for the UVic Frankenweek 2018 Workshop
updated 5 Oct 2017

Based on Sweep by Tom Igoe.

*/

#include <Servo.h> 

Servo servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
int sensorPin = A0;    // select the input pin for the photoresistor
int sensorValue = 0;  // variable to store the value coming from the sensor
int threshold = 100;  // threshold at which to turn the LEDs on or off
                      // (you can tweak this value if needed)

void setup() {
  Serial.begin(9600); //start serial Monitor. This lets you keep track of
                        //what value is coming from the photoresistor.
  servo.attach(9);  // attaches the servo on pin 9 to the servo object

// Rise and then stop
  servo.write(100);
  delay(800);
  servo.write(90);

  
}

void loop() {

  // read the light sensor on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value:
  Serial.println(sensorValue);

// Wave slowly
//  wave();

}

void wave() {
 
  bool goingUp = true;
  servo.write(105);
  delay(600);
  goingUp = false;

  if (goingUp == true) {
    servo.write(95);
    delay(1500);
    goingUp = false;
  }
  else {
    servo.write(85);
    delay(1500);
    goingUp = true;
  }

}

void rise() {
  servo.write(100);
  delay(800);
  servo.write(90);
}

