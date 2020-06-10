#include "CDoubleHashing.hpp"

CDoubleHashing::CDoubleHashing()
{
}

CDoubleHashing& CDoubleHashing::getInstance()
{
    return m_instance;
}

unsigned int CDoubleHashing::hash (unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt)
{
    // berechnet aus beiden inout werten I und J einen schlüssel welcher der eigentlichen hash funktion übergeben wird.
    unsigned int key = 0.5*(I+J)*(I+J+1)+J;
    
    // hash mit ggf. rehash
    unsigned int hash_value = (key + attempt * (1 + key % (dict_size - 2))) % dict_size;
    return hash_value;
}

// static instances müssen initialisert werden
CDoubleHashing CDoubleHashing::m_instance;

CDoubleHashing::~CDoubleHashing()
{
}
