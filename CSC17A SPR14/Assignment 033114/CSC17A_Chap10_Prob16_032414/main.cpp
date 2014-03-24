/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 24, 2014, 3:22 PM
 * Gaddis Chapter 10 Problem 16
 * Pig Latin
 */

//System Libraries
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    
    
    //Exit
    return 0;
}

string pigLatin(string a,int size){
    string pigLtn,temp[size],ending="ay";
    int pos,indx,srch=0;
    
    do{
        indx=0;
        for(int i=0;i<size;i++){
            temp[i]='\0';
        }
        pos=a.find(' ',srch);
        srch=pos+1;
        temp[indx]=a[pos-1];
        for(int i=0;i<pos-1;i++){
            temp[++indx]=a[i];
        }
        temp.append(1,ending);
        pigLtn.append(1,temp);
    }while(pos<size);
}//Try using a vector to push back instead of append