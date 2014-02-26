/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 23, 2014, 8:41 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS = 60; //60 minutes in an hour
const unsigned char CNV_24HR = 12; //24 hour clock conversion 

//Function Prototypes
void read(unsigned short&, unsigned short&, char&);
unsigned short minutes(unsigned short, unsigned short, char);
unsigned short diff(unsigned short, unsigned short);

//Execution Begins
int main(int argc, char** argv) {
    //Declare variables
    unsigned short shr, ehr, smin, emin, scmin, ecmin, diffMin;
    char sampm, eampm;
    //Read the data
    read(shr, smin, sampm);
    read(ehr, emin, eampm);
    //Convert to minutes
    scmin = minutes(shr, smin, sampm);
    ecmin = minutes(ehr, emin, eampm);
    cout << "Starting Minutes = " << scmin << endl;
    cout << "Ending Minutes = " << ecmin << endl;
    //What is the difference in minutes?
    diffMin = diff(scmin,ecmin);
    cout << "The difference in minutes = " << diffMin << endl;
    //Exit
    return 0;
}

void read(unsigned short& hr, unsigned short& min, char& ampm){
    char dum;
    cout << "Input a time: " << endl;
    cout << "Format XX:XX AM/PM" << endl;
    cin >> hr >> dum >> min >> ampm >> dum;
    cout << "You input the following: " << endl;
    cout << "The hour = " << hr << endl;
    cout << "The minute = " << min << endl;
    cout << "AM/PM = " << ampm << "M" << endl;
}

unsigned short minutes(unsigned short hr, unsigned short min, char ampm){
    hr += ((ampm = 'P' || ampm == 'p') && hr != CNV_24HR) ? CNV_24HR : 0;
    hr -= ((ampm = 'A' || ampm == 'a') && hr == CNV_24HR) ? CNV_24HR : 0;
    return (hr * CNV_MIN_HRS) + min;
} //12:00 AM - 12:00 PM shows no difference in time. Why?

unsigned short diff(unsigned short strt, unsigned short stp){
    short min = stp - strt;
    return (min >= 0)? min : (min + (2*CNV_24HR*CNV_MIN_HRS));
}