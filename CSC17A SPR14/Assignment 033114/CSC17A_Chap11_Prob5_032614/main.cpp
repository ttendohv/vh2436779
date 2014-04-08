/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 26, 2014, 1:44 PM
 * Gaddis Chapter 11 Problem 5
 * Weather Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User-Defined Libraries
#include "WthrStats.h"

//Global Constants

//Function Prototypes
void inpData(WthrData[],int);
float rainfall(WthrData[],int,float&,float&);
void sort(WthrData[],int[],int[],int);
string monthN(int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=12;
    WthrData year1[SIZE];
    float avgRain,totRain,avgTmp;
    int highTmp[SIZE],lowTmp[SIZE];
    //Input
    inpData(year1,SIZE);
    for(int i=0;i<SIZE;i++){
        highTmp[i]=i;
        lowTmp[i]=i;
    }
    //Totals and averages
    avgRain=rainfall(year1,SIZE,totRain,avgTmp);
    //Sort temperatures
    sort(year1,highTmp,lowTmp,SIZE);
    //Print
    cout << "Testing: " << APRIL+1 << " " 
            << year1[APRIL].totRain << endl; 
    cout << setprecision(2) << fixed << showpoint;
    cout << "Average monthly rainfall: " << avgRain << endl;
    cout << "Total rainfall for the year: " << totRain << endl;
    cout << "Highest temperature for the year: " << year1[highTmp[0]].highTmp 
           << " in " << monthN(highTmp[0]) << endl;
    cout << "Lowest temperature for the year: " << year1[lowTmp[0]].lowTmp 
           << " in " << monthN(lowTmp[0]) << endl;
    cout << "Average temperature for the year: " << avgTmp << endl;
    
    //Exit
    return 0;
}

string monthN(int m){
    switch(m){
        case JANUARY:
            return "January";
            break;
        case FEBRUARY:
            return "February";
            break;
        case MARCH:
            return "March";
            break;
        case APRIL:
            return "April";
            break;
        case MAY:
            return "May";
            break;
        case JUNE:
            return "June";
            break;
        case JULY:
            return "July";
            break;
        case AUGUST:
            return "August";
            break;
        case SEPTEMBER:
            return "September";
            break;
        case OCTOBER:
            return "October";
            break;
        case NOVEMBER:
            return "November";
            break;
        case DECEMBER:
            return "December";
            break;
    }
    
}

void inpData(WthrData a[],int size){
    //Month index=JANUARY;
    cout << "Please enter weather data for the "
            "entire year, starting with January\n"
            "(Temperatures must be between -100 and 145"
            "degrees Fahrenheiht) " 
            << endl << endl;
    for(int index=JANUARY;index<size;index++){
        cout << "Month " << index+1 << ": " << endl;
        cout << "Total Rainfall: ";
        cin >> a[index].totRain;
        do{
            cout << "High Temperature: ";
            cin >> a[index].highTmp;
        }while(a[index].highTmp>145||a[index].highTmp<-100);
        do{
            cout << "Low Temperature: ";
            cin >> a[index].lowTmp;
        }while(a[index].lowTmp>145||a[index].lowTmp<-100);
        a[index].avgTmp=((a[index].highTmp+a[index].lowTmp)/2.0);
        cout << setprecision(2) << fixed << showpoint;
        cout << "Average Temperature: " << a[index].avgTmp << endl;
        cout << endl;
    }
}

float rainfall(WthrData a[],int size,float &total,float &temp){
    float sum=0.0;
    for(int index=JANUARY;index<size;index++){
        sum+=a[index].avgTmp;
    }
    temp=sum/size;
    sum=0.0;    
    for(int index=JANUARY;index<size;index++)
        sum+=a[index].totRain;
    total=sum;
    return sum/size;
}

void sort(WthrData a[],int indx[],int indx1[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((a[indx[i]].highTmp)<(a[indx[j]].highTmp)){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((a[indx1[i]].lowTmp)>(a[indx1[j]].lowTmp)){
                int temp=indx1[i];
                indx1[i]=indx1[j];
                indx1[j]=temp;
            }
        }
    }
}