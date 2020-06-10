#ifndef CForwardCounter_hpp
#define CForwardCounter_hpp

#include <stdio.h>
#include <iostream>
#include "CCounter.hpp"

/*!
 \file CForwardCounter.hpp
 \brief Counter
 diese klasse implementiert einen counter, welcher die rehashing versuche in der Trie implementation des LZW zählt. 
 */
class CForwardCounter : public CCounter
{
public:
    void count ();
};

#endif /* CForwardCounter_hpp */
