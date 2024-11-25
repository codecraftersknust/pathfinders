#include <Servo.h>

// Pin definitions
const int TRIG_LEFT = 10;
const int ECHO_LEFT = 9;
const int TRIG_RIGHT = 3;
const int ECHO_RIGHT = 2;
const int ESC_PIN = 5;
const int SERVO_PIN = 6;

// ESC calibration values
const int NEUTRAL_PULSE = 1500;
const int FULL_THROTTLE = 2000;
const int FULL_REVERSE = 1000;

const float Kp = 1.5;
const float Ki = 0.0;
const float Kd = 0.0;
const float FORWARD_SPEED = 1000;

float error = 0;
float previous_error = 0;
float integral = 0;
float derivative = 0;
float output = 0;

// Servo angles
const int CENTER_ANGLE = 90;
const int MAX_STEERING_ANGLE = 30;  // Maximum deviation from center

// Global variables
Servo esc;
Servo steering;
float lastError = 0;
unsigned long lastTime = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize ultrasonic sensor pins
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  
  // Attach and initialize servo and ESC
  esc.attach(ESC_PIN);
  steering.attach(SERVO_PIN);
  
  // Center the steering
  steering.write(CENTER_ANGLE);
  delay(1000);
}

void loop() {
  // Get current distance from wall
  float distanceLeft = getDistance(TRIG_LEFT, ECHO_LEFT);
  float distanceRight = getDistance(TRIG_RIGHT, ECHO_RIGHT);
  
  // Calculate error
  error = distanceLeft - distanceRight;
  
  // Calculate time difference
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - lastTime) / 1000.0;  // Convert to seconds
  
  // Calculate derivative of error
  derivative = (error - lastError) / deltaTime;
  
  // Calculate PD control output
  output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  
  // Limit control output to maximum steering angle
  output = constrain(output, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
  
  // Convert control output to steering angle
  int steeringAngle = CENTER_ANGLE + output;
  
  // Apply steering control
  steering.write(steeringAngle);
  
  // Set forward motion
  esc.writeMicroseconds(FORWARD_SPEED);
  
  // Update previous values
  lastError = error;
  lastTime = currentTime;
  
  // Debug output
  Serial.print("Left Distance: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Right Distance: ");
  Serial.print(distanceRight);
  Serial.print(" cm, Error: ");
  Serial.print(error);
  Serial.print(", Servo Angle: ");
  Serial.println(steeringAngle);
  
  delay(50);
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Convert to cm
}
