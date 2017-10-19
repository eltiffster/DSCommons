//Point Arduino to some code libraries we need
#include <Boards.h>
#include <Firmata.h>
#include <PCM.h>

const unsigned char sample[] PROGMEM = {
  //Paste the converted sound file here
};

int sensorPin = A0;
int sensorValue = 0;
int threshold = 100;

//set variables for colours and corresponding pins
int redPin = 10;
int greenPin = 9;
int bluePin = 8;
int redPin2 = 6;
int greenPin2 = 5;
int bluePin2 = 4;

void setup() {
  Serial.begin(9600);

  //Set input and output pins
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(redPin2,OUTPUT);
  pinMode(greenPin2,OUTPUT);
  pinMode(bluePin2,OUTPUT);
  pinMode(sensorPin,INPUT);
}

void loop()
{
  //Read the sensor value and print it to the serial monitor
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print ("\n");

  //Check if the box is open by using the sensor to detect ambient light
  if(sensorValue > threshold){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,HIGH);
    digitalWrite(redPin2,HIGH);
    digitalWrite(greenPin2,HIGH);
    digitalWrite(bluePin2,HIGH);
  //You can change the colour of the eyes. Google "rgb color picker" and
    //then replace the values below with the ones you want.
  setColor(255, 0, 0);  // red
  //Or you can change the colour to the colours below by uncommenting 
    //the line and commenting out the above setColor line with //
  //setColor(0, 255, 0);  // green
  //setColor(0, 0, 255);  // blue
  //setColor(255, 255, 0);  // yellow
  //setColor(80, 0, 80);  // purple
  //setColor(0, 255, 255);  // aqua
  }
  else {
      digitalWrite(redPin,LOW);
      digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,LOW);
      digitalWrite(redPin2,LOW);
      digitalWrite(greenPin2,LOW);
      digitalWrite(bluePin2,LOW);
      startPlayback(sample, sizeof(sample));
  }
}

//A function to change the pin colours
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(redPin2, red);
  analogWrite(greenPin, green);
  analogWrite(greenPin2, green);
  analogWrite(bluePin, blue);
  analogWrite(bluePin2, blue);    
}
