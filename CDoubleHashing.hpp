#ifndef CDoubleHashing_hpp
#define CDoubleHashing_hpp

#include <iostream>
using namespace std;

/*!
 \file CDoubleHashing.hpp
 \brief hashing
 Diese klasse implementiert die hashfunktion (singelton). hierbei wird eine hashfunktion verwendet, welche abhängig vom attempt input einnen hash oder rehash durchführt.
 */
class CDoubleHashing
{
public:
    // static instance existiert weil singleton
    static CDoubleHashing& getInstance();
    unsigned int hash (unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt);
    virtual ~CDoubleHashing();
    
private:
    static CDoubleHashing m_instance;
    
    // Konstruktor, Kopierkosntruktor und Zuweisungsoperator sind privat. 
    CDoubleHashing ();
    CDoubleHashing (const CDoubleHashing&);
    CDoubleHashing operator= (CDoubleHashing&);
};




#endif
