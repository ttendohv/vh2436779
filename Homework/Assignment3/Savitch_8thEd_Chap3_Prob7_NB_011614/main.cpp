/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 16, 2014, 8:11 PM
 * Savitch 8th Edition Chapter 3 Problem 7
 * Convert years to Roman numerals
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const char RMN_1 = 'I'; //1 year
const char RMN_5 = 'V'; //5 years
const char RMN_10 = 'X'; //10 years
const char RMN_50 = 'L'; //50 years
const char RMN_100 = 'C'; //100 years
const char RMN_500 = 'D'; //500 years
const char RMN_1000 = 'M'; //1000 years
const int ONE_YR = 1; //1 year, use for calculating 5's
const int TEN_YR = 10; //10 years, use for calculating 50's
const int HUND_YR = 100; //100 years, use for calculating 500's
const int THOU_YR = 1000; //1000 years

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    int year;
    char answer;
    
    //Loop to ask numerous times for year conversion
    do{
        do{
            //Input year between 1000 and 3000
            cout << "Enter a year between 1000 and 3000 to convert "
                 << "to Roman Numerals: ";
            cin >> year;
        }while (year < 1000 || year > 3000);

    //Begin outputting year:
    cout << endl;
    cout << year << " in Roman numerals is: ";
    
         //Determine year in Roman Numerals
         //1,000 Years
            int nThoYr = year/THOU_YR;
            for (int i = 0; i < nThoYr; i++){
                cout << RMN_1000;
            }
                year -= nThoYr*THOU_YR;
         //100 years, 500 years
            int nHunYr = year/HUND_YR;
            if (nHunYr == 4){
                cout << RMN_100 << RMN_500;
            }else if (nHunYr == 9){
                cout << RMN_100 << RMN_1000;
            }else if (nHunYr >= 5){
                cout << RMN_500;
                int temp = nHunYr - 5;
                for (int i = 0; i < temp; i++){
                    cout << RMN_100;
                }
            }else{
                for (int i = 0; i < nHunYr; i++){
                    cout << RMN_100;
                }
            }
            year -= nHunYr*HUND_YR;
         //10 years, 50 years
            int nTenYr = year/TEN_YR;
            if (nTenYr == 4){
                cout << RMN_10 << RMN_50;
            }else if (nTenYr == 9){
                cout << RMN_10 << RMN_100;
            }else if (nTenYr >= 5){
                cout << RMN_50;
                int temp = nTenYr - 5;
                for (int i = 0; i < temp; i++){
                    cout << RMN_10;
                }
            }else{
                for (int i = 0; i < nTenYr; i++){
                    cout << RMN_10;
                }
            }
            year -= nTenYr*TEN_YR;
         //1 year, 5 years
            int nOneYr = year/ONE_YR;
            if (nOneYr == 4){
                cout << RMN_1 << RMN_5;
            }else if (nOneYr == 9){
                cout << RMN_1 << RMN_10;
            }else if (nOneYr >= 5){
                cout << RMN_5;
                int temp = nOneYr - 5;
                for (int i = 0; i < temp; i++){
                    cout << RMN_1;
                }
            }else{
                for (int i = 0; i < nOneYr; i++){
                    cout << RMN_1;
                }
            }
        cout << endl << endl;
        //Prompt to repeat
        cout << "Would you like to repeat for another year? Y/N ";
        cin >> answer;
        cout << endl;
    }while(answer == 'y' || answer == 'Y');
    
    //Exit
    return 0;
}

