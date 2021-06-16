/*
 * File: main.cpp
 * -----------------
 * This file has the main implementation of the program
 *
 *
 * Author:  Suhail - Shahesta - Abdelrahman
 * Version: 1.0
 * Date:    12 Dec. 2018
 */

#include <iostream>
#include"Sequence.h"
#include"DNA.h"
#include"RNA.h"
#include "exceptions.h"
#include "System.h"
#include <set>
using namespace std;


/// This function checks if he enters strange char or ASCII
template < class T>
void check(T*s, int choice1)
{
    if(choice1 == 1)
    {
        set<char> ss = {'A','T','C','G'};
        for(int i = 0; s[i] != NULL; i++)
            if(ss.count(s[i]) == 0)
                throw strangeCharDNA();
    }
    else if(choice1 == 2)
    {
        set<char> ss = {'A','U','C','G'};
        for(int i = 0; s[i] != NULL; i++)
            if(ss.count(s[i]) == 0)
                throw strangeCharRNA();
    }
    else
    {
        set<char> ss = {'K','N','T','R','S','I','M','Q','H','P','R','L','E','D','A','G','V','Y','C','W','L','F'};
        for(int i = 0; s[i] != NULL; i++)
            if(ss.count(s[i]) == 0)
                throw strangeCharProtein();
    }

}

/// this function checks if the user enters wrong data type input
void checkCIN()
{
    if(cin.fail()) throw wrongDataTypeInput();
}

