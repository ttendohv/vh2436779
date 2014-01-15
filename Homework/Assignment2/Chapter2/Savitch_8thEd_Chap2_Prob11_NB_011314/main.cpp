/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 13, 2014, 7:20 PM
 * Savitch 8th Edition Chapter 2 Problem 11
 * Sums and Averages of Positive, Negative, 
 * and all inputted numbers
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    int number, posSum = 0, negSum = 0, allSum = 0, 
            numCntr = 0, posCntr = 0, negCntr = 0;
    //Input 10 whole numbers
    cout << "Please insert 10 whole numbers (positive, negative, or "
            "zero) in any order, pressing enter after each number:\n";
    do {
        cin >> number;
        //Calculate sums
        if (number > 0){
            posSum += number;
            posCntr++;
        }
        else{
            negSum += number;
            negCntr++;
        }
        allSum += number;
        numCntr++;
    } while (numCntr < 10);

    //Output sums
    cout << "The sum of all positive numbers entered is: " << posSum << endl;
    cout << "The sum of all negative numbers entered is: " << negSum << endl;
    cout << "The sum of all the numbers entered is: " << allSum << endl;
    //Output averages
    cout << "The average of all positive numbers entered is: " << posSum / posCntr << endl;
    cout << "The average of all negative numbers entered is: " << negSum / negCntr << endl;
    cout << "The average of all the numbers entered is: " << allSum / numCntr << endl;
    //Exit
    return 0;
}

