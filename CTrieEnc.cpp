#include "CTrieEnc.hpp"

CTrieEnc::CTrieEnc(){
    for (int c = 0; c < 265; c++)
    {
        m_symbolTable[c].setParent(-1);
        m_symbolTable[c].setSymbol(intToString(c));
    }
}


vector <unsigned int> CTrieEnc::encode (const string &in)
{
    vector <unsigned int> out;
    
    // empty string as input
    if (in == "") return out;
    
    // J speichert ASCII-wert des eingelesen Buchstaben, I speichert index des elternteils, hv und init_hv sind die hashwerte
    // hier liest I den ersten und J den zweiten buchstaben ein
    string::const_iterator rdr (in.begin());
    unsigned int I,J,hv,init_hv;
    I = charToInt(*rdr);
    J = charToInt(*(++rdr));
    
    // schelife bis string vollständig eingelesen
    while (rdr != in.end())
    {
        // erster hashwert mit attempt zähler (initialisiert mit 0)
        // init wert für abbruchbdingungen beim rehashen
        CForwardCounter attempt;
        hv = CDoubleHashing::getInstance().hash(I, J, LZW_DICT_SIZE, attempt.getValue());
        init_hv = hv;
    
        // rehashing, wenn knoten mit anderen I und J werten belegt ist
        // abbruch wenn hv dem ersten hv wieder gleicht, I und J dem parent und ASCII-wert des Knotens entsprechen, oder wenn der knoten leer ist
        if (m_symbolTable[hv].getParent() != I && m_symbolTable[hv].getSymbol() != intToString(J) && m_symbolTable[hv].getParent() != -2 )
        {
            do
            {
                attempt.count();
                hv = CDoubleHashing::getInstance().hash(I, J, LZW_DICT_SIZE, attempt.getValue());
            }
            while (!((m_symbolTable[hv].getParent() == -2) || ((m_symbolTable[hv].getParent() == I) && (m_symbolTable[hv].getSymbol()) == intToString(J)) || (hv == init_hv)));
        }
        
        
        // wenn string noch nicht vorhanden dann prüfen ob der knoten leer ist
        // neunen knoten erstellen mit I als elternteil, J als symbol
        // I an den output senden
        if ((m_symbolTable[hv].getParent() != I) && (m_symbolTable[hv].getSymbol() != intToString(J)))
        {
            if ((m_symbolTable[hv].getParent() == -2))
            {
                
                m_symbolTable[hv].setSymbol(intToString(J));
                m_symbolTable[hv].setParent(I);
                out.push_back(I);
                I = J;
            }
        }
        
        // wenn string bekannt
        else if ((m_symbolTable[hv].getParent() == I) && (m_symbolTable[hv].getSymbol() == intToString(J)))
        {
            I = hv;
        }
        
        // nächstes zeichen einlesen
        J = charToInt(*(++rdr));
    }
    
    // index des letzen teilstrings senden
    out.push_back(I);
    
    return out;
}
