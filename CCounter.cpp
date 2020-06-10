#include "CCounter.hpp"

CCounter::CCounter(): m_count(0){}

CCounter::~CCounter()
{
};

void CCounter::count()
{
}

int CCounter::getValue() const {
    return m_count;
}

void CCounter::setValue(int val){
    m_count = val;
}

bool CCounter::operator < (const CCounter &h) const
{
    return (m_count < h.m_count);
}

bool CCounter::operator > (const CCounter &h) const
{
    return (m_count > h.m_count);
}


