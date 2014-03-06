/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 5, 2014, 10:31 AM
 * Gaddis Chapter 9 Problem 11
 * Array Expander
 */

//System Libaries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
int *alloc(int);
int *expand(int*,int);
void fillAry(int*,int);
void prntAry(int*,int,int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    int size;
    do{
        cout << "Enter a number to indicate how large you would "
                "like the integer array to be (must be nonnegative): ";
        cin >> size;
    }while(size<0);
    int *array = alloc(size);
    int *brray = expand(array,size);
    //Print array
    prntAry(array,size,10);
    //Print expanded array with unused elements
    prntAry(brray,(size*2),10);
    //Exit
    return 0;
}

int *alloc(int size){
    int *a = new int[size];
    //Fill array with random numbers
    fillAry(a,size);
    return a;
}

int *expand(int *a,int size){
    int *b = new int[(size*2)];
    for(int i=0;i<size;i++)
        *(b+i)=*(a+i);
    for(int i=size;i<(size*2);i++)
        *(b+i)=0;
    return b;
}

void fillAry(int *a, int size){
    for(int i=0;i<size;i++){
        *(a+i) = rand()%90+10;
    }
}

void prntAry(int *a, int size, int perLine){
    cout << endl;
    for(int i=0;i<size;i++){
        cout << setw(3);
        cout << *(a+i);
        if(i%perLine==(perLine-1))cout << endl;
    }
    cout << endl;
}
