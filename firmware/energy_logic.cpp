float calculatePower(float voltage, float current)
{
    return voltage * current;
}

bool energyEfficient(float newPower, float oldPower, float motorCost)
{
    return (newPower - oldPower) > motorCost;
}
