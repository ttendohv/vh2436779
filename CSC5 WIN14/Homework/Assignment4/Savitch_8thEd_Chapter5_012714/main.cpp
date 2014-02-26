/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 27, 2014, 5:17 PM
 * Chapter 5 Problems using a Menu
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int CNV_24HR = 12; //Convert from/to 24-hour notation
const int FULL_DAY = 24; //hours in a day
const int CNV_HRS_MIN = 60; //minutes in an hour
const int QTR_VAL = 25;
const int DIM_VAL = 10;
const int PEN_VAL = 1;
const float CNV_FT_M = 0.3048; //meters in foot
const float CNV_M_CM = 100.0; //cm in meter
const float CNV_FT_IN = 12.0; //inches in foot
const float CNV_KG_LB = 2.2046; //lbs in kg
const float CNV_KG_G = 1000.0; //g in kg
const float CNV_LB_OZ = 16.0; //oz in lb

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem5();
void problem6();
void problem7();
void problem9();
void problem10();
void read(int&, int&);
void cnvTime(int&, char&);
void output(int, int, char);
void inpTime(int&, int&, int&, int&);
void endWtg(int, int, int, int, int&, int&);
void outputT(int, int);
void inpTime(int&, int&, int&, int&, char&);
void endWtg(int, int, int, int, int&, int&, char&);
void outputT(int, int, char);
void numCoin(int, int&, int&);
string coinWrd(int, int);
void readP6(int&, int&);
void cnvMsmt(float, float, int&, int&);
void output(int, int, int, int);
void readP7(int&, int&);
void cnvMsmtP7(float, float, int&, int&);
void outputP7(int, int, int, int);
void readP9(int&, int&);
void cnvMsmtP9(float, float, int&, int&);
void outputP9(int, int, int, int);
void readP10(int&, int&);
void cnvMsmtP10(float, float, int&, int&);
void outputP10(int, int, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem5();break;
        case 5:    problem6();break;
        case 6:    problem7();break;
        case 7:    problem9();break;
        case 8:    problem10();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=8);
    //Exit
    return 0;
}

void Menu(){
    cout<<"Menu for Chapter 5"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 5"<<endl;
    cout<<"Type 5 for problem 6"<<endl;
    cout<<"Type 6 for problem 7"<<endl;
    cout<<"Type 7 for problem 9"<<endl;
    cout<<"Type 8 for problem 10"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

//Convert from 24-hour notation to 12-hour notation
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;

    //Declare variables
    int hour, minute;
    char ampm, response;
    do{
        //Input time
        read(hour, minute);
        //Convert time
        cnvTime(hour, ampm);
        //Output result
        output(hour, minute, ampm);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
                "another time? Y/N ";
        cin >> response;
    }while(response == 'Y' || response == 'y');
}

//Calculate time after waiting
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;

    //Declare variables
    int curHour, curMin, waitHrs, waitMin, finHour, finMin;
    char response;
    do{
        //Input times
        inpTime(curHour, curMin, waitHrs, waitMin);
        //Calculate time after waiting
        endWtg(curHour, curMin, waitHrs, waitMin, finHour, finMin);
        //Output time after waiting
        outputT(finHour, finMin);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for another time? ";
        cin >> response;
    }while(response == 'Y' || response == 'y');
}

//Calculate time after waiting, modification
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    //Declare variables
    int curHour, curMin, waitHrs, waitMin, finHour, finMin;
    char ampm, response;
    do{
        //Input times
        inpTime(curHour, curMin, waitHrs, waitMin, ampm);
        //Calculate time after waiting
        endWtg(curHour, curMin, waitHrs, waitMin, finHour, finMin, ampm);
        //Output time after waiting
        outputT(finHour, finMin, ampm);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for another time? ";
        cin >> response;
    }while(response == 'Y' || response == 'y');
}

