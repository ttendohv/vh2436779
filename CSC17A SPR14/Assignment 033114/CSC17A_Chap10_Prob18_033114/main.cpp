/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 7:09 PM
 * Gaddis Chapter 10 Problem 18
 * Phone Number List
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes
void srch(string[],string,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    string numbers[] = { "Becky Warren, 555-1223",
                       "Joe Looney, 555-0097",
                       "Geri Palmer, 555-8787",
                       "Lynn Presnell, 555-1212",
                       "Holly Gaddis, 555-8878",
                       "Sam Wiggins, 555-0998",
                       "Bob Kain, 555-8712",
                       "Tim Haynes, 555-7676",
                       "Warren Gaddis, 555-9037",
                       "Jean James, 555-4939",
                       "Ron Palmer, 555-2783"     };
    string name;
    //Search
    cout << "Please enter a name or partial number you are "
            "looking for: ";
    cin >> name;
    srch(numbers,name,11);
    //Exit
    return 0;
}

void srch(string a[], string find,int size){
    int found;
    for(int i=0;i<size;i++){
        found=a[i].find(find,0);
        if(found!=string::npos){
            cout << a[i] << endl;
        }
    }
}