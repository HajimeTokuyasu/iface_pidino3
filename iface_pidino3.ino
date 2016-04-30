enum {
  STEER_MOVE_PIN,
  STEER_DIR_PIN,
  LINEAR_MOVE_PIN,
  LINEAR_DIR_PIN
}

enum {
  CW = LOW,
  CCW = HIGH
}

enum {
  FRONT = LOW,
  BACK = HIGH
}

enum {
  CW_PIN,//2
  CCW_PIN,//3
  ACCEL_PIN = 8,
  BACK_GEAR_PIN//9
}

void setup(){
  //pinMode(, INPUT);
  //pinMode(, OUTPUT);
}

void loop(){
  if (!digitalRead(STEER_MOVE_PIN)) {
    digitalWrite(CW_PIN, LOW);
    digitalWrite(CCW_PIN, LOW);
  } else {
    switch (digitalRead(STEER_DIR_PIN)) {
    case CW:
      digitalWrite(CW_PIN, HIGH);
      delay(STEER_TIME);
      digitalWrite(CW_PIN, LOW);
    case CCW:
      digitalWrite(CW_PIN, HIGH);
      delay(STEER_TIME);
      digitalWrite(CW_PIN, LOW);
    }
  }

  if (!digitalRead(LINEAR_MOVE_PIN)) {
    analogWrite(ACCEL_PIN, 0);
  } else {
    switch (digitalRead(LINEAR_DIR_PIN)) {
    case FRONT:
      if (digitalRead(BACK_PIN)) {
        analogWrite(ACCEL_PIN, 0);
        delay(500);
        digitalWrite(BACK_PIN, LOW);
        delay(200)
      }
      analogWrite(ACCEL_PIN, speed);
      break;

    case BACK:
      if (!digitalRead(BACK_PIN)) {
        digitalWrite(CW_PIN, HIGH);
        delay(STEER_TIME);
        digitalWrite(CW_PIN, LOW);
      }
      analogWrite(ACEEL_PIN, speed);
      break;
    }
  }
}
