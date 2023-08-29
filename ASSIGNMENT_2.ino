#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int echo = 2;
int trig = 3;
int buzzer = 4;
int green = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(buzzer,255);
  digitalWrite(trig, HIGH);
  delay(200);
  digitalWrite(trig, LOW);
  int period = pulseIn(echo, HIGH);
  int distance = (period / 2) / 29.1;
  if (distance <=46 && distance >=0){
  Serial.println("OBJECT APPROACHING");
  }
  Serial.print("OBJECT DISTANCE =");
  Serial.println(distance);
  if (distance <=46 && distance >=0) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    delay(1000);
  }
  if (distance <= 46 && distance >= 0) {
    digitalWrite(green, HIGH);

  }
  else {
    digitalWrite(green, LOW);
  }

}
