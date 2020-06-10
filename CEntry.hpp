#ifndef CEntry_hpp
#define CEntry_hpp

#include <iostream>
#include <string>
using namespace std;

class CEntry
{
public:
    /*!
     This is the the Constructor.
     */
    CEntry();
    
    /*!
     This is the the Destructor.
     */
    virtual ~CEntry ();
    
    /*!
     This getter method returns the the string stored in the m_symbol variable of an object.
     */
    const string& getSymbol() const;
    
    /*!
     This setter method takes a string as an argument and assigns it to the m_symbol variable of an object.
     */
    void setSymbol (const string);
    
    
    /*!
     This getter method returns the value of the member variable m_number.
     */
    static unsigned int getNumber ();
    
private:
    
    string m_symbol;
    
    static unsigned int m_number;
};

#endif /* CEntry_hpp */
