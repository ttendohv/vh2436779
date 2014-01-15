/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 13, 2014, 7:54 PM
 * Savitch 8th Edition Chapter 2 Problem 14
 * MadLib
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    string instrN, yrName, fooditm, 
           adj, color, animal;
    float number;
    char response; //to signal repetition of game
    //Input values
    do {
        cout << "Let's play Mad Lib! Please enter the following, pressing "
                "the return key after each entry:\n\n";
        cout << "\tFirst or Last Name of Your Instructor: ";
        cin >> instrN;
        cout << "\tYour Name: ";
        cin >> yrName;
        cout << "\tA food item: ";
        cin >> fooditm;
        do {
            cout << "\tA number between 100 and 120: ";
            cin >> number;
        } while (number < 100 || number > 120);
        cout << "\tAn adjective: ";
        cin >> adj;
        cout << "\tA color: ";
        cin >> color;
        cout << "\tAn animal: ";
        cin >> animal;
        //Output story
        cout << "\n\nDear Instructor " << instrN << ",\n\n";
        cout << "I am sorry that I am unable to turn in my homework "
             << "at this time. First, I ate a rotten " << fooditm
             << ", which made me turn " << color << " and extremely ill."
             << " I came down with a fever of " << number << ". Next, "
             << "my " << adj << " pet " << animal << " must have smelled "
             << "the remains of the " << fooditm << " on my homework, "
             << "because he ate it. I am currently rewriting my homework "
             << "and hope you will accept it late.\n\nSincerely,\n"
             << yrName;
        //Prompt for repeat
        cout << "\n\nWould you like to repeat the game? Y/N: ";
        cin >> response;
    } while (response == 'Y' || response == 'y');
    //Exit
    return 0;
}

