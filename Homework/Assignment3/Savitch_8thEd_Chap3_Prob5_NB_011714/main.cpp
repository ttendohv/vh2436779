/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 17, 2014, 8:56 PM
 * Savitch 8th Edition Chapter 3 Problem 5
 * Cost of Long-Distance Call
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float MF_DAY_RT = 0.40; //$ per minute, M-F, 8am-6pm
const float MF_MR_NI_RT = 0.25; //$ per minute, M-F, before 8am, after 6pm
const float SAT_SUN_RT = 0.15; //$ per minute, Sat/Sun 
        
//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    char dayFirI, daySecI; //first and second initials for day of week
    char response;
    int timeHr, timeMin, callTime;
    float callCst;
    do{
        bool repeat;
        do{
            do{
                //Input day of week
                cout << "Enter the first two letters of the day your call started: ";
                cin >> dayFirI >> daySecI;
                switch (dayFirI){
                    case 'M':
                    case 'm':
                        if (daySecI == 'O' || daySecI == 'o'){
                            repeat = false;
                        }else{
                            cout << "Invalid input. Please start over." << endl;
                            repeat = true;
                        }
                        break;
                    case 'T':
                    case 't':
                        if (daySecI == 'U' || daySecI == 'u'
                            || daySecI == 'H' || daySecI == 'h'){
                            repeat = false;
                        }else{
                            cout << "Invalid input. Please start over." << endl;
                            repeat = true;
                        }
                        break;
                    case 'W':
                    case 'w':
                        if (daySecI == 'E' || daySecI == 'e'){
                            repeat = false;
                        }else{
                            cout << "Invalid input. Please start over." << endl;
                            repeat = true;
                        }
                        break;
                    case 'F':
                    case 'f':
                        if (daySecI == 'R' || daySecI == 'r'){
                            repeat = false;
                        }else{
                            cout << "Invalid input. Please start over." << endl;
                            repeat = true;
                        }
                        break;
                    case 'S':
                    case 's':
                        if (daySecI == 'A' || daySecI == 'a'
                            || daySecI == 'U' || daySecI == 'u'){
                            repeat = false;
                        }else{
                            cout << "Invalid input. Please start over." << endl;
                            repeat = true;
                        }
                        break;
                    default:
                        cout << "Invalid input. Please start over." << endl;
                        repeat = true;
                        break;
                }
            }while(repeat);
            do{
                //Input time of call
                cout << "Enter the time the call started in 24-hour notation." << endl;
                cout << " Please input the hour (HH), press Enter, and then "
                     << "input the minutes (MM), and press Enter: " << endl;
                cin >> timeHr >> timeMin;
                if (timeHr < 0 || timeHr > 23){
                    cout << "Invalid input. Please enter a new time." << endl;
                    repeat = true;
                }else if (timeMin < 0 || timeMin > 59){
                    cout << "Invalid input. Please enter a new time." << endl;
                    repeat = true;
                }else{
                    repeat = false;
                }
            }while (repeat);
            //Input call time
            cout << "Enter the length of your call in minutes: ";
            cin >> callTime;
            cout << endl;
            //Compute call cost
            switch (dayFirI){
                case 'M':
                case 'm':
                case 'T':
                case 't':
                case 'W':
                case 'w':
                case 'F':
                case 'f':
                        if (timeHr >= 8 && timeHr <= 17){
                            callCst = callTime * MF_DAY_RT;
                        }else if (timeHr == 6 && timeMin == 00){
                            callCst = callTime * MF_DAY_RT;
                        }else{
                            callCst = callTime * MF_MR_NI_RT;
                        }
                        break;
                case 'S':
                case 's':
                        callCst = callTime * SAT_SUN_RT;
                        break;
            }
        }while (repeat);
        //Output cost of call
        cout << endl;
        cout << "Your call started on [" << dayFirI << daySecI << "] at "
             << timeHr << ":" << timeMin << "." << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "The cost of your call is: $" << callCst << endl;
        //Prompt for repeat
        cout << "\nWould you like to compute the cost for another call? Y/N: ";
        cin >> response;
    }while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

