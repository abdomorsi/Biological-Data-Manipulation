#ifndef PROTEIN_H
#define PROTEIN_H
#include"sequence.h"



#include<iostream>
using namespace std;
template<class T>
class DNA;


enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
template <class T>
class Protein : public Sequence<T>
{
private:
    Protein_Type type;
public:
    // constructors and destructor
    Protein();
    Protein(T * seq);
    ~Protein();
    void Print();
    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    DNA<T>* GetDNAStrandsEncodingMe(const DNA<T> & bigDNA);
    void  add_newProtein (const DNA<T> & bigDNA , int i , int SIZE ,int SIZE2,int index, string temp,DNA<T>* DNAs);
    friend istream& operator>> (istream& in , Protein<T>& S);
    friend ostream& operator<< (ostream& out , Protein<T>& S);
    bool operator== ( Protein<T> S );
    bool operator!= ( Protein<T> S );
    Protein operator+ ( Protein<T>& S );

};


#endif // PROTEIN_H
