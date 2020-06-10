#ifndef CArrayEnc_hpp
#define CArrayEnc_hpp

#include <iostream>
#include <string>
#include "CEnc.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

using namespace std;

/*!
 \class CArrayEnc
 \brief Enkodierung Teilaufgabe 1
    Diese Klasse stellt den Encoder für den LZW Algorithmus, des ersten Teils der Praktikumsaufgabe, dar. Hierbei wird das erstellte Dictionary in einem Array gepeichert. Das Array ist vom Datentyp CArray, welcher bereits im File CArray.hpp als Template-Klasse existiert.
 */

class CArrayEnc : public CEnc
{
public:
    /*! \fn CArrayEnc ()
        \brief Konstruktor
        dies ist der Konstruktor welcher eine instanz von der Klasse CArrayEnc erstellt. hierbei werden werden die ersten 265 einträge des arrays, m_symbolTable (dictionary), mit den strings, welche zu den positionen 0-255 der ASCII-tabelle gehören, belegt. zudem werden in der initialisierungsliste der konstruktor der basisklasse CEnc aufgerufen.
     */
    CArrayEnc ();
    
    /*! \fn virtual ~CArrayEnc();
     \brief Destruktor
     dies ist der destruktor der klasse CArrayEnc. er sollte als sicherheitsmaßnahme immer als virtual definiert werden (#polymorphie).
     */
    virtual ~CArrayEnc();
    
    /*! \fn int searchInTable (const string&)
        \brief sucht string im dcitionary
        diese methode bekommt eine referenz auf einen konstanten string übergeben. nun wird das gesamte dicitonary nach dem parameter durchsucht. bei erfolgreicher suche wird der index-wert des array zurückgegeben an dem sich der string befindet, ansonsten wird -1 zurückgegeben.
        \param string welcher im dictionary gesucht werden soll
        \return integer that represents the index of the string in the dictionary
     */
    int searchInTable (const string& string);
    
    /*! \fn vector <unsigned int> encode (const string &)
        \brief encoder
        diese methode ist nun für das encoding zuständig. es wird als parameter eine referenz auf den konstanten string übergeben, der durch den LZW algorithmus komprimiert werden soll. dann wird der lzw encoding algorithmus angewand. ist dies geschehen wird schlussendlich ein vector mit den indizes, welcher so an den decoder gesendet wird, zurückgegeben.
        \param in ist die zu enkodierende zeichenkette.
        \return vector aus unsigned ints welcher die indizees speichert 
     */
    vector <unsigned int> encode (const string &in);
    
    CArray<CEntry, LZW_DICT_SIZE> getdic ();
    
    
private:
    /*! \var CArray<CEntry, LZW_DICT_SIZE> m_symbolTable
        \brief dictionary
        dies ist die datenstruktur, in der der encoder das dictionary abspeichert. das array hat eine größe von LZW_DICT_SIZE, welches eine im file CLZW.hpp definierte konstante ist. der datentyp der array-elemente ist CEntry.
     */
    CArray<CEntry, LZW_DICT_SIZE> m_symbolTable;
};

#endif
