#include "MIU.h"
#include "cstring"
#include "memory"

#include "iostream"

MIU::MIU()
{
    m_size = -1;
}

MIU::MIU(const char *data)
{
    m_size = strlen(data);
    m_data = (char *)malloc(m_size);
    strcpy(m_data, data);
}

bool MIU::canApplyRule(const Rules rule, int *fromp)
{
    switch (rule)
    {
    case Rules::I:
    {
        if (m_data[m_size - 1] == 'I')
            return true;
        return false;
    }
    case Rules::II:
    {
        if (m_data[0] == 'M' && m_size > 1)
            return true;
        return false;
    }
    case Rules::III:
    {
        int from = fromp ? *fromp : 0;
        for (int i = from; i < m_size - 2; i++)
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
        int from = fromp ? *fromp : 0;
        for (int i = from; i < m_size - 1; i++)
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
}

MIU MIU::applyRule(const Rules rule, int *fromp)
{
    int from = fromp ? *fromp : 0;
    if (!canApplyRule(rule, &from))
        return MIU();

    switch (rule)
    {
    case Rules::I:
    {
        char *newdata = (char *)malloc(m_size + 1);
        strcpy(newdata, m_data);
        newdata[m_size] = 'U';

        auto elem = MIU(newdata);
        delete newdata;
        return elem;
    }
    case Rules::II:
    {
        char *newdata = (char *)malloc(2 * m_size - 1);
        strcpy(newdata, m_data);
        for (int i = 0; i < m_size - 1; i++)
        {
            newdata[m_size + i] = m_data[i + 1];
        }

        auto elem = MIU(newdata);
        delete newdata;
        return elem;
    }
    case Rules::III:
    {
        char *newdata = (char *)malloc(m_size);
        strcpy(newdata, m_data);
        newdata[from] = 'U';
        for (int i = from + 1; i < m_size - 2; i++)
        {
            newdata[i] = m_data[i + 2];
        }
        newdata[m_size - 2] = 0;

        auto elem = MIU(newdata);
        free(newdata);
        return elem;
    }
    case Rules::IV:
    {
        char *newdata = (char *)malloc(m_size);
        strcpy(newdata, m_data);
        for (int i = from; i < m_size - 2; i++)
        {
            newdata[i] = m_data[i + 2];
        }
        newdata[m_size - 2] = 0;

        auto elem = MIU(newdata);
        free(newdata);
        return elem;
    }
    }
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
