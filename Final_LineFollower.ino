// Sensors
#define LEFT_SNR 27
#define CENTER_SNR 26
#define RIGHT_SNR 28
// Motors
#define LEFT_MOTOR_FORWARD 8
#define LEFT_MOTOR_BACKWARD 9
#define RIGHT_MOTOR_FORWARD 10
#define RIGHT_MOTOR_BACKWARD 11

// PID Control and Speed Parameters
double Kp = 0.3;
double Ki = 0.0;
double Kd = 0.5;

int baseSpeed = 80;
int P, I, D, error, PreviousError = 0;
int LSp, RSp;

// Line Detection Threshold
int LineThreshold = 500;

void setup() {
  pinMode(LEFT_SNR, INPUT);
  pinMode(CENTER_SNR, INPUT);
  pinMode(RIGHT_SNR, INPUT);

  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
}

void loop() {
  int Left = analogRead(LEFT_SNR);
  int Center = analogRead(CENTER_SNR);
  int Right = analogRead(RIGHT_SNR);

  if (Left > LineThreshold && Center > LineThreshold && Right > LineThreshold) {
    motorDrive(0, 0);
    while (true);  // Stop Robot
  }

  // Position Calculation
  int position = readLineWeighted();
  error = 3500 - position;

  // PID Calculation
  P = error;
  I += error;
  D = error - PreviousError;
  PreviousError = error;

  float pidValue = Kp * P + Ki * I + Kd * D;
  // Calculates Speed For Each Motor
  LSp = constrain(baseSpeed - pidValue / 10, 0, 255);
  RSp = constrain(baseSpeed + pidValue / 10, 0, 255);

  motorDrive(LSp, RSp);
}

// Reads Sensors And Calculates Position Based on Weights
int readLineWeighted() {
  int sensorVals[3];
  sensorVals[0] = analogRead(LEFT_SNR);   // Weight: 0
  sensorVals[1] = analogRead(CENTER_SNR); // Weight: 3500
  sensorVals[2] = analogRead(RIGHT_SNR);  // Weight: 7000

  long weightedSum = 0;
  int activeCount = 0;
  const int weights[3] = {0, 3500, 7000};

  // If Sensor Reads Above Threshold Add Its Weight To Sum And Increase The Active Sensors By 1
  for (int i = 0; i < 3; i++) {
    if (sensorVals[i] > LineThreshold) {
      weightedSum += (long)weights[i];
      activeCount++;
    }
  }
  // If At Least One Sensor Is Active Divide The Weight Sum By The Active Sensors To Get Position Otherwise Return Far Left Or Far Right Depending On The Robot's Previous Position
  if (activeCount > 0) {
    return weightedSum / activeCount;
  } else {
    return (PreviousError > 0) ? 0 : 7000;
  }
}

// Drives Motors Using PWM
void motorDrive(int LeftSpeed, int RightSpeed) {
  analogWrite(LEFT_MOTOR_FORWARD, LeftSpeed);
  analogWrite(LEFT_MOTOR_BACKWARD, 0);

  analogWrite(RIGHT_MOTOR_FORWARD, RightSpeed);
  analogWrite(RIGHT_MOTOR_BACKWARD, 0);
}