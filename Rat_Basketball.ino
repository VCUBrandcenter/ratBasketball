//Matt Reamer / Elyse Jalbert / Soheil Oliaei - Rat Basketball / Brandcenter Fall 2013

#include <Servo.h>

#define ON LOW
#define OFF HIGH
#define SERVO_PIN 9    // sets servo to analog pin 1

int count = 0; // current display count
int buzzer = 12;      // buzzer to pin 12
int ledPin1 = 13;    // LED in pin 13
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellValue;     // the analog reading from the sensor
int pos = 0;    // variable to store the servo position

Servo myservo;  // create servo object to control the gumball machine

void setup(){
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);  // attaches the servo to analog pin 1
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(photocellPin, INPUT);
  zero();
}

void loop() {
  photocellValue = analogRead(photocellPin);
    Serial.print("Analog reading = ");
    Serial.println(photocellValue);     // the raw analog reading
    
      // photocellValue = 1023 - photocellValue;
       
    if (photocellValue > 430) {
      count++;
      //if (count == 9) {
      //  count = 0;
      //} 
    }
    delay(50);
    switch (count) {
      case 0:
        startGame();
        zero();
        Serial.print("LED Reads 0");
        break;
      case 1:
        one();
        Serial.print("LED Reads 1");
        break;
      case 2:
        two();
        Serial.print("LED Reads 2");
        break;
      case 3:
        three();
        Serial.print("LED Reads 3");
        break;
      case 4:
        four();
        Serial.print("LED Reads 4");
        break;
      case 5:
        five();
        Serial.print("LED Reads 5");
        break;
      case 6:
        six();
        Serial.print("LED Reads 6");
        break;
      case 7:
        seven();
        Serial.print("LED Reads 7");
        break;
      case 8:
        eight();
        Serial.print("LED Reads 8");
        break;
      case 9: {
        nine();
        Serial.print("LED Reads 9");
        endGame();
        count = 0;
        break;
      }
    }
  }

void zero(){
// 0
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
}

void one(){
// 1
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
}

void two(){
// 2
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
}

void three(){
// 3
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
}

void four(){
// 4
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
}

void five(){
// 5
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
}

void six(){
// 6
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
}

void seven(){
// 7
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
}

void eight(){
// 8
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
}

void nine(){
// 9
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
}
  
  
void endGame (){
// end of game do these functions and return 7 segment LED to 0
        Serial.print("You Win");              // tell serial to print "You Win" when button is hit 
        digitalWrite(ledPin1, HIGH);      // LED turns on when 9 is reached
        digitalWrite(buzzer, HIGH);       // Buzzer turns on to open servo
        myservo.write(179);              // tell servo to go to 179
        delay(3000);                       // waits 15ms to allow grabbing of candy
  }
        

void startGame(){
//turns servo back to starting position
         Serial.print("Set To Original");   // states that the game has started and everything has been set back
         myservo.write(0);           // tell servo to go back to original position
         digitalWrite(ledPin1, LOW);      // LED turns off
         digitalWrite(buzzer, LOW);       // Buzzer stops as servo closes
         // delay(15);             // waits 15ms for the servo to reach the position 
}


