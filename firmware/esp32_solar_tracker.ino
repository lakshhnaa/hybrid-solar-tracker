#include <Servo.h>

Servo tracker;

/* -------- Pin Definitions -------- */
int LDR_left = 34;
int LDR_right = 35;

int voltagePin = 32;
int currentPin = 33;

int servoPin = 18;

/* -------- Parameters -------- */
int threshold = 50;
int position = 90;

float motorCost = 0.05;
float previousPower = 0;

/* -------- Sensor Functions -------- */

int readLDRLeft()
{
  return analogRead(LDR_left);
}

int readLDRRight()
{
  return analogRead(LDR_right);
}

int calculateLightDifference()
{
  int left = readLDRLeft();
  int right = readLDRRight();
  return left - right;
}

float readVoltage()
{
  int sensorValue = analogRead(voltagePin);
  float voltage = sensorValue * (3.3 / 4095.0);
  return voltage * 5;
}

float readCurrent()
{
  int sensorValue = analogRead(currentPin);
  float voltage = sensorValue * (3.3 / 4095.0);
  float current = (voltage - 2.5) / 0.185;
  return abs(current);
}

float calculatePower()
{
  float V = readVoltage();
  float I = readCurrent();
  return V * I;
}

/* -------- Movement Logic -------- */

bool shouldMove(int difference)
{
  if (abs(difference) > threshold)
    return true;
  else
    return false;
}

void movePanel(int difference)
{
  if (difference > 0)
    position++;
  else
    position--;

  position = constrain(position, 0, 180);
  tracker.write(position);
}

/* -------- Setup -------- */

void setup()
{
  Serial.begin(115200);

  pinMode(LDR_left, INPUT);
  pinMode(LDR_right, INPUT);

  tracker.attach(servoPin);
  tracker.write(position);
}

/* -------- Main Control Loop -------- */

void loop()
{
  int diff = calculateLightDifference();

  if (shouldMove(diff))
  {
    float oldPower = calculatePower();

    movePanel(diff);
    delay(300);

    float newPower = calculatePower();

    if ((newPower - oldPower) > motorCost)
    {
      previousPower = newPower;
    }
    else
    {
      tracker.write(position);
    }
  }

  delay(500);
}
