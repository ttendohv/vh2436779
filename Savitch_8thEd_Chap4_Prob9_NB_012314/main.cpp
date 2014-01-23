/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 23, 2014, 11:03 AM
 * Savitch 8th Edition Chapter 4 Problem 9
 * Clothing Sizes
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants
const float EGTH_IN = 0.125; //1/8 inch
const float TNTH_IN = 0.10; //1/10 inch

//Function Prototypes
int hatSize(float, float);
float jktSize(float, float, int);
float wstInch(float, int);

int main(int argc, char** argv) {
    //Declare variables
    float height, weight, jacket, waist;
    int age, hat;
    char response;
    do{
        //Input height, weight, age
        cout << "Please enter the following: " << endl;
        cout << "  Height, in inches: ";
        cin >> height;
        cout << "  Weight, in pounds: ";
        cin >> weight;
        cout << "  Age, in years: ";
        cin >> age;
        //Calculate clothing sizes
        hat = hatSize(weight, height);
        jacket = jktSize(weight, height, age);
        waist = wstInch(weight, age);
        //Output clothing sizes
        cout << "Here are your clothing sizes: " << endl;
        cout << "  Hat Size (closest size up): " << hat << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "  Jacket Size (chest in inches): " << jacket << endl;
        cout << "  Waist (in inches): " << waist << endl;
        //Prompt for repeat
        cout << "Would you like to compute different clothing sizes? Y/N: ";
        cin >> response;
    }while (response == 'y' || response == 'Y');
         
    
    //Exit
    return 0;
}

int hatSize(float wgt, float hgt){
    return static_cast<int>(ceil(((wgt/hgt) * 2.9)));
}

float jktSize(float wgt, float hgt, int age){
    float size = (wgt * hgt) / 288;
    if (age > 30){
        int adj = (age - 30)/10;
        size += adj * EGTH_IN;
    }
    return size;
}

float wstInch(float wgt, int age){
    float size = wgt / 5.7;
    if (age > 28){
        int adj = (age - 28)/2;
        size += adj * TNTH_IN;
    }
    return size;
}