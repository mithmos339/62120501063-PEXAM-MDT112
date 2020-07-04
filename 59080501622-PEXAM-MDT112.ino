const int MTR1 = 5;
const int MTL1 = 6;
const int MTR2 = 9;
const int MTL2 = 10;

void setup(){
    Serial.begin(9600);
    pinMode(8,OUTPUT);
    tone(8,400,800);
    Serial.println("Hello MDT !!")
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop(){
    Serial.println("Turn CCW");
    analogWrite(MTL1,1);
    analogWrite(MTR1,0);
    delay(3000);
    analogWrite(MTL1,0);
    analogWrite(MTR1,0);
}
