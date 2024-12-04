#include "MIU.h"
#include "cstring"
#include "memory"

#include "iostream"

MIU::MIU()
{
}

MIU::MIU(const MIU &from)
{
    copyFrom(from);
}

MIU::MIU(const char *data)
{
    setFromStr(data);
}

MIU &MIU::operator=(MIU from)
{
    copyFrom(from);
    return *this;
}

bool MIU::operator==(const MIU &oth)
{
    return this->checkData(oth.m_data);
}

MIU::~MIU()
{
    if (m_data)
        free(m_data);
    m_data = nullptr;
}

void MIU::copyFrom(const MIU &from)
{
    if (m_data)
        free(m_data);
    m_data = nullptr;
    setFromStr(from.m_data);
}

void MIU::setFromStr(const char *data)
{
    m_size = strlen(data);
    m_data = (char *)malloc(sizeof(m_data) * m_size);
    strcpy(m_data, data);
}

bool MIU::canApplyRule(const Rules rule, int *fromp)
{
    switch (rule)
    {
    case Rules::I:
    {
        if (*fromp == 0 && m_data[m_size - 1] == 'I')
        {
            return true;
        }
        return false;
    }
    case Rules::II:
    {
        if (*fromp == 0 && m_data[0] == 'M' && m_size > 1)
        {
            return true;
        }
        return false;
    }
    case Rules::III:
    {
        for (int i = *fromp; i < m_size - 2; i++)
        {
            if (m_data[i] == 'I' && m_data[i + 1] == 'I' && m_data[i + 2] == 'I')
            {
                if (fromp)
                    *fromp = i;
                return true;
            }
        }
        return false;
    }
    case Rules::IV:
    {
        for (int i = *fromp; i < m_size - 1; i++)
        {
            if (m_data[i] == 'U' && m_data[i + 1] == 'U')
            {
                if (fromp)
                    *fromp = i;
                return true;
            }
        }
        return false;
    }
    }
    return false;
}

bool MIU::canApplyRule(const Rules rule)
{
    int _ = 0;
    return canApplyRule(rule, &_);
}

MIU MIU::applyRule(const Rules rule)
{
    int _ = 0;
    return applyRule(rule, &_);
}

MIU MIU::applyRule(const Rules rule, int *fromp)
{
    if (!canApplyRule(rule, fromp))
        return MIU();

    auto elem = MIU();
    switch (rule)
    {
    case Rules::I:
    {
        char *newdata = (char *)malloc(sizeof(newdata) * (m_size + 2));
        strcpy(newdata, m_data);
        newdata[m_size] = 'U';
        newdata[m_size + 1] = 0;

        elem = MIU(newdata);
        free(newdata);
        break;
    }
    case Rules::II:
    {
        char *newdata = (char *)malloc(sizeof(newdata) * (2 * m_size));
        strcpy(newdata, m_data);
        for (int i = 0; i < m_size - 1; i++)
        {
            newdata[m_size + i] = m_data[i + 1];
        }
        newdata[2 * m_size - 1] = 0;

        elem = MIU(newdata);
        free(newdata);
        break;
    }
    case Rules::III:
    {
        char *newdata = (char *)malloc(sizeof(newdata) * m_size);
        strcpy(newdata, m_data);
        newdata[*fromp] = 'U';
        for (int i = *fromp + 1; i < m_size - 2; i++)
        {
            newdata[i] = m_data[i + 2];
        }
        newdata[m_size - 2] = 0;

        elem = MIU(newdata);
        free(newdata);
        break;
    }
    case Rules::IV:
    {
        char *newdata = (char *)malloc(sizeof(newdata) * m_size);
        strcpy(newdata, m_data);
        for (int i = *fromp; i < m_size - 2; i++)
        {
            newdata[i] = m_data[i + 2];
        }
        newdata[m_size - 2] = 0;

        elem = MIU(newdata);
        free(newdata);
        break;
    }
    }
    *fromp += 1;
    return elem;

    return MIU();
}

const char *MIU::getData()
{
    return m_data;
}

bool MIU::checkData(const char *data)
{
    if (m_size == -1)
        return false;
    return strcmp(data, m_data) == 0;
}

bool MIU::isValid()
{
    return m_size != -1;
}

void MIU::unsafeSetNull()
{
    m_data = nullptr;
    m_size = 0;
}
