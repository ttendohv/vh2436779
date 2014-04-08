/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 11:36 PM
 * Gaddis Chapter 10 Problems
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
        //Problem12
void problem12();
bool length(string);
bool chkChars(string);
        //Problem18
void problem18();
void srch(string[],string,int);
        //Problem19
void problem19();
string translate(float);
void prntChk(string,string,string,float);

//Execution Begins Here
int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem12();break;
            case 2:    problem18();break;
            case 3:    problem19();break;
            default:   def(inN);}
    }while(inN>=1&&inN<=3);
    //Exit
    return 0;
}

void Menu(){
    cout << endl << endl;
    cout<<"Chapter 10 Homework"<<endl;
    cout<<"Type 1 for problem 12"<<endl;
    cout<<"Type 2 for problem 18"<<endl;
    cout<<"Type 3 for problem 19"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
    cout << endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Password Verifier
void problem12(){
    //Declare variables
    string psswrd;
    //Input
    cout << "Please input your password:\n"
            "(It must include only letters and numbers, and "
            "at least one uppercase, one lowercase, and one "
            "digit.)" << endl;
    cin >> psswrd;
    cout << endl;
    //Validate password
    while(!length(psswrd) || !chkChars(psswrd)){
        cout << "Please try again. Enter in a new password: ";
        cin >> psswrd;
        cout << endl;
    }
}

bool length(string a){
    if(a.size()<6){
        cout << "Your password must be at least "
                "6 characters in length. " << endl;
        return false;
    }else return true;
}

bool chkChars(string a){
    int lower=0,upper=0,digit=0,
            invalid=0,size=a.size();
    for(int i=0;i<size;i++){
        if(isalnum(a[i])){
            if(isalpha(a[i])){
                isupper(a[i]) ? upper++ : lower++;
            }else digit++;
        }else invalid++;
    }
    if(invalid>0){
        cout << "Your password contains an invalid "
                "character. " << endl;
        return false;
    }else if(lower==0||upper==0){
        cout << "Your password must include at "
                "least one lowercase letter and "
                "one uppercase letter. " << endl;
        return false;
    }else if(digit==0){
        cout << "Your password must include at "
                "least one digit. " << endl;
        return false;
    }else{
        cout << "You have entered a valid password. " << endl;
        return true;
    }
}

//Phone Number List
void problem18(){
    //Declare variables
    string numbers[] = { "Becky Warren, 555-1223",
                       "Joe Looney, 555-0097",
                       "Geri Palmer, 555-8787",
                       "Lynn Presnell, 555-1212",
                       "Holly Gaddis, 555-8878",
                       "Sam Wiggins, 555-0998",
                       "Bob Kain, 555-8712",
                       "Tim Haynes, 555-7676",
                       "Warren Gaddis, 555-9037",
                       "Jean James, 555-4939",
                       "Ron Palmer, 555-2783"     };
    string name;
    //Search
    cout << "Please enter a name or partial number you are "
            "looking for: ";
    cin >> name;
    srch(numbers,name,11);
}

void srch(string a[], string find,int size){
    int found;
    for(int i=0;i<size;i++){
        found=a[i].find(find,0);
        if(found!=string::npos){
            cout << a[i] << endl;
        }
    }
}

//Check Writer
void problem19(){
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
    amtWrds = translate(amount);
    //Print
    prntChk(date,name,amtWrds,amount);
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