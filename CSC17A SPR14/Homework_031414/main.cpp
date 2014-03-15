/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 14, 2014, 7:09 PM
 * Homework 03/14/14 Program Selection
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problemMode();
void problem1();
void problem2();
void problem3();
void problem4();
void problem6();
void problem10();
void problem11();
void problem12();
void problem13();
    //Mode Problem
void filAry1Dgt(int[],int);
    //Problem 1
int *alloc(int);
void fillAry(int*,int);
void prntAry(int*,int,int);
    //Problem 2
void input(int*,int);
int *cpy(int*,int);
void sort(int*,int);
void swap(int&,int&);
float avg(int*,int);
void display(int*,int);
void destroy(int*);
    //Problem 3
float avgProb3(int*,int);
void displayProb3(int*,int);
    //Problem 4
void input(int*,string*,int);
string *cpy(string*,int);
void sort(int*,string*,int);
void swap(string&,string&);
void display(int*,string*,int);
    //Problem 6
void arrSelectSort(int *[],int);
void showArray(const int[],int);
void showArrPtr(int *[],int);
    //Problem 10
int *reverse(int*,int);
    //Problem 11
int *expand(int*,int);
    //Problem 12
int *shift(int*,int);
    //Problem 13
void sort(const int[],int[],int);
float mean(int[],int);
float median(int[],int);
int *mode(int[],int);
int maxFreq(int[],int);
int nModes(int[],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problemMode();break;
            case 2:    problem1();break;
            case 3:    problem2();break;
            case 4:    problem3();break;
            case 5:    problem4();break;
            case 6:    problem6();break;
            case 7:    problem10();break;
            case 8:    problem11();break;
            case 9:    problem12();break;
            case 10:   problem13();break;
            default:   def(inN);}
    }while(inN>=1&&inN<=8);
    //Exit
    return 0;
}

