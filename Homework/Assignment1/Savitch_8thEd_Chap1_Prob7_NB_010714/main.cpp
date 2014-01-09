/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 7, 2014, 8:57 PM
 * Output "CS!" in large block letters
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Output top border
    cout << "****************************************"
         << "*************" << endl << endl;
    //Output block letters
    cout << "           C C C             S S S S"
         << "        !!" << endl;
    cout << "         C       C         S         S"
         << "      !!" << endl;
    cout << "        C                 S         "
         << "        !!" << endl;
    cout << "       C                   S        "
         << "        !!" << endl;
    cout << "       C                    S S S S "
         << "        !!" << endl;
    cout << "       C                             S"
         << "      !!" << endl;
    cout << "        C                             S"
         << "     !!" << endl;
    cout << "         C       C         S         S"
         << endl;
    cout << "           C C C             S S S S "
         << "       00" << endl << endl;
    //Output bottom border
    cout << "****************************************"
         << "*************" << endl << endl << endl;
    //Output Final Statement
    cout << "    Computer Science is Cool Stuff!!!";
    
    //Exit
    return 0;
}

