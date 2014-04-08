/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 10:27 AM
 * Gaddis Chapter 11 Problem 14
 * Inventory Bins
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User-defined Libraries
#include "InventoryBins.h"

//Global Constants

//Function Prototypes
void initial(Inventory[]);
void display(Inventory[],int);
void addPrts(Inventory[],int);
void remPrts(Inventory[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=10,bin;
    Inventory parts[SIZE];
    bool quit;
    char choice;
    //Initialize
    initial(parts);
    
    do{
        display(parts,SIZE);
        cout << "Enter 1 to choose a bin or anything else to quit: ";
        cin >> choice;
        if(choice=='1'){
            quit=false;
            cout << "Enter in corresponding number to choose a bin: ";
            cin >> bin;
            cout << "Enter 1 to add parts or 2 to remove parts: ";
            cin >> choice;
            if(choice=='1')
                addPrts(parts,bin-1);
            else
                remPrts(parts,bin-1);
        }else quit=true;
    }while(!quit);
    //Exit
    return 0;
}

void addPrts(Inventory a[],int bin){
    int temp = a[bin].numPrts,
        add;
    bool repeat;
    
    do{
        repeat=false;
        do{
        cout << endl;
            cout << "How many parts would you like to "
                    "add to this bin? (Must be greater than 0). ";
            cin >> add;
        }while(add<0);
        if((temp+add)>30){
            cout << "You have added too many parts. Items "
                    "in bin cannot exceed 30. Please try again." << endl;
            repeat=true;
        }else{
            a[bin].numPrts+=add;
        }
    }while(repeat);
}

void remPrts(Inventory a[],int bin){
    int temp = a[bin].numPrts,
        remv;
    bool repeat;
    
    do{
        repeat=false;
        do{
        cout << endl;
            cout << "How many parts would you like to "
                    "remove from this bin? (Must be greater than 0). ";
            cin >> remv;
        }while(remv<0);
        if((temp-remv)<0){
            cout << "You have chosen to remove too many parts. "
                    "Please try again." << endl;
            repeat=true;
        }else{
            a[bin].numPrts-=remv;
        }
    }while(repeat);
}

void display(Inventory a[],int n){
    cout << endl;
    for (int i=0;i<n;i++){
        cout << setw(2) << i+1 << ". " << setw(15) << a[i].name 
                << setw(3) << a[i].numPrts << endl;
    }
    cout << endl;
}

void initial(Inventory a[]){
    //Initialize
        //Valve
        a[0].name="Valve";
        a[0].numPrts=10;
        //Bearing
        a[1].name="Bearing";
        a[1].numPrts=5;
        //Bushing
        a[2].name="Bushing";
        a[2].numPrts=15;
        //Coupling
        a[3].name="Coupling";
        a[3].numPrts=21;
        //Flange
        a[4].name="Flange";
        a[4].numPrts=7;
        //Gear
        a[5].name="Gear";
        a[5].numPrts=5;
        //Gear Housing
        a[6].name="Gear Housing";
        a[6].numPrts=5;
        //Vacuum Gripper
        a[7].name="Vacuum Gripper";
        a[7].numPrts=25;
        //Cable
        a[8].name="Cable";
        a[8].numPrts=18;
        //Rod
        a[9].name="Rod";
        a[9].numPrts=12;
}