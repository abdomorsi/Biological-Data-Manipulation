#include "Protein.h"
#include"DNA.h"

using namespace std;
void Protein<T> ::  add_newProtein (const DNA<T> & bigDNA , int i , int SIZE ,int SIZE2,int index, string temp,DNA<T>* DNAs){
    if (i>=SIZE){ return; }
    temp += bigDNA.seq[i];
   //cout << temp << endl;
    if(temp.size() < SIZE2) return add_newProtein(bigDNA , i+1 , SIZE , SIZE2 , index, temp,DNAs);
    if(temp.size() == SIZE2 ){
        DNA<T> d(temp) ;
       // cout << SIZE2 << endl;
        RNA<T> r ;
        r=d.ConvertToRNA();
        Protein<T> p;
        CodonsTable c;
        p = r.ConvertToProtein(c);
        bool IS = true;
        for (int i =0 ; i<temp.size() ; i++){
             if(p.seq[i] != seq[i]) IS = false;
        }
        if(IS == false) return add_newProtein(bigDNA,i-SIZE2+2,SIZE,SIZE2,index,temp="",DNAs);
        DNA<T>* a = new DNA<T>(temp);
        DNAs[index++] = *a;
            //cout << temp << endl;

        return add_newProtein(bigDNA,i+1,SIZE,SIZE2,index,temp="",DNAs);
    }
}
template <class T>
Protein<T>::Protein()
{
    //ctor
}
template<class T>
Protein<T> :: Protein(char*seq): Sequence(seq)
{

}
template <class T>
Protein<T>::~Protein()
{
}
template <class T>
void  Protein<T>::Print()
{
    cout << this ->seq << endl;
}
DNA<T>* Protein<T> :: GetDNAStrandsEncodingMe(const DNA<T> & bigDNA)
{
    int counter = 1 , newB=0 , newE = 8 , SIZE=0;

    for ( int i = 0 ; bigDNA.seq[i]!=NULL ; i+=counter ){
        SIZE++;
    }
    int SIZE2 = 0;
    for(int i = 0;this->seq[i]!= NULL;i++) SIZE2++;
    DNA<T>* DNAs = new DNA<T>[100];
    add_newProtein(bigDNA,0,SIZE,SIZE2*3,0,"",DNAs);
    return DNAs;


}
template <class T>
istream&  operator>>(istream& in,Protein<T>& S)
{
    in>>S.seq;
    return in;
}
template <class T>
ostream& operator<<(ostream& out,Protein<T>& S)
{
    out<<S.seq;
    return out;
}
template<class T>
bool Protein<T> :: operator== ( Protein<T> S )
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
template<class T>

bool Protein<T> :: operator!= ( Protein<T> S )
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
template<class T>
Protein<T> Protein<T>:: operator+ ( Protein<T>& S )
{
   ///Protein w;
   char kk[10000];
   int c=0;
  /// cout << S << endl;
   for(int i=0;seq[i]!=NULL;i++)
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
        ///cout << w.seq[c] << endl;
        break;
        }
   }
   Protein<T> w(kk);
  /// cout << w << endl;
   return w;
}

