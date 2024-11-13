#pragma once

enum class Rules
{
    I = 0,
    II,
    III,
    IV,
};

class MIU
{
public:
    MIU();
    MIU(char *data);
    bool canApplyRule(const Rules rule, int *from = nullptr);
    MIU applyRule(const Rules rule, int *from = nullptr);
    bool checkData(char *data);
    bool isValid();

private:
    int m_size;
    char *m_data;
};