#include "RNA.h"
#include "DNA.h"
template <class T>
RNA<T>::RNA()
{
    //ctor
}

template<class T>
RNA<T> :: RNA(char * seq, RNA_Type atype) : Sequence<T> (seq)
{
    type = atype ;

}
template <class T>
RNA <T>:: RNA(const RNA& rhs): Sequence<T>(rhs.seq)
{
    type =  rhs.type;


}
template <class T>
RNA<T>::~RNA()
{
}
template <class T>
void RNA<T> :: Print()
{

    cout << "type is : ";
    if ( mRNA==type )
    {
        cout << "mRNA" << endl;
    }
    if ( pre_mRNA==type )
    {
        cout << "pre_mRNA" << endl;
    }
    if ( mRNA_exon==type )
    {
        cout << "mRNA_exon" << endl;
    }
    if ( mRNA_intron==type )
    {
        cout << "mRNA_intron" << endl;
    }
    cout << *this << endl;


}
template<class T>
DNA<T> RNA<T> :: ConvertToDNA()
{
    int c=0;
    char str[10000];
    for(int i=0;this-> seq[i]!=NULL; i++)
    {
      if(this ->seq[i]=='U'){
        str[i]='T';
      }
      else{
       str[i]=this ->seq[i];
      }
      c=i;
    }
str[c+1]=NULL;
    DNA<T> b(str,promoter);
    return b;


}
/*Protein<T> RNA<T> :: ConvertToProtein(const CodonsTable & table)
{

    char value[4];
    char arr[305];
    char amino;
    int j=0;
    //cout << 111 << endl;
  for(int i=0;seq[i]!=NULL;i+=3)
  {
      value[0]=seq[i];
       value[1]=seq[i+1];
      value[2]=seq[i+2];
      value[3] = NULL;
      //cout << 1 << endl;
    amino=table.getAminoAcid(value);
    arr[j++]=amino;

  }
  arr[j]=NULL;

    Protein b(arr);

  return b;
}*/
template <class T>
istream&  operator>>(istream& in,RNA<T>& S)
{
    in>>S.seq;
    return in;
}
template <class T>
ostream& operator<<(ostream& out,const RNA<T>& S)
{
    out<<S.seq;
    return out;
}
template <class T>
bool RNA<T> :: operator== ( RNA<T> S )
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
bool RNA<T> :: operator!= ( RNA<T> S )
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
RNA<T> RNA<T> :: operator+ ( RNA<T>& S )
{
   ///RNA w;
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
        ///cout << w.seq[c] << endl;
        break;
        }
   }
   RNA<T> w(kk,mRNA);
  /// cout << w << endl;
   return w;
}

