/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on February 26, 2014, 10:41 AM
 * Gaddis Chapter 9 Problem 6
 * Modify Program 9-17, United Case case study
 */

//System Libaries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void arrSelectSort(int *[],int);
void showArray(const int[],int);
void showArrPtr(int *[],int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    //const int NUM_DONATIONS = 15;
        //Donation Amounts
    //int donations[NUM_DONATIONS] = {5,  100, 5,  25, 10,
    //                                5,  25,  5,  5,  100,
    //                                10, 15,  10, 5,  10 };
    int numDntn;
    cout << "How many donations would you like to make? ";
    cin >> numDntn;
    int *donations = new int[numDntn];
    cout << "Please input each donation amount, "
            "pressing enter after each entry " << endl;
    for(int i=0;i<numDntn;i++)
        cin >> *(donations+i);
    int *arrPtr[numDntn];
    //Each element of arrPtr points to 
    //an element in donations
    for(int count=0;count<numDntn;count++)
        arrPtr[count] = &donations[count];
    //Sort elements of array of pointers
    arrSelectSort(arrPtr,numDntn);
    //Display donations using array of pointers
    cout << "The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr,numDntn);
    //Display donations in original order
    cout << "The donations, in their original order, are: \n";
    showArray(donations,numDntn);
    //Exit
    return 0;
}

void arrSelectSort(int *arr[],int size){
    int startScan,minIndex;
    int *minElem;
    
    for(startScan=0;startScan<(size-1);startScan++){
        minIndex=startScan;
        minElem=arr[startScan];
        for(int index=startScan+1;index<size;index++){
            if(*(arr[index])<*minElem){
                minElem=arr[index];
                minIndex=index;
            }
        }
        arr[minIndex]=arr[startScan];
        arr[startScan]=minElem;
    }
}

void showArray(const int arr[],int size){
    for(int count=0;count<size;count++)
        cout << arr[count] << " ";
    cout << endl;
}

void showArrPtr(int *arr[],int size){
    for(int count=0;count<size;count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}
