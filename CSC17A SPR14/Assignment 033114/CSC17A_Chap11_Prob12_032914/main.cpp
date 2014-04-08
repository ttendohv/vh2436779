/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 29, 2014, 8:50 PM
 * Gaddis Chapter 11 Problem 12
 * Course Grade
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User-defined Libraries
#include "StudentInfo.h"

//Global Constants

//Function Prototypes
void alloc(Student*,int,int);
void inpData(Student*,int,int);
float findAvg(int*,int);
char findGrd(float);
void prntData(Student*,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int students,tests;
    
    cout << "How many students? ";
    cin >> students;
    Student *group = new Student[students];
    cout << "How many tests? ";
    cin >> tests;
    alloc(group,students,tests);
    //Input
    inpData(group,students,tests);
    //Print
    prntData(group,students);
    //Exit
    return 0;
}

void alloc(Student *a,int students,int tests){
    for(int i=0;i<students;i++){
        a[i].tests=new int[tests];
    }
}

void inpData(Student *a,int students,int test){
    //Input 
    for(int i=0;i<students;i++){
        cout << "Name: ";
        cin >> a[i].name;
        cout << "ID#: ";
        cin >> a[i].ID;
        cout << "Enter the following tests: " << endl;
        for(int j=0;j<test;j++){
            cout << "Test #" << j+1 << ": ";
            cin >> a[i].tests[j];
        }
        a[i].average=findAvg(a[i].tests,test);
        a[i].grade=findGrd(a[i].average);
        cout << endl;
    }
}

float findAvg(int *a,int size){
    int sum=0.0;
    for(int i=0;i<size;i++){
        sum+=a[i];
    }
    return sum/size;
}

char findGrd(float a){
    if(a>=91.0)
        return 'A';
    else if (a>=81)
        return 'B';
    else if (a>=71)
        return 'C';
    else if (a>=61)
        return 'D';
    else
        return 'F';
}

//Formatting
void prntData(Student *a,int size){
    cout << endl;
    cout << setw(40) << "Average" << endl;
    cout << setw(16) << "Student Name" << setw(12) << "ID Number" << setw(14) 
            << "Test Score" << setw(16) << "Course Grade" << endl;
    for(int i=0;i<size;i++)
        cout << setw(14) << a[i].name << setw(13) << a[i].ID << setw(12)
                << a[i].average << setw(14) << a[i].grade << endl;
}