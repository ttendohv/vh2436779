/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 6, 2014, 5:38 PM
 * Gaddis Chapter 9 Problem 13
 * Movie Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void sort(const int[],int[],int);
float mean(int[],int);
float median(int[],int);
int *mode(int[],int);
int maxFreq(int[],int);
int nModes(int[],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int stdnts;
    //Input how many students surveyed
    do{
        cout << "How many students were surveyed? (Must be greater than 0) ";
        cin >> stdnts;
    }while(stdnts<1);
    int *movies = new int [stdnts];
    //Input number of movies each student saw
    for(int i=0;i<stdnts;i++){
        do{
            cout << "Please enter the number of movies Student #"
                    << i+1 << " saw: ";
            cin >> *(movies+i);
        }while(*(movies+i)<0);
    }
    cout << endl;
    //Calculate mean, median, and mode of values entered
    //Sort first
    int *cpy = new int[stdnts];
    sort(movies,cpy,stdnts);
    //Average
    cout << endl;
    cout << "The average number of movies seen: "
            << setprecision(2) << showpoint << fixed
            << mean(cpy,stdnts) << endl;
    //Median
    cout << "The median value for number of movies seen: "
            << setprecision(2) << showpoint << fixed
            << median(cpy,stdnts) << endl;
    //Mode
    int *modeAry = mode(cpy,stdnts);
    cout << "The number of modes: "
            << *(modeAry+0) << endl;
    cout << *(modeAry+1) << " students have watched the "
            "following number of movies: ";
    for(int i=2;i<(*(modeAry+0)+2);i++){
        cout << *(modeAry+i) << ", "; 
    }
    cout << endl;
    //Exit
    return 0;
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