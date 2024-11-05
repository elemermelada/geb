#include "iostream"

constexpr long SERIES_SIZE = 999;

bool arrayIncludes(long *array, int size, long value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            return true;
    }
    return false;
}

int main()
{
    long current = 1;
    long series[SERIES_SIZE];

    long lastadded = 1;
    series[0] = lastadded;
    int size = 1;

    while (true)
    {
        std::cout << lastadded << std::endl;
        if (size >= SERIES_SIZE)
            return 0;
        if (arrayIncludes(series, size, current))
        {
            current++;
            continue;
        }

        lastadded += current;
        current++;
        series[size] = lastadded,
        size++;
    }
    return 1;
}