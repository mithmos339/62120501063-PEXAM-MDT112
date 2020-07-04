const int MTR1 = 5;
const int MTL1 = 6;
const int MTR2 = 9;
const int MTL2 = 10;

void setup(){
    Serial.begin(9600);
    pinMode(8,OUTPUT);
    tone(8,400,800);
    Serial.println("Hello MDT !!")
    pinMode(MTR1,OUTPUT);
    pinMode(MTL1,OUTPUT);
    pinMode(MTR2,OUTPUT);
    pinMode(MTL2,OUTPUT);

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
    
}
