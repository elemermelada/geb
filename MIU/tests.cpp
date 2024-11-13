#include "MIU.h"

bool testRuleIII()
{
    auto s1 = MIU("MIII");
    if (!s1.applyRule(Rules::III).checkData("M"))
    {
        throw "Rule III is not defined properly";
    }

    s1 = MIU("MUIIIU");
    if (!s1.applyRule(Rules::III).checkData("MUU"))
    {
        throw "Rule III is not defined properly";
    }

    s1 = MIU("MIUIIIIUUI");
    if (!s1.applyRule(Rules::III).checkData("MIUIUUI"))
    {
        throw "Rule III is not defined properly";
    }
    s1 = MIU("MIUUUI");
    if (s1.applyRule(Rules::III).isValid())
    {
        throw "Rule III is not defined properly";
    }
}

bool testRuleIV()
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

void main()
{
    testRuleIII();
}