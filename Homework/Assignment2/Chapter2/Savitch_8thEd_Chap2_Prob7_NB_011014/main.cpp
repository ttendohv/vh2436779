/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 10, 2014, 9:02 PM
 * Savitch 8th Edition Chapter 2 Problem 7
 * Calculate Gross Pay, Withheld Taxes and Take Home Pay
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float PAY_RT = 16.78; //Pay rate for first 40 hours, dollars
const float OT_PAY = 16.78 * 1.5;
const float SS_TX = 0.06; //Social Security Tax
const float FDRL_TX = 0.14; //Federal Income Tax
const float ST_TX = 0.05; //State Income Tax
const short UNION = 10; //Union Dues, dollars
const short HLTH_IN = 35; //Extra cost of health care, 3+ dependents, dollars

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    unsigned int hrsWrk, dpndts;
    unsigned float grssPy, socS, fdrlTx, stTax, netPay;
    
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
    stTax = grssPy * ST_TAX;
    
    //Determine subtotal for net pay
    netPay = grssPy - (socS + fdrlTx + stTax + UNION);
    //Determine if extra health insurance 
    //cost is needed and final netPay and
    //Output gross pay, withheld costs and net pay
    if (dpndts >= 3)
        netPay += HLTH_IN;
    else
        
    
        
    
    
    //Exit
    return 0;
}

