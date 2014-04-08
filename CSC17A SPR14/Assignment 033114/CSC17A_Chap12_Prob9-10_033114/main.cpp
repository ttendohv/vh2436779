/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 1:35 PM
 * Gaddis Chapter 12 Problem 9-10
 * File Encryption and Decryption
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Global Constants

//Function Prototypes
vector<char> read(ifstream&);
void encrypt(vector<char>&);
void write(vector<char>&,ofstream&);
void decrypt(vector<char>&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    vector<char> file;
    //Open and read in text
    ifstream in;
    in.open("101nos.txt");
    file=read(in);
    in.close();
    //Encrypt text
    encrypt(file);
    //Output encryption
    ofstream out;
    out.open("Encrypt.txt");
    write(file,out);
    out.close();
    //Open and read in text for decryption
    vector<char> file2;
    ifstream encrypt;
    encrypt.open("Encrypt.txt");
    file2=read(encrypt);
    encrypt.close();
    //Decrypt text
    decrypt(file2);
    //Output decryption
    ofstream decrypted;
    decrypted.open("Decrypted.txt");
    write(file2,decrypted);
    decrypted.close();
    //Exit
    return 0;
}

vector<char> read(ifstream& a){
    vector<char> b;
    char letter;
    while(a.get(letter)){
        b.push_back(letter);
    }
    return b;
}

void encrypt(vector<char>& a){
    for(int i=0;i<a.size();i++){
        a[i]+=10;
    }
}

void write(vector<char>& a,ofstream& b){
    for(int i=0;i<a.size();i++){
        b << a[i];
    }
}

void decrypt(vector<char>& a){
    for(int i=0;i<a.size();i++){
        a[i]-=10;
    }
}