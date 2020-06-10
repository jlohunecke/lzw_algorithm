#include "CTrieDec.hpp"


CTrieDec::CTrieDec(){
    for (int c = 0; c < 265; c++)
    {
        m_symbolTable[c].setParent(-1);
        m_symbolTable[c].setSymbol(intToString(c));
    }
}


string CTrieDec::construct_string(int index){
    string out ("");
    
    int i = index;
    
    // loopt durch alle miteinander verbundenen knoten bis man beim wurzelelement angekommen ist und konstruiert den string (reihenfolge beachten).
    while (i >= 0) {
        out = m_symbolTable [i].getSymbol() + out;
        i = m_symbolTable [i].getParent();
    }
    return out;
}


string CTrieDec::decode (const vector<unsigned int>& in) {
    
    string out ("");
    
    // case leerer vector
    if (in.size() == 0) return out;
    
    auto iter = in.begin();
    
    // ersten index einlesen
    unsigned int idx = *(iter++);
    
    out += m_symbolTable[idx].getSymbol();
    
    unsigned int hv, init_hv; // hashvalues
    
    // zweiten index einlesen
    idx = *iter;
    
    // loop solange bis die sequenz vollständig ausgelesen wurde
    while (iter != in.end()) {
        
        // wenn index im wörterbuch vorhanden ist
        if (m_symbolTable[idx].getParent() != -2) {
            
            CForwardCounter attempt;
            
            // speichert den ersten buchstabe des jetzigen strings
            int s = charToInt(construct_string(idx).front());
            
            hv = CDoubleHashing::getInstance().hash(*(iter-1), s, LZW_DICT_SIZE, attempt.getValue());
            init_hv = hv;
            
            // rehashing, bricht ab wenn man auf einen leeren knoten trifft, auf einen knoten mit gleichem parent und symbol trifft oder der hash value wieder beim ersten hashwert ankommt und somit keine neuen werte zu erwarten sind
            if (m_symbolTable[hv].getParent() != *(iter-1) && m_symbolTable[hv].getSymbol() != intToString(s) && m_symbolTable[hv].getParent() != -2) {
                do {
                    attempt.count();
                    hv = CDoubleHashing::getInstance().hash(*(iter-1), s, LZW_DICT_SIZE, attempt.getValue());
                }
                while (!((m_symbolTable[hv].getParent() == -2) || ((m_symbolTable[hv].getParent() == *(iter-1)) && (m_symbolTable[hv].getSymbol()) == intToString(s)) || (hv == init_hv)));
            }
            
            // füge den zum index gehörigen string zum output string hinzu
            out += construct_string(idx);
            
            // neuer eintrag im dicitonary wird erstellt
            m_symbolTable[hv].setParent(*(iter-1));
            string n (1, construct_string(idx).front());
            m_symbolTable[hv].setSymbol(n);
        }
        
        // spezialfall, wenn gesuchter index noch nicht vorhanden ist. hier wissen wir das der für das hashing benötigte char der erste des letzen teilstrings ist und können somit mit dem zuvor eingelesenen index arbeiten
        else {
            CForwardCounter attempt;
            int s = charToInt(construct_string(*(iter-1)).front());
            
            hv = CDoubleHashing::getInstance().hash(*(iter-1), s, LZW_DICT_SIZE, attempt.getValue());
            init_hv = hv;
            
            // rehashing, gleiche abbruchbedingungen wie oben, nur dass sich alles auf den letzen anstatt von dem jetzigen index bezieht
            if (m_symbolTable[hv].getParent() != *(iter-1) && m_symbolTable[hv].getSymbol() != intToString(s) && m_symbolTable[hv].getParent() != -2) {
                do {
                    attempt.count();
                    hv = CDoubleHashing::getInstance().hash(*(iter-1), s, LZW_DICT_SIZE, attempt.getValue());
                }
                while (!((m_symbolTable[hv].getParent() == -2) || ((m_symbolTable[hv].getParent() == *(iter-1)) && (m_symbolTable[hv].getSymbol()) == intToString(s)) || (hv == init_hv)));
            }
            
            // string an den output anhängen. ACHTUNG!!! von letzen index mit erstem buchstaben auch am ende.
            out += (construct_string(*(iter-1)) + construct_string(*(iter-1)).front());
            
            // nun neuen eintrag im dictionary erstellen (aktueller hashvalue)
            m_symbolTable[hv].setParent(*(iter-1));
            string n (1, construct_string(*(iter-1)).front());
            m_symbolTable[hv].setSymbol(n);
        }
        
        // weitere indizees einlesen
        idx = *(++iter);
        
    }
    
    // output
    return out;
}
