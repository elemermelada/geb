#include "MIU.h"
#include "Container.h"
#include "tests.cpp"

int main()
{
    bool success = runTests();
    if (!success)
        return 1;
    auto container = Container(MIU("MI"));
    for (int i = 0; i < 8; i++)
    {
        container.iterateCurrent();
    }
    container.printChains();
    return 0;
}