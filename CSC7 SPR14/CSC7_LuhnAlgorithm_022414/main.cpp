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
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void dblNum(char&);
int sumDgts(char[],int);
void prntNum(char[],int);
bool valid(char [],int);
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=16;
    char account[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Begin Luhn Algorithm
    prpLuhn(account,SIZE-2);
    Luhn(account,SIZE-2);
    
    
    //Exit
    return 0;
}

void dblNum(char &a){
    int num=(a-'0');
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
        sum+=a[i]-'0';
    }
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
    //cout << "Validating total: " << sum << endl;
    if(sum%10==0)return true;
    else return false;
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Print out generated number
    cout << "Card number: ";
    prntNum(cc,n);
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}

void Luhn(char a[], int size){
    //Double numbers
    int pos=size-1,sum,chkDgt;
    do{
        dblNum(a[pos]);
        pos=pos-2;
    }while(pos>0);
    
    //Sum digits
    sum=sumDgts(a,size);
    //Find checking digit
    chkDgt=sum*9%10;
    //Add checking digit to account number
    a[size]=chkDgt+'0';
    cout << "Card number (plus checking digit): ";
    prntNum(a,size+1);
    //Validate card
    if(valid(a,size+1))cout << "Your card is valid " << endl;
    else cout << "Invalid" << endl;
}