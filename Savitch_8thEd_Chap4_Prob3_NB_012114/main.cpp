/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 21, 2014, 11:49 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float stkPrc(int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int shares, whDllr, frcNum, frcDenm;
    float price;
    char slash, response;
    do{
        //Input shares, dollar portion of price
        //and fraction portion of price
        cout << "How many shares of the stock do you own? ";
        cin >> shares;
        cout << "How much is each share? (Format XXX X/X): ";
        cin >> whDllr >> frcNum >> slash >> frcDenm;
        //Compute stock price
        price = stkPrc(whDllr, frcNum, frcDenm);
        //Output value of user's holdings
        cout << fixed << showpoint << setprecision(2);
        cout << "You own " << shares << " shares of this stock at $" 
             << price << " per share. The total value of your shares is $"
             << shares * price << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
             << "another stock? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'Y' || response == 'y');
    //Exit
    return 0;
}

float stkPrc(int dollar, int num, int denom){
    return ((static_cast<float>(dollar)) + 
            (static_cast<float>(num)/denom));
}