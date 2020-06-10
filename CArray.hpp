#ifndef CArray_hpp
#define CArray_hpp

#include <iostream>
#include "XOutOfBounds.hpp"
using namespace std;

// deklararion und definition von member funktionen in hpp, da template klasse
// T is the type parameter and N determines the length of the array.
template <typename T, unsigned int N = 0> class CArray
{
public:
    CArray ();
    
    // cutstom kopierkonstruktor, wegen zeigervariable (tiefe kopie)
    CArray (CArray<T,N>& other);
    virtual ~CArray ();
    
    // index operator (wirft ggf. XOutOfBounds)
    T& operator[] (unsigned int index);
    
    long int find (const T& element);
    
    T* begin();
    
    T* end ();
    
private:
    T* entries;
    
};

// Constructor
template <typename T, unsigned int N>
CArray<T,N>::CArray (): entries (new T [N]){};

//Copy constructor (tiefe kopie durch new)
template <typename T, unsigned int N>
CArray<T,N>::CArray (CArray<T,N>& other): entries(new T [N])
{
    for (int i = 0; i < N; i++)
        entries [i] = other.entries[i];
}

// Destructor
template <typename T, unsigned int N>
CArray<T,N>::~CArray ()
{
    delete[] entries;
    //cout << "INSTANCE OF CArray WAS DELETED!" << endl;
}

// Assignement operator (wirft ggf. exception)
template <typename T, unsigned int N>
T& CArray<T,N>::operator[](unsigned int index)
{
    if (index >= N)
        throw XOutOfBounds ("the index is too large");
    
    else
        return entries [index];
}

// binary search function
// rekursiv
template <typename T, unsigned int N>
long int CArray<T,N>::find (const T& element)
{
    
    // variable wird nur einmal initialisiert
    static int index = N/2;
    
    // element gefunden 
    if (entries[index] == element)
        return index;
    
    if (index == 1)
        return -1;
    
    // rekursion (entweder kleiner oder größer)
    if (entries[index] < element){
        index = index + index / 2;
        find (element);
    }
    if (entries[index] > element){
        index = index / 2;
        find (element);
    }
    return -1;
}

// returns pointer to first element of the array
template <typename T, unsigned int N>
T* CArray<T,N>::begin() { return entries;}

// returns pointer to adress behind the last element
template <typename T, unsigned int N>
T* CArray<T,N>::end() { return entries+N;}

#endif /* CArray_hpp */
