#include "TM1637.h"

const int MTR1 = 5;
const int MTL1 = 6;
const int MTR2 = 9;
const int MTL2 = 10;

const int CLK = 15;
const int DIO = 14;

TM1637 sevenSegment(CLK, DIO);

void setup(){
    sevenSegment.init();
    pinMode(8,OUTPUT);
    tone(8,400,800);
    Serial.println("Hello MDT !!")
    pinMode(MTR1,OUTPUT);
    pinMode(MTL1,OUTPUT);
    pinMode(MTR2,OUTPUT);
    pinMode(MTL2,OUTPUT);
    Serial.begin(9600);

}

void loop(){
    Serial.println("Turn CCW");
    analogWrite(MTL1,1);
    analogWrite(MTR1,0);
    delay(3000);
    analogWrite(MTL1,0);
    analogWrite(MTR1,0);
    delay(3000);

    Serial.println("Turn CW");
    analogWrite(MTL2,0);
    analogWrite(MTR2,1);
    delay(2000);
    analogWrite(MTL2,0);
    analogWrite(MTR2,0);
    
    sevenSegment.displayNum(0000);
    delay(600);
    sevenSegment.clear();

}