void Menu(){
    cout << endl << endl;
    cout<<"Chapter 9 Homework"<<endl;
    cout<<"Type 1 for Mode Problem"<<endl;
    cout<<"Type 2 for problem 1"<<endl;
    cout<<"Type 3 for problem 2"<<endl;
    cout<<"Type 4 for problem 3"<<endl;
    cout<<"Type 5 for problem 4"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 10"<<endl;
    cout<<"Type 8 for problem 11"<<endl;
    cout<<"Type 9 for problem 12"<<endl;
    cout<<"Type 10 for problem 13"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
    cout << endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

//Mean, Median, Mode
void problemMode(){
    //Declare variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE],max,numMds;
    //Fill the array with 0-9
    filAry1Dgt(array,SIZE);
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
}

//Gaddis Chapter 9 Problem 1
//Array Allocator
void problem1(){
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    int size;
    do{
        cout << "Enter a number to indicate how large you would "
                "like the integer array to be (must be nonnegative): ";
        cin >> size;
    }while(size<0);
    int *array = alloc(size);
    //Print array
    prntAry(array,size,10);
}

//Gaddis Chapter 9 Problem 2
//Test Scores
void problem2(){
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
    //Calculate average
    average = avg(scrSrtd,numScrs);
    //Display scores and average
    display(scrSrtd,numScrs);
    cout << "----------------------" << endl;
    cout << "Average   " << average << endl;
    //Exit
    destroy(scores);
    destroy(scrSrtd);
}

//Gaddis Chapter 9 Problem 3
//Drop Lowest Score
void problem3(){
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
    average = avgProb3(scrSrtd,numScrs);
    //Display scores and average
    displayProb3(scrSrtd,numScrs);
    cout << "----------------------" << endl;
    cout << "     Average      " << average << endl;
    cout << "  (with lowest \n  score dropped)" << endl;
    //Exit
    destroy(scores);
    destroy(scrSrtd);
}

//Gaddis Chapter 9 Problem 4
//Test Scores and Names
void problem4(){
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
}

//Gaddis Chapter 9 Problem 6
//Modify Program 9-17, United Case case study
void problem6(){
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
}

//Gaddis Chapter 9 Problem 10
//Reverse Array
void problem10(){
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
}

//Gaddis Chapter 9 Problem 11
//Array Expander
void problem11(){
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    int size;
    do{
        cout << "Enter a number to indicate how large you would "
                "like the integer array to be (must be nonnegative): ";
        cin >> size;
    }while(size<0);
    int *array = alloc(size);
    int *brray = expand(array,size);
    //Print array
    prntAry(array,size,10);
    //Print expanded array with unused elements
    prntAry(brray,(size*2),10);
}

//Gaddis Chapter 9 Problem 12
//Element Shifter
void problem12(){
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    int size;
    do{
        cout << "Enter a number to indicate how large you would "
                "like the integer array to be (must be nonnegative): ";
        cin >> size;
    }while(size<0);
    int *array = alloc(size);
    int *brray = shift(array,size);
    //Print array
    prntAry(array,size,10);
    //Print shifted array
    prntAry(brray,(size+1),10);
}

//Gaddis Chapter 9 Problem 13
//Movie Statistics
void problem13(){
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
    if(*(modeAry+0)>0){
        cout << *(modeAry+1) << " students have watched the "
                "following number of movies: ";
        for(int i=2;i<(*(modeAry+0)+2);i++){
            cout << *(modeAry+i) << ", "; 
        }
    }
    cout << endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

int *alloc(int size){
    int *a = new int[size];
    //Fill array with random numbers
    fillAry(a,size);
    return a;
}

void fillAry(int *a, int size){
    for(int i=0;i<size;i++){
        *(a+i) = rand()%90+10;
    }
}

//Repetitive count with 1 digit elements
void filAry1Dgt(int a[],int size){
    for(int i=0;i<size;i++){
        a[i]=i%10;
    }
}

void prntAry(int *a, int size, int perLine){
    cout << endl;
    for(int i=0;i<size;i++){
        cout << setw(3);
        cout << a[i];
        if(i%perLine==(perLine-1))cout << endl;
    }
    cout << endl;
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
    return (sum/size);
}

void display(int *a, int size){
    cout << "    Sorted" << endl;
    cout << "    Scores" << endl; 
    for (int i=0;i<size;i++){
        cout << i+1 << "|    " 
                << *(a+i) << endl;
    }
}

void destroy(int *a){
    delete [] a;
}

float avgProb3(int *a,int size){
    float sum=0.0;
    for(int i=0;i<size;i++){
        sum+=*(a+i);
    }
    return (sum/(size-1));
}

void displayProb3(int *a, int size){
    cout << "    Sorted" << endl;
    cout << "    Scores" << endl; 
    for (int i=1;i<size;i++){
        cout << i << "|    " 
                << *(a+i) << endl;
    }
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

void swap(string &a, string &b){
    string temp = a;
    a=b;
    b=temp;
}

void display(int *a,string *name,int size){
    cout << "    Sorted Scores" << endl; 
    for (int i=0;i<size;i++){
        cout << setw(10) << *(name+i) << "|" 
             << setw(4) << *(a+i) << endl;
    }
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

int *reverse(int *a,int size){
    int *b = new int[size];
    //Copy reverse elements
    for(int i=0,j=size-1;i<size,j>=0;i++,j--)
            *(b+j)=*(a+i);
    return b;
}

int *expand(int *a,int size){
    int *b = new int[(size*2)];
    for(int i=0;i<size;i++)
        *(b+i)=*(a+i);
    for(int i=size;i<(size*2);i++)
        *(b+i)=0;
    return b;
}

int *shift(int *a,int size){
    int *b = new int[(size+1)];
    //Shift elements from a into
    //new array b
    *(b+0)=0;
    for(int i=0;i<size+1;i++)
        *(b+i+1)=*(a+i);
    return b;
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
    int count=1,max=2;
    //Loop and compare
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>=max)max=count;
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