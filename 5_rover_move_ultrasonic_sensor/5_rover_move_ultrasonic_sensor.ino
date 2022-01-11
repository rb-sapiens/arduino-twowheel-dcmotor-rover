/*
  motor control
  This example code is in the public domain.
  rb-station.com
*/
// 障害物を避けながら走るサンプル
#define LEFTPOWER 10
#define LEFTDIR 12
#define RIGHTPOWER 11
#define RIGHTDIR 13

#define BUZZER 4
#define TRIG 3
#define ECHO 2

double Duration = 0; //受信した間隔
double Distance = 0; //距離

void setup() {
  pinMode(LEFTPOWER, OUTPUT);
  pinMode(LEFTDIR, OUTPUT);
  pinMode(RIGHTPOWER, OUTPUT);
  pinMode(RIGHTDIR, OUTPUT);
  Serial.begin( 9600 );

  pinMode(BUZZER, OUTPUT);
  pinMode(ECHO, INPUT );
  pinMode(TRIG, OUTPUT );

  buzzer(2800,200);
  buzzer(3200,200);
  buzzer(4000,200);
}

void loop() {
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); 
  digitalWrite( TRIG, HIGH ); //超音波を出力
  delayMicroseconds( 10 ); //
  digitalWrite( TRIG, LOW );
  Duration = pulseIn( ECHO, HIGH ); //センサからの入力
  if (Duration > 0) {
    Duration = Duration/2;
    Distance = Duration*340*100/1000000;
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
  }

  if (Distance < 40){
    setSpeed(100, -100);
  }else if(Distance < 60){
    setSpeed(100, -20);
  }else{
    setSpeed(150,150);
  }
  delay(200);
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

// freq: frequency of buzzer [hz]
// duration: buzzer duration [ms]
void buzzer(long freq, long duration){
  long delaymicrosec = 1000000 / freq / 2;
  long count = freq * duration / 1000 / 2;

  for (int i = 0; i < count; i++){
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(delaymicrosec);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(delaymicrosec);
  }
}
