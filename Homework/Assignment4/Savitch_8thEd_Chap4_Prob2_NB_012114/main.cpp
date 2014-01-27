/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 21, 2014, 3:45 PM
 * Savitch 8th Edition Chapter 4 Problem 2
 * Miles per gallon, modification of Problem 1
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_L_GAL = 0.264179;

//Function Prototypes
float mpg(float, float);
void fuelEff(float, float);

//Execution Begins Here

int main(int argc, char** argv) {
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
    //Exit
    return 0;
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