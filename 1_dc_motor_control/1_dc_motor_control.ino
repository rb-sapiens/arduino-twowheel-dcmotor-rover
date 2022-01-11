/*
  motor control
  This example code is in the public domain.
  rb-station.com
*/
// 前後に移動を繰り返すサンプル
#define E1 10
#define M1 12
#define E2 11
#define M2 13

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
}

void loop() {
  digitalWrite(M1,HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, 100);
  analogWrite(E2, 100);

  delay(2000);

  digitalWrite(M1,LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 100);
  analogWrite(E2, 100);

  delay(2000);

}
