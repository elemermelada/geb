#include "MIU.h"
#include "tests.cpp"

int main()
{
    bool success = runTests();
    if (!success)
        return 1;
    return 0;
}