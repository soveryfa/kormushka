// Blocking.pde
// -*- mode: C++ -*-
//
// Shows how to use the blocking call runToNewPosition
// Which sets a new target position and then waits until the stepper has 
// achieved it.
//
// Copyright (C) 2009 Mike McCauley
// $Id: Blocking.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
AccelStepper stepper(8, IN1, IN3, IN2, IN4); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
int target = 0;
int led = 7; //порт диода
int dl = 5; // время задержки между импульсами для мотора
int p = 2; //buzzer
const int buttonPin = 4;     // the number of the pushbutton pin
int buttonState = 0;
void setup()
{  
    pinMode(p, OUTPUT); //объявляем пин как выход
    stepper.setMaxSpeed(2000.0);
    stepper.setAcceleration(100.0);
    
    Serial.begin(9600);
     pinMode(buttonPin, INPUT);
   

}

void loop()
{   

    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    light_on();
    sound_on();
    turn();
    sound(); 
    light_off();
    sound_off();
  } 
   if (buttonState == LOW) {
   
  } 
    
}

void turn()
{   
    target += 582;
    Serial.println(target);
    stepper.runToNewPosition(target);
    delay(2000);
    
}

void light_on() {
    digitalWrite(led, HIGH);
    delay(100);
}
void light_off() {
    digitalWrite(led, LOW);
    delay(100);
}

void sound() {
    tone (p, 3); //включаем на 500 Гц
    delay(100); //ждем 100 Мс
    tone(p, 1); //включаем на 1000 Гц
    delay(100); //ждем 100 Мс
}

 void sound_on() {
    tone (p, 4); //включаем на 500 Гц
    delay(100); //ждем 100 Мс
    }
  void sound_off() { 
    tone(p, 5); //включаем на 1000 Гц
    delay(100); //ждем 100 Мс
}
 
