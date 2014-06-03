/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on April 7, 2014, 10:17 AM
 * Testing Hashcash Algorithm
 */

//System Libaries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <sstream>
using namespace std;

//User-defined Libraries
/* From General Purpose Hash Function Algorithms Library 
 * Author: Arash Partow - 2002                                      
 * URL: http://www.partow.net                                        
 * URL: http://www.partow.net/programming/hashfunctions/index.html */
#include "GeneralHashFunctions.h" 

//Global Variables

//Function Prototypes
void prntRes(int[],int);
int cntDgts(string);
unsigned int hashFunct(string,int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=10,count;
    int freq[SIZE];
    //Initialize
    for(int i=0;i<SIZE;i++)
        freq[i]=0;
    srand(static_cast<unsigned int>(time(0)));
    unsigned int randNum = rand();
    cout << "Initial random number: " << randNum << endl << endl;
    //Use quote
    string quote = "Then out spake brave Horatius, "
                       "The Captain of the Gate: "
                       "To every man upon this earth "
                       "Death cometh soon or late. "
                       "And how can man die better "
                       "Than facing fearful odds, "
                       "For the ashes of his fathers, "
                       "And the temples of his gods.";
    cout << "Quote: " << quote << endl << endl;
    //Choose hash function
    int choice;
    cout << "Choose which Hashing Function you would like to run: " << endl;
    cout << "  1. RS-Hash Function\n"
            "  2. JS-Hash Function\n"
            "  3. PJW-Hash Function\n"
            "  4. ELF-Hash Function\n"
            "  5. BKDR-Hash Function\n"
            "  6. SDBM-Hash Function\n"
            "  7. DJB-Hash Function\n"
            "  8. DEK-Hash Function\n"
            "  9. FNV-Hash Function\n"
            "  10. BP-Hash Function\n"
            "  11. AP-Hash Function\n";
    cin >> choice;
    cout << endl;
    
    //Record start time
    int start = time(0);
    do{
        //Create a concatenation of the two by first converting the random
        //number to a string
        //cout << "Random number " << randNum << endl;
        ostringstream convert;   // stream used for the conversion
        convert << randNum++;      // insert the textual representation of 'Number' in the characters in the stream
        string strRnd = convert.str();
        //cout << "Text of random number " << strRnd << endl;
        //Concatenate two strings
        string newMsg = strRnd + quote;
        //cout << "New string " << newMsg << endl;
        //Use hash function on new string
        unsigned int hashNum = hashFunct(newMsg,choice);
        //cout << "Hash result " << hashNum << endl;
        //Convert hash to string
        ostringstream convert1;
        convert1 << hashNum++;
        string hashRes = convert1.str();
        //cout << "Text of hash result " << hashRes << endl;        
        
        count=cntDgts(hashRes);
        freq[count]++;
    }while(count>2);
    
    //Take the time it took
    int end = time(0);
    //Output the result
    cout<<"The total time took: "<<end-start<<" (secs)"<<endl<<endl;
    prntRes(freq,SIZE);
    
    //Exit
    return 0;
}

unsigned int hashFunct(string a,int choice){
    
    
    switch(choice){
        case 1:
            //RS-Hash Function
            return RSHash(a);
            break;
        case 2:
            //JS-Hash Function
            return JSHash(a);
            break;
        case 3:
            //PJW-Hash Function
            return PJWHash(a);
            break;
        case 4:
            //ELF-Hash Function
            return ELFHash(a);
            break;
        case 5:
            //BKDR-Hash Function
            return BKDRHash(a);
            break;
        case 6:
            //SDBM-Hash Function
            return SDBMHash(a);
            break;
        case 7:
            //DJB-Hash Function
            return DJBHash(a);
            break;
        case 8:
            //DEK-Hash Function
            return DEKHash(a);
            break;
        case 9:
            //FNV-Hash Function
            return FNVHash(a);
            break;
        case 10:
            //BP-Hash Function
            return BPHash(a);
            break;
        case 11:
            //AP-Hash Function
            return APHash(a);
            break;
        default:
            break;
    }
}

void prntRes(int freq[],int n){
    //Output the frequency for each occurence
    for(int i=n-1;i>=0;i--){
        cout << "10^" << i <<" occured "<<freq[i]<<" times"<<endl;
    }
}

int cntDgts(string a){
    return a.length()-1;
}