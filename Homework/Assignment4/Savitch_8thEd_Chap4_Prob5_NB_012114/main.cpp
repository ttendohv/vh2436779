/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 21, 2014, 4:03 PM
 * Savitch 8th Edition Chapter 4 Problem 5
 * Inflation Rate, modification of Problem 4
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const int CNV_PRC = 100; //Convert percentage

//Function Prototypes
float inflnRt(float, float);
float estCost(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float prcPres, prcPast, // prices present and past
            infltn;
    char response;
    do{
        //Input current and past price
        cout << "What is the price of your item today? $";
        cin >> prcPres;
        cout << "What was the price of this same item a "
                "year ago? $";
        cin >> prcPast;
        cout << endl;
        //Calculate Inflation Rate
        infltn = inflnRt(prcPres, prcPast);
        //Output estimated inflation rate
        cout << fixed << showpoint << setprecision(2);
        cout << "Inflation Rate: " << infltn << "%" << endl;
        //Calculate estimated cost in one year, two years
        cout << "The estimated cost in one year is $"
             << estCost(prcPres, infltn) << endl;
        cout << "The estimated cost in two years is $"
             << estCost(estCost(prcPres,infltn),infltn) << endl;
        cout << endl;
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

//Calculate estimated cost in a year
//Input
//      Current Price
//      Inflation Rate
//Output
//      Estimated future cost
float estCost(float currPrc, float iRate){
    float rate = iRate/CNV_PRC;
    return (currPrc*(1+rate));
}