/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 24, 2014, 2:46 PM
 * Gaddis Chapter 10 Problem 12
 * Password Verifier
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
bool length(string);
bool chkChars(string);

//Execution Begins
int main(int argc, char** argv) {
    //Declare variables
    string psswrd;
    //Input
    cout << "Please input your password:\n"
            "(It must include only letters and numbers, and "
            "at least one uppercase, one lowercase, and one "
            "digit.)" << endl;
    cin >> psswrd;
    cout << endl;
    //Validate password
    while(!length(psswrd) || !chkChars(psswrd)){
        cout << "Please try again. Enter in a new password: ";
        cin >> psswrd;
        cout << endl;
    }
    
    //Exit
    return 0;
}

bool length(string a){
    if(a.size()<6){
        cout << "Your password must be at least "
                "6 characters in length. " << endl;
        return false;
    }else return true;
}

bool chkChars(string a){
    int lower=0,upper=0,digit=0,
            invalid=0,size=a.size();
    for(int i=0;i<size;i++){
        if(isalnum(a[i])){
            if(isalpha(a[i])){
                isupper(a[i]) ? upper++ : lower++;
            }else digit++;
        }else invalid++;
    }
    if(invalid>0){
        cout << "Your password contains an invalid "
                "character. " << endl;
        return false;
    }else if(lower==0||upper==0){
        cout << "Your password must include at "
                "least one lowercase letter and "
                "one uppercase letter. " << endl;
        return false;
    }else if(digit==0){
        cout << "Your password must include at "
                "least one digit. " << endl;
        return false;
    }else{
        cout << "You have entered a valid password. " << endl;
        return true;
    }
}