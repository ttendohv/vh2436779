/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on February 24, 2014, 3:41 PM
 * Luhn Algorithm
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
void dblNum(char&);
int sumDgts(char[],int);
void prntNum(char[],int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=25,actSize,sum,chkDgt;
    char account[SIZE];
    //Input account number
    cout << "Please input account number: ";
    cin >> account;
    actSize=strlen(account);
    //Begin Luhn Algorithm
    //Double numbers
    int pos=actSize-1;
    do{
        dblNum(account[pos]);
        pos=pos-2;
    }while(pos>=0);
    //Sum digits
    sum=sumDgts(account,SIZE);
    //Find checking digit
    chkDgt=sum*9;
    chkDgt%=10;
    //Add checking digit to account number
    account[actSize]=chkDgt;
    actSize=strlen(account);
    //Print account number with checking digit
    prntNum(account,actSize);
    //Exit
    return 0;
}

//void dblNum(char &a){
//    int num=atoi(a);
//    num*=2;
//    if(num>9){
//        num%=10;
//        num++;
//    }
//    a=('0'+num);
//}

void dblNum(char &a){
    int num=a;
    num*=2;
    if(num>9){
        num%=10;
        num++;
    }
    a=num+'0';
}

int sumDgts(char a[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=a[i];
    }
    return sum;
}

void prntNum(char a[],int size){
    for(int i=0;i<size;i++){
        cout << a[i];
    }
    cout << endl;
}