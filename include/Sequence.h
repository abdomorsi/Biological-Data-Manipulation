#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
using namespace std;

template <class T>

class Sequence
{
    protected:
    char * seq;
public:
    // constructors and destructor
    Sequence();
    ///Sequence(int length);
    Sequence(T* str);
    Sequence(string str);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    int calSize();
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
     virtual void Print()= 0;

    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism
    friend char* Align(Sequence * s1, Sequence * s2);
    //friend istream& operator>> (istream& in , Sequence& S);
    friend ostream& operator<< (ostream& out , Sequence* s);
   /// bool operator== ( Sequence S );
   /// bool operator!= ( Sequence S );
   /// Sequence operator+ ( Sequence& S );
    void save_Sequence(string filename);

};

#endif // SEQUENCE_H
