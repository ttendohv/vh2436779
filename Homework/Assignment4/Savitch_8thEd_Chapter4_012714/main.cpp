/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 27, 2014, 3:42 PM
 * Chapter 4 Problems using a Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants
const float CNV_L_GAL = 0.264179; //Gallons per liter
const int CNV_PRC = 100; //Convert percentage
const float EGTH_IN = 0.125; //1/8 inch
const float TNTH_IN = 0.10; //1/10 inch

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem9();
void problem10();
void problem13();
float mpg(float, float);
void fuelEff(float, float);
float stkPrc(int,int,int);
float inflnRt(float, float);
float estCost(float, float);
int hatSize(float, float);
float jktSize(float, float, int);
float wstInch(float, int);
string numEng(int);

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
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem9();break;
        case 7:    problem10();break;
        case 8:    problem13();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=8);
    //Exit
    return 0;
}

void Menu(){
    cout<<"Menu for Chapter 4"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 9"<<endl;
    cout<<"Type 7 for problem 10"<<endl;
    cout<<"Type 8 for problem 13"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

//Calculate Miles per gallon
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;

    //Declare variables
    float ltrsGas, milesTr;
    char response;
    do{
        //Input liters and miles
        cout << "How many liters of gasoline did your car consume? ";
        cin >> ltrsGas;
        cout << "How many miles did your car travel? ";
        cin >> milesTr;
        //Output miles per gallon
        cout << fixed << showpoint << setprecision(2);
        cout << "Miles per gallon: " << mpg(ltrsGas, milesTr) << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this for another car? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'y' || response == 'Y');
}

//Calculate Miles per gallon for two cars
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;

    //Declare variables
    float ltrCar1, ltrCar2, miCar1, miCar2,
          mpgCar1, mpgCar2;
    char response;
    do{
        //Input liters and miles, Car 1
        cout << "Please enter the following information for the "
                "first car: " << endl;
        cout << "   Liters of Gas Used: ";
        cin >> ltrCar1;
        cout << "   Miles Traveled: ";
        cin >> miCar1;
        cout << endl;
        //Input liters and miles, Car 2
        cout << "Please enter the following information for the "
                "second car: " << endl;
        cout << "   Liters of Gas Used: ";
        cin >> ltrCar2;
        cout << "   Miles Traveled: ";
        cin >> miCar2;
        cout << endl;
        //Calculate mpg, Car 1 and Car 2
        mpgCar1 = mpg(ltrCar1, miCar1);
        mpgCar2 = mpg(ltrCar2, miCar2);
        //Output miles per gallon, Car 1 and Car 2
        cout << fixed << showpoint << setprecision(2);
        cout << "Car 1" << endl;
        cout << "   Miles per gallon: " << mpgCar1 << endl;
        cout << endl;
        cout << "Car 2" << endl;
        cout << "   Miles per gallon: " << mpgCar2 << endl;
        cout << endl;
        //Determine which is more fuel efficient
        fuelEff(mpgCar1, mpgCar2);
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
                "more cars? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'y' || response == 'Y');
}

//Calculate Stock Prices
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;

    //Declare variables
    int shares, whDllr, frcNum, frcDenm;
    float price;
    char slash, response;
    do{
        //Input shares, dollar portion of price
        //and fraction portion of price
        cout << "How many shares of the stock do you own? ";
        cin >> shares;
        cout << "How much is each share? (Format XXX X/X): ";
        cin >> whDllr >> frcNum >> slash >> frcDenm;
        //Compute stock price
        price = stkPrc(whDllr, frcNum, frcDenm);
        //Output value of user's holdings
        cout << fixed << showpoint << setprecision(2);
        cout << "You own " << shares << " shares of this stock at $" 
             << price << " per share. The total value of your shares is $"
             << shares * price << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
             << "another stock? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'Y' || response == 'y');
}

//Calculate Inflation Rate
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;

    //Declare variables
    float prcPres, prcPast; // prices present and past
    char response;
    do{
        //Input current and past price
        cout << "What is the price of your item today? $";
        cin >> prcPres;
        cout << "What was the price of this same item a "
                "year ago? $";
        cin >> prcPast;
        //Output estimated inflation rate
        cout << fixed << showpoint << setprecision(2);
        cout << "Inflation Rate: " << inflnRt(prcPres, prcPast) 
             << "%" << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
                "another item and price? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'y' || response == 'Y');
}

//Inflation Rate and Estimated Cost
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;

    //Declare variables
    float prcPres, prcPast, // prices present and past
            infltn;
    char response;
    do{
        //Input current and past price
        cout << "What is the price of your item today? $";
        cin >> prcPres;
        cout << "What was the price of this same item a "
                "year ago? $";
        cin >> prcPast;
        cout << endl;
        //Calculate Inflation Rate
        infltn = inflnRt(prcPres, prcPast);
        //Output estimated inflation rate
        cout << fixed << showpoint << setprecision(2);
        cout << "Inflation Rate: " << infltn << "%" << endl;
        //Calculate estimated cost in one year, two years
        cout << "The estimated cost in one year is $"
             << estCost(prcPres, infltn) << endl;
        cout << "The estimated cost in two years is $"
             << estCost(estCost(prcPres,infltn),infltn) << endl;
        cout << endl;
        //Prompt for repeat
        cout << "Would you like to repeat this calculation for "
                "another item and price? Y/N: ";
        cin >> response;
        cout << endl;
    }while(response == 'y' || response == 'Y');
}

