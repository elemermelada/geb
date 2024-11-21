#pragma once

enum class Rules
{
    I = 0,
    II,
    III,
    IV,
    Last
};

class MIU
{
public:
    MIU();
    MIU(const MIU &from);
    ~MIU();
    MIU(const char *data);
    MIU &operator=(MIU from);
    bool operator==(const MIU &oth);

    void copyFrom(const MIU &from);
    void setFromStr(const char *data);

    bool canApplyRule(const Rules rule, int *from);
    bool canApplyRule(const Rules rule);
    MIU applyRule(const Rules rule);
    MIU applyRule(const Rules rule, int *from);

    const char *getData();
    bool checkData(const char *data);
    bool isValid();
    void unsafeSetNull();

private:
    int m_size = -1;
    char *m_data = nullptr;
};