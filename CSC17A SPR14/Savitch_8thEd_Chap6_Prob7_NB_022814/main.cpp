/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on February 28, 2014, 4:13 PM
 * Savitch 8th Edition Chapter 6 Problem 7
 * Purpose: Merge two files
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void mrgFile(fstream&,fstream&,ofstream&,int,int);
void sortAry(int*,int);
void swap(int&,int&);
void destroy(int*);
int filFile(fstream&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    fstream fileOne,fileTwo;
    ofstream outFile;
    srand(static_cast<unsigned int>(time(0)));
    //Open files
    fileOne.open("dataOne.dat",ios::out);
    fileTwo.open("dataTwo.dat",ios::out);
    //Randomly fill files
    int sizeOne = filFile(fileOne);
    int sizeTwo = filFile(fileTwo);
    //Close files
    fileOne.close();
    fileTwo.close();
    //Open files
    fileOne.open("dataOne.dat",ios::in);
    fileTwo.open("dataTwo.dat",ios::in);
    outFile.open("mergeData.dat");
    //Merge files
    mrgFile(fileOne,fileTwo,outFile,sizeOne,sizeTwo);
    //Close files
    fileOne.close();
    fileTwo.close();
    outFile.close();
    //Exit
    return 0;
}

//Randomly fill file with 1-25
//one digit numbers, and sort 
//in ascending order
int filFile(fstream& file){
    int size = rand()%25+1;
    int *array = new int[size];
    for(int i=0;i<size;i++){
        *(array+i) = rand()%90+10;
    }
    sortAry(array,size);
    for(int i=0;i<size;i++){
        file << *(array+i) << endl;
    }
    destroy(array);
    return size;
}

void mrgFile(fstream& fileOne,fstream& fileTwo,ofstream& outFile,
                                        int sizeOne, int sizeTwo){
    //Declare size and allocate memory
    //for merged files
    int size = (sizeOne+sizeTwo);
    int *merge = new int[size];
    //Merge two files into one array
    for(int i=0;i<sizeOne;i++)
        fileOne >> *(merge+i);
    for(int i=sizeOne;i<size;i++)
        fileTwo >> *(merge+i);
    //Sort merged array
    sortAry(merge,size);
    //Output sorted array to file
    for(int i=0; i<size; i++){
        outFile << *(merge+i) << endl;
    }
    //Delete merge
    destroy(merge);
}

void sortAry(int *a,int size){
    for(int i=0; i<size-1; i++){
        for(int j=i; j<size; j++){
            if(*(a+i)>*(a+j))swap(*(a+i),*(a+j));
        }
    }
}

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void destroy(int *a){
    delete [] a;
}