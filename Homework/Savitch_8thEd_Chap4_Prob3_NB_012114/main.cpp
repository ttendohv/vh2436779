/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 21, 2014, 11:49 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float stkPrc(int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int shares, whDllr, frcNum, frcDenm;
    //Input shares, dollar portion of price
    //and fraction portion of price
    cout << "";
    //Exit
    return 0;
}

float stkPrc(int dollar, int num, int denom){
    return ((static_cast<float>(dollar)) + 
            (static_cast<float>(num)/denom));
}