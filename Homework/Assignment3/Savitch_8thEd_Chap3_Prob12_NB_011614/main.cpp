/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 16, 2014, 10:48 AM
 * Savitch 8th Edition Chapter 3 Problem 12
 * Approximating PI
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int nTerms; //number of terms to approximate PI
    float term, apprxPI;
    char response; //allow for repetition
    
    do{
        apprxPI = 0.0; //reinitialize each loop if the
                       //user wants to repeat program
        //Input n terms
        cout << "Input the number of terms you want to "
             << "use to approximate PI: ";
        cin >> nTerms;
        //Calculate PI approximation
        for (int n = 0; n < nTerms; n++){
            term = 4.0; //product for each term in 
                             //PI approximation
                             //reinitialize each loop
            term *= ((pow(-1, n))/(2 * n + 1));
            apprxPI += term;
        }
        //Output approximation of PI
        cout << "The approximation for PI with " << nTerms 
             << " terms is " << apprxPI << endl;
        //Prompt for repeat
        cout << "Would you like to make another approximation? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

