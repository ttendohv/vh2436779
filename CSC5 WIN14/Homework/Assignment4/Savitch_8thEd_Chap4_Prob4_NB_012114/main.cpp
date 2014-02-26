/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 21, 2014, 4:03 PM
 * Savitch 8th Edition Chapter 4 Problem 4
 * Inflation Rate
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const int CNV_PRC = 100; //Convert percentage

//Function Prototypes
float inflnRt(float, float);

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float prcPres, prcPast; // prices present and past
    char response;
    do{
        //Input current and past price
        cout << "What is the price of your item today? $";
        cin >> prcPres;
        cout << "What was the price of this same item a "
                "year ago? $";
        cin >> prcPast;
        //Output estimated inflation rate
        cout << fixed << showpoint << setprecision(2);
        cout << "Inflation Rate: " << inflnRt(prcPres, prcPast) 
             << "%" << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
                "another item and price? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'y' || response == 'Y');
    //Exit
    return 0;
}

//Calculate Inflation Rate
//Input
//      Present Day Price
//      Price a year ago
//Output
//      Inflation Rate
float inflnRt(float prcNow, float prcThen){
    return (((prcNow - prcThen)/prcThen)*CNV_PRC);
}