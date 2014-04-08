/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 26, 2014, 11:36 AM
 * Gaddis Chapter 10 Problem 19
 * Check Writer
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
string translate(float);
void prntChk(string,string,string,float);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    string date,name,amtWrds;
    float amount;
    //Input
    cout << "Input the date (Format MM/DD/YYYY): ";
    getline(cin,date);
    cout << "Name: ";
    getline(cin,name);
    cout << "Check Amount: $";
    cin >> amount;
//    //Test
//    amount = 3245.68;
//    amtWrds = translate(amount);
//    cout << amtWrds << endl;
    amtWrds = translate(amount);
    //Print
    prntChk(date,name,amtWrds,amount);
    
    //Exit
    return 0;
}

void prntChk(string date,string name,string amtWrds,float amount){
    cout << endl;
    cout << setw(50)<< "Date: " << date << endl << endl;
    cout << "Pay to the order of: " << setw(8) << name << setw(17) << " $" 
            << setprecision(2) << fixed << showpoint << amount 
            << endl << endl;
    cout << amtWrds << endl;
    
}

string translate(float amount){
    string mnyTxt,thsnd,hndrd,tns,one,cnt;
    int temp,thous,hund,tens,ones;
    
    thous = amount/1000;
    temp = amount-(thous*1000);
    hund = temp/100;
    temp -=(hund*100);
    tens = temp/10;
    ones = temp-(tens*10);
    
    if(thous>0){
        switch(thous){
            case 1:
                thsnd = "One ";
                break;
            case 2:
                thsnd = "Two ";
                break;
            case 3:
                thsnd = "Three ";
                break;
            case 4:
                thsnd = "Four ";
                break;
            case 5:
                thsnd = "Five ";
                break;
            case 6:
                thsnd = "Six ";
                break;
            case 7:
                thsnd = "Seven ";
                break;
            case 8:
                thsnd = "Eight ";
                break;
            case 9:
                thsnd = "Nine ";
                break;
            case 10:
                thsnd = "Ten ";
                break;
            default:
                break;
        }
        thsnd+="Thousand ";
    }
    
    if(hund>0){
        switch(hund){
            case 1:
                hndrd = "One ";
                break;
            case 2:
                hndrd = "Two ";
                break;
            case 3:
                hndrd = "Three ";
                break;
            case 4:
                hndrd = "Four ";
                break;
            case 5:
                hndrd = "Five ";
                break;
            case 6:
                hndrd = "Six ";
                break;
            case 7:
                hndrd = "Seven ";
                break;
            case 8:
                hndrd = "Eight ";
                break;
            case 9:
                hndrd = "Nine ";
                break;
            case 10:
                hndrd = "Ten ";
                break;
            default:
                break;
        }
        hndrd+="Hundred ";
    }
    
    switch(tens){
        case 1:{
            //Test for numbers 10 - 19
            switch(ones){
                case 0:
                    tns = "Ten ";
                    break;
                case 1:
                    tns = "Eleven ";
                    break;
                case 2:
                    tns = "Twelve ";
                    break;
                case 3:
                    tns = "Thirteen ";
                    break;
                case 4:
                    tns = "Fourteen ";
                    break;
                case 5:
                    tns = "Fifteen ";
                    break;
                case 6:
                    tns = "Sixteen ";
                    break;
                case 7:
                    tns = "Seventeen ";
                    break;
                case 8:
                    tns = "Eighteen ";
                    break;
                case 9:
                    tns = "Nineteen ";
                    break;
                default:
                    break;
            }
            break;
        case 2:
            tns = "Twenty ";
            break;
        case 3:
            tns = "Thirty ";
            break;
        case 4:
            tns = "Forty ";
            break;
        case 5:
            tns = "Fifty ";
            break;
        case 6:
            tns = "Sixty ";
            break;
        case 7:
            tns = "Seventy ";
            break;
        case 8:
            tns = "Eighty ";
            break;
        case 9:
            tns = "Ninety ";
            break;
        default:
            break;
        }
    }
    if(tens == 0 || tens > 1){
        switch(ones){
            case 1:
                one = "One ";
                break;
            case 2:
                one = "Two ";
                break;
            case 3:
                one = "Three ";
                break;
            case 4:
                one = "Four ";
                break;
            case 5:
                one = "Five ";
                break;
            case 6:
                one = "Six ";
                break;
            case 7:
                one = "Seven ";
                break;
            case 8:
                one = "Eight ";
                break;
            case 9:
                one = "Nine ";
                break;
            default:
                break;
        }
    }
    
    int cents;
    cents = ceil((amount - static_cast<int>(amount))*100);
    
    mnyTxt = thsnd + hndrd + tns + one;
    if(cents>0){
        mnyTxt+="and ";
        cout << mnyTxt << endl;
        cnt = cents/10 + '0'; 
        cout << cnt << endl;
        mnyTxt+=cnt;
        cnt = cents%10 + '0';
        cout << cnt << endl;
        mnyTxt+=cnt;
        mnyTxt += " Cents";
    }else mnyTxt+="Dollars ";

    return mnyTxt;
}