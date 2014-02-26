/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 2:57 PM
 * Savitch 8th Edition Chapter 5 Problem 2
 * Time after waiting
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int FULL_DAY = 24; //hours in a day
const int CNV_HRS_MIN = 60; //minutes in an hour

//Function Prototypes
void inpTime(int&, int&, int&, int&);
void endWtg(int, int, int, int, int&, int&);
void outputT(int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int curHour, curMin, waitHrs, waitMin, finHour, finMin;
    char response;
    do{
        //Input times
        inpTime(curHour, curMin, waitHrs, waitMin);
        //Calculate time after waiting
        endWtg(curHour, curMin, waitHrs, waitMin, finHour, finMin);
        //Output time after waiting
        outputT(finHour, finMin);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for another time? ";
        cin >> response;
    }while(response == 'Y' || response == 'y');
    
    //Exit
    return 0;
}

//Input current time and waiting time
//Input
//      current hour
//      current minute
//      waiting hour
//      waiting minute
//Output
//      none
//      reference current hour, minute and
//      waiting hour, minute
void inpTime(int& currH, int& currM, int& waitH, int& waitM){
    char dummy;
    cout << "Please enter the current time in 24-hour notation "
            "(Format HH:MM) ";
    cin >> currH >> dummy >> currM;
    cout << "Please enter the amount of time you must wait "
            "(Format HH:MM) ";
    cin >> waitH >> dummy >> waitM;
}

//Calculate time after waiting period
//Input
//      current hour
//      current minute
//      waiting hour
//      waiting minute
//      after hour
//      after minute
//Output
//      none
//      reference after hour, minute
void endWtg(int currH, int currM, int waitH, int waitM, 
            int& afterH, int& afterM){
    afterH = currH + waitH;
    if(afterH >= FULL_DAY)
        afterH -= FULL_DAY;
    afterM = currM + waitM;
    if(afterM >= CNV_HRS_MIN){
        afterM -= CNV_HRS_MIN;
        afterH += 1;
        afterH -= (afterH >= FULL_DAY) ? FULL_DAY : 0;
    }
}

//Output final time
//Input
//      after hour
//      after minute
//Output
//      none
void outputT(int afterH, int afterM){
    cout << "After the waiting period, the time will be "
         << afterH << ":";
    if (afterM < 10)
        cout << "0";
    cout << afterM << endl;
}