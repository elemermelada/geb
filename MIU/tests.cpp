#include "MIU.h"
#include "iostream"
#include "string"

void testRuleIII()
{
    auto s1 = MIU(std::string("MIII").c_str());
    if (!s1.applyRule(Rules::III).checkData(std::string("MU").c_str()))
    {
        throw std::string("Rule III is not defined properly");
    }

    s1 = MIU(std::string("MUIIIU").c_str());
    if (!s1.applyRule(Rules::III).checkData(std::string("MUUU").c_str()))
    {
        throw std::string("Rule III is not defined properly");
    }

    s1 = MIU(std::string("MIUIIIIUUI").c_str());
    if (!s1.applyRule(Rules::III).checkData(std::string("MIUUIUUI").c_str()))
    {
        throw std::string("Rule III is not defined properly");
    }

    s1 = MIU(std::string("MIUUUI").c_str());
    if (s1.applyRule(Rules::III).isValid())
    {
        throw std::string("Rule III is not defined properly");
    }
}

void testRuleIV()
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

bool runTests()
{
    try
    {
        testRuleIII();
        testRuleIV();
    }
    catch (std::string err)
    {
        std::cout << "TESTS FAILED: " << err << std::endl;
        return false;
    }
    std::cout << "ALL TESTS PASSED" << std::endl;
    return true;
}