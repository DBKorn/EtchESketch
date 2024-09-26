#include <wiringPi.h> 
#include <stdio.h> 
#include <softPwm.h> 
#include <math.h> 
#include <stdlib.h> 
#include "ads7830.h"

//ads7830 input pins to read joystick motions
#define Y_PIN 0
#define X_PIN 1

//define the pins connected to L293D
#define xMotorPin1    2  
#define xMotorPin2    0 
#define xEnablePin    3 
#define yMotorPin1    21  
#define yMotorPin2    22 
#define yEnablePin    23

 
//Map function: map the value from a range to another range. 
long map(long value,long fromLow,long fromHigh,long toLow,long toHigh){ 
    return (toHigh-toLow)*(value-fromLow) / (fromHigh-fromLow) + toLow; 
} 
//motor function: determine the direction and speed of the motor according to the ADC  
void motor(int xVal, int yVal){ 
    //The joystick ranges from 0-255
    xVal -= 126; 
    yVal -= 126;
    //joystick is not super precise, so we have a small amount of 'give'
    int errorMargin = 2; 
    if(xVal > errorMargin){ 
        digitalWrite(xMotorPin1,HIGH); 
        digitalWrite(xMotorPin2,LOW); 
        printf("turn Forward...\n"); 
    } 
    else if (xVal < -errorMargin){ 
        digitalWrite(xMotorPin1,LOW); 
        digitalWrite(xMotorPin2,HIGH); 
        printf("turn Back...\n"); 
    } 
    else { 
        digitalWrite(xMotorPin1,LOW);  
        digitalWrite(xMotorPin2,LOW); 
        printf("Motor Stop...\n"); 
    } 

    if(yVal > errorMargin){ 
        digitalWrite(yMotorPin1,HIGH); 
        digitalWrite(yMotorPin2,LOW); 
        printf("turn Forward...\n"); 
    } 
    else if (yVal < -errorMargin){ 
        digitalWrite(yMotorPin1,LOW); 
        digitalWrite(yMotorPin2,HIGH); 
        printf("turn Back...\n"); 
    } 
    else { 
        digitalWrite(yMotorPin1,LOW);  
        digitalWrite(yMotorPin2,LOW); 
        printf("Motor Stop...\n"); 
    } 
    softPwmWrite(xEnablePin,map(abs(xVal),0,128,0,100)); 
    softPwmWrite(yEnablePin,map(abs(yVal),0,128,0,100)); 
} 
int main(void){ 
     
    wiringPiSetup(); 
    ads7830Init(0x4b);
    //set mode for the pin
    pinMode(xEnablePin,OUTPUT); 
    pinMode(xMotorPin1,OUTPUT); 
    pinMode(xMotorPin2,OUTPUT); 
    pinMode(yEnablePin,OUTPUT);
    pinMode(yMotorPin1,OUTPUT); 
    pinMode(yMotorPin2,OUTPUT); 
    //define PMW pin
    softPwmCreate(xEnablePin,0,100); 
    softPwmCreate(yEnablePin,0,100); 
    while(1){ 
        int yVal = adsAnalogRead(Y_PIN); 
        int xVal = adsAnalogRead(X_PIN);
        printf("X value : %d --- Y value :%d\n",xVal, yVal); 
        motor(xVal, yVal);
        delay(100); 
    } 
    return 0; 
} 
