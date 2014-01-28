/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 28, 2014, 11:28 AM
 * Midterm Problem 1
 * Print number of lines
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void lines(int);

//Execution Begins
int main(int argc, char** argv) {
    //Declare variables
    int num;
    //Enter number of lines
    cout << "How many lines do you want to print out? ";
    cin >> num;
    //Print out lines
    lines(num);
    //Exit
    return 0;
}

void lines(int numLines){
    for (int x = 1; x <= numLines; x++){
        for (int n = 1; n < x; n++){
            cout << " ";
        }
        cout << x << endl;
    }
}