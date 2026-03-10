int readLDR(int pin)
{
    return analogRead(pin);
}

float readVoltage(int pin)
{
    int val = analogRead(pin);
    return val * (3.3 / 4095.0);
}
