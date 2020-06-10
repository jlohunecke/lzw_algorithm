#include "CArrayEnc.hpp"

CArrayEnc::CArrayEnc():CEnc()
{
    for (int i = 0; i < 256; i++)
    {
        m_symbolTable[i].setSymbol(intToString(i));
    }
}

CArrayEnc::~CArrayEnc()
{
    //cout << "the instance of CArrayEnc was destroyed" << endl;
}

int CArrayEnc::searchInTable(const string &str)
{
    for (int i = 0; i < LZW_DICT_SIZE; i++)
        if (str == m_symbolTable[i].getSymbol()) return i;
    
    return -1;
}

vector <unsigned int> CArrayEnc:: encode (const string &text)
{
    // return vector, welcher die die indizes speichert.
    vector<unsigned int> trans;
    
    // gibt einen leeren vector zurück, für den fall, dass der übermittelte string empty ist.
    if (text == "") return trans;
    
    // dieser iterator wird benutzt um den string zeichen für zeichen einzulesen
    string::const_iterator reader (text.begin());
    
    // Sx ist der string welcher sich immer weiter aufbaut bis er nicht mehr im dictionary enthalten ist, dieser wird im fall das ein neuer eintrag ins dictionary hinzugefügt werden muss, dort ans ende hinzugefügt
    // S hingegen ist immer einen Schritt zurück. S wird zu jeder zeit im dictionary enthalten sein. im falle, dass Sx nicht mehr auffindbar ist, wird der index von S dem vector hinzugefügt.
    string Sx;
    string S ("");
    
    // index gibt den index eines strings im dictionary an.
    int index;
    
    // sagt welches der nächste freie index im dictionary ist, am anfang 256, da der konstruktor bereits die einträge von 0-255 belegt hat.
    unsigned int c = 256;
    
    // x speichert immer den buchstaben der gerade eingelsen wurde.
    char x = *reader;
    
    // solange nicht EOF erreicht ist wird der loop wiederholt.
    while (reader != text.end())
    {
        // die concatenation von S und x wird in Sx abgespeichert.
        Sx = S + x;
        
        // bestimmt ob und wenn ja wo der string im dicitonary abgepeichert ist.
        index = searchInTable(Sx);
        
        // case: Sx nicht im dictionary vorhanden.
        if (index == -1)
        {
            // sende index von dem nich auffindbaren, um den letzen buchstaben verringerten, string Sx (sprich S). der index wird also dem vector hinten angefügt.
            trans.push_back(searchInTable(S));
            
            // nun wird der string Sx dem dictionary an der nächsten freien stelle hinzugefügt.
            m_symbolTable[c].setSymbol(Sx);
            c++;
            
            //es wird wieder von vorne der string S neu aufgebaut und zunächst mit dem noch nicht gesendeten element x beschrieben. anschließend springt der reader zum nächsten zeichen.
            S = x;
            x = *(++reader);
        }
        
        // case: Sx ist bereits im dictionary vorhanden.
        else
        {
            //der S baut sich weiter auf und der loop beginnt von vorne.
            S = Sx;
            x = *(++reader);
        }
    }
    
    // wenn das ende des files erreicht ist sind alle bis auf die noch in S enthaltenen zeichen gesendet. somit muss dieser index am ende noch explizit dem vector hinzugefügt werden.
    trans.push_back(searchInTable(S));
    
    return trans;
}



CArray<CEntry, LZW_DICT_SIZE> CArrayEnc::getdic ()
{
    return m_symbolTable;
}
