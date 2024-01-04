int square(int num)
{
    return num * num;
}

double power(double base, int exponent)
{

    int ex = exponent;
    if (ex == 0)
    {
        return 1.0;
    }
    if (ex < 0)
    {
        ex = -ex;
        base = 1 / base;
    }

    if (ex % 2 == 0)
    {
        return power(base * base, (int)ex / 2);
    }
    else
    {
        return base * power(base, (int)(ex - 1));
    }
}

void changeVal(int *num)
{
    *num = 69;
}

int calOldest(int ages[], int size)
{
    int oldest = ages[0];
    for (int i = 1; i < size; i++)
    {
        if (ages[i] > oldest)
        {
            oldest = ages[i];
        }
    }
    return oldest;
}