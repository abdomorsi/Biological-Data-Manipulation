#include "Sequence.h"
#include<fstream>
#include<iomanip>

template <class T>
Sequence<T>::Sequence()
{
    seq = new char [100000];

}
template <class T>
Sequence<T> :: Sequence ( T* str )
{
    seq = new char [100000];
    int i = 0;
    for ( ; str[i] != NULL ; i++ )
    {
        seq[i] = str[i];
    }
    seq[i] = 0;
}
template <class T>
Sequence<T>::~Sequence()
{
    //dtor
}
template <class T>
int Sequence<T>:: calSize()
{
    int i = 0;
    for(;seq[i] != NULL;i++){}
    return i;
}

//template <class T>
//int Sequence<T>:: calSize()
//{
//    int i = 0;
//    for(;seq[i] != NULL;i++){}
//    return i;
//}

template <class T>
Sequence<T> :: Sequence(string str)
{
    seq = new char [100000];
    int i = 0;
    for ( ; str[i] != NULL ; i++ )
    {
        seq[i] = str[i];
    }
    seq[i] = 0;
}
template <class T>
Sequence<T> :: Sequence(Sequence& rhs)
{
    ///cout << 111111111111 << endl;
    seq = new char [100000];
    int i = 0;
    for(; rhs.seq[i] != NULL; i++)
        seq[i] = rhs.seq[i];
        seq[i] = 0;
}

template <class T>
ostream& operator<<(ostream& out,const Sequence<T>& S)
{
//    s->Print();
    return out;
}


char LCS_chars[1000];
template<class T>
char* Align(Sequence<T> * s1, Sequence<T> * s2)
{
    int len1 = s1->calSize();///get size of first sequence
    int len2 = s2->calSize(); ///get size of second sequence
    int length[len1+1][len2+1];
    int c = 0; ///counter to insert the chars in LCS
    int j=0 , i=0;

    for ( i=0 ; s1->seq[i]!=NULL  ; i++){
            //cout <<  i << "\n";
        for ( j=0 ; s2->seq[j]!=NULL  ; j++){
      //      cout << "second loop \n";

            if(i==0||j==0)
                length[i][j]=0;
            else if (s1->seq[i-1]==s2->seq[j-1] ){
                length[i][j]=length[i-1][j-1]+1;
                //cout << s1->seq[i-1]<<" " << s2->seq[j-1]<< "AA" << endl;
            }
            else
                length[i][j]=max(length[i][j-1] ,length[i-1][j]);
        }

    }
    //cout << i << j << "AA" << endl;

    int lcs = length[i-1][j-1];///length of common sequence
//    cout << lcs  << "\n" ;
    LCS_chars [ lcs + 1]; /// make C_string to store common sequence with length lcs
    LCS_chars[ lcs ]= NULL ; /// terminating last char

    while (i > 0 && j > 0)
    {
        //cout << "while loop \n" ;

      //  cout << s1->seq[i-1]<< "aa" << i-1 << " " << s2->seq[j-1]<< "AA" << endl;
        if ( s1->seq[i-1] == s2->seq[j-1]  ){
             //cout << lcs  << "\n" ;

            LCS_chars[ lcs ] = s1->seq[i-1];
         //    cout << s1->seq[i-2]<< " " << s2->seq[j-2]<< "AA" << endl;
            lcs--;
            i--;
            j--;

        }
        else if ( length[i][j-1] > length[i-1][j] )
            j--;

        else
            i--;
    }

    return LCS_chars;
}

template <class T>
void Sequence<T> :: save_Sequence( string filename)
{
    ofstream file1;
    file1.open(filename);
    for(int i=0;seq[i]!=NULL;i++)
    {
        file1<<seq[i];
    }
    file1.close();


}


