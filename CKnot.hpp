#ifndef CKnot_hpp
#define CKnot_hpp

#include <iostream>
#include "CEntry.hpp"

/*!
 \file CKnot.hpp
 \brief Diese Klasse erstellt den datentypen aus dem das dictionary im TEIL 2 besteht (Trie).
 diesr datentyp besteht aus einem textsymbol und einem parent, welcher ebenfalls im trie wieder auf einen CKnot verweist.
 */

class CKnot : public CEntry
{
public:
    CKnot();
    int getParent() const;
    void setParent (int);
    
private:
    int m_parent;
};


#endif 
