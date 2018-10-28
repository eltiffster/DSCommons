/*
Monster Eyes with Sound
Lights up two LEDs when the photoresistor (light sensor) detects light
(i.e. the box has been opened).

Created by Tiffany Chan for the Halloweeen 2017 Workshop
updated 5 Oct 2017

Based on Analog Input by Tom Igoe
(http://www.arduino.cc/en/Tutorial/AnalogInput)

*/

//#include <PCM.h>
//const unsigned char sample[] PROGMEM = {
//  
//};

int sensorPin = A0;    // select the input pin for the photoresistor
int ledPin1 = 12;     // select pins for the LED eyes
int ledPin2 = 13;      
int sensorValue = 0;  // variable to store the value coming from the sensor
int threshold = 100;  // threshold at which to turn the LEDs on or off
                      // (you can tweak this value if needed)

void setup() {
Serial.begin(9600); //start serial Monitor. This lets you keep track of
                        //what value is coming from the photoresistor.
pinMode(13, OUTPUT); // pins 13 and 12 as output
pinMode(12, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(100); // value updated every 0.1 second.
  if (sensorValue < threshold){ //when the box is closed
    digitalWrite(ledPin1, LOW); //turn the LEDs off.
    digitalWrite(ledPin2, LOW);
  }
  else {
    digitalWrite(ledPin1, HIGH); //otherwise, turn the LEDs on.
    digitalWrite(ledPin2, HIGH);
//    startPlayback(sample, sizeof(sample));
//    delay(3000);
  }

}
