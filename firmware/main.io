#include <Servo.h>

/* -------- Pin Definitions -------- */

#define LDR_LEFT 34
#define LDR_RIGHT 35
#define VOLTAGE_PIN 32
#define CURRENT_PIN 33
#define SERVO_PIN 18

/* -------- System Parameters -------- */

int threshold = 50;
int position = 90;

float motorCost = 0.05;
float previousPower = 0;

/* -------- Servo Object -------- */

Servo tracker;

/* -------- Sensor Functions -------- */

int readLDR(int pin)
{
    return analogRead(pin);
}

float readVoltage()
{
    int val = analogRead(VOLTAGE_PIN);
    float voltage = val * (3.3 / 4095.0);
    return voltage * 5;
}

float readCurrent()
{
    int val = analogRead(CURRENT_PIN);
    float voltage = val * (3.3 / 4095.0);
    float current = (voltage - 2.5) / 0.185;
    return abs(current);
}

/* -------- Tracking Logic -------- */

int calculateLightDifference(int left, int right)
{
    return left - right;
}

bool shouldMove(int difference)
{
    return abs(difference) > threshold;
}

/* -------- Energy Logic -------- */

float calculatePower(float voltage, float current)
{
    return voltage * current;
}

bool energyEfficient(float newPower, float oldPower)
{
    return (newPower - oldPower) > motorCost;
}

/* -------- Movement Function -------- */

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

    pinMode(LDR_LEFT, INPUT);
    pinMode(LDR_RIGHT, INPUT);

    tracker.attach(SERVO_PIN);
    tracker.write(position);
}

/* -------- Main Loop -------- */

void loop()
{
    int left = readLDR(LDR_LEFT);
    int right = readLDR(LDR_RIGHT);

    int diff = calculateLightDifference(left, right);

    if (shouldMove(diff))
    {
        float voltage = readVoltage();
        float current = readCurrent();

        float oldPower = calculatePower(voltage, current);

        movePanel(diff);

        delay(300);

        voltage = readVoltage();
        current = readCurrent();

        float newPower = calculatePower(voltage, current);

        if (energyEfficient(newPower, oldPower))
        {
            previousPower = newPower;
        }
        else
        {
            tracker.write(position);
        }
    }

    Serial.print("Left: ");
    Serial.print(left);
    Serial.print(" Right: ");
    Serial.print(right);
    Serial.print(" Power: ");
    Serial.println(previousPower);

    delay(500);
}
