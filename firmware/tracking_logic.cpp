int calculateLightDifference(int left, int right)
{
    return left - right;
}

bool shouldMove(int difference, int threshold)
{
    return abs(difference) > threshold;
}
