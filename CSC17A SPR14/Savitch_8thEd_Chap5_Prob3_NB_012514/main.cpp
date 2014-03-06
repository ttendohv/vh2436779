/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 4:19 PM
 * Savitch 8th Edition Chapter 5 Problem 3
 * Time after waiting, modifying Problem 2
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int CNV_12HR = 12; //12 hour notation
const int CNV_HRS_MIN = 60; //minutes in an hour

//Function Prototypes
void inpTime(int&, int&, int&, int&, char&);
void endWtg(int, int, int, int, int&, int&, char&);
void outputT(int, int, char);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int curHour, curMin, waitHrs, waitMin, finHour, finMin;
    char ampm, response;
    do{
        //Input times
        inpTime(curHour, curMin, waitHrs, waitMin, ampm);
        //Calculate time after waiting
        endWtg(curHour, curMin, waitHrs, waitMin, finHour, finMin, ampm);
        //Output time after waiting
        outputT(finHour, finMin, ampm);
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
//      ampm
//Output
//      none
//      reference current hour, minute and
//      waiting hour, minute and ampm
void inpTime(int& currH, int& currM, int& waitH, int& waitM, char& ampm){
    char dummy;
    cout << "Please enter the current time in 12-hour notation "
            "(Format HH:MM AM/PM) ";
    cin >> currH >> dummy >> currM >> ampm >> dummy;
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
//      ampm
//Output
//      none
//      reference after hour, minute, ampm
void endWtg(int currH, int currM, int waitH, int waitM, 
            int& afterH, int& afterM, char& ampm){
    afterH = currH + waitH;
    if(afterH >= CNV_12HR){
        afterH -= CNV_12HR;
        if (afterH != 12){
            if(ampm == 'A') ampm = 'P';
            else ampm = 'A';
        }
    }
    afterM = currM + waitM;
    if(afterM >= CNV_HRS_MIN){
        afterM -= CNV_HRS_MIN;
        afterH += 1;
        if(afterH >= CNV_12HR){
            afterH -= CNV_12HR;
            if(afterH != 12){
                if(ampm == 'A') ampm = 'P';
                else ampm = 'A';
            }
        }
    }
}

//Output final time
//Input
//      after hour
//      after minute
//      ampm
//Output
//      none
void outputT(int afterH, int afterM, char ampm){
    cout << "After the waiting period, the time will be "
         << afterH << ":";
    if (afterM < 10)
        cout << "0";
    cout << afterM << " " << ampm << "M" << endl;
}