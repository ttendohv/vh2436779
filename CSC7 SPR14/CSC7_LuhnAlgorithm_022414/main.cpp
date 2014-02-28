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
bool valid(char [],int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=25,actSize,sum,chkDgt;
    char account[SIZE];
    //Input account number
    cout << "Please input account number: ";
    cin >> account;
    actSize=strlen(account);
    cout << "Actual size: " << actSize << endl;
    //Begin Luhn Algorithm
    account[actSize]=account[actSize+1]='\0';
    //Double numbers
    int pos=actSize-1;
    do{
        dblNum(account[pos]);
        cout << "Position " << pos << ": " << account[pos] << endl;
        pos=pos-2;
    }while(pos>0);
    //Sum digits
    sum=sumDgts(account,actSize);
    //Find checking digit
    cout << "Sum: " << sum << endl;
    chkDgt=sum*9;
    chkDgt%=100;
    chkDgt%=10;
    //Add checking digit to account number
    account[actSize]=chkDgt+'0';
    cout << "Checking digit: " << chkDgt << ", " << account[actSize] << endl;
    actSize=strlen(account);
    //Print account number with checking digit
    prntNum(account,actSize);
    //Validate card
    if(valid(account,actSize))cout << "Your card is valid " << endl;
    else cout << "Invalid" << endl;
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
    int num=(a-'0');
    cout << "Before "<< num << endl;
    num*=2;
    cout << "After x2 " << num << endl;
    if(num>9){
        num%=10;
        num++;
    }
    a=num+'0';
}

int sumDgts(char a[],int size){
    int sum=0;
//    int b[size];
//    for(int i=0;i<size;i++){
//        b[i]=a[i];
//    }
    for(int i=0;i<size;i++){
        cout << "Index " << i << ": " << a[i] << endl;
        sum+=a[i]-'0';
    }
    cout << "Sum: " << sum << endl;
    return sum;
}

void prntNum(char a[],int size){
    for(int i=0;i<size;i++){
        cout << a[i];
    }
    cout << endl;
}

bool valid(char a[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=a[i]-'0';
    }
    cout << "Validating total: " << sum << endl;
    if(sum%10==0)return true;
    else return false;
}