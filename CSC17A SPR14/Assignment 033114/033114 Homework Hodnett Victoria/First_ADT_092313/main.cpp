/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Victoria Hodnett
 * Created on September 23, 2013, 8:22 PM
 * Edited on March 30, 2014
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Our Libraries
#include "Array.h"
#include "Array2d.h"

//Global Constants

//Function Prototypes
Array *filStrct(int);
void   prntStrc(Array *,int);
void   dstrStr(Array *);
Array2d *filStrc2(int,int);
void   prntStrc(Array2d *);
void   dstrStr(Array2d *);

int main(int argc, char** argv) {
    //Initialize random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the array structure
    Array *array1=filStrct(75);
    Array *array2=filStrct(25);
    //Print the structure
    prntStrc(array1,10);
    prntStrc(array2,10);
    //Deallocate memory
    dstrStr(array1);
    dstrStr(array2);
    
    //Allocate the array structure
    Array2d *array3=filStrc2(10,10);
    Array2d *array4=filStrc2(15,10);
    //Print the structure
    prntStrc(array3);
    prntStrc(array4);
    //Deallocate memory
    dstrStr(array3);
    dstrStr(array4);
    //Exit stage right
    return 0;
}

void   dstrStr(Array *a){
    //Deallocate the data first
    delete [] a->data;
    //Deallocate the array structure
    delete a;
}
void   dstrStr(Array2d *a){
    //Deallocate data
    for(int i=0;i<a->row;i++){
        delete [] a->data[i];
    }
    delete [] a->data;
    //Deallocate the array structure
    delete a;
}

void   prntStrc(Array *a,int colPRow){
    //Output the array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%colPRow==(colPRow-1))
            cout<<endl;
    }
    cout<<endl;
}

void prntStrc(Array2d *a){
    //Output the array
    cout << endl;
    for(int i=0;i<a->row;i++){
        for(int j=0;j<a->col;j++){
            cout << a->data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Array *filStrct(int n){
    //Create the pointer to a structure
    Array *a=new Array;
    //Set the size of the array in the structure
    a->size=n;
    //Allocate the array
    a->data=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;
    }
    //Return the structure
    return a;
}

Array2d *filStrc2(int row,int col){
    //Create the pointer to a structure
    Array2d *a=new Array2d;
    //Set dimensions of array in the structure
    a->row=row;
    a->col=col;
    //Allocate the array
    a->data=new int*[row];
    for(int i=0;i<row;i++)
        a->data[i]=new int[col];
    //Fill the array
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a->data[i][j]=rand()%90+10;
        }
    }
    //Return structure
    return a;
}