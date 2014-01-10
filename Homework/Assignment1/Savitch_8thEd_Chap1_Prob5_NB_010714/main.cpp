/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 7, 2014, 7:15 PM
 * Savitch 8th Edition Chapter 1 Problem 5
 * Read two integers and output sum and product
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    int num1, num2, sum, prod;
    
    cout << "Press return after entering a number.\n";
    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;
    sum = num1 + num2;
    prod = num1 * num2;
    cout << "The sum of " << num1 << " and "
         << num2 << " is " << sum << ".\n"
         << "The product of " << num1 << " and "
         << num2 << " is " << prod << ".\n";
    cout << "Good-bye." << endl;
    
    return 0;
}

