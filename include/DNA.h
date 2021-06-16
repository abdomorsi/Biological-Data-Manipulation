#ifndef DNA_H
#define DNA_H
#include"sequence.h"
#include"RNA.h"
#include<iostream>
#include"Protein.h"
using namespace std;

enum DNA_Type {promoter, motif, tail, noncoding};
template <class T>

class DNA : public Sequence<T>
{
    private:
        DNA_Type type ;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;

    public:
        DNA();
        DNA (T * seq, DNA_Type atype);
        DNA (const DNA& rhs);
        DNA(string str);

        void Print();

       RNA<T> converToRNA();
        void BuildComplementaryStrand();
      friend DNA<T>* Protein<T> :: GetDNAStrandsEncodingMe(const DNA<T> & bigDNA);
    friend void Protein<T> ::  add_newProtein (const DNA<T> & bigDNA , int i , int SIZE ,int SIZE2,int index, string temp,DNA* DNAs);
        friend istream& operator>> (istream& in , DNA<T>& S);
        friend ostream& operator<< (ostream& out , const DNA<T>& S);
        bool operator== ( DNA<T> S );
        bool operator!= ( DNA<T> S );
        DNA operator+ ( const DNA<T>& S );


        ~DNA();
    protected:

};

#endif // DNA_H
