/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 16, 2014, 10:07 AM
 * Savitch 8th Edition Chapter 3 Problem 16
 * Comparing Celsius and Fahrenheit
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int tempC, tempF;
    //Loop to find same Celsius and Fahrenheit degress
    for (tempC = 100; tempC != tempF; --tempC){
        tempF = ((9*tempC)/5)+ 32;
    }
    cout << "Temperature in Celsius is " << tempC << " degrees\n"
         << "Temperature in Fahrenheit is " << tempF << " degrees\n"
         << "The temperatures are the same at this point." << endl;
        
    
    //Exit
    return 0;
}

