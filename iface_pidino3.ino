#define TIME 500
#define SPD 125

enum {//IN
  STEER_MOVE_PIN = 4,
  STEER_DIR_PIN,//5
  LINEAR_MOVE_PIN,//6
  LINEAR_DIR_PIN//7
};

enum {
  CW = LOW,
  CCW = HIGH
};

enum {
  FRONT = LOW,
  BACK = HIGH
};

enum {//OUT
  CW_PIN = 2,
  CCW_PIN,//3
  BACK_GEAR_PIN = 8,
  ACCEL_PIN//9
};

void setup(){
  pinMode(STEER_MOVE_PIN, INPUT);
  pinMode(STEER_DIR_PIN, INPUT);
  pinMode(LINEAR_MOVE_PIN, INPUT);
  pinMode(LINEAR_DIR_PIN, INPUT);
  pinMode(CW_PIN, OUTPUT);
  pinMode(CCW_PIN, OUTPUT);
  pinMode(ACCEL_PIN, OUTPUT);
  pinMode(BACK_GEAR_PIN, OUTPUT);
}

void loop(){
  int steerDirPin;
  int counterDirPin;
  if (!digitalRead(STEER_MOVE_PIN)) {
    digitalWrite(CW_PIN, LOW);
    digitalWrite(CCW_PIN, LOW);
  } else {
    switch (digitalRead(STEER_DIR_PIN)) {
    case CW:
      steerDirPin = CW_PIN;
      counterDirPin = CCW_PIN;
      break; 
    case CCW:
      steerDirPin = CCW_PIN;
      counterDirPin = CW_PIN;
      break;
    }
    digitalWrite(counterDirPin, HIGH);
    digitalWrite(steerDirPin, HIGH);
    delayMicroseconds(TIME);
    digitalWrite(steerDirPin, LOW);
    delayMicroseconds(TIME);
    digitalWrite(counterDirPin, LOW);
  }

  if (!digitalRead(LINEAR_MOVE_PIN)) {
    analogWrite(ACCEL_PIN, 0);
  } else {
    switch (digitalRead(LINEAR_DIR_PIN)) {
    case FRONT:
      if (digitalRead(BACK_GEAR_PIN)) {
        analogWrite(ACCEL_PIN, 0);
        delay(TIME);
        digitalWrite(BACK_GEAR_PIN, LOW);
        delay(TIME);
      }
      analogWrite(ACCEL_PIN, SPD);
      break;

    case BACK:
      if (!digitalRead(BACK_GEAR_PIN)) {
        digitalWrite(CW_PIN, LOW);
        delay(TIME);
        digitalWrite(BACK_GEAR_PIN, HIGH);
      }
      analogWrite(ACCEL_PIN, SPD);
      break;
    }
  }
}
