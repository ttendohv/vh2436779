/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 17, 2014, 7:41 PM
 * Savitch 8th Edition Chapter 3 Problem 2
 * Interest in Revolving Credit Account
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float FIR_INT = 0.015; //Interest rate on first $1000
const float EXT_INT = 0.01; //Extra interest after first $1000
const float DEF_MIN_PY = 10.0; //Default minimum payment, $10
const float MIN_PY_PRCT = 0.1; //Minimum payment, 10%, if more than $10

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float accntBal, intrDue, amtDue, minPymt; 
    char response;
    do{
        //Input account balance
        cout << "What is your account balance? $";
        cin >> accntBal;
        //Calculate interest due and total amount due
        if (accntBal > 1000){
            intrDue = 1000 * FIR_INT + (accntBal - 1000) * EXT_INT;
            amtDue = accntBal + intrDue;
        }else{
            intrDue = accntBal * FIR_INT;
            amtDue = accntBal + intrDue;
        }
        //Calculate minimum payment due
        if (amtDue > DEF_MIN_PY){
            if (DEF_MIN_PY >= (MIN_PY_PRCT * amtDue)){
                minPymt = DEF_MIN_PY;
            }else{
                minPymt = MIN_PY_PRCT * amtDue;
            }
        }else{
            minPymt = amtDue;
        }
        //Output account balance, interest due, total amount due, 
        //and minimum payment due
        cout << fixed << showpoint << setprecision(2);
        cout << "Account Summary: " << endl;
        cout << "  Account Balance: $" << accntBal << endl;
        cout << "  Interest Due: $" << intrDue << endl;
        cout << "  Total Amount Due: $" << amtDue << endl;
        cout << "  Minimum Payment: $" << minPymt << endl;
        //Prompt for repeat
        cout << "\nWould you like to repeat for another account? ";
        cin >> response;
        cout << endl;
    }while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

