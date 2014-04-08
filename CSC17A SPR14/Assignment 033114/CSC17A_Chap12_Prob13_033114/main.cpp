/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 3:39 PM
 * Gaddis Chapter 12 Problem 13
 * Inventory
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User-defined Libraries
#include "InventoryData.h"

//Global Constants

//Function Prototypes
void addRcrd(Inventory&,fstream&);
void dspRcrd(Inventory&,fstream&,long);
void chgRcrd(Inventory&,fstream&,long);

//Execution Begins Here
int main(int argc, char** argv) {
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
    return 0;
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