//Calculate clothing sizes
void problem9(){
    cout<<"In problem # 9"<<endl<<endl;

    //Declare variables
    float height, weight, jacket, waist;
    int age, hat;
    char response;
    do{
        //Input height, weight, age
        cout << "Please enter the following: " << endl;
        cout << "  Height, in inches: ";
        cin >> height;
        cout << "  Weight, in pounds: ";
        cin >> weight;
        cout << "  Age, in years: ";
        cin >> age;
        //Calculate clothing sizes
        hat = hatSize(weight, height);
        jacket = jktSize(weight, height, age);
        waist = wstInch(weight, age);
        //Output clothing sizes
        cout << "Here are your clothing sizes: " << endl;
        cout << "  Hat Size (closest size up): " << hat << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "  Jacket Size (chest in inches): " << jacket << endl;
        cout << "  Waist (in inches): " << waist << endl;
        //Prompt for repeat
        cout << "Would you like to compute different clothing sizes? Y/N: ";
        cin >> response;
    }while (response == 'y' || response == 'Y');
}

//Calculate clothing sizes, after 10 years
void problem10(){
    cout<<"In problem # 10"<<endl<<endl;

    //Declare variables
    float height, weight, jacket, waist;
    int age, hat;
    char response;
    do{
        //Input height, weight, age
        cout << "Please enter the following: " << endl;
        cout << "  Height, in inches: ";
        cin >> height;
        cout << "  Weight, in pounds: ";
        cin >> weight;
        cout << "  Age, in years: ";
        cin >> age;
        cout << endl;
        //Calculate clothing sizes
        hat = hatSize(weight, height);
        jacket = jktSize(weight, height, age);
        waist = wstInch(weight, age);
        //Output clothing sizes
        cout << "Here are your clothing sizes: " << endl;
        cout << "  Hat Size (closest size up): " << hat << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "  Jacket Size (chest in inches): " << jacket << endl;
        cout << "  Waist (in inches): " << waist << endl;
        cout << endl;
        //Add 10 years
        age += 10;
        cout << "At age " << age << "..." << endl;
        //Recalculate clothing sizes
        hat = hatSize(weight, height);
        jacket = jktSize(weight, height, age);
        waist = wstInch(weight, age);
        //Output new clothing sizes
        cout << "Here are your clothing sizes after 10 years: " << endl;
        cout << "  Hat Size (closest size up): " << hat << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "  Jacket Size (chest in inches): " << jacket << endl;
        cout << "  Waist (in inches): " << waist << endl;
        cout << endl;
        //Prompt for repeat
        cout << "Would you like to compute different clothing sizes? Y/N: ";
        cin >> response;
        cout << endl;
    }while (response == 'y' || response == 'Y');
}

//Ninety-Nine Bottles Song
void problem13(){
    cout<<"In problem # 13"<<endl<<endl;

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
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Compute miles per gallon
//Input
//      liters of gas
//      miles traveled
//Output
//      miles per gallon
float mpg(float liters, float miles){
    float gallons;
    gallons = liters * CNV_L_GAL;
    return miles/gallons;
}

//Determine best fuel efficiency
//Input
//      Car 1 mpg
//      Car 2 mpg
//Output
//      none
void fuelEff(float mpg1, float mpg2){
    if (mpg1 > mpg2){
        cout << "Car 1 has the best fuel efficiency." << endl;
    }else if (mpg1 < mpg2){
        cout << "Car 2 has the best fuel efficiency." << endl;
    }else{
        cout << "Both cars have equivalent fuel efficiency." << endl;
    }
    cout << endl;
}

//Calculate stock price
//Input
//      dollar amount
//      numerator for fractional amount
//      denominator for fractional amount
//Output
//      stock price
float stkPrc(int dollar, int num, int denom){
    return ((static_cast<float>(dollar)) + 
            (static_cast<float>(num)/denom));
}

//Calculate Inflation Rate
//Input
//      Present Day Price
//      Price a year ago
//Output
//      Inflation Rate
float inflnRt(float prcNow, float prcThen){
    return (((prcNow - prcThen)/prcThen)*CNV_PRC);
}

//Calculate estimated cost in a year
//Input
//      Current Price
//      Inflation Rate
//Output
//      Estimated future cost
float estCost(float currPrc, float iRate){
    float rate = iRate/CNV_PRC;
    return (currPrc*(1+rate));
}

//Calculate hat size, size up
//Input
//      weight
//      height
//Output
//      hat size, as an integer, one size up
int hatSize(float wgt, float hgt){
    return static_cast<int>(ceil(((wgt/hgt) * 2.9)));
}

//Calculate jacket size
//Input
//      weight
//      height
//      age
//Output
//      jacket size
float jktSize(float wgt, float hgt, int age){
    float size = (wgt * hgt) / 288;
    if (age > 30){
        int adj = (age - 30)/10;
        size += adj * EGTH_IN;
    }
    return size;
}

//Calculate waist in inches
//Input
//      weight
//      age
//Output
//      waist size, in inches
float wstInch(float wgt, int age){
    float size = wgt / 5.7;
    if (age > 28){
        int adj = (age - 28)/2;
        size += adj * TNTH_IN;
    }
    return size;
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