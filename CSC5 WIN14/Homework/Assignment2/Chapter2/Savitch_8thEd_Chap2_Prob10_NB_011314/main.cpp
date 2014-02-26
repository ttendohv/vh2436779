/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 13, 2014, 7:20 PM
 * Savitch 8th Edition Chapter 2 Problem 10
 * Sums of Positive, Negative, and all inputted numbers
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int number, posSum = 0, negSum = 0, allSum = 0, counter = 0;
    //Input 10 whole numbers
    cout << "Please insert 10 whole numbers (positive, negative, or "
            "zero) in any order, pressing enter after each number:\n";
    do {
        cin >> number;
        //Calculate sums
        if (number > 0)
            posSum += number;
        else
            negSum += number;
        allSum += number;
        counter++;
    } while (counter < 10);
    //Output sums
    cout << "The sum of all positive numbers entered is: " << posSum << endl;
    cout << "The sum of all negative numbers entered is: " << negSum << endl;
    cout << "The sum of all the numbers entered is: " << allSum << endl;
    
    //Exit
    return 0;
}

