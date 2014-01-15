/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 14, 2014, 7:42 PM
 * Savitch 8th Edition Chapter 2 Problem 19
 * Calculate grades
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    unsigned int numExc, totPts, sumPts = 0, counter = 1;
    float excScore, sumScore = 0, totPerc;
    //Input number of exercises
    cout << "How many exercises do you want to input? ";
    cin >> numExc;
    do {
        //Input scores and total points possible
        cout << "\nScore received for exercise " << counter << ": ";
        cin >> excScore;
        cout << "Total points possible for exercise " << counter << ": ";
        cin >> totPts;
        sumScore += excScore;
        sumPts += totPts;
        counter++;
    } while (counter <= numExc);
    //Calculate percentage
    totPerc = (sumScore/sumPts)*100;
    //Output
    cout << "\nYour total is " << sumScore << " out of " << sumPts
         << ", or " << fixed << showpoint << setprecision(2) << totPerc << "%.";
    
    
    //Exit
    return 0;
}

