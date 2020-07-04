#include "TM1637.h"

const int MTR1 = 5;
const int MTL1 = 6;
const int MTR2 = 9;
const int MTL2 = 10;

const int CLK = 15;
const int DIO = 14;

TM1637 sevenSegment(CLK, DIO);

void setup(){
    pinMode (MTR1,OUTPUT);
    pinMode (MTL1,OUTPUT);
    pinMode (2,INPUT_PULLUP);
    pinMode (8,OUTPUT);
    sevenSegment.init();
    tone(8,400,800);
    Serial.println("Hello MDT !!");
}

int Speed = 0;
int X;
void loop(){
    Serial.println("Turn CCW");
    digitalWrite(MTL1,1);
    digitalWrite(MTR1,0);
    delay(3000);
    digitalWrite(MTL1,0);
    digitalWrite(MTR1,0);
    delay(3000);

    Serial.println("Turn CW");
    digitalWrite(MTL1,0);
    digitalWrite(MTR1,1);
    delay(2000);
    digitalWrite(MTL1,0);
    digitalWrite(MTR1,0);
    
    sevenSegment.displayNum(0000);
    delay(600);
    sevenSegment.displayStr("    ");

    delay(300);
    tone(8,400,900);
    
    for (X = 0; X <= 100 ; X++){
        sevenSegment.displayNum(0);
        if (digitalRead(2)==0){
            tone(8,200,800);
            digitalWrite(MTR1,Speed + 51);
            sevenSegment.displayNum(20);
            if(digitalRead(2)==0){
                tone(8,200,800);
                digitalWrite(MTR1,Speed + 102);
                sevenSegment.displayNum(40);
                if(digitalRead(2)==0){
                    tone(8,200,800);
                    digitalWrite(MTR1,Speed + 153);
                    sevenSegment.displayNum(60);
                    if(digitalRead(2)==0){
                        tone(8,200,800);
                        digitalWrite(MTR1,Speed + 204);
                        sevenSegment.displayNum(80);
                        if(digitalRead(2)==0){
                            tone(8,200,800);
                            digitalWrite(MTR1,Speed + 255);
                            sevenSegment.displayNum(100);
                            
                        }
                    }
                }
            }
        }
    }
    
    for (X = 100 ; X > 0; X--){
        digitalWrite(MTR1,Speed + 255);
        sevenSegment.displayNum(100);
        if (digitalRead(2)==0){
            tone(8,200,800);
            digitalWrite(MTR1,Speed + 204);
            sevenSegment.displayNum(80);
            if(digitalRead(2)==0){
                tone(8,200,800);
                digitalWrite(MTR1,Speed + 153);
                sevenSegment.displayNum(60);
                if(digitalRead(2)==0){
                    tone(8,200,800);
                    digitalWrite(MTR1,Speed + 102);
                    sevenSegment.displayNum(40);
                    if(digitalRead(2)==0){
                        tone(8,200,800);
                        digitalWrite(MTR1,Speed + 51);
                        sevenSegment.displayNum(20);
                        if(digitalRead(2)==0){
                            tone(8,200,800);
                            digitalWrite(MTR1,Speed);
                            sevenSegment.displayNum(0);
                        }
                    }
                }
            }
        }
    }
}
