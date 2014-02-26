/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 10, 2014, 9:02 PM
 * Savitch 8th Edition Chapter 2 Problem 7
 * Calculate Gross Pay, Withheld Taxes and Take Home Pay
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float PAY_RT = 16.78; //Pay rate for first 40 hours, dollars
const float OT_PAY = 16.78 * 1.5; //Overtime, every hour after 40
const float SS_TX = 0.06; //Social Security Tax
const float FDRL_TX = 0.14; //Federal Income Tax
const float ST_TX = 0.05; //State Income Tax
const float UNION = 10.00; //Union Dues, dollars
const float HLTH_IN = 35.00; //Extra cost of health care, 3+ dependents, dollars

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int hrsWrk, dpndts;
    float grssPy, socS, fdrlTx, stTax, netPay;
    char response;
    
    do{
        //Input hours worked and dependents
        cout << "Please enter the following: " << endl;
        cout << " Hours worked in a week: ";
        cin >> hrsWrk;
        cout << " Number of dependents: ";
        cin >> dpndts;

        //Process
        //Calculate gross pay
        if (hrsWrk > 40)
            grssPy = (PAY_RT * hrsWrk) + (OT_PAY * (hrsWrk - 40));
        else
            grssPy = PAY_RT * hrsWrk;

        //Calculate Taxes Withheld
        socS = grssPy * SS_TX;
        fdrlTx = grssPy * FDRL_TX;
        stTax = grssPy * ST_TX;

        //Determine subtotal for net pay
        netPay = grssPy - (socS + fdrlTx + stTax + UNION);

        //Output gross pay, each withholding amount, and the
        //net take-home pay for the week
        cout << fixed << showpoint << setprecision(2)
             << "This week:"
             << "\n Gross Pay: $" << grssPy
             << "\n  Social Security Tax: $" << socS
             << "\n  Federal Income Tax: $" << fdrlTx
             << "\n  State Income Tax: $" << stTax
             << "\n  Union Dues: $" << UNION;
          //Determine if extra health insurance 
          //cost is needed and add to netPay
          if (dpndts >= 3){
            netPay -= HLTH_IN;
            cout << "\n  Health Insurance: $" << HLTH_IN;
          }else{
            cout << "\n  Health Insurance: $0.00";  
          }
          cout << "\n Net Take-Home Pay: $" << netPay << endl;
          //Prompt for repeat
          cout << "\nWould you like to recalculate? Y/N ";
          cin >> response;
    }while (response == 'y' || response == 'Y');    
    
    //Exit
    return 0;
}

