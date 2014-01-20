/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 19, 2014, 2:42 PM
 * Savitch 8th Edition Chapter 3 Problem 15
 * Buoyancy
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float SP_WGT_WTR = 62.4; //Specific weight of water, lb/ft^3
const double PI = 3.141592653589793;

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float sphWgt, sphRad, sphVol, //weight, radius and volume of sphere
          buoyFrc;
    //Input weight and radius
    cout << "What is the weight of the sphere in pounds? ";
    cin >> sphWgt;
    cout << endl;
    cout << "What is the radius of the sphere in feet? ";
    cin >> sphRad;
    cout << endl;
    //Calculate volume
    sphVol = (4/3)*PI*(sphRad*sphRad*sphRad);
    //Calculate buoyant force
    buoyFrc = sphVol * SP_WGT_WTR;
    //Check if the sphere will float or sink
    if (buoyFrc >= sphWgt){
        cout << "The sphere will float." << endl;
    }else{
        cout << "The sphere will sink." << endl;
    }
    
    //Exit
    return 0;
}

