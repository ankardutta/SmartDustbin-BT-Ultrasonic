// #include <SoftwareSerial.h>
#include <Servo.h>
#include <SoftwareSerial.h>
const int servoPin = 8;
Servo myServo;
const int trigPin = 12;
const int echoPin = 13;
long duration, distance;
char incoming_value;
// int led = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // bluetooth.begin(9600);
  myServo.attach(servoPin);
  // myServo.write(0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
    if (distance < 20) {
    myServo.write(90); // Adjust the angle as needed
  } else {
    myServo.write(0); // Close the lid if no object is detected
  }
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    incoming_value = Serial.read();
    Serial.println(incoming_value);

  // if (bluetooth.available()) {
  //   char incoming_value = bluetooth.read();
    
    // If 'O' is received, open the lid
    if (incoming_value == 'O') {
      myServo.write(90);
    }
    // If 'C' is received, close the lid
    else if (incoming_value == 'C') {
      myServo.write(0);
    }
  }

  // Small delay to prevent reading errors
  // delay(10);
  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // duration = pulseIn(echoPin, HIGH);
  // distance = duration * 0.034 / 2;
  //   if (distance < 20) {
  //   myServo.write(90); // Adjust the angle as needed
  // } else {
  //   myServo.write(0); // Close the lid if no object is detected
  // }
}
  // if (incoming_value == 'A')
  //   digitalWrite(13, HIGH);
  // else if (incoming_value == 'B')
  //   digitalWrite(13, LOW);
//   }
// }