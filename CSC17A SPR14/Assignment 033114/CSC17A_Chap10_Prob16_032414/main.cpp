/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 24, 2014, 3:22 PM
 * Gaddis Chapter 10 Problem 16
 * Pig Latin
 */

//System Libraries
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Global Constants

//Function Prototypes
void pigLatin(string&,vector<char>&);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    string sntce = "This is a test";
    vector<char>final;
    //Translate
    pigLatin(sntce,final);
    //Print
    for(int i=0;i<final.size();i++)
        cout << final[i];
    cout << endl;
    //Exit
    return 0;
}

//string pigLatin(string a,int size){
//    string pigLtn;
//    string temp(size,'\0');
//    string ending("ay");
//    int pos,indx,srch=0;
//    
//    do{
//        indx=0;
//        for(int i=0;i<size;i++){
//            temp[i]='\0';
//        }
//        pos=a.find(' ',srch);
//        srch=pos+1;
//        temp[indx]=a[pos-1];
//        for(int i=0;i<pos-1;i++){
//            temp[++indx]=a[i];
//        }
//        temp.append(1,ending);
//        pigLtn.append(1,temp);
//    }while(pos<size);
//}
//Try using a vector to push back instead of append

//void pigLatin(string &a,vector<char>& b){
//    int size = a.length();
//    
//    vector<char>temp;
//    string ending("ay");
//    int pos,indx=0;
//    //srch=0;
//    
//    do{
//        //indx=0;
//        
//        
//        pos=a.find(' ',indx);
//        //indx=pos+1;
//        temp.clear();
//        for(int i=indx;i<pos-1;i++)
//            temp.push_back(a[i]);
//        temp.push_back('a');
//        temp.push_back('y');
//        for(int j=0;j<temp.size();j++)
//            b.push_back(temp[0]);
//        b.push_back(' ');
//        indx=pos+1;
//    }while(indx<size);
//    
//}

string pigLatin(string &a){
    int size=a.length();
    string temp,ending("ay");
    int pos,indx=0;
    
    do{
        pos=a.find(' ',indx);
      
        temp(a,indx,pos);
        temp+=ending;
        indx=pos+1;
        temp(' ',pos);
    }while(indx<size);
}
