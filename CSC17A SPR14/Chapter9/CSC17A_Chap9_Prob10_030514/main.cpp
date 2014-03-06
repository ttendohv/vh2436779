/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 5, 2014, 10:14 AM
 * Gaddis Chapter 9 Problem 10
 * Reverse Array
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
int *reverse(int*,int);
void fillAry(int*,int);
void prntAry(int*,int,int);
void sort(int*,int);
void swap(int&,int&);

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
    int *brray = reverse(array,size);
    //Print array
    cout << "Original Array:" << endl;
    prntAry(array,size,10);
    //Print sorted array, in ascending order
    sort(array,size);
    cout << "Original Array Sorted:" << endl;
    prntAry(array,size,10);
    //Print Reverse original array
    cout << "Original Array Reversed:" << endl;
    prntAry(brray,size,10);
    //Print Reverse sorted array, now in descending order
    brray = reverse(array,size);
    cout << "Sorted Original Array Reversed:" << endl;
    prntAry(brray,size,10);
    //Exit
    return 0;
}

int *alloc(int size){
    int *a = new int[size];
    //Fill array with random numbers
    fillAry(a,size);
    return a;
}

int *reverse(int *a,int size){
    int *b = new int[size];
    //Copy reverse elements
    for(int i=0,j=size-1;i<size,j>=0;i++,j--)
            *(b+j)=*(a+i);
    return b;
}

void fillAry(int *a,int size){
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

void sort(int *a, int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(*(a+j)<*(a+i))swap(*(a+j),*(a+i));
        }
    }
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}