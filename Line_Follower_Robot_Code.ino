// Libraries
#include <Arduino.h>

// Motor Driver Pins
#define ENA  5   // PWM for left motor
#define DIR1A  18  // Direction 1 for left motor
#define DIR2A  19  // Direction 2 for left motor
#define DIR1B  22  // Direction 1 for right motor
#define DIR2B  23  // Direction 2 for right motor
#define ENB  21  // PWM for right motor

// Sensor Pins
#define SENSOR_1  34  // Far Left
#define SENSOR_2  35  
#define SENSOR_3  32  // Center
#define SENSOR_4  33  
#define SENSOR_5  25  // Far Right

// PID Constants (NEEDS FINE-TUNING!!)
#define Kp  0.4  // Proportional Gain (Adjusts correction intensity)
#define Kd  2.0  // Derivative Gain (Smooths out corrections and reduces overshooting)

int lastError = 0;
int baseSpeed = 180;  // Adjust based on testing

int lastValidPosition = 0;  // Stores last known good position of the line

void setup() {
    Serial.begin(115200); // Allows us to see sensor data in the Serial Monitor

    // Motor pins as outputs
    pinMode(ENA, OUTPUT);
    pinMode(DIR1A, OUTPUT);
    pinMode(DIR2A, OUTPUT);
    pinMode(DIR1B, OUTPUT);
    pinMode(DIR2B, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Sensor pins as inputs
    pinMode(SENSOR_1, INPUT);
    pinMode(SENSOR_2, INPUT);
    pinMode(SENSOR_3, INPUT);
    pinMode(SENSOR_4, INPUT);
    pinMode(SENSOR_5, INPUT);
}

// Reads sensor values and calculates position
int readSensors() {
    int s1 = digitalRead(SENSOR_1) ? 0 : 1;  // We may need to invert it
    int s2 = digitalRead(SENSOR_2) ? 0 : 2;
    int s3 = digitalRead(SENSOR_3) ? 0 : 3;
    int s4 = digitalRead(SENSOR_4) ? 0 : 4;
    int s5 = digitalRead(SENSOR_5) ? 0 : 5;

    int position = (s1 * -2) + (s2 * -1) + (s3 * 0.5) + (s4 * 1) + (s5 * 2); //Position calculation with weights

    // If sensors detects a valid position it gets stored
    if (position != 0) {
        lastValidPosition = position;
    }

    return position;
}

// Set motor speeds
void setMotorSpeed(int leftSpeed, int rightSpeed) {
    // Set left motor direction
    if (leftSpeed > 0) {
        digitalWrite(DIR1A, HIGH);
        digitalWrite(DIR2A, LOW);
    } else {
        digitalWrite(DIR1A, LOW);
        digitalWrite(DIR2A, HIGH);
    }
    analogWrite(ENA, abs(leftSpeed));

    // Set right motor direction
    if (rightSpeed > 0) {
        digitalWrite(DIR1B, HIGH);
        digitalWrite(DIR2B, LOW);
    } else {
        digitalWrite(DIR1B, LOW);
        digitalWrite(DIR2B, HIGH);
    }
    analogWrite(ENB, abs(rightSpeed));
}

// Auto-correction 
void autoCorrect() {
    Serial.println("Line lost! Auto-correcting...");

    // If line is lost, retrace last known movement
    if (lastValidPosition < 0) {
        // Line was to the left, so turn left to find it
        setMotorSpeed(-100, 100);
        delay(300);
    } else {
        // Line was to the right, so turn right to find it
        setMotorSpeed(100, -100);
        delay(300);
    }
}

void loop() {
    int position = readSensors();
    int error = position * 100;  // Scale for sensitivity

    if (position == 0) {
        // Line is lost, trigger auto-correction
        autoCorrect();
        return;  // Skip PID control this cycle
    }

    int derivative = error - lastError;
    int correction = Kp * error + Kd * derivative;
    lastError = error;

    int leftSpeed = baseSpeed - correction;
    int rightSpeed = baseSpeed + correction;

    // Ensure speed limits
    leftSpeed = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);

    setMotorSpeed(leftSpeed, rightSpeed);
    delay(10);  // Small delay for stability
}
