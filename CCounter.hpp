#ifndef CCounter_hpp
#define CCounter_hpp

#include <iostream>

class CCounter {
public:
    
    /*! the function constructs an object of the CCounter class and initializes
     *  the value of the m_value variable with 0.
     */
    CCounter();
    
    /*! the function increments the m_count variable by 1
     */
    
    virtual ~CCounter();
    
    
    virtual void count();
    
    /*! the function returns the value of the m_value variable.
     */
    int getValue () const;
    
    
    void setValue(int value);
    
    // impelmentation von vergleichsoperatoren
    bool operator < (const CCounter &h) const;
    
    bool operator > (const CCounter &h) const;
    
    
private:
    int m_count;
    
}
;




#endif
