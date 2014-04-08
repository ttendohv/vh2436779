/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on April 1, 2014, 10:52 AM
 * Chapter 12 Problems
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//User-defined Libraries
#include "InventoryData.h"

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
        //Problem9-10
void problem9_10();
vector<char> read(ifstream&);
void encrypt(vector<char>&);
void write(vector<char>&,ofstream&);
void decrypt(vector<char>&);
        //Problem 13
void problem13();
void addRcrd(Inventory&,fstream&);
void dspRcrd(Inventory&,fstream&,long);
void chgRcrd(Inventory&,fstream&,long);


//Execution Begins Here
int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem9_10();break;
            case 2:    problem13();break;
            default:   def(inN);}
    }while(inN==1||inN==2);
    //Exit
    return 0;
}

void Menu(){
    cout << endl << endl;
    cout<<"Chapter 12 Homework"<<endl;
    cout<<"Type 1 for problem 9-10"<<endl;
    cout<<"Type 2 for problem 13"<<endl;;
    cout<<"Type anything else to exit \n"<<endl;
    cout << endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//File Encryption and Decryption
void problem9_10(){
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

//Inventory
void problem13(){
    //Declare variables
    Inventory item;
    int record;
    char choice;
    fstream invntry;
    invntry.open("Inventory.dat",ios::in | ios::out | ios::binary | ios::app);
    
    do{
        cout << "Enter in the corresponding number to make a choice: " << endl;
        cout << "  1. Add new records to the file. " << endl;
        cout << "  2. Display any record in the file. " << endl;
        cout << "  3. Change any record in the file. " << endl;
        cout << " Enter in anything else to quit. " << endl;
        cin >> choice;

        switch(choice){
            case '1':
                //Add records
                addRcrd(item,invntry);
                break;
            case '2':
                //Display any record
                cout << "Which record would you like to display? ";
                cin >> record;
                dspRcrd(item,invntry,record);
                break;
            case '3':
                //Change any record
                cout << "Which record would you like to change? ";
                cin >> record;
                chgRcrd(item,invntry,record);
                break;
            default:
                break;
        }
    }while(choice>0&&choice<4);
    //Exit
    invntry.close();
}

void addRcrd(Inventory &a,fstream& file){
    
    cout << "Enter in the following data about the item: " << endl;
    cout << "Item Description: ";
    cin.ignore();
    cin.getline(a.name,NAME);
    cout << "Quantity on Hand: ";
    cin >> a.qty;
    cout << "Wholesale Cost: ";
    cin >> a.wholesale;
    cout << "Retail Cost: ";
    cin >> a.retail;
    cout << "Date Added to Inventory: ";
    cin.ignore();
    cin.getline(a.dateAdd,DATE);
    
    file.write(reinterpret_cast<char *>(&a),sizeof(a));

}

void dspRcrd(Inventory &a,fstream& file,long record){
    file.seekg(sizeof(a)*record,ios::beg);
    file.read(reinterpret_cast<char *>(&a),sizeof(a));
    
    //Display
    cout << "Item Description: " << a.name << endl;
    cout << "Quantity on Hand: " << a.qty << endl;
    cout << "Wholesale Cost: $" << a.wholesale << endl;
    cout << "Retail Cost: $" << a.retail << endl;
    cout << "Date Added to Inventory: " << a.dateAdd << endl;

}

void chgRcrd(Inventory &a,fstream& file,long record){
    
    //Display data
    dspRcrd(a,file,record);
    
    //Get new data
    cout << "Enter new data: " << endl;
    cout << "Item Description: ";
    cin.ignore();
    cin.getline(a.name,NAME);
    cout << "Quantity on Hand: ";
    cin >> a.qty;
    cout << "Wholesale Cost: ";
    cin >> a.wholesale;
    cout << "Retail Cost: ";
    cin >> a.retail;
    cout << "Date Added to Inventory: ";
    cin.ignore();
    cin.getline(a.dateAdd,DATE);
    
    file.seekp(sizeof(a)*record,ios::beg);
    file.write(reinterpret_cast<char *>(&a),sizeof(a));
}