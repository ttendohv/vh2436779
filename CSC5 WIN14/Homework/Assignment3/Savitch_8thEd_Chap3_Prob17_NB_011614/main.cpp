/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 14, 2014, 8:54 PM
 * Savitch 8th Edition Chapter 3 Problem 17
 * Modify Problem 18 from Chapter 2
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
    char gender, response;
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
    //Calculate initial BMR
    if (gender == 'F' || gender == 'f')
        basMeRt = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    else
        basMeRt = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    //Input activity
    do{
        cout << "Are you: "
             << "\n  (A) Sedentary"
             << "\n  (B) Somewhat active (exercise occasionally)"
             << "\n  (C) Active (exercise 3-4 days per week)"
             << "\n  (D) Highly active (exercise every day)"
             << "\n\n Please enter either A, B, C, or D, for your response: ";
        cin >> response;
        //Calculate final BMR based on activity
        switch (response){
            case 'A':
            case 'a':
                basMeRt *= (1 + 0.20);
                break;
            case 'B':
            case 'b':
                basMeRt *= (1 + 0.30);
                break;
            case 'C':
            case 'c':
                basMeRt *= (1 + 0.40);
                break;
            case 'D':
            case 'd':
                basMeRt *= (1 + 0.50);
                break;
            default:
                cout << "Invalid response. Please try again." << endl;
                response = -1;
    }}while(response == -1);
    //Output number of chocolate bars to be consumed
    cout << "You should consume " << fixed << showpoint << setprecision(2)
         << basMeRt/CHOC_BAR << " chocolate bars to maintain your current weight." << endl;
        
    //Exit
    return 0;
}