template < class T>
void checkIsTherePreviousInput(Sequence<T>* s)
{
    if(s == NULL || s->getSeq().size() == 0) throw noPreviousInput();
}
int main()
{


    bool isChar = false;
    int choice1;
    Sequence<char>* s1 = NULL;
    Sequence<char>*s2 = NULL;
    Sequence<int>* s11 = NULL;
    Sequence<int>*s22 = NULL;

    bool rightChoice = false;
    while(rightChoice == false)
    {
    System().showIntro();/// The user here have to choose he want to enter his input as chars or ASCIIS



    try
    {
        cin >> isChar;
        checkCIN();   /// this function throws an exception if the users enters wrong data type input
        rightChoice = true;
    }
    catch(const wrongDataTypeInput& d)
    {
        cin.clear();
        cin.ignore();
        cout<< d.what() << endl;
    }
    }
    while(true)
    {
        try
        {
            if (isChar)
            {
                System().showMenu();
                int choice;
                cin >> choice;
                checkCIN();
                if(choice > 11 || choice < 1 ) throw notAvailableChoice();
                if(choice == 1) ///Loading a sequence
                {

                    cout << "Enter the type of the sequence \n 1- DNA \n 2- RNA \n 3- Protein" << endl;
                    cin >> choice1;
                    checkCIN();
                    if(choice1 == 1)  s1 = new DNA<char>;
                    else if(choice1 == 2) s1 = new RNA<char>;
                    else if(choice1 == 3) s1 = new Protein<char>;
                    else  throw notAvailableChoice();
                    cout << "Enter 2 if you want to load from file, 1 throw console" << endl;
                    cin >> choice;
                    checkCIN();
                    if(choice == 1) /// loading throw console
                    {
                        char sss[1000] = {0};
                        cout << "Enter the Sequence";
                        cin >> sss;
                        checkCIN();
                        check(sss, choice1);
                        if(choice1 == 1)
                        {
                            s1 = new DNA<char>(sss);
                        }
                        else if(choice1 == 2)
                        {
                            s1 = new RNA<char>(sss,mRNA);
                        }
                        else if(choice1 == 3)
                        {
                            s1 = new Protein<char>(sss);
                        }
                    }
                    else if(choice == 2)  ///loading throw file
                    {

                        string ss;
                        cout << "Enter FILE NAME : " << endl;
                        cin >> ss;
                        checkCIN();
                        s1-> load_Sequence(ss);
                    }
                    else throw notAvailableChoice();
                }
                else if(choice == 2) ///Saving a Sequence to file
                {
                    checkIsTherePreviousInput(s1);
                    cout << "Enter the file name you want to save to " << endl;
                    string ss;
                    cin >> ss;
                    checkCIN();
                    s1-> save_Sequence(ss);
                }
                else if(choice == 3) ///LCS
                {
                    checkIsTherePreviousInput(s1);
                    char str[1000] = {0};
                    cout << "Enter the sequence : " << endl;
                    cin >> str;
                    check(str,choice1);
                    if(choice1 == 1) s2 = new DNA<char>(str,promoter);
                    else if(choice1 == 2) s2 = new RNA<char>(str,mRNA);
                    else s2 = new Protein<char>(str);
                    cout << "the result of align is : " << Align(s1,s2) << endl;

                }
                else if(choice == 4) /// Global Alignment
                {
                    checkIsTherePreviousInput(s1);
                    cout << "Enter the sequence : " << endl;
                    char str[1000] = {0};
                    cin >> str;
                    checkCIN();
                    check(str,choice1);
                    cout << "Enter penalty 1 : " << endl;
                    int xx;
                    cin >> xx;
                    cout << "Enter penaltry 2 : " << endl;
                    int yy;
                    cin >> yy;
                    if(choice1 == 1) s2 = new DNA<char>(str,promoter);
                    else if(choice1 == 2) s2 = new RNA<char>(str,mRNA);
                    else s2 = new Protein<char>(str);
                    getMinimumPenalty(s1,s2,xx,yy);

                }
                else if(choice == 5) ///Printing details about sequence
                {checkIsTherePreviousInput(s1);s1->Print();}
                else if(choice == 6 ) /// comparing two sequences
                {
                    checkIsTherePreviousInput(s1);
                    char str[1000] = {0};
                    cout << "Enter the sequence : " << endl;
                    cin >> str;
                    checkCIN();
                    check(str,choice1);
                    if(choice1 == 1) s2 = new DNA<char>(str,promoter);
                    else if(choice1 == 2) s2 = new RNA<char>(str,mRNA);
                    else s2 = new Protein<char>(str);
                    if(s1->getSeq() == s2->getSeq()) cout << "The sequences are identical " << endl;
                    else cout << "The sequences are different " << endl;

                }
                else if(choice == 7) /// Adding two sequences
                {
                    checkIsTherePreviousInput(s1);
                    char str[1000] = {0};
                    cout << "Enter the sequence : " << endl;
                    cin >> str;
                    checkCIN();
                    check(str,choice1);
                    if(choice1 == 1) s2 = new DNA<char>(str,promoter);
                    else if(choice1 == 2) s2 = new RNA<char>(str,mRNA);
                    else s2 = new Protein<char>(str);
                    cout << "The result of adding sequences : " << s1->getSeq()+s2->getSeq() << endl;
                }
                else if(choice == 8) /// Converting to DNA
                {
                    checkIsTherePreviousInput(s1);
                    if(choice1 == 1) throw WrongConversion();
                    else if(choice1 == 2) cout << ( dynamic_cast<RNA<char>*>(s1) ) -> ConvertToDNA().getSeq() << endl;

                    else /// Protein Case
                    {
                        cout << "Enter the big DNA Sequence" << endl;
                        char str[1000] = {0};
                        cin >> str;
                        checkCIN();
                        check(str,1);
                        DNA<char> big(str,promoter);
                        DNA<char>* DNAs = ( static_cast<Protein<char>*>(s1) ) -> GetDNAStrandsEncodingMe(big);
                        cout << "The possible DNAs are : " << endl;
                        for(int i = 0; DNAs[i].getEndIndex() != 0; i++)
                            cout << DNAs[i].getSeq() << endl;

                    }
                }
                else if(choice == 9) /// Converting to RNA
                {
                    checkIsTherePreviousInput(s1);
                    if(choice1 == 1) cout << static_cast<DNA<char>*>(s1) -> ConvertToRNA().getSeq() << endl;
                    else  throw WrongConversion();

                }
                else if(choice == 10 ) /// Converting to Protein
                {
                    checkIsTherePreviousInput(s1);
                    if(choice1 == 1)
                    {
                        RNA<char> a = static_cast<DNA<char>*>(s1) -> ConvertToRNA();
                        cout << " The converted Sequence :  "  << a.ConvertToProtein(CodonsTable()).getSeq() << endl;
                    }
                    else if(choice1 == 2)
                    {
                        cout << "The converted Sequence : " << static_cast<RNA<char>*>(s1) -> ConvertToProtein(CodonsTable()).getSeq() << endl;
                    }
                    else throw WrongConversion();
                }
                else if(choice == 11) break; /// Exiting


            }

            else
            {
                System().showMenu();
                int choice;
                cin >> choice;
                checkCIN();
                if(choice > 11 || choice < 1 ) throw notAvailableChoice();
                if(choice == 1) /// Loading a Sequence
                {
                    int sss[1000] = {0};
                    cout << "Enter the type of the sequence \n 1- DNA \n 2- RNA \n 3- Protein" << endl;
                    cin >> choice1;
                    checkCIN();
                    cout << "Enter 2 if you want to load from file, 1 throw console" << endl;
                    cin >> choice;
                    checkCIN();
                    if(choice == 1)
                    {
                        cout << "Enter the length of the sequence" << endl;
                        int length;
                        cin >> length;
                        cout << "Enter the Sequence : " << endl;
                        for(int i = 0; i < length ; i++)
                            cin >> sss[i];
                        check(sss,choice1);
                        if(choice1 == 1)  s11 = new DNA<int>(sss,promoter);
                        else if(choice1 == 2) s11 = new RNA<int>(sss,mRNA);
                        else if(choice1 == 3) s11 = new Protein<int>(sss);

                    }
                    else if(choice == 2)
                    {
                        string ss;
                        cout << "Enter FILE NAME : " << endl;
                        cin >> ss;
                        checkCIN();
                        s11-> load_Sequence(ss);
                    }
                    else throw notAvailableChoice();

                }
                else if(choice == 2)  /// Saving the sequence to a file
                {
                    checkIsTherePreviousInput(s11);
                    cout << "Enter the file name you want to save to " << endl;
                    string ss;
                    cin >> ss;
                    checkCIN();
                    s11-> save_Sequence(ss);
                }
                else if(choice == 3) /// LCS
                {
                    checkIsTherePreviousInput(s11);
                    int str[1000]= {0};
                    cout << "Enter the length of the sequence" << endl;
                    int length;
                    cin >> length;
                    cout << "Enter the Sequence : " << endl;
                    for(int i = 0; i < length ; i++)
                        cin >> str[i];
                    checkCIN();
                    check(str,choice1);
                    if(choice1 == 1) s22 = new DNA<int>(str,promoter);
                    else if(choice1 == 2) s22 = new RNA<int>(str,mRNA);
                    else s22 = new Protein<int>(str);
                    cout << "the result of align is : " << Align(s11,s22);

                }
                else if(choice == 4) /// Global Alignment
                {
                    checkIsTherePreviousInput(s11);
                    cout << "Enter the sequence : " << endl;
                    int str[1000] = {0};
                    int length;
                    cin >> length;
                    for(int i = 0; i < length; i++)
                        cin >> str[i];
                    checkCIN();
                    check(str,choice1);
                    cout << "Enter penalty 1 : " << endl;
                    int xx;
                    cin >> xx;
                    cout << "Enter penaltry 2 : " << endl;
                    int yy;
                    cin >> yy;
                    checkCIN();
                    if(choice1 == 1) s22 = new DNA<int>(str,promoter);
                    else if(choice1 == 2) s22 = new RNA<int>(str,mRNA);
                    else s22 = new Protein<int>(str);
                    getMinimumPenalty(s1,s2,xx,yy);

                }
                else if(choice == 5){checkIsTherePreviousInput(s11); s11->Print(); } /// Printing details
                else if(choice == 6 ) /// Comparing two sequences
                {
                    checkIsTherePreviousInput(s11);
                    int str[1000]= {0};
                    cout << "Enter the length of the sequence" << endl;
                    int length;
                    cin >> length;
                    cout << "Enter the Sequence : " << endl;
                    for(int i = 0; i < length ; i++)
                        cin >> str[i];
                    checkCIN();
                    check(str,choice1);
                    if(choice1 == 1) s22 = new DNA<int>(str,promoter);
                    else if(choice1 == 2) s22 = new RNA<int>(str,mRNA);
                    else s22 = new Protein<int>(str);
                    if(s11 == s22) cout << "The sequences are identical " << endl;
                    else cout << "The sequences are different " << endl;

                }
                else if(choice == 7) /// Adding two sequences to each other
                {
                    checkIsTherePreviousInput(s11);
                    int str[1000]= {0};
                    cout << "Enter the length of the sequence" << endl;
                    int length;
                    cin >> length;
                    checkCIN();
                    cout << "Enter the Sequence : " << endl;
                    for(int i = 0; i < length ; i++)
                        cin >> str[i];
                    checkCIN();
                    check(str,choice1);
                    if(choice1 == 1) s22 = new DNA<int>(str,promoter);
                    else if(choice1 == 2) s22 = new RNA<int>(str,mRNA);
                    else s22 = new Protein<int>(str);
                    cout << "The result of adding sequences : " << s11->getSeq()+s22->getSeq() << endl;
                }
                else if(choice == 8) /// converting to DNA
                {
                    checkIsTherePreviousInput(s11);
                    if(choice1 == 1) throw WrongConversion();
                    else if(choice1 == 2) cout << static_cast<RNA<int>*>(s11) -> ConvertToDNA() . getSeq() << endl;
                    else if(choice1 == 3)
                    {
                        int str[1000]= {0};
                        cout << "Enter the length of the bigDNA SEQUENCE " << endl;
                        int length;
                        cin >> length;
                        checkCIN();
                        cout << "Enter the Sequence : " << endl;
                        for(int i = 0; i < length ; i++)
                            cin >> str[i];
                        checkCIN();
                        check(str,1);
                        DNA<int> big(str,promoter);
                        DNA<int>* DNAs = ( static_cast<Protein<int>*>(s11) ) -> GetDNAStrandsEncodingMe(big);
                        cout << "The possible DNAs are : " << endl;
                        for(int i = 0; DNAs[i].getEndIndex() != 0; i++)
                            cout << DNAs[i].getSeq() << endl;


                    }
                    else throw WrongConversion();
                }
                else if(choice == 9) /// converting to RNA
                {
                    checkIsTherePreviousInput(s11);
                    if(choice1 == 1) cout << static_cast<DNA<int>*>(s11) -> ConvertToRNA().getSeq() << endl;
                    else  throw WrongConversion();

                }
                else if(choice == 10 ) /// cONVERTING TO pROTEIN
                {
                    checkIsTherePreviousInput(s11);
                    if(choice1 == 1)
                    {
                        RNA<int> a = static_cast<DNA<int>*>(s11) -> ConvertToRNA();
                        cout << " The converted Sequence :  "  << a.ConvertToProtein(CodonsTable()).getSeq() << endl;
                    }
                    else if(choice1 == 2)
                    {
                        cout << "The converted Sequence : " << static_cast<RNA<int>*>(s11) -> ConvertToProtein(CodonsTable()).getSeq() << endl;
                    }
                    else throw WrongConversion();
                }
                else if(choice == 11) break; /// Exits


            }

        }
        catch(const strangeCharDNA& a)
        {
            cout<< a.what() << endl;
        }
        catch(const strangeCharRNA& b)
        {
            cout<< b.what() << endl;
        }
        catch(const strangeCharProtein& c)
        {
            cout<< c.what() << endl;
        }
        catch(const wrongDataTypeInput& d)
        {
            cin.clear();
            cin.ignore();

            cout<< d.what() << endl;
        }
        catch(const notAvailableChoice& e)
        {
            cout<< e.what() << endl;
        }
        catch(const WrongFileName& f)
        {
            cout << f.what() << endl;
        }
        catch(const noPreviousInput& l)
        {
            cout << l.what() << endl;
        }
        catch(...)
        {
            cout << "Wrong operation << please restart the program " << endl;
        }
        ///Deleting temp objects
        if(s2 != NULL) delete s1;
        if(s11 != NULL) delete s1;
    }
    /// Deleting all objects
    if(s1 != NULL) delete s1;
    if(s2 != NULL) delete s1;
    if(s11 != NULL) delete s1;
    if(s22 != NULL) delete s1;


}
