#include "CEntry.hpp"

CEntry::CEntry(): m_symbol("")
{
    m_number++;
}

CEntry::~CEntry()
{
    m_number--;
}

const string& CEntry::getSymbol() const
{
    return m_symbol;
}

void CEntry::setSymbol(const string symbol)
{
    m_symbol = symbol;
}

unsigned int CEntry::getNumber()
{
    return m_number;
}

unsigned int CEntry::m_number = 0;
