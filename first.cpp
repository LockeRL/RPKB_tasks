# include <iostream>

bool isMinuteFree(int period, int minute)
{
    if (minute == 0)
        return false;
    return true;
}

void reserveBlock(int period, int startMinute, int duration)
{
}

int findFreeBlock(int period, int duration)
{
    int currentFreeBlock = 0;
    for (int i = 0; i <= 59; i++)
    {
        if (isMinuteFree(period, i))
            currentFreeBlock++;
        else
            currentFreeBlock = 0;

        if (currentFreeBlock == duration)
            return i - duration;
    }
    return -1;
}

bool makeAppointment(int startPeriod, int endPeriod, int duration)
{
    int freeBlockStart = -1;
    for (int i = startPeriod; i <= endPeriod; i++)
    {
        freeBlockStart = findFreeBlock(i, duration);
        if (freeBlockStart != -1)
        {
            reserveBlock(i, freeBlockStart, duration);
            return true;
        }
    }
    return false;
}

int main()
{
}
