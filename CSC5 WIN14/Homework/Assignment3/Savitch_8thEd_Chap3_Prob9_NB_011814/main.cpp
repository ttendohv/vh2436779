/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 18, 2014, 4:15 PM
 * Savitch 8th Edition Chapter 3 Problem 9
 * Interest on Loan
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const int MTH_YR = 12; //Months in year
const int CNV_PERC = 100; //Convert percentage to decimal
const float MTH_PYT = 0.05; //Monthly payment is 5% of loan amount

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float loanAmt, loanBal, intstRt, mthPymt, 
          balPyd, mthInt, totInt = 0;
    char response; //to prompt for repeat
    
    do{
        int month = 1; //Keep track of how many months it
                       //took to pay off loan
        //Input loan amount and interest rate
        cout << "What is the loan amount? $";
        cin >> loanAmt;
        cout << "What is the interest rate on the loan? %";
        cin >> intstRt;
        //Convert interest rate
        intstRt /= CNV_PERC;
        //Calculate monthly payment
        loanBal = loanAmt;
        mthPymt = loanBal * MTH_PYT;
        //Output heading
        cout << endl;
        cout << "Month     Loan Balance     Monthly Payment  Interest Payed  "
                "Balance Payed" << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << setw(3) << "0" << setw(10) << "$" << loanBal 
             << setw(11) << "$" << mthPymt 
             << setw(14) << " - " << setw(15) << " - " << endl;
        do {
            //Calculate interest
            mthInt = (intstRt * loanBal)/MTH_YR;
            //Calculate loan balance
            balPyd = mthPymt - mthInt;
            if (balPyd <= loanBal){
                loanBal -= balPyd;
            }else{
                //Do not overpay loan
                balPyd = loanBal;
                loanBal = 0;
            }
            //Output monthly payment and loan balance
            cout << fixed << showpoint << setprecision(2);
            cout << setw(3) << month;
            cout << setw(10) << "$" << setw(8) << right << loanBal; 
            cout << setw(11) << "$" << right << mthPymt; 
            cout << setw(10) << "$" << setw(6) << right << mthInt; 
            cout << setw(9) << "$" << setw(6) << right << balPyd;
            cout << endl;
            //Increment month and add total interest
            month++;
            totInt += mthInt;
        }while(loanBal > 0);
        //Output total interest payed overtime
        cout << endl;
        cout << "The total interest paid over the life of the loan is $"
             << fixed << showpoint << setprecision(2) << totInt << endl;
        //Determine simple annualized percentage paid in interest
        float loanYrs = static_cast<float>(month)/MTH_YR;
        float annInt = totInt/loanYrs;
        float annPerc = annInt/loanAmt;
        annPerc *= 100; //Convert to percentage
        //Output annualized interest and percentage
        cout << "It took " << loanYrs << " years to pay off your loan of $"
             << loanAmt << "." << endl;
        cout << "Therefore, your annualized interest paid was $"
             << annInt << ", which is " << annPerc << "% of the $" << loanAmt
             << " loan amount." << endl;
        //Prompt for repeat
        cout << endl;
        cout << "Would you like to repeat this calculation for a new loan "
             << "amount? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

