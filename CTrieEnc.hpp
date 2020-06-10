#ifndef CTrieEnc_hpp
#define CTrieEnc_hpp

#include <iostream>
#include "CArray.hpp"
#include "CEnc.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"

using namespace std;


/*!
 \class CTrieEnc
 \brief Enkodierung Teilaufgabe 2
    Diese Klasse stellt den Encoder für den LZW Algorithmus, des zweiten Teils der Praktikumsaufgabe, dar. Hierbei wird das erstellte Dictionary in einem Trie gepeichert. Die benötigten indexe für neune dictionary einträge werden von einer hashfunktion ermittelt.
 */

class CTrieEnc : public CEnc
{
public:
    /*! \fn CTrieEnc ()
        \brief Konstruktor
        dies ist der Konstruktor welcher eine instanz von der Klasse CTrieEnc erstellt. hierbei werden werden die ersten 265 einträge des arrays, m_symbolTable (dictionary), mit den strings, welche zu den positionen 0-255 der ASCII-tabelle gehören, belegt. zudem werden in der initialisierungsliste der konstruktor der basisklasse CDec aufgerufen. die variable für den elternknoten wird jeweils mit -1 initialisiert, da es sich bei diesen einträgen um die wurzelelemente handelt. bei den noch unbelegten knoten, wird die variable, die den elternknoten angibt mit -2 initilaisiert.
     */
    CTrieEnc();
    
    /*! \fn vector <unsigned int> encode (const string &)
        \brief Enkodierungsalgorithmus
        diese funktion ist letztendlich für die encodierung zuständig. sie iteriert durch den input string und baut hierbei das bereits im konstruktor angelegte dictionary weiter aus. zudem wird hierbei immer wieder geprüft ob eine eingelesene zeichenkette bereits vorhanden ist. wenn dies der fall ist wird diese erweitert bis sie nicht mehr im doctionary vorhanden ist. nun wird diese unbekannte hinzugefügt und der index des letzen bekannten strings an den output vecotr gesendet. die indizees der neuen dicitonary einträge werden durch eine hash funktion bestimmt (inkl. rehashing bei kollisionen). am ende gibt die funktion einen vector zurück welcher die indizes in der richtigen reihenfolge beinhaltet.
        \param in ist die zu enkodierende zeichenkette.
        \return vector aus unsigned ints welcher die indizees speichert
     */
    vector <unsigned int> encode (const string &in);
    
    
private:
    /*! \var CArray<CKnot, LZW_DICT_SIZE> m_symbolTable
        \brief Dictionary
        dies ist die datenstruktur, in der der encoder das dictionary abspeichert. das array hat eine größe von LZW_DICT_SIZE, welches eine im file CLZW.hpp definierte konstante ist. der datentyp der array-elemente ist CKnot.
     */
    CArray<CKnot, LZW_DICT_SIZE> m_symbolTable;
};




#endif
