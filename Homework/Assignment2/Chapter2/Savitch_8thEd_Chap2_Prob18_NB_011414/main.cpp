/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 14, 2014, 8:54 PM
 * Savitch 8th Edition Chapter 2 Problem 18
 * Basal Metabolic Rate
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const int CHOC_BAR = 230; //calories in typical chocolate bar

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    float weight, basMeRt;
    int height, age, numBars;
    char gender;
    //Input weight, height, age, gender
    cout << "Please input the following: \n"
         << "\tWeight, in pounds: ";
    cin >> weight;
    cout << "\tHeight, in inches: ";
    cin >> height;
    cout << "\tAge, in years: ";
    cin >> age;
    cout << "\tGender, M or F: ";
    cin >> gender;
    //Calculate BMR
    if (gender == 'F' || gender == 'f')
        basMeRt = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    else
        basMeRt = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    //Output number of chocolate bars to be consumed
    cout << "You should consume " << fixed << showpoint << setprecision(2)
         << basMeRt/CHOC_BAR << " chocolate bars to maintain your current weight.";
        
    //Exit
    return 0;
}