//Amount of Change
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;

    //Declare variables
    int number, amount;
    char response;
    string coin;
    do{
        do{
            //Input amount of change between 1 and 99 cents
            cout << "Enter the amount of change you have in cents, "
                    "between 1 and 99: ";
            cin >> amount;
            cout << endl;
        }while (amount < 1 || amount > 99);
        //Calculate number of quarters, dimes and pennies to be
        //given and output
        cout << amount << " cents can be given as:" << endl;
        numCoin(QTR_VAL, number, amount);
        coin = coinWrd(QTR_VAL, number);
        cout << "  " << number << coin << endl;
        numCoin(DIM_VAL, number, amount);
        coin = coinWrd(DIM_VAL, number);
        cout << "  " << number << coin << endl;
        numCoin(PEN_VAL, number, amount);
        coin = coinWrd(PEN_VAL, number);
        cout << "  " << number << coin << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for a new "
                "amount? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
}

//Convert from ft/in to m/cm
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;

    //Declare variables
    int feet, inches, meters, centim;
    char response;
    do{
        //Input feet and inches
        readP6(feet, inches);
        //Convert to meters and centimeters
        cnvMsmt(feet, inches, meters, centim);
        //Output conversion
        output(feet, inches, meters, centim);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
}

//Convert from m/cm to ft/in
void problem7(){
    cout<<"In problem # 7"<<endl<<endl;

    //Declare variables
    int feet, inches, meters, centim;
    char response;
    do{
        //Input meters and centimeters
        readP7(meters, centim);
        //Convert to feet and inches
        cnvMsmtP7(meters, centim, feet, inches);
        //Output conversion
        outputP7(meters, centim, feet, inches);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
}

//Convert from lb/oz to kg/g
void problem9(){
    cout<<"In problem # 9"<<endl<<endl;

    //Declare variables
    int pounds, ounces, kgrams, grams;
    char response;
    do{
        //Input pounds and ounces
        readP9(pounds, ounces);
        //Convert to kilograms and grams
        cnvMsmtP9(pounds, ounces, kgrams, grams);
        //Output conversion
        outputP9(pounds, ounces, kgrams, grams);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
}

//Convert from kg/g to lb/oz
void problem10(){
    cout<<"In problem # 10"<<endl<<endl;

    //Declare variables
    int kgrams, grams, pounds, ounces;
    char response;
    do{
        //Input kilograms and grams
        readP10(kgrams, grams);
        //Convert to pounds and ounces
        cnvMsmtP10(kgrams, grams, pounds, ounces);
        //Output conversion
        outputP10(kgrams, grams, pounds, ounces);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'Y' || response == 'y');
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Input time
//Input
//      hour
//      minute
//Output
//      none
//      reference hour, minute
void read(int& hour, int& minute){
    char dummy;
    cout << "Enter a time in 24-hour notation (Format XX:XX) ";
    cin >> hour >> dummy >> minute;
}

//Convert time to 12 hour notation
//Input
//      hour
//      ampm
//Output
//      none
//      reference hour, ampm
void cnvTime(int& hour, char& ampm){
    if(hour > CNV_24HR){
        hour -= CNV_24HR;
        ampm = 'P';
    }else{
        ampm = 'A';
    }
}

//Output result
//Input
//      hour
//      minute
//      ampm
//Output
//      none
void output(int hour, int minute, char ampm){
    cout << "The time in 12-hour notation is " << hour << ":";
    if (minute < 10)
        cout << "0";
    cout << minute << " " << ampm << "M" << endl;
}

//Input current time and waiting time
//Input
//      current hour
//      current minute
//      waiting hour
//      waiting minute
//Output
//      none
//      reference current hour, minute and
//      waiting hour, minute
void inpTime(int& currH, int& currM, int& waitH, int& waitM){
    char dummy;
    cout << "Please enter the current time in 24-hour notation "
            "(Format HH:MM) ";
    cin >> currH >> dummy >> currM;
    cout << "Please enter the amount of time you must wait "
            "(Format HH:MM) ";
    cin >> waitH >> dummy >> waitM;
}

//Calculate time after waiting period
//Input
//      current hour
//      current minute
//      waiting hour
//      waiting minute
//      after hour
//      after minute
//Output
//      none
//      reference after hour, minute
void endWtg(int currH, int currM, int waitH, int waitM, 
            int& afterH, int& afterM){
    afterH = currH + waitH;
    if(afterH >= FULL_DAY)
        afterH -= FULL_DAY;
    afterM = currM + waitM;
    if(afterM >= CNV_HRS_MIN){
        afterM -= CNV_HRS_MIN;
        afterH += 1;
        afterH -= (afterH >= FULL_DAY) ? FULL_DAY : 0;
    }
}

//Output final time
//Input
//      after hour
//      after minute
//Output
//      none
void outputT(int afterH, int afterM){
    cout << "After the waiting period, the time will be "
         << afterH << ":";
    if (afterM < 10)
        cout << "0";
    cout << afterM << endl;
}

//Input current time and waiting time
//Input
//      current hour
//      current minute
//      waiting hour
//      waiting minute
//      ampm
//Output
//      none
//      reference current hour, minute and
//      waiting hour, minute and ampm
void inpTime(int& currH, int& currM, int& waitH, int& waitM, char& ampm){
    char dummy;
    cout << "Please enter the current time in 12-hour notation "
            "(Format HH:MM AM/PM) ";
    cin >> currH >> dummy >> currM >> ampm >> dummy;
    cout << "Please enter the amount of time you must wait "
            "(Format HH:MM) ";
    cin >> waitH >> dummy >> waitM;
}

//Calculate time after waiting period
//Input
//      current hour
//      current minute
//      waiting hour
//      waiting minute
//      after hour
//      after minute
//      ampm
//Output
//      none
//      reference after hour, minute, ampm
void endWtg(int currH, int currM, int waitH, int waitM, 
            int& afterH, int& afterM, char& ampm){
    afterH = currH + waitH;
    if(afterH >= CNV_24HR){
        afterH -= CNV_24HR;
        if (afterH != 12){
            if(ampm == 'A') ampm = 'P';
            else ampm = 'A';
        }
    }
    afterM = currM + waitM;
    if(afterM >= CNV_HRS_MIN){
        afterM -= CNV_HRS_MIN;
        afterH += 1;
        if(afterH >= CNV_24HR){
            afterH -= CNV_24HR;
            if(afterH != 12){
                if(ampm == 'A') ampm = 'P';
                else ampm = 'A';
            }
        }
    }
}

//Output final time
//Input
//      after hour
//      after minute
//      ampm
//Output
//      none
void outputT(int afterH, int afterM, char ampm){
    cout << "After the waiting period, the time will be "
         << afterH << ":";
    if (afterM < 10)
        cout << "0";
    cout << afterM << " " << ampm << "M" << endl;
}

//Calculate number of coins based on coin value
//Input
//      coin value
//      number of coins
//      amount of change left
//Output
//      none
//      reference number of coins, change left
void numCoin(int coinVal, int& num, int& amtLeft){
    num = amtLeft / coinVal;
    amtLeft %= coinVal;
}

//Print out coin word based on coin value
//Input
//      coin value
//      number of coins
//Output
//      string with coin in English
string coinWrd(int coinVal, int num){
    if (coinVal == QTR_VAL){
        if (num > 1 || num < 1) return " quarters";
        else return " quarter";
    }else if (coinVal == DIM_VAL){
        if (num > 1 || num < 1) return " dimes";
        else return " dime";
    }else{
        if (num > 1 || num < 1) return " pennies";
        else return " penny";
    }
}

//Read in length
//Input
//      feet
//      inches
//Output
//      none
//      reference feet, inches
void readP6(int& feet, int& inches){
    cout << "Enter a length in feet and inches: " << endl;
    cout << "  Feet: ";
    cin >> feet;
    cout << "  Inches: ";
    cin >> inches;
    cout << endl;
}

//Convert measurement
//Input
//      feet, inches, meters, centimeters
//Output
//      none
//      reference meters, centimeters
void cnvMsmt(float feet, float inches, int& meters, int& cmeters){
    feet += inches / CNV_FT_IN;
    
    float mtr = feet * CNV_FT_M;
    meters = static_cast<int>(mtr);
    float cm = mtr - meters;
    cmeters = cm * CNV_M_CM;
}

//Output results
//Input
//      feet, inches, meters, centimeters
//Output
//      none
void output(int feet, int inches, int meters, int cmeters){
    cout << feet << " feet and " << inches << " inch(es) converts to "
         << meters << " meter(s) and about " << cmeters << " centimeters." 
         << endl;
}

//Read in length
//Input
//      meters
//      centimeters
//Output
//      none
//      reference meters, centimeters
void readP7(int& meters, int& cmeters){
    cout << "Enter a length in meters and centimeters: " << endl;
    cout << "  Meters: ";
    cin >> meters;
    cout << "  Centimeters: ";
    cin >> cmeters;
    cout << endl;
}

//Convert measurement
//Input
//      meters, centimeters, feet, inches
//Output
//      none
//      reference feet, inches
void cnvMsmtP7(float meters, float cmeters, int& feet, int& inches){
    meters += cmeters / CNV_M_CM;
    
    float ft = meters / CNV_FT_M;
    feet = static_cast<int>(ft);
    float in = ft - feet;
    inches = in * CNV_FT_IN;
}

//Output results
//Input
//      meters, centimeters, feet, inches
//Output
//      none
void outputP7(int meters, int cmeters, int feet, int inches){
    cout << meters << " meter(s) and " << cmeters << " centimeter(s) "
         " converts to " << feet << " feet and about " << inches 
         << " inches." << endl;
}

//Read in length
//Input
//      pounds
//      ounces
//Output
//      none
//      reference pounds, ounces
void readP9(int& lbs, int& ozs){
    cout << "Enter a length in pounds and ounces: " << endl;
    cout << "  Pounds: ";
    cin >> lbs;
    cout << "  Ounces: ";
    cin >> ozs;
    cout << endl;
}

//Convert measurement
//Input
//      pounds, ounces, kilograms, grams
//Output
//      none
//      reference kilograms, grams
void cnvMsmtP9(float lbs, float ozs, int& kgrms, int& grms){
    lbs += ozs / CNV_LB_OZ;
    
    float kg = lbs / CNV_KG_LB;
    kgrms = static_cast<int>(kg);
    float g = kg - kgrms;
    grms = g * CNV_KG_G;
}

//Output results
//Input
//      pounds, ounces, kilograms, grams
//Output
//      none
void outputP9(int lbs, int ozs, int kgrms, int grms){
    cout << lbs << " pound(s) and " << ozs << " ounce(s) converts to "
         << kgrms << " kilogram(s) and about " << grms << " gram(s)." 
         << endl;
}

//Read in length
//Input
//      kilograms
//      grams
//Output
//      none
//      reference kilograms, grams
void readP10(int& kgrms, int& grms){
    cout << "Enter a length in kilograms and grams: " << endl;
    cout << "  Kilograms: ";
    cin >> kgrms;
    cout << "  Grams: ";
    cin >> grms;
    cout << endl;
}

//Convert measurement
//Input
//      kilograms, grams, pounds, ounces
//Output
//      none
//      reference pounds and ounces
void cnvMsmtP10(float kgrms, float grms, int& lbs, int& ozs){
    kgrms += grms / CNV_KG_G;
    
    float lb = kgrms * CNV_KG_LB;
    lbs = static_cast<int>(lb);
    float oz = lb - lbs;
    ozs = oz * CNV_LB_OZ;
}

//Output results
//Input
//      kilograms, grams, pounds, ounces
//Output
//      none
void outputP10(int kgrms, int grms, int lbs, int ozs){
    cout << kgrms << " kilogram(s) and " << grms << " gram(s) converts to "
         << lbs << " pound(s) and about " << ozs << " ounce(s)." 
         << endl;
}