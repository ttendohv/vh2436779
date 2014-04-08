/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 9:18 PM
 * Gaddis Chapter 11 Problem 10
 * Speakers' Bureau
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User-defined Libraries
#include "SpkrInfo.h"

//Global Constants

//Function Prototypes
void menuChc(Speaker[],int,char);
void newData(Speaker[],int&);
void chgData(Speaker[],int);
void prntData(Speaker[],int);
bool srch(Speaker[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=10;
    char choice;
    Speaker people[SIZE];
    
    //Display Menu
    do{
        cout << "Enter the corresponding number to make a choice:\n"
                "  1. Enter in new speaker information\n"
                "  2. Change any speaker's information\n"
                "  3. Display speakers' information\n"
                "  \nEnter anything else to quit.\n";
        cin >> choice;
        menuChc(people,SIZE,choice);
    }while(choice=='1'||choice=='2'||choice=='3');     
    
    //Exit
    return 0;
}

void menuChc(Speaker p[],int size,char choice){
    static int pos=0;
    
    switch(choice){
        case '1':
            //Insert new data
            newData(p,pos);
            break;
        case '2':
            //Change data
            chgData(p,size);
            break;
        case '3':
            //Print all data entered
            for(int i=0;i<pos;i++){
                prntData(p,i);
            }
            break;
        default:
            break;
    }
    
}

void newData(Speaker p[],int &pos){
    char i;
    do{
        cout << endl;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,p[pos].name);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,p[pos].number);
        cout << "Speaking topic: ";
        getline(cin,p[pos].topic);
        cout << "Fee Required: $";
        cin >> p[pos].fee;
        
        cout << endl;
        cout << "Enter 0 to enter in information for another speaker, "
                "enter in anything else to quit: ";
        cin >> i;
        pos++;
        cout << endl;
    }while(i=='0');
}

void chgData(Speaker p[],int size){
    //Search for item to change    
    int indx;
    bool found;
    //Print available 
    cout << endl;
    cout << "Enter in the corresponding number to "
            "change information: " << endl;
    found=srch(p,size);
    if(found){
        cin >> indx;
        indx--;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,p[indx].name);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,p[indx].number);
        cout << "Speaking topic: ";
        getline(cin,p[indx].topic);
        cout << "Fee Required: $";
        cin >> p[indx].fee;
    }    
    cout << endl;
}

void prntData(Speaker p[],int pos){
    cout << endl;
    cout << "Name: " << p[pos].name << endl;
    cout << "Telephone Number: " << p[pos].number << endl;
    cout << "Speaking Topic: " << p[pos].topic << endl;
    cout << "Required Fee: $" << p[pos].fee << endl;
    cout << endl;
}

bool srch(Speaker p[],int size){
    string key;
    int found,notFnd=0;
    
    cout << "Enter in a key word of the topic you "
            "want to search for: ";
    cin >> key;
    cout << endl;
    
    for(int i=0;i<size;i++){
        found=(p[i].topic).find(key,0);
        if(found!=string::npos){
            cout << i+1 << ". ";
            prntData(p,i);
        }else notFnd++;
    }if (notFnd==size){
        cout << "No matches found." << endl;
        return false;
    }else return true;
}