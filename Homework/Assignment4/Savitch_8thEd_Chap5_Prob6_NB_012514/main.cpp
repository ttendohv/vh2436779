/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 4:59 PM
 * Savitch 8th Edition Chapter 5 Problem 6
 * Converting from ft/in to m/cm
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
        //Input feet and inches
        read(feet, inches);
        //Convert to meters and centimeters
        cnvMsmt(feet, inches, meters, centim);
        //Output conversion
        output(feet, inches, meters, centim);
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
//      feet
//      inches
//Output
//      none
//      reference feet, inches
void read(int& feet, int& inches){
    cout << "Enter a length in feet and inches: " << endl;
    cout << "  Feet: ";
    cin >> feet;
    cout << "  Inches: ";
    cin >> inches;
    cout << endl;
}

//Convert measurement
//Input
//      feet, inches, meters, centimeters
//Output
//      none
//      reference meters, centimeters
void cnvMsmt(float feet, float inches, int& meters, int& cmeters){
    feet += inches / CNV_FT_IN;
    
    float mtr = feet * CNV_FT_M;
    meters = static_cast<int>(mtr);
    float cm = mtr - meters;
    cmeters = cm * CNV_M_CM;
}

//Output results
//Input
//      feet, inches, meters, centimeters
//Output
//      none
void output(int feet, int inches, int meters, int cmeters){
    cout << feet << " feet and " << inches << " inch(es) converts to "
         << meters << " meter(s) and about " << cmeters << " centimeters." 
         << endl;
}