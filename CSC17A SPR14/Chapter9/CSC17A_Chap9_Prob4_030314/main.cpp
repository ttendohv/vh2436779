/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 3, 2014, 3:10 PM
 * Gaddis Chapter 9 Problem 4
 * Test Scores and Names
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void input(int*,string*,int);
int *cpy(int*,int);
string *cpy(string*,int);
void sort(int*,string*,int);
void swap(int&,int&);
void swap(string&,string&);
float avg(int*,int);
void display(int*,string*,int);
void destroy(int*);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int numScrs;
    float average;
    //Prompt user for number of test scores
    do{
        cout << "How many test scores would you like to enter? "
                "(must be greater than 0): ";
        cin >> numScrs;
    }while(numScrs<=0);
    //Allocate an array for test scores
    int *scores = new int[numScrs];
    string *names = new string[numScrs];
    //Input each score with name
    input(scores,names,numScrs);
    //Sort scores
    int *scrSrtd = cpy(scores,numScrs);
    string *nameCpy = cpy(names,numScrs);
    sort(scrSrtd,nameCpy,numScrs);
    //Calculate average
    average = avg(scrSrtd,numScrs);
    //Display scores and average
    display(scrSrtd,nameCpy,numScrs);
    cout << "----------------------" << endl;
    cout << "Average Score  " << average << endl;
    //Exit
    destroy(scores);
    destroy(scrSrtd);
    return 0;
}

void input(int *tests, string *names, int scores){
    for(int i=0;i<scores;i++){
        cout << "Please enter the name for Test Score #" << i+1 << ": ";
        cin >> *(names+i);
        cout << "Please enter the score for " << *(names+i) << ": ";
        cin >> *(tests+i);
    }
    cout << endl;
}

int *cpy(int *a, int size){
    int *b = new int[size];
    for(int i=0;i<size;i++){
        *(b+i)=*(a+i);
    }
    return b;
}

string *cpy(string *a,int size){
    string *b = new string[size];
    for(int i=0;i<size;i++){
        *(b+i)=*(a+i);
    }
    return b;
}

void sort(int *a, string *name,int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(*(a+j)<*(a+i)){
                swap(*(a+j),*(a+i));
                swap(*(name+j),*(name+i));
            }
        }
    }
}

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void swap(string &a, string &b){
    string temp = a;
    a=b;
    b=temp;
}

float avg(int *a,int size){
    float sum=0.0;
    for(int i=0;i<size;i++){
        sum+=*(a+i);
    }
    return (sum/size);
}

void display(int *a,string *name,int size){
    cout << "    Sorted Scores" << endl; 
    for (int i=0;i<size;i++){
        cout << setw(10) << *(name+i) << "|" 
             << setw(4) << *(a+i) << endl;
    }
}

void destroy(int *a){
    delete [] a;
}