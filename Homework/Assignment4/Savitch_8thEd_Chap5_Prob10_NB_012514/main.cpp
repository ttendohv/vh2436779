/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 5:58 PM
 * Savitch 8th Edition Chapter 5 Problem 10
 * Converting from kg/g to lb/oz
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
    int kgrams, grams, pounds, ounces;
    char response;
    do{
        //Input kilograms and grams
        read(kgrams, grams);
        //Convert to pounds and ounces
        cnvMsmt(kgrams, grams, pounds, ounces);
        //Output conversion
        output(kgrams, grams, pounds, ounces);
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
//      kilograms
//      grams
//Output
//      none
//      reference kilograms, grams
void read(int& kgrms, int& grms){
    cout << "Enter a length in kilograms and grams: " << endl;
    cout << "  Kilograms: ";
    cin >> kgrms;
    cout << "  Grams: ";
    cin >> grms;
    cout << endl;
}

//Convert measurement
//Input
//      kilograms, grams, pounds, ounces
//Output
//      none
//      reference pounds and ounces
void cnvMsmt(float kgrms, float grms, int& lbs, int& ozs){
    kgrms += grms / CNV_KG_G;
    
    float lb = kgrms * CNV_KG_LB;
    lbs = static_cast<int>(lb);
    float oz = lb - lbs;
    ozs = oz * CNV_LB_OZ;
}

//Output results
//Input
//      kilograms, grams, pounds, ounces
//Output
//      none
void output(int kgrms, int grms, int lbs, int ozs){
    cout << kgrms << " kilogram(s) and " << grms << " gram(s) converts to "
         << lbs << " pound(s) and about " << ozs << " ounce(s)." 
         << endl;
}