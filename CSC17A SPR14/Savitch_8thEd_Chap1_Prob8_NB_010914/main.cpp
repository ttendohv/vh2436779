/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 9, 2014, 7:39 PM
 * Savitch 8th Edition Chapter 1 Problem 8
 * Calculate money in cents from quarters,
 * dimes, and nickels
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const short QTR_CNT = 25; //Quarter amount in cents
const short DIM_CNT = 10; //Dime amount in cents
const short NIK_CNT = 5; //Nickel amount in cents

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int numQtr, numDime, numNikl, total;
    //Input amount of quarters, dimes, and nickels
    cout << "Please enter the following:\n Number of Quarters: ";
    cin >> numQtr;
    cout << " Number of Dimes: ";
    cin >> numDime;
    cout << " Number of Nickels: ";
    cin >> numNikl;
    //Calculate the total amount of money
    total = (numQtr*QTR_CNT) + (numDime*DIM_CNT) + (numNikl*NIK_CNT);
    //Output total
    cout << "You have " << total << " cents.\nGoodbye";
    //Exit
    return 0;
}

