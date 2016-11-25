#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX
char ch=' ';


//motor 1
int enL = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enR = 5;
int in3 = 7;
int in4 = 6;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  
  
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
mySerial.begin(9600);


}


void start()

{
Serial.println("Start FUNC");
  digitalWrite(in1,HIGH);

  digitalWrite(in2,LOW);

  digitalWrite(in3,HIGH);

  digitalWrite(in4,LOW);

  analogWrite(enL,230);

  analogWrite(enR,255);

}



void right()

{
Serial.println("RIGHT   FUNC");
  digitalWrite(in1,HIGH);

  digitalWrite(in2,LOW);

  analogWrite(enL,240);

  

  digitalWrite(in3,HIGH);

  digitalWrite(in4,LOW);

  analogWrite(enR,120);

}



void left()

{
Serial.println("LEFT  FUNC");
 

  digitalWrite(in3,HIGH);

  digitalWrite(in4,LOW);
 analogWrite(enR,190);


  digitalWrite(in1,HIGH);

  digitalWrite(in2,LOW);

  analogWrite(enL,90);

}

void brake()

{
Serial.println("BRAKE   FUNC");
  analogWrite(enL,0);

  analogWrite(enR,0);

}



void reverse()

{
Serial.println("REVERSE  FUNC");
  digitalWrite(in1,LOW);

  digitalWrite(in2,HIGH);

  digitalWrite(in3,LOW);

  digitalWrite(in4,HIGH);

  analogWrite(enL,105);

  analogWrite(enR,150);

}
void loop(){
if (mySerial.available()){
  ch=mySerial.read(); 
Serial.println(ch);
if(ch=='0'){
brake();
}
if(ch=='1'){
  Serial.println("Start the motors");
start();
}
if(ch=='2'){
Serial.println("reverse");
reverse();

}
if(ch=='3'){
  Serial.println("left");
left();
}
if(ch=='4'){
  Serial.println("right");
right();
}
}

  
}
