/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 15, 2014, 7:19 PM
 * Savitch 8th Edition Chapter 2 Problem 6
 * Maximum Room Capacity
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    int maxRmCp, numPpl, addlPpl, exclPpl;
    char response;
    
    do{
        //Input room capacity and people for meeting
        cout << "What is the maximum room capacity for the room "
             << "that will be used for the meeting? ";
        cin >> maxRmCp;
        cout << "How many people will be attending the meeting? ";
        cin >> numPpl;
        //Check if it is legal to hold meeting
        if (numPpl <= maxRmCp){
            cout << "It is legal to hold the meeting. ";
            //Calculate additional people
            addlPpl = maxRmCp - numPpl;
            cout << addlPpl << " additional people may legally "
                 << "attend." << endl;
        }else{
            cout << "The meeting cannot be held due to fire "
                    "regulations. ";
            //Calculate people that must be excluded
            exclPpl = numPpl - maxRmCp;
            cout << exclPpl << " people must be excluded from "
                 << "the meeting in order to meet fire regulations." << endl;
        }
        //Prompt for repetition
        cout << "Would you like to repeat for another room? ";
        cin >> response;
    }while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

