/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 27, 2014, 2:48 PM
 * Gaddis Chapter 11 Problem 8
 * Customer Accounts
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User-defined Libraries
#include "CustmrInfo.h"

//Global Constants

//Function Prototypes
void menuChc(Account[],int,char);
void newData(Account[],int&);
void chgData(Account[],int);
void prntData(Account[],int);
bool srch(Account[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=20;
    char choice;
    Account customer[SIZE];
    
    //Display Menu
    do{
        cout << "Enter the corresponding number to make a choice:\n"
                "  1. Enter in new customer data\n"
                "  2. Change any customer data\n"
                "  3. Display customer data\n"
                "  \nEnter anything else to quit.\n";
        cin >> choice;
        menuChc(customer,SIZE,choice);
    }while(choice=='1'||choice=='2'||choice=='3');     
    
    //Exit
    return 0;
}

void menuChc(Account c[],int size,char choice){
    static int pos=0;
    
    switch(choice){
        case '1':
            //Insert new data
            newData(c,pos);
            break;
        case '2':
            //Change data
            chgData(c,size);
            break;
        case '3':
            //Print all data entered
            for(int i=0;i<pos;i++){
                prntData(c,i);
            }
            break;
        default:
            break;
    }
    
}

void newData(Account c[],int &pos){
    char i;
    do{
        cout << endl;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,c[pos].name);
        cout << "Address (House number and Street only): ";
        getline(cin,c[pos].address);
        cout << "City: ";
        getline(cin,c[pos].city);
        cout << "State: ";
        getline(cin,c[pos].state);
        cout << "Zip Code: ";
        getline(cin,c[pos].zip);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,c[pos].number);
        cout << "Account balance: $";
        cin >> c[pos].balance;
        cin.ignore(1,'\n');
        cout << "Date of Last Payment: ";
        getline(cin,c[pos].date);
        
        cout << endl;
        cout << "Enter 0 to enter in data for a new account, "
                "enter in anything else to quit: ";
        cin >> i;
        pos++;
        cout << endl;
    }while(i=='0');
}

void chgData(Account c[],int size){
    //Search for item to change    
    int indx;
    bool found;
    //Print available 
    cout << endl;
    cout << "Enter in the corresponding number to "
            "change information: " << endl;
    found=srch(c,size);
    if(found){
        cin >> indx;
        indx--;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,c[indx].name);
        cout << "Address (House number and Street only): ";
        getline(cin,c[indx].address);
        cout << "City: ";
        getline(cin,c[indx].city);
        cout << "State: ";
        getline(cin,c[indx].state);
        cout << "Zip Code: ";
        getline(cin,c[indx].zip);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,c[indx].number);
        cout << "Account balance: ";
        cin >> c[indx].balance;
        cin.ignore(1,'\n');
        cout << "Date of Last Payment (MM/DD/YYYY): ";
        getline(cin,c[indx].date);
    }

    cout << endl;
}

void prntData(Account c[],int pos){
    cout << endl;
    cout << "Name: " << c[pos].name << endl;
    cout << "Address: " << c[pos].address << endl;
    cout << c[pos].city << ", " << c[pos].state << " " 
            << c[pos].zip << endl;
    cout << "Telephone Number: " << c[pos].number << endl;
    cout << "Account Balance: $" << c[pos].balance << endl;
    cout << "Date of Last Payment: " << c[pos].date << endl;
    cout << endl;
}

bool srch(Account c[],int size){
    string name;
    int found,notFnd=0;
    
    cout << "Enter in the name or part of the name you "
            "want to search for: ";
    cin >> name;
    cout << endl;
    
    for(int i=0;i<size;i++){
        found=(c[i].name).find(name,0);
        if(found!=string::npos){
            cout << i+1 << ". ";
            prntData(c,i);
        }
    }if(notFnd==size){
        cout << "No matches found. " << endl;
        return false;
    }else return true;
}