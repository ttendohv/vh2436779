/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 6, 2014, 4:19 PM
 * Purpose: Mean, Median, Mode
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float mean(int[],int);
float median(int[],int);
int *mode(int[],int);
void fillAry(int[],int);
void prntAry(int[],int,int);
void sort(const int[],int[],int);
int maxFreq(int[],int);
int nModes(int[],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE],max,numMds;
    //Fill the array with 0-9
    fillAry(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort array
    sort(array,brray,SIZE);
    //Print sorted array
    prntAry(brray,SIZE,10);
    //What is the mean of this array?
    cout << endl;
    cout << "The mean of this array is: "
            << setprecision(2) << showpoint << fixed
            << mean(brray,SIZE) << endl;
    //What is the median of this array?
    cout << "The median of this array is: "
            << setprecision(2) << showpoint << fixed
            << median(brray,SIZE) << endl;
    //What is the mode of this array?
    int *modeAry = mode(brray,SIZE);
    cout << "The number of modes in this array: "
            << *(modeAry+0) << endl;
    cout << "The number of times this (these) number(s) "
            "occurred " << *(modeAry+1) << endl;
    cout << "The mode(s): ";
    for(int i=2;i<(*(modeAry+0)+2);i++){
        cout << *(modeAry+i) << " "; 
    }
    cout << endl;
    
    //Exit
    return 0;
}

//Repetitive count with 1 digit elements
void fillAry(int a[],int size){
    for(int i=0;i<size;i++){
        a[i]=i%10;
    }
}

void prntAry(int a[],int size,int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout << a[i] << " ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void sort(const int a[],int b[],int size){
    //Make a copy
    for(int i=0;i<size;i++){
        b[i]=a[i];
    }
    //Sort the copied array
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(b[i]>b[j]){
                int temp = b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}

float mean(int a[],int size){
    float sum=0.0;
    for(int i=0;i<size;i++){
        sum+=a[i];
    }
    return sum/size;
}

float median(int a[],int size){
    if(size%2==1)
        return a[(size-1)/2];
    else
        return (a[size/2]+a[(size/2)-1])/2.0;
}

int *mode(int a[],int size){
    int maxFr=maxFreq(a,size);
    int numMds=nModes(a,size,maxFr);
    int *modes = new int[numMds+2];
    *(modes+0)=numMds;
    *(modes+1)=maxFr;
    for(int n=2;n<(numMds+2);n++){
        //Declare counters
        int count=1,max=1;
        //Loop and compare
        for(int i=1;i<size;i++){
            if(a[i-1]==a[i]){
                count++;
                if(count>max)max=count;
            }else{
                count = 1;
            }
            if(count==maxFr)modes[n++]=a[i];
        }
    }
    return modes;
}

int maxFreq(int a[],int size){
    //Declare counters
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count = 1;
        }
    }
    return max;
}

int nModes(int a[],int size,int maxFreq){
    int modes=0,count=1,max=1;
    
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            if(count==maxFreq)modes++;
            count = 1;
        }
    }
    return modes;
}