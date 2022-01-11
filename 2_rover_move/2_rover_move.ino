/*
  motor control
  This example code is in the public domain.
  rb-station.com
*/
// 前後運動と回転、スピード調整のサンプル
#define LEFTPOWER 10
#define LEFTDIR 12
#define RIGHTPOWER 11
#define RIGHTDIR 13

void setup() {
  pinMode(LEFTPOWER, OUTPUT);
  pinMode(LEFTDIR, OUTPUT);
  pinMode(RIGHTPOWER, OUTPUT);
  pinMode(RIGHTDIR, OUTPUT);
}

void loop() {
  setSpeed(100,100); //前進
  delay(2000);

  setSpeed(100, -100); //その場で回転
  delay(2000);

  setSpeed(-100,-100); //後退
  delay(2000);

  setSpeed(100,200); //曲がりながら前進
  delay(2000);

  setSpeed(-200,100); //曲がりながら後退
  delay(2000);

  setSpeed(0,0); //停止
  delay(5000);

}

// left/rightともに-255〜255の整数値を取る
void setSpeed(int left, int right){
  if(left > 0){
    digitalWrite(LEFTDIR,LOW);
  }else{
    digitalWrite(LEFTDIR,HIGH);
  }

  // モーターは左右逆向きについているので、モータ線の並びが同じ場合は向きは逆にする
  if(right > 0){
    digitalWrite(RIGHTDIR,HIGH);
  }else{
    digitalWrite(RIGHTDIR,LOW);
  }

  analogWrite(LEFTPOWER, abs(left));
  analogWrite(RIGHTPOWER, abs(right));
}
