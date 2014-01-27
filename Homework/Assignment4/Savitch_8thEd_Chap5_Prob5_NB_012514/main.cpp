/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 4:39 PM
 * Savitch 8th Edition Chapter 5 Problem 5
 * Amount of Change
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int QTR_VAL = 25;
const int DIM_VAL = 10;
const int PEN_VAL = 1;

//Function Prototypes
void numCoin(int, int&, int&);
string coinWrd(int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int number, amount;
    char response;
    string coin;
    do{
        do{
            //Input amount of change between 1 and 99 cents
            cout << "Enter the amount of change you have in cents, "
                    "between 1 and 99: ";
            cin >> amount;
            cout << endl;
        }while (amount < 1 || amount > 99);
        //Calculate number of quarters, dimes and pennies to be
        //given and output
        cout << amount << " cents can be given as:" << endl;
        numCoin(QTR_VAL, number, amount);
        coin = coinWrd(QTR_VAL, number);
        cout << "  " << number << coin << endl;
        numCoin(DIM_VAL, number, amount);
        coin = coinWrd(DIM_VAL, number);
        cout << "  " << number << coin << endl;
        numCoin(PEN_VAL, number, amount);
        coin = coinWrd(PEN_VAL, number);
        cout << "  " << number << coin << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for a new "
                "amount? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
    //Exit
    return 0;
}

//Calculate number of coins based on coin value
//Input
//      coin value
//      number of coins
//      amount of change left
//Output
//      none
//      reference number of coins, change left
void numCoin(int coinVal, int& num, int& amtLeft){
    num = amtLeft / coinVal;
    amtLeft %= coinVal;
}

//Print out coin word based on coin value
//Input
//      coin value
//      number of coins
//Output
//      string with coin in English
string coinWrd(int coinVal, int num){
    if (coinVal == QTR_VAL){
        if (num > 1 || num < 1) return " quarters";
        else return " quarter";
    }else if (coinVal == DIM_VAL){
        if (num > 1 || num < 1) return " dimes";
        else return " dime";
    }else{
        if (num > 1 || num < 1) return " pennies";
        else return " penny";
    }
}