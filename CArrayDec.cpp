#include "CArrayDec.hpp"

CArrayDec::CArrayDec() : CDec(), m_dic_lngth(256)
{
    for (int i = 0; i < 256; i++)
    {
        m_symbolTable[i].setSymbol(intToString(i));
    }
}

CArrayDec::~CArrayDec()
{
    //cout << "the instance of CArrayDec was destroyed" << endl;
}

string CArrayDec::decode (const vector<unsigned int> &trans)
{
    // output string
    string out ("");
    
    // case: input vector ist leer
    if (trans.empty()) return out;
    
    // zeiger auf das erste element des vectors
    auto vecptr = trans.begin();
    
    // hier wird bereits das erste zeichen eingelesen und verarbeitet 
    string S ("");
    string Sv (m_symbolTable[*(vecptr)].getSymbol());
    
    out += Sv;
    
    while (vecptr != trans.end()-1)
    {
        vecptr++;
        
        // normalfall. hier wird einfach zu dem index wert der dazugehörige string in S gespeichert.
        if (*vecptr < m_dic_lngth)
            S = (m_symbolTable[*(vecptr)].getSymbol());
        
        
        // sonderfall wenn der index noch nicht bekannt ist. hier kann der letze buchstabe durch den ersten des vorherigen strings rekonstruiert werden.
        else
            S = Sv + Sv.at(0);
        
        // S baut schließlich loop für loop den ausgabestring auf. 
        out  += S;
        
        // speichern der neunen zeichenketten im dictionary
        m_symbolTable[m_dic_lngth].setSymbol(Sv + S.at(0));
        m_dic_lngth++;
        
        Sv = S;
    }
    return out;
}
