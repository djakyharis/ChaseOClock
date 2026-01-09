// --------------------------------------------------
// PIN DEFINITIONS
// --------------------------------------------------
#define TRIG_PIN 5
#define ECHO_PIN 18
#define IR_PIN 27

// Motor kiri (ENA, IN1, IN2)
#define ENA 16
#define IN1 17
#define IN2 19

// Motor kanan (ENB, IN3, IN4)
#define ENB 4
#define IN3 21
#define IN4 22

#define BUZZER_PIN 23

// --------------------------------------------------
unsigned long alarmTime = 0;
bool alarmActive = false;

// --------------------------------------------------
// Ultrasonic Distance
// --------------------------------------------------
long readUltrasonic() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  long distance = duration * 0.034 / 2;
  return distance;
}

// --------------------------------------------------
// Motor Control (4 motor = 2 kiri paralel + 2 kanan paralel)
// --------------------------------------------------
void moveForward(int speedVal) {
  // Motor kiri
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedVal);

  // Motor kanan
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedVal);
}

void stopMotor() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// --------------------------------------------------
void buzzerOn() { digitalWrite(BUZZER_PIN, HIGH); }
void buzzerOff() { digitalWrite(BUZZER_PIN, LOW); }

// --------------------------------------------------
// SETUP
// --------------------------------------------------
void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(IR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotor();
  buzzerOff();

  // Alarm aktif 10 detik setelah boot
  alarmTime = millis() + 10000;
}

// --------------------------------------------------
// LOOP
// --------------------------------------------------
void loop() {
  long distance = readUltrasonic();
  int irVal = digitalRead(IR_PIN);

  if (!alarmActive && millis() >= alarmTime) {
    alarmActive = true;
  }

  if (alarmActive) {
    buzzerOn();

    // Jika pengguna mendekat < 30 cm -> robot lari
    if (distance < 30) {
      moveForward(200);  // speed 0–255
    } else {
      stopMotor();
    }

    // Alarm mati ketika IR tertutup
    if (irVal == LOW) {
      buzzerOff();
      stopMotor();
      alarmActive = false;
      delay(1500);
    }
  }

  delay(80);
}