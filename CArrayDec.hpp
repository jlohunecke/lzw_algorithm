#ifndef CArrayDec_hpp
#define CArrayDec_hpp

#include <iostream>
#include <string>
#include "CDec.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

using namespace std;

/*!
 \class CArrayDec
 \brief Dekodierung Teilaufgabe 1
    diese Klasse stellt den Decoder für den LZW Algorithmus, des ersten Teils der Praktikumsaufgabe, dar. Hierbei wird das erstellte Dictionary in einem Array gepeichert. Das Array ist vom Datentyp CArray, welcher bereits im File CArray.hpp als Template-Klasse existiert.
 */

class CArrayDec : public CDec
{
public:
    /*! \fn CArrayDec ()
        \brief Konstruktor
        dies ist der Konstruktor welcher eine instanz von der Klasse CArrayDec erstellt. hierbei werden werden die ersten 256 einträge des arrays, m_symbolTable (dictionary), mit den strings, welche zu den positionen 0-255 der ASCII-tabelle gehören, belegt. zudem werden in der initialisierungsliste der konstruktor der basisklasse CDec aufgerufen. die m_dic_lngth wird auf 256 gesetzt.
     */
    CArrayDec();
    
    /*! \fn ~CArrayDec ()
        \brief Destruktor
        dies ist der Destructor welcher eine instanz von der Klasse CArrayDec erstellt. hierbei werden werden die ersten 265 einträge des arrays, m_symbolTable (dictionary), mit den strings, welche zu den positionen 0-255 der ASCII-tabelle gehören, belegt. zudem werden in der initialisierungsliste der konstruktor der basisklasse CDec aufgerufen.
     */
    virtual ~CArrayDec();
    
    /*! \fn const string decode (vector<unsigned int>)
        \brief dekodierungsalgorithmus
        dies ist die decoder funktion. sie bekommt den vector, den der encoder ausgegeben hat, als argument übergeben und kann so ein eigenes dicitonary anhand des lzw algorithmus erstellen und den string rekonstruieren. im sonderfall, wenn ein eingelesener index noch nicht im dicitonary ecistiert, kann dieser dennoch konstruiert werden.
        \param in ist der input vektor mit den idizees welcher ausgelesen wird
        \return die dekomprimierte zeichenkette.
     */
    string decode (const vector<unsigned int>&in);
    
private:
    /*! \var CArray<CEntry, LZW_DICT_SIZE> m_symbolTable
        \brief dictionary
        dies ist die datenstruktur, in der der decoder das dictionary abspeichert. das array hat eine größe von LZW_DICT_SIZE, welches eine im file CLZW.hpp definierte konstante ist. der datentyp der array-elemente ist CEntry.
     */
    CArray<CEntry, LZW_DICT_SIZE> m_symbolTable;
    
    
    /*! \var unsigned int m_dic_lngth
        \brief dictionary length
        der algoritmus muss wissen welches nächste dictionary position ist wo er einen eintrag erstellen kann. diese variable wird von der funktion inkrementiert.
    */
    unsigned int m_dic_lngth;
};




#endif
