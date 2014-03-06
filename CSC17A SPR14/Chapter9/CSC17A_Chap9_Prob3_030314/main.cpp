/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 3, 2014, 2:53 PM
 * Gaddis Chapter 9 Problem 3
 * Drop Lowest Score
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void input(int*,int);
int *cpy(int*,int);
void sort(int*,int);
void swap(int&,int&);
float avg(int*,int);
void display(int*,int);
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
    //Input each score
    input(scores,numScrs);
    //Sort scores
    int *scrSrtd = cpy(scores,numScrs);
    sort(scrSrtd,numScrs);
    //Drop Lowest Score
    scrSrtd[0]='\0';
    //Calculate average
    average = avg(scrSrtd,numScrs);
    //Display scores and average
    display(scrSrtd,numScrs);
    cout << "----------------------" << endl;
    cout << "     Average      " << average << endl;
    cout << "  (with lowest \n  score dropped)" << endl;
    //Exit
    destroy(scores);
    destroy(scrSrtd);
    return 0;
}

void input(int *tests, int scores){
    for(int i=0;i<scores;i++){
        cout << "Please enter the score for Test #" << i+1 << ": ";
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

void sort(int *a, int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(*(a+j)<*(a+i))swap(*(a+j),*(a+i));
        }
    }
}

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

float avg(int *a,int size){
    float sum=0.0;
    for(int i=0;i<size;i++){
        sum+=*(a+i);
    }
    return (sum/(size-1));
}

void display(int *a, int size){
    cout << "    Sorted" << endl;
    cout << "    Scores" << endl; 
    for (int i=1;i<size;i++){
        cout << i << "|    " 
                << *(a+i) << endl;
    }
}

void destroy(int *a){
    delete [] a;
}