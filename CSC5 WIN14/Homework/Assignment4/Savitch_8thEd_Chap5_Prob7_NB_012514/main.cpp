/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 5:24 PM
 * Savitch 8th Edition Chapter 5 Problem 7
 * Converting from m/cm to ft/in
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CNV_FT_M = 0.3048;
const float CNV_M_CM = 100.0;
const float CNV_FT_IN = 12.0;

//Function Prototypes
void read(int&, int&);
void cnvMsmt(float, float, int&, int&);
void output(int, int, int, int);

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    int feet, inches, meters, centim;
    char response;
    do{
        //Input meters and centimeters
        read(meters, centim);
        //Convert to feet and inches
        cnvMsmt(meters, centim, feet, inches);
        //Output conversion
        output(meters, centim, feet, inches);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
    //Exit
    return 0;
}

//Read in length
//Input
//      meters
//      centimeters
//Output
//      none
//      reference meters, centimeters
void read(int& meters, int& cmeters){
    cout << "Enter a length in meters and centimeters: " << endl;
    cout << "  Meters: ";
    cin >> meters;
    cout << "  Centimeters: ";
    cin >> cmeters;
    cout << endl;
}

//Convert measurement
//Input
//      meters, centimeters, feet, inches
//Output
//      none
//      reference feet, inches
void cnvMsmt(float meters, float cmeters, int& feet, int& inches){
    meters += cmeters / CNV_M_CM;
    
    float ft = meters / CNV_FT_M;
    feet = static_cast<int>(ft);
    float in = ft - feet;
    inches = in * CNV_FT_IN;
}

//Output results
//Input
//      meters, centimeters, feet, inches
//Output
//      none
void output(int meters, int cmeters, int feet, int inches){
    cout << meters << " meter(s) and " << cmeters << " centimeter(s) "
         " converts to " << feet << " feet and about " << inches 
         << " inches." << endl;
}