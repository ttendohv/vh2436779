/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 21, 2014, 3:34 PM
 * Savitch 8th Edition Chapter 4 Problem 1
 * Miles per gallon
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_L_GAL = 0.264179;

//Function Prototypes
float mpg(float, float);

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float ltrsGas, milesTr;
    char response;
    do{
        //Input liters and miles
        cout << "How many liters of gasoline did your car consume? ";
        cin >> ltrsGas;
        cout << "How many miles did your car travel? ";
        cin >> milesTr;
        //Output miles per gallon
        cout << fixed << showpoint << setprecision(2);
        cout << "Miles per gallon: " << mpg(ltrsGas, milesTr) << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this for another car? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'y' || response == 'Y');
    //Exit
    return 0;
}

//Compute miles per gallon
//Input
//      liters of gas
//      miles traveled
//Output
//      miles per gallon
float mpg(float liters, float miles){
    float gallons;
    gallons = liters * CNV_L_GAL;
    return miles/gallons;
}