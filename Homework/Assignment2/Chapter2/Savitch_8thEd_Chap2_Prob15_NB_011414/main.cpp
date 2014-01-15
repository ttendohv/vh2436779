/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 14, 2014, 9:25 PM
 * Savitch 8th Edition Chapter 2 Problem 15
 * Velocity of Sound
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
    int tempC, endTemp;
    float velSnd; // meters per second
    //Input start and end temperatures
    cout << "What is the starting temperature, in degrees Celsius? ";
    cin >> tempC;
    cout << "What is the ending temperature, in degrees Celsius? ";
    cin >> endTemp;
    //Output
    do{
        velSnd = 331.3 + 0.61 * tempC; 
        cout << "At " << tempC << " degrees Celsius the velocity of "
             << "sound is " << fixed << showpoint << setprecision(1) 
             << velSnd << " m/s" << endl;
        tempC++;
    }while(tempC <= endTemp);
    //Exit
    return 0;
}

