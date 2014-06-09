/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on June 2, 2014, 10:03 AM
 * CSC7 Project 2
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

//User-defined Libraries
#include "GeneralHashFunctions.h"

//Global Constants

//Function Prototypes
bool login();
void subsets(vector<string>&,int,bool&);
string choose(vector<string>&);
void fillBitAry(vector<bool>&,string);
unsigned int findIndx(string,int);
char encrypt(char);
void guessing(vector<bool>&,char[],char[],int);
void printPostn(char[],int);
bool searchBitAry(vector<bool>&,char);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    
    if(login()){
        //Choose word
        int number;
        vector<string>sbset(0);
        bool setfound;
        do{
            cout << "Enter in a number for the size of word you would "
                "like to guess: ";
            cin >> number;
            sbset.clear();
            subsets(sbset,number,setfound);
        }while(!setfound);
        
        string word = choose(sbset);
        //cout << word << endl;
        //Fill Bit Array
        int size = 52;
        vector<bool>a(size);
        fillBitAry(a,word);
        //Initialize guess and solution arrays
        char guess[word.length()], solution[word.length()];
        for(int i=0;i<word.length();i++){
            guess[i]=i+'0';
        }
        for(int i=0;i<word.length();i++){
            solution[i]=encrypt(word[i]);
        }
        //Make guess
        cout << "The word you must guess is " << word.length() 
                << " letters long. " << endl;
        guessing(a,guess,solution,word.length());
        }else{
        cout << "Invalid user name and/or password. Exiting now..." << endl;
    }
    return 0;
}

//Login before playing game
bool login(){
    fstream file;
    char choice;
    unsigned int hashUser,hashPW;
    string userName,password;
    unsigned int nums[25]={};
    
    cout << "Enter 1 to Login or 2 to Create and new account" << endl;
    cin >> choice;

    if(choice=='1'){
        file.open("Data.txt", ios::in);
        int j=0;
        while(file >> nums[j++]){
        }
        file.close();
        cout << "Enter your user name: ";
        cin >> userName;
        cout << "Enter your password: ";
        cin >> password;

        hashUser = BKDRHash(userName);
        hashPW = BKDRHash(password);

        int found=0,indx;
        //search for hashUser in inputs
        //if found, check password against the first index after
        //if password matches, return true
        //if not found, return false;
        for(int i=0;i<j-1;i++){
            if(hashUser==nums[i]){
                found++;
                indx=i;
            }
        }
        if(found>0){
            if(hashPW==nums[indx+1])return true;
            else return false;
        }else return false;
    }else if(choice=='2'){
        file.open("Data.txt", ios::out | ios::app);
        //Input account info
        cout << "Enter your user name: ";
        cin >> userName;
        cout << "Enter your password: ";
        cin >> password;

        hashUser = BKDRHash(userName);
        hashPW = BKDRHash(password);

        file << hashUser << endl;
        file << hashPW << endl;
        file.close();
        return true;
    }else{
        return false;
    }
}

//Choose subset of words
void subsets(vector<string>&words, int num, bool&found){
    vector<string>file;
    string temp;
    ifstream infile;
    infile.open("wordlist.txt");
    while(infile >> temp){
        file.push_back(temp);
    }
    infile.close();
    
    for(int i=0;i<file.size();i++){
        if(file[i].length()==num)
            words.push_back(file[i]);
    }
    
    if(words.size()==0){
        cout << "That set is empty. Try again. " << endl;
        found = false;
    }else{
        found = true;
    }
}

//Choose word
string choose(vector<string>& words){
//    //Test input
//    for(int i=0;i<words.size();i++){
//        cout << words[i] << " ";
//    }cout << endl;
    //Choose random word
    int indx = rand()%words.size();
    return words[indx];
}

void fillBitAry(vector<bool>& a,string w){
    for(int i=0;i<w.length();i++){
        string temp = "";
        temp+=w[i];
        unsigned int temp1 = findIndx(temp,1);
        unsigned int temp2 = findIndx(temp,2);
        
        a[temp1]=1;
        a[temp2]=1;
    }
}

bool searchBitAry(vector<bool>&a,char ltr){
    string temp = "";
    temp+=ltr;
    unsigned int temp1 = findIndx(temp,1);
    unsigned int temp2 = findIndx(temp,2);
    
    if(a[temp1]==1||a[temp2]==1){
        cout << "The letter is possibly in the secret word" << endl;
        return true;
    }else{
        cout << "The letter is not in the secret word" << endl;
        return false;
    }       
}

unsigned int findIndx(string a, int hash){
    unsigned int index;
    if(hash==1){
        index = APHash(a);
        return index%52;
    }else{
        index = PJWHash(a);
        return index%52;
    }
}

char encrypt(char a){
    int temp = a - '0';
    temp+=10;
    return (temp + '0');
}

void guessing(vector<bool>&a,char g[], char s[],int n){
    bool outerRepeat,innerRepeat;
    int filled = 0;
    cout << "You have a " << fixed << showpoint << setprecision(10) 
                << pow(1.0/26,n) * 100 << "% chance of guessing the entire "
                "word in one try. " << endl << endl;
    do{
        char letter;
        int count = 0;
        outerRepeat = false;
        cout << "Type in a letter to guess (letters may be "
                "repeated): ";
        cin >> letter;
        letter=tolower(letter);

        bool found=searchBitAry(a,letter);
        if(!found){
            //Try again
            cout << "Try again" << endl;
            outerRepeat = true;
        }else{
            do{
                innerRepeat = false;
                //Print positions
                printPostn(g,n);
                //Guess position
                int pos;
                cout << "You have at least a " << fixed << showpoint 
                        << setprecision(1) << 1.0/(n-filled) * 100 << "% chance of "
                        "correctly guessing this letter's position. " << endl; 
                cout << "Enter the position you would like to "
                        "place your letter: ";
                cin >> pos;
                if(encrypt(letter)==s[pos]){
                    g[pos]=letter;
                    filled++;
                    printPostn(g,n);
                    outerRepeat = true;
                    innerRepeat = false;
                }else{
                    count++;
                    cout << "Try again " << endl;
                    innerRepeat = true;
                    if(count>=(n-filled)){
                        cout << "Letter was not found. " << endl;
                        innerRepeat = false;
                        outerRepeat = true;
                    }
                }
            }while(innerRepeat);
            if(filled<n)outerRepeat = true;
            else outerRepeat = false;
        }
    }while(outerRepeat);
}

void printPostn(char a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }cout << endl;
}