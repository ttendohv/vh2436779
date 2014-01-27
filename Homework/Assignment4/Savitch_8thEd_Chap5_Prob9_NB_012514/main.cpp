/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 5:37 PM
 * Savitch 8th Edition Chapter 5 Problem 9
 * Converting from lb/oz to kg/g
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CNV_KG_LB = 2.2046; //lbs in kg
const float CNV_KG_G = 1000.0; //g in kg
const float CNV_LB_OZ = 16.0; //oz in lb

//Function Prototypes
void read(int&, int&);
void cnvMsmt(float, float, int&, int&);
void output(int, int, int, int);

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    int pounds, ounces, kgrams, grams;
    char response;
    do{
        //Input pounds and ounces
        read(pounds, ounces);
        //Convert to kilograms and grams
        cnvMsmt(pounds, ounces, kgrams, grams);
        //Output conversion
        output(pounds, ounces, kgrams, grams);
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
//      pounds
//      ounces
//Output
//      none
//      reference pounds, ounces
void read(int& lbs, int& ozs){
    cout << "Enter a length in pounds and ounces: " << endl;
    cout << "  Pounds: ";
    cin >> lbs;
    cout << "  Ounces: ";
    cin >> ozs;
    cout << endl;
}

//Convert measurement
//Input
//      pounds, ounces, kilograms, grams
//Output
//      none
//      reference kilograms, grams
void cnvMsmt(float lbs, float ozs, int& kgrms, int& grms){
    lbs += ozs / CNV_LB_OZ;
    
    float kg = lbs / CNV_KG_LB;
    kgrms = static_cast<int>(kg);
    float g = kg - kgrms;
    grms = g * CNV_KG_G;
}

//Output results
//Input
//      pounds, ounces, kilograms, grams
//Output
//      none
void output(int lbs, int ozs, int kgrms, int grms){
    cout << lbs << " pound(s) and " << ozs << " ounce(s) converts to "
         << kgrms << " kilogram(s) and about " << grms << " gram(s)." 
         << endl;
}