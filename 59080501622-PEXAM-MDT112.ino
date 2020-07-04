#include "TM1637.h"

const int MTR1 = 5;
const int MTL1 = 6;
const int MTR2 = 9;
const int MTL2 = 10;

const int CLK = 15;
const int DIO = 14;

bool good = false;

TM1637 sevenSegment(CLK, DIO);

void setup(){
    sevenSegment.init();
    pinMode(2,INPUT_PULLUP);
    pinMode(8,OUTPUT);
    tone(8,400,800);
    Serial.println("Hello MDT !!")
    pinMode(MTR1,OUTPUT);
    pinMode(MTL1,OUTPUT);
    pinMode(MTR2,OUTPUT);
    pinMode(MTL2,OUTPUT);
    Serial.begin(9600);

}
int Speed = 0;
int X;
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
    sevenSegment.displayStr("    ");

    delay(300);
    tone(8,400,900);
    
    for (X = 0; X <= 100 ; x++){
        sevenSegment.displayNum(0);
        if (digitalRead(2)==0){
            tone(8,200,800);
            analogWrite(MTR2,Speed + 51);
            sevenSegment.displayNum(20);
            if(digitalRead(2)==0){
                tone(8,200,800);
                analogWrite(MTR2,Speed + 102);
                sevenSegment.displayNum(40);
                if(digitalRead(2)==0){
                    tone(8,200,800);
                    analogWrite(MTR2,Speed + 153);
                    sevenSegment.displayNum(60);
                    if(digitalRead(2)==0){
                        tone(8,200,800);
                        analogWrite(MTR2,Speed + 204);
                        sevenSegment.displayNum(80);
                        if(digitalRead(2)==0){
                            tone(8,200,800);
                            analogWrite(MTR2,Speed + 255);
                            sevenSegment.displayNum(100);
                            
                        }
                    }
                }
            }
        }
    }
    
    for (X = 100 ; X > 0; X--){
        analogWrite(MTR2,Speed + 255);
        sevenSegment.displayNum(100);
        if (digitalRead(2)==0){
            tone(8,200,800);
            analogWrite(MTR2,Speed + 204);
            sevenSegment.displayNum(80);
            if(digitalRead(2)==0){
                tone(8,200,800);
                analogWrite(MTR2,Speed + 153);
                sevenSegment.displayNum(60);
                if(digitalRead(2)==0){
                    tone(8,200,800);
                    analogWrite(MTR2,Speed + 102);
                    sevenSegment.displayNum(40);
                    if(digitalRead(2)==0){
                        tone(8,200,800);
                        analogWrite(MTR2,Speed + 51);
                        sevenSegment.displayNum(20);
                        if(digitalRead(2)==0){
                            tone(8,200,800);
                            analogWrite(MTR2,Speed);
                            sevenSegment.displayNum(0);
                        }
                    }
                }
            }
        }
    }




    



}
