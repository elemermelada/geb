#pragma once

#include "MIU.h"

class Container
{
public:
    Container(const MIU &axiom);
    ~Container();

    void iterateCurrent();
    void printChains();

private:
    bool alreadyExists(const MIU &chain);
    void clearCurrent();

    MIU *m_next = nullptr;
    int m_nexsize = 0;
    MIU *m_current = nullptr;
    int m_cursize = 0;
    MIU *m_archive = nullptr;
    int m_arcsize = 0;
};