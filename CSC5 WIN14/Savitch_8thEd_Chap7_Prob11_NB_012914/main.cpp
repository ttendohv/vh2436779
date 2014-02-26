/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 29, 2014, 10:18 AM
 * Savitch 8th Edition Chapter 7 Problem 11
 * Seating Chart
 */

//System libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned short COLS = 500;

//Function Prototypes
void initial(bool [][COLS],unsigned short[],int,int);
void display(const bool [][COLS],const unsigned short[],int);
bool whtSeat(bool [][COLS],const unsigned short[],int);

//Execution Begins
int main(int argc, char** argv) {
    //Declares variables
    const int ROWS = 500;
    bool seat[ROWS][COLS];
    int rowUtil=15, colUtil=12;
    unsigned short pCol[ROWS];
    //Initialize arrays
    initial(seat,pCol,rowUtil,colUtil);
    do{
        //Display the seating array
        display(seat,pCol,rowUtil);
        //Prompt for desired seat
    }while(whtSeat(seat,pCol,rowUtil));
    //Exit
    return 0;
}

void initial(bool seat[][COLS],unsigned short pCol[],int ROWS,int colMax){
    //Initialize the arrays
    for(int row = 0;row < ROWS; row++){
        for (int col = 0;col < COLS; col++){
            seat[row][col] = false;
        }
        pCol[row] = colMax;
    }
}

void display(const bool seat[][COLS],const unsigned short pCol[],int ROWS){
    //Display the seating arrangement
    char view = 'A';
    cout << endl;
    for(int row = 0;row < ROWS; row++){
        cout << setw(2) << row+1;
        for (int col = 0;col < pCol[row]; col++){
            if(seat[row][col]) cout << setw(2) << "X";
            else cout << setw(2) << static_cast<char>(view + col); 
        }
        cout << endl;
        pCol[row];
    }
}

bool whtSeat(bool seat[][COLS],const unsigned short pCol[],int ROWS){
    //Prompt user for seat desired
    cout << "Choose Seat to take i.e. 3C " << endl;
    int rowSeat; char colSeat;
    cin >> rowSeat >> colSeat;
    rowSeat--;
    colSeat-='A';
    //Check if valid seats
    if(rowSeat <= ROWS && (colSeat) <= pCol[rowSeat]){
        if(!seat[rowSeat][colSeat]){
            seat[rowSeat][colSeat] = true;
        }else{
            cout << "Seat already taken!"<< endl;
        } 
    }else{
        cout << "Not a Seat" << endl;
        return false;
    }
    return true;
}