/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 9:37 AM
 * Gaddis Chapter 11 Problem 13
 * Drink Machine Simulator
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User-defined Libraries
#include "DrinkMachine.h"

//Global Constants

//Function Prototypes
void initial(Drink[],int);
void display(Drink[],int);
void select(Drink[],float&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=5;
    Drink machine[SIZE];
    bool quit;
    char choice;
    float total=0.0;
    //Initialize
    initial(machine,SIZE);
    //Display
    do{
        display(machine,SIZE);
        cout << "Press 1 to pick a drink and anything "
                "else to quit. ";
        cin >> choice;
        if(choice=='1'){
            quit=false;
            select(machine,total);
        }else quit=true;
    }while(!quit);
    cout << setprecision(2) << fixed << showpoint;
    cout << "This machine earned a total of $" << total << endl;
    //Exit
    return 0;
}

void select(Drink a[],float &total){
    int choice;
    float money;
    bool repeat;
    
    do{
        repeat=false;
        do{
            cout << "Enter the corresponding number to choose "
                    "a drink. ";
            cin >> choice;
        }while(choice<1||choice>5);
        if(a[choice-1].numDrnk==0){
            cout << a[choice-1].name << " is sold out. Please make another "
                    "selection." << endl;
            repeat=true;
        }
    }while(repeat);
    
    do{
        cout << setprecision(2) << fixed << showpoint;
        cout << "Please enter at least $" << a[choice-1].cost << ", but "
                "no more than $1.00\n $";
        cin >> money;
    }while(money>1||money<a[choice-1].cost);
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Your change is $" << money-a[choice-1].cost << endl;
    total+=a[choice-1].cost;
    a[choice-1].numDrnk--;
    cout << endl;
}

void display(Drink a[],int n){
    cout << endl;
    for(int i=0;i<n;i++){
        cout << setprecision(2) << fixed << showpoint;
        cout << i+1 << ". " << setw(12) <<  a[i].name 
                << setw(5) << a[i].cost << endl;
    }
    cout << endl;
}

void initial(Drink a[],int n){
    //Cola
    a[0].name="Cola";
    a[0].cost=0.75;
    //Root Beer
    a[1].name="Root Beer";
    a[1].cost=0.75;
    //Lemon-Lime
    a[2].name="Lemon-Lime";
    a[2].cost=0.75;
    //Grape Soda
    a[3].name="Grape Soda";
    a[3].cost=0.80;
    //Cream Soda
    a[4].name="Cream Soda";
    a[4].cost=0.80;
    //All
    for(int i=0;i<n;i++){
        a[i].numDrnk=20;
    }
}