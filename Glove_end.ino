/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12); // RX, TX


const int analogInPin1 = A0;//thumb
const int analogInPin2 = A1;//
const int analogInPin3 = A2;
const int analogInPin4 = A3;
const int outPin1 = 13;//5v
const int outPin2 = 10;//0v

const int outPin3=9;//0
const int outPin4=8;//5
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int outputValue1 = 0;  
int outputValue2 = 0;
int outputValue3 = 0;
int outputValue4 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Serial.println("Ready");

mySerial.begin(9600);
  
  pinMode(outPin1,OUTPUT);
  pinMode(outPin2,OUTPUT);
  pinMode(outPin3,OUTPUT);
  pinMode(outPin4,OUTPUT);
  digitalWrite(outPin1,1);
  digitalWrite(outPin2,0);
  digitalWrite(outPin3,0);
  digitalWrite(outPin4,1);
  
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  
  
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  sensorValue3 = analogRead(analogInPin3);
  sensorValue4 = analogRead(analogInPin4);
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue1, 130,300 ,255,0);
  outputValue2 = map(sensorValue2, 200, 360,255,0);
  outputValue3 = map(sensorValue3, 140, 380,255,0);
  outputValue4 = map(sensorValue4, 130, 320,255,0);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  /*Serial.print("sensor = ");
  Serial.print(sensorValue1);
  Serial.print("sensor = ");
  Serial.print(sensorValue2);
  Serial.print("sensor = ");
  Serial.print(sensorValue3);
  Serial.print("sensor = ");
  Serial.println(sensorValue4);*/
  /*if(outputValue1<0) outputValue1=0;
  if(outputValue2<0) outputValue2=0;
  if(outputValue3<0) outputValue3=0;
  if(outputValue4<0) outputValue4=0;
  if(outputValue1>100) outputValue1=100;
  if(outputValue2>100) outputValue2=100;
  if(outputValue3>100) outputValue3=100;
  if(outputValue4>100) outputValue4=100;*/
  Serial.print("\t output = ");
  Serial.print(outputValue1);
  Serial.print("\t output = ");
  Serial.print(outputValue2);
  Serial.print("\t output = ");
  Serial.print(outputValue3);
  Serial.print("\t output = ");
  Serial.println(outputValue4);
  if(outputValue1<100&&outputValue2<100&&outputValue3<100&&outputValue4<100){
  mySerial.write('0');
  }
   if(outputValue1>100&&outputValue2>100&&outputValue3>100&&outputValue4>100){
  mySerial.write('1');
  }
   if(outputValue1<100&&outputValue2<100&&outputValue3>100&&outputValue4>100){
  mySerial.write('2');
  }
   if(outputValue1<100&&outputValue2>100&&outputValue3>100&&outputValue4>100){
  mySerial.write('3');
  }
   if(outputValue1>100&&outputValue2<100&&outputValue3>100&&outputValue4>100){
  mySerial.write('4');
  }

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(200);
}
