#include "Container.h"
#include "memory"
#include "iostream"

static void addChainTo(const MIU &chain, MIU *&targ, int &targsize)
{
    if (targsize == 0 || targ == nullptr)
    {
        targ = (MIU *)malloc(sizeof(MIU) * 16);
        targsize = 0;
    }

    if (targsize > 15 && (((targsize) & (targsize - 1)) == 0))
    { // Time to grow!
        targ = (MIU *)realloc((void *)targ, sizeof(MIU) * 2 * (targsize));
    }
    targ[targsize].unsafeSetNull();
    targ[targsize] = chain;
    targsize++;
}

Container::Container(const MIU &axiom)
{
    addChainTo(axiom, m_current, m_cursize);
}

Container::~Container()
{
    if (m_next)
    {
        free(m_next);
        m_next = nullptr;
    }
    if (m_current)
    {
        free(m_current);
        m_current = nullptr;
    }
    if (m_archive)
    {
        free(m_archive);
        m_archive = nullptr;
    }
}

bool Container::alreadyExists(const MIU &chain)
{
    for (int i = 0; i < m_nexsize; i++)
    { // TODO - needed??
        if (m_next[i] == chain)
            return true;
    }
    for (int i = 0; i < m_cursize; i++)
    {
        if (m_current[i] == chain)
            return true;
    }
    for (int i = 0; i < m_arcsize; i++)
    {
        if (m_archive[i] == chain)
            return true;
    }
    return false;
}

void Container::clearCurrent()
{
    m_archive = (MIU *)realloc((void *)m_archive, sizeof(MIU) * (m_arcsize + m_cursize));
    memcpy((void *)&(m_archive[m_arcsize]), (void *)m_current, sizeof(MIU) * m_cursize);
    free(m_current);
    m_arcsize = m_arcsize + m_cursize;

    m_current = (MIU *)malloc(sizeof(MIU) * m_nexsize);
    memcpy(m_current, m_next, sizeof(MIU) * m_nexsize);
    m_cursize = m_nexsize;
    free(m_next);
    m_next = nullptr;
    m_nexsize = 0;
}

void Container::iterateCurrent()
{
    for (int i = 0; i < m_cursize; i++)
    {
        auto chain = m_current[i];
        for (int r = (int)Rules::I; r < (int)Rules::Last; r++)
        {
            int from = 0;
            while (true)
            {
                auto newchain = chain.applyRule((Rules)r, &from);
                if (!newchain.isValid())
                    break;
                if (alreadyExists(newchain))
                    continue;
                addChainTo(newchain, m_next, m_nexsize);
                std::cout << " > Added chain \"" << newchain.getData() << "\" to next batch" << std::endl;
            }
        }
    }
    clearCurrent();
}

void Container::printChains()
{
    std::cout << "--------------" << std::endl;
    std::cout << "CURRENT CHAINS" << std::endl;
    std::cout << "--------------" << std::endl;

    for (int i = 0; i < m_arcsize; i++)
    {
        std::cout << m_archive[i].getData() << std::endl;
    }
    for (int i = 0; i < m_cursize; i++)
    {
        std::cout << m_current[i].getData() << "*" << std::endl;
    }
    std::cout << "--------------" << std::endl;
}
