#include "CKnot.hpp"

CKnot::CKnot() : m_parent(-2), CEntry()
{
    setSymbol("");
};

int CKnot::getParent() const
{
    return m_parent;
}

void CKnot::setParent(int n)
{
    m_parent = n;
}


