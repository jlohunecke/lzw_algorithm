#include "XOutOfBounds.hpp"

XOutOfBounds::XOutOfBounds (const string error): m_error(error){};

XOutOfBounds::~XOutOfBounds()
{
}

string XOutOfBounds::geterror() const
{
    return m_error;
}
