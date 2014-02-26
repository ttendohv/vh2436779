/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 7, 2014, 9:03 AM
 * Savitch 8th Edition Chapter 1 Problem 9
 * Calculate Free Fall
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float GRAVITY = 32.174; //Units = (ft/s^2)

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float time, frefall;
    //Input the time
    cout << "Input the time in seconds" << endl;
    cin >> time;
    //Calculate the distance dropped
    frefall=GRAVITY*time*time*1/2;
    //Output the result
    cout << "The Distance Dropped = " 
            << frefall << "(ft)" <<endl;
    //Exit
    return 0;
}

