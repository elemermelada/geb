#include "MIU.h"
#include "iostream"
#include "string"

static void testRuleIII()
{
    auto s1 = MIU("MIII");
    if (!s1.applyRule(Rules::III).checkData("MU"))
    {
        throw "Rule III is not defined properly";
    }

    s1 = MIU("MUIIIU");
    if (!s1.applyRule(Rules::III).checkData("MUUU"))
    {
        throw "Rule III is not defined properly";
    }

    s1 = MIU("MIUIIIIUUI");
    if (!s1.applyRule(Rules::III).checkData("MIUUIUUI"))
    {
        throw "Rule III is not defined properly";
    }

    s1 = MIU("MIUUUI");
    if (s1.applyRule(Rules::III).isValid())
    {
        throw "Rule III is not defined properly";
    }

    s1 = MIU("MUIIIUIIIU");
    int index = 1;
    if (s1.applyRule(Rules::III, &index).checkData("MUUIIIU"))
    {
        throw "Rule III is not defined properly";
    }

    index = 3;
    if (s1.applyRule(Rules::III, &index).checkData("MUIIIUU"))
    {
        throw "Rule III is not defined properly";
    }
}

static void testRuleIV()
{
    auto s1 = MIU("MUU");
    if (!s1.applyRule(Rules::IV).checkData("M"))
    {
        throw "Rule IV is not defined properly";
    }

    s1 = MIU("MIUUUI");
    if (!s1.applyRule(Rules::IV).checkData("MIUI"))
    {
        throw "Rule IV is not defined properly";
    }

    s1 = MIU("MUI");
    if (s1.applyRule(Rules::IV).isValid())
    {
        throw "Rule IV is not defined properly";
    }
}

static bool runTests()
{
    try
    {
        testRuleIII();
        testRuleIV();
    }
    catch (char *err)
    {
        std::cout << "TESTS FAILED: " << err << std::endl;
        return false;
    }
    std::cout << "ALL TESTS PASSED" << std::endl;
    return true;
}