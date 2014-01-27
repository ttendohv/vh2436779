/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 2:44 PM
 * Savitch 8th Edition Chapter 5 Problem 1
 * Convert from 24 hour notation to 12 hour notation
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int CNV_24HR = 12;

//Function Prototypes
void read(int&, int&);
void cnvTime(int&, char&);
void output(int, int, char);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int hour, minute;
    char ampm, response;
    do{
        //Input time
        read(hour, minute);
        //Convert time
        cnvTime(hour, ampm);
        //Output result
        output(hour, minute, ampm);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
                "another time? Y/N ";
        cin >> response;
    }while(response == 'Y' || response == 'y');
    
    //Exit
    return 0;
}

//Input time
//Input
//      hour
//      minute
//Output
//      none
//      reference hour, minute
void read(int& hour, int& minute){
    char dummy;
    cout << "Enter a time in 24-hour notation (Format XX:XX) ";
    cin >> hour >> dummy >> minute;
}

//Convert time to 12 hour notation
//Input
//      hour
//      ampm
//Output
//      none
//      reference hour, ampm
void cnvTime(int& hour, char& ampm){
    if(hour > CNV_24HR){
        hour -= CNV_24HR;
        ampm = 'P';
    }else{
        ampm = 'A';
    }
}

//Output result
//Input
//      hour
//      minute
//      ampm
//Output
//      none
void output(int hour, int minute, char ampm){
    cout << "The time in 12-hour notation is " << hour << ":"
         << minute << " " << ampm << "M" << endl;
}