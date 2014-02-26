/*
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 13, 2014, 4:53 PM
 * Savitch 8th Edition Chapter 2 Problem 1
 * Conversion with metric tons
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float MTRC_TON_OZ = 35273.92; //metric ton in ounces

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float crlWgt, //weight of cereal box
          mtrcWgt, //weight of cereal in metric tons
          numBox; //number of cereal boxes to make metric ton
    char response; //user response to continue or discontinue program

    do {
        //Input cereal box weight
        cout << "How much does the box of cereal weigh in ounces? ";
        cin >> crlWgt;
        //Calculate metric weight and number of boxes in metric ton
        mtrcWgt = crlWgt / MTRC_TON_OZ;
        numBox = MTRC_TON_OZ / mtrcWgt;
        //Output metric weight and number of boxes
        cout << scientific << showpoint << setprecision(2);
        cout << "Your box of cereal is " << mtrcWgt << " metric tons." << endl;
        cout << "It would take " << numBox << " boxes of cereal to make "
                "a metric ton." << endl;
        //Prompt the user on how to continue
        cout << "Would you like to repeat the program? Y / N : ";
        cin >> response;
    } while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

