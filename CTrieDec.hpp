#ifndef CTrieDec_hpp
#define CTrieDec_hpp

#include <iostream>
#include <string>
#include "CArray.hpp"
#include "CDec.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"

using namespace std;

/*!
 \class CTrieDec
 \brief Dekodierung Teilaufgabe 2
    Diese Klasse stellt den Decoder für den LZW Algorithmus, des zweiten Teils der Praktikumsaufgabe, dar. Hierbei wird das erstellte Dictionary in einem Trie gepeichert. Die benötigten indizees für neue dictionary einträge werden von einer hashfunktion bestimmt. Zudem ist noch eine funktion implementiert welcher anhand eines gegebenen indizees den trie bis zur wurzel hinaufwandert und so den string an einem index besrtimmt.
 */


class CTrieDec :public CDec
{
public:
    /*! \fn CTrieDec()
        \brief Konstruktor
        dies ist der Konstruktor welcher eine instanz von der Klasse CTrieDec erstellt. hierbei werden werden die ersten 265 einträge des arrays, m_symbolTable (dictionary), mit den strings, welche zu den positionen 0-255 der ASCII-tabelle gehören, belegt. zudem werden in der initialisierungsliste der konstruktor der basisklasse CDec aufgerufen. die variable für den elternknoten wird jeweils mit -1 initialisiert, da es sich bei diesen einträgen um die wurzelelemente handelt. bei den noch unbelegten knoten, wird die variable, die den elternknoten angibt mit -2 initilaisiert.
     */
    CTrieDec();
    
    /*! \fn string decode (const vector<unsigned int>&)
        \brief Dekodierungsalgorithmus
        nun wird der enkodierte string wieder dekodiert. hierbei wird nun index für index aus dem input vektor ausgelesen. im idealfall ist dieser bereits im zuvor dicitonary enthalten und kann rekonstruiert werden mithilfe der unten deklarierten construct_string funktion. ist dies jedoch nicht der fall liegt folgender fall vor. der index welcher ausgelesen wurde wird erst später im gleichen iterationsschritt des loops ins dicitonary gespeichert. so kann man jedoch den string erschließen, da der neue string, der letze string mit dessen ersten zeichen am ende ist. so hat man dieses problem gelöst. in jedem schritt wird zu dem jeweiligen index der string konstruiert und an den outpur string rangehängt. wenn alle indizees ausgelesen wurden, wird der output string ausgegeben.
        \param in ist der input vektor mit den idizees welcher ausgelesen wird
        \return die dekomprimierte zeichenkette.
     */
    string decode (const vector<unsigned int>&in);
    
private:
    /*! \var CArray<CKnot, LZW_DICT_SIZE> m_symbolTable
        \brief Dictionary
      Datenstruktur CArray bestend aus elementen con CKnot. 
     */
    CArray<CKnot, LZW_DICT_SIZE> m_symbolTable;
    
    /*! \fn string construct_string (int)
        \brief String Konstruktor
        bildet von dem index den jeweiligen string, indem er von diesem durch den jeweiligen parent bis zur wurzel die jeweiligen symbols herausliest  und aneinanderhängt.
        \param idx ist ein belegter index im dicitonary.
        \return ist die konstruierte zeichenkette. 
     */
    string construct_string (int idx);
    
    
};

#endif
