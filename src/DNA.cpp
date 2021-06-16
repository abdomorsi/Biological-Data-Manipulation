#include "DNA.h"
#include<bits/stdc++.h>
using namespace std;

template <class T>
DNA<T>::DNA()
{
    type = promoter;
    startIndex = 0;
    endIndex = 0;
    ///cout << 2 << endl;
    complementary_strand = NULL;
    ///cout << 1 << endl;
    //ctor
}

//template <class T>
//DNA<T> ::  DNA(T * seq, DNA_Type atype) : Sequence<T>(seq)
//{
//
//    type = atype;
//    startIndex = 0;
//    endIndex = calSize()-1;
//    complementary_strand = NULL;
//
//}

template <class T>
DNA<T> :: DNA(string str) : Sequence<T>(str)
{
       complementary_strand = NULL;
        startIndex = 0;
        endIndex = str.size();
}

template <class T>
DNA<T> :: DNA(const DNA& rhs) :  Sequence<T>(rhs.seq)
{
    type=rhs.type;
   ///complementary_strand= new DNA;
    /// *complementary_strand=*(rhs.complementary_strand);
    complementary_strand=NULL;

   // startIndex=rhs.startIndex;
    //endIndex=rhs.endIndex;
}

template <class T>
void DNA<T> :: Print()
{

    cout << "type is : ";
    if ( promoter==type )
    {
        cout << "promoter" << endl;
    }
    if ( motif==type )
    {
        cout << "motif" << endl;
    }
    if ( tail==type )
    {
        cout << "tail" << endl;
    }
    if ( noncoding==type )
    {
        cout << "noncoding" << endl;
    }
    BuildComplementaryStrand();
    cout << "The main strand is:  "<<*this << endl;

    cout<<"The complementry strand is : "<<complementary_strand->seq << endl;
}

template <class T>
void DNA<T> :: BuildComplementaryStrand()
{
    string seq1;
    int c=startIndex;
    for(int i=0;i<(endIndex-startIndex+1);++i)
    {
        switch(this->seq[c])
        {
        case 'T':
            seq1+='A';
            break;
        case 'A':
            seq1+='T';
            break;
        case 'C':
            seq1+='G';
            break;
        case 'G':
            seq1+='C';
            break;
        }
        ///seq1+=seq[c];
        c++;
    }
    ///cin>>seq1;
    reverse(seq1.begin(),seq1.end());
   /// cout<<seq1<<endl;
   int s=0;
   ///cout<<seq1.length()<<endl;
   char seq2[1000];
   for(int i=0;i<seq1.length();i++)
   {
      /// cout<<i<<endl;
       seq2[i]=seq1[i];
       s=i;
      /// cout<<s<<endl;

   }
   s++;
   ///cout<<s;
   seq2[s]=NULL;
   complementary_strand= new DNA<T>(seq2,promoter);
   ///cout<<a.seq;
}
///try
/*
template <class T>
RNA<T> DNA<T> :: ConvertToRNA()
{
    int c=0;
    char str[10000];

    for(int i=0,j=startIndex; seq[i]!=NULL && j <= endIndex; i++,j++)
    {
      if(seq[j]=='T'){
        str[i]='U';
      }
      else{
       str[i]=seq[j];
      }
      c=j;
    }
str[c+1]=NULL;
    RNA<T> b(str,mRNA);

    return b;


}
*/
template <class T>
istream&  operator>>(istream& in,DNA<T>& S)
{
    in>>S.seq;
    return in;
}

template <class T>
ostream& operator<<(ostream& out,const DNA<T>& S)
{
    out<<S.seq;
    return out;
}

template<class T>
bool DNA<T> :: operator== ( DNA<T> S )
{
    /* bool IS = true ;
     int i = 0;
     for(  ;  S.seq[i]!=NULL ; i++ ){
         if (seq[i] != S.seq[i]){ IS = false; break; }
     }
     if ( S.seq[i+1]==NULL && seq[i+1]!=S.seq[i+1] ){ IS = false;  }

     return IS;*/
     if(type != S.type) return false;
    for(int i=0;; i++)
    {
        if(this->seq[i]!=S.seq[i])
        {
            return false;
        }
        else if(this->seq[i]==NULL)
        {
            break;
        }
    }

    return true;

}

template <class T>
bool DNA<T> :: operator!= ( DNA S )
{
    /* bool isEqual=true;
    for(int i=0;; i++)
     {
         if(seq[i]!=S[i])
         {
             isEqual=false;
         }
         else if(seq[i]==NULL)
         {
             break;
         }
     }
     if(isEqual==true){
         return false;
     }
     else{
         return true;
     }*/
    return(!(*this==S));

}

template <class T>
DNA<T> DNA<T> :: operator+ (const DNA<T>& S )
{
   ///DNA w;
   char kk[10000];
   int c=0;
   ///cout << S << endl;
   for(int i=0;this->seq[i]!=NULL;i++)
    {
    kk[i]=this->seq[i];
     c=i;
    }
   int k=0;
   c++;
   for( ;;c++){
        if(S.seq[k]!=NULL){
        kk[c]=S.seq[k];
      k++;
    }
        else{
        kk[c]=S.seq[k];
       /// cout << kk[c] << endl;
        break;
        }
   }
   DNA<T> w(kk,promoter);

   return w;
}






template <class T>
DNA<T>::~DNA()
{
    //dtor
}
