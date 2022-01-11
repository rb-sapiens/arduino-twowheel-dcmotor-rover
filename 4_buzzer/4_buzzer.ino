
#define BUZZER 4

void setup() {
  pinMode(BUZZER, OUTPUT);

  buzzer(2800,200);
  buzzer(3200,200);
  buzzer(4000,200);
}

void loop() {
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
