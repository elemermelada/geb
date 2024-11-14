#include "iostream"

constexpr int SERIES_SIZE = 999;

bool sortedArrayIncludes(long *array, int size, long value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] > value)
            return false;
        if (array[i] == value)
            return true;
    }
    return false;
}

void cleanArray(long *array, int &size, long removeuntil)
{
    int offset = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < removeuntil)
            continue; // XXX - consider <=
        offset = i;
        break;
    }

    for (int i = 0; i < size - offset; i++)
    {
        array[i] = array[i + offset];
    }
    size -= offset;
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
        {
            cleanArray(series, size, current);
            if (size >= SERIES_SIZE)
                return 0; // Could not free any memory!
            continue;
        }
        if (sortedArrayIncludes(series, size, current))
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