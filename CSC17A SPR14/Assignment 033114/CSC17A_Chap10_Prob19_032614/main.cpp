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
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes
string translate(float);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    char date[10];
    string name,amtWrds;
    float amount;
    //Test
    amount = 3245.68;
    amtWrds = translate(amount);
    cout << amtWrds << endl;
    
    //Exit
    return 0;
}

void prntChk(){
    cout << endl;
    cout << "Date: " << endl << endl;
    cout << "Pay to the order of: " << endl << endl;
    cout << "Some text" << endl;
    
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
    thsnd+="thousand ";
    
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
    hndrd+="hundred ";
    
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
    cout << mnyTxt << endl;
    cnt = to_string(cents); 
    cout << cnt << endl;
    mnyTxt += " cents";

    return mnyTxt;
}