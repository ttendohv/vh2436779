/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 25, 2014, 7:38 PM
 * Savitch 8th Edition Chapter 4 Problem 13
 * Ninety-Nine Bottles Song
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
string numEng(int);

//Execution Begins Here

int main(int argc, char** argv) {
    //Output song
    for (int number = 99; number >= 0; number--){
        if (number == 1){
            cout << numEng(number) << "bottle of beer on the wall," << endl;
            cout << numEng(number) << "bottle of beer," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << numEng(number) << "bottle of beer on the wall." << endl;
            cout << endl;
        }else{
            cout << numEng(number) << "bottles of beer on the wall," << endl;
            cout << numEng(number) << "bottles of beer," << endl;
            cout << "Take one down, pass it around," << endl;
            cout << numEng(number) << "bottles of beer on the wall." << endl;
            cout << endl;
        }
    }
    //Exit
    return 0;
}

//Numbers Printed in English
//Input
//      number
//Output
//      concatenated string with number in English
string numEng(int num){
    int frstDig = num / 10;
    int secDig = num % 10;
    string numPrt1, numPrt2;
    //Test first digit
    switch(frstDig){
        case 1:{
            //Test for numbers 10 - 19
            switch(secDig){
                case 0:
                    numPrt1 = "Ten ";
                    break;
                case 1:
                    numPrt1 = "Eleven ";
                    break;
                case 2:
                    numPrt1 = "Twelve ";
                    break;
                case 3:
                    numPrt1 = "Thirteen ";
                    break;
                case 4:
                    numPrt1 = "Fourteen ";
                    break;
                case 5:
                    numPrt1 = "Fifteen ";
                    break;
                case 6:
                    numPrt1 = "Sixteen ";
                    break;
                case 7:
                    numPrt1 = "Seventeen ";
                    break;
                case 8:
                    numPrt1 = "Eighteen ";
                    break;
                case 9:
                    numPrt1 = "Nineteen ";
                    break;
                default:
                    break;
            }
            break;
        case 2:
            numPrt1 = "Twenty ";
            break;
        case 3:
            numPrt1 = "Thirty ";
            break;
        case 4:
            numPrt1 = "Forty ";
            break;
        case 5:
            numPrt1 = "Fifty ";
            break;
        case 6:
            numPrt1 = "Sixty ";
            break;
        case 7:
            numPrt1 = "Seventy ";
            break;
        case 8:
            numPrt1 = "Eighty ";
            break;
        case 9:
            numPrt1 = "Ninety ";
            break;
        default:
            break;
        }
    }
    if(frstDig == 0 || frstDig > 1){
        switch(secDig){
            case 1:
                numPrt2 = "One ";
                break;
            case 2:
                numPrt2 = "Two ";
                break;
            case 3:
                numPrt2 = "Three ";
                break;
            case 4:
                numPrt2 = "Four ";
                break;
            case 5:
                numPrt2 = "Five ";
                break;
            case 6:
                numPrt2 = "Six ";
                break;
            case 7:
                numPrt2 = "Seven ";
                break;
            case 8:
                numPrt2 = "Eight ";
                break;
            case 9:
                numPrt2 = "Nine ";
                break;
            default:
                break;
        }
        if(frstDig == 0 && secDig == 0) numPrt2 = "Zero ";
    }
    return numPrt1 + numPrt2;
}