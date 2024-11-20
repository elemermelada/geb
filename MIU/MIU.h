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
    MIU(const MIU &from);
    ~MIU();
    MIU(const char *data);
    MIU &operator=(MIU from);

    void copyFrom(const MIU &from);
    void setFromStr(const char *data);
    bool canApplyRule(const Rules rule, int *from = nullptr);
    MIU applyRule(const Rules rule, int *from = nullptr);
    bool checkData(const char *data);
    bool isValid();

private:
    int m_size = -1;
    char *m_data = nullptr;
};