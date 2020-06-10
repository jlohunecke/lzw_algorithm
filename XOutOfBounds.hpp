#ifndef XOutOfBounds_hpp
#define XOutOfBounds_hpp

#include <iostream>
#include <string>

using namespace std;

/*!
 \file XOutOfBounds.hpp
 \brief Diese Klasse erstellt einen für CArray relevanten Exception Datentypen.
 */

class XOutOfBounds
{
public:
    /*!
     \fn XOutOfBounds (const string error)
     \brief Konstruktor
     bekommt die fehlermeldung als string übergeben.
     */
    XOutOfBounds (const string error);
    
    virtual ~XOutOfBounds ();
    
    // fehlermeldung auslesen 
    string geterror () const;
    
private:
    string m_error;
};

#endif /* XOutOfBounds_hpp */
