/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Victoria Hodnett
 * Created on January 27, 2014, 9:18 PM
 * Purpose:  Food for Monkeys
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Global Constants
const int COLS=7;

//Function Prototypes
int read(const char [],int [][COLS]);
void write(const int [][COLS],int);
void write(const int [][COLS], const float [], int);
int min(const int [][COLS],int);
int max(const int [][COLS],int);
void avg(const int [][COLS],float [], float [],int);

int main(int argc, char** argv) {
    //Declare variables
    const int ROWS=20;
    int mnkFood[ROWS][COLS];
    float avgPerM[ROWS], avgPerD[COLS];
    char fName[]="./monkey.dat";
    //Read the data from the file
    int actSize=read(fName,mnkFood);
    //Write the data
    write(mnkFood,actSize);
    //Output the minimum amount of food eaten
    //by a monkey
    cout << "Smallest amount eaten by a monkey: "
            << min(mnkFood,actSize) << " ounces" << endl;
    //Output the maximum amount of food eaten
    //by a monkey
    cout << "Largest amount eaten by a monkey: "
            << max(mnkFood,actSize) << " ounces" << endl;
    cout << endl;
    //Output the average amount of food eaten
    //by each monkey
    avg(mnkFood,avgPerM,avgPerD,actSize);
    cout << "Average amount of food eaten by each monkey: " << endl;
    cout << fixed << showpoint << setprecision(2);
    for (int row = 0; row < actSize; row++){
        cout << "Monkey " << row+1 << "  " << avgPerM[row] << endl;
    }
    cout << endl;
    //Output average amount of food eaten by the
    //monkeys per day
    cout << "Average amount of food eaten each day: " << endl;
    cout << "   M     T     W     T     F     S     S" << endl;
    cout << fixed << showpoint << setprecision(2);
    for (int col = 0; col < COLS; col++){
        cout << setw(6) << avgPerD[col];
    }
    cout << endl;
    //Output augmented table
    cout << endl;
    cout << "             Augmented Table:";
    write(mnkFood,avgPerM,actSize);
    //Exit stage right
    return 0;
}

void write(const int monkey[][COLS],int ROWS){
    cout<<endl;
    cout << "Amount of food eaten by each Monkey per Day" << endl;
    cout << "                      Day" << endl;
    cout << "           M   T   W   T   F   S   S" << endl;
    for(int row=0;row<ROWS;row++){
        cout << "Monkey " << row+1;
        for(int col=0;col<COLS;col++){
            cout<<setw(4)<<monkey[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}

void write(const int monkey[][COLS],const float avgPerM[],int ROWS){
    cout<<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Amount of food eaten by each Monkey per Day" << endl;
    cout << "                      Day" << endl;
    cout << "           M   T   W   T   F   S   S   Average" << endl;
    for(int row=0;row<ROWS;row++){
        cout << "Monkey " << row+1;
        for(int col=0;col<COLS;col++){
            cout<<setw(4)<<monkey[row][col];
        }
        cout << "    " << avgPerM[row];
        cout<<endl;
    }
    cout<<endl;
}

int read(const char fName[],int monkey[][COLS]){
    //Open the file
    ifstream input;
    input.open(fName);
    //Read the data
    int row=0;
    while(input){
        for(int col=0;col<COLS;col++){
                input>>monkey[row][col];
        }
        row++;
    }
    //Close the file
    input.close();
    //return the number of rows
    return --row;
}

int min(const int monkey[][COLS],int ROWS){
    //Declare some small variable
    int small = monkey[0][0];
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLS; col++){
            if (small > monkey[row][col]){
                small = monkey[row][col];
            }
        }
    }
    return small;
}

int max(const int monkey[][COLS],int ROWS){
    //Declare some big variable
    int big = monkey[0][0];
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLS; col++){
            if (big < monkey[row][col]){
                big = monkey[row][col];
            }
        }
    }
    return big;
}

void avg(const int monkey[][COLS],float avgPerM[],float avgPerD[],int ROWS){
    for(int row = 0; row < ROWS; row++){
        float sum = 0.0;
        for(int col = 0; col < COLS; col++){
            sum += monkey[row][col];
        }
        avgPerM[row] = sum / COLS;
    }
    for(int col = 0; col < COLS; col++){
        float sum = 0.0;
        for(int row = 0; row < ROWS; row++){
            sum += monkey[row][col];
        }
        avgPerD[col] = sum / ROWS;
    }
}
