#ifndef RNA_H
#define RNA_H
#include"sequence.h"
//#include"Protein.h"
//#include"CodonsTable.h"
#include<iostream>
using namespace std;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

template <class T>
class DNA ;

template <class T>
class RNA : public Sequence<T>
{

private:
    RNA_Type type;
public:
    // constructors and destructor
    RNA();
    RNA(char * seq, RNA_Type atype);
    RNA(const RNA& rhs);
    ~RNA();
    // function to be overridden to print all the RNA information
    void Print();
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
//    Protein ConvertToProtein(const CodonsTable & table);
    // function to convert the RNA sequence back to DNA
  DNA<T> ConvertToDNA();
   /// friend void Protein<T> ::  add_newProtein (const DNA & bigDNA , int i , int SIZE ,int SIZE2,int index, string temp,DNA* DNAs);
    friend istream& operator>> (istream& in , RNA & S);
    friend ostream& operator<< (ostream& out ,const RNA& S);
    bool operator== ( RNA S );
    bool operator!= ( RNA S );
    RNA operator+ ( RNA& S );


};

#endif // RNA_H
