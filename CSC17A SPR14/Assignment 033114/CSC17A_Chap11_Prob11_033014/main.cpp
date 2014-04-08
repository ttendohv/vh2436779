/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 30, 2014, 8:09 PM
 * Gaddis Chapter 11 Problem 11
 * Monthly Budget
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User-defined Libraries
#include "Budget.h"

//Global Constants

//Function Prototypes
void input(MonthlyBudget&);
void display(MonthlyBudget);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    MonthlyBudget thisMth;
    //Input Amounts for the month
    input(thisMth);
    //Display month's report
    display(thisMth);
    //Exit
    return 0;
}

void input(MonthlyBudget &a){
    cout << "Please enter the following expenses for the "
            "month: " << endl;
    cout << "  Housing: $";
    cin >> a.housing;
    cout << "  Utilities: $";
    cin >> a.util;
    cout << "  Household Expenses: $";
    cin >> a.houseExp;
    cout << "  Transportation: $";
    cin >> a.transp;
    cout << "  Food: $";
    cin >> a.food;
    cout << "  Medical: $";
    cin >> a.medic;
    cout << "  Insurance: $";
    cin >> a.insur;
    cout << "  Entertainment: $";
    cin >> a.entertain;
    cout << "  Clothing: $";
    cin >> a.clothing;
    cout << "  Miscellaneous: $";
    cin >> a.misc;
    cout << endl;
}

void display(MonthlyBudget a){
    float total=0.0;
    
    cout << endl;
    cout << "Monthly Report: " << endl;
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "  Housing: ";
    total+=a.housing;
        if(a.housing>HSNG){
            cout << "$" << a.housing-HSNG << " over budget." << endl;
        }else if(a.housing<HSNG){
            cout << "$" << HSNG-a.housing << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Utilities: ";
    total+=a.util;
        if(a.util>UTIL){
            cout << "$" << a.util-UTIL << " over budget." << endl;
        }else if(a.util<UTIL){
            cout << "$" << UTIL-a.util << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Household Expenses: ";
    total+=a.houseExp;
        if(a.houseExp>HHEXP){
            cout << "$" << a.houseExp-HHEXP << " over budget." << endl;
        }else if(a.houseExp<HHEXP){
            cout << "$" << HHEXP-a.houseExp << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Transportation: ";
    total+=a.transp;
        if(a.transp>TRANSP){
            cout << "$" << a.transp-TRANSP << " over budget." << endl;
        }else if(a.transp<TRANSP){
            cout << "$" << TRANSP-a.transp << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Food: ";
    total+=a.food;
        if(a.food>FOOD){
            cout << "$" << a.food-FOOD << " over budget." << endl;
        }else if(a.food<FOOD){
            cout << "$" << FOOD-a.food << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Medical: ";
    total+=a.medic;
        if(a.medic>MEDCL){
            cout << "$" << a.medic-MEDCL << " over budget." << endl;
        }else if(a.medic<MEDCL){
            cout << "$" << MEDCL-a.medic << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Insurance: ";
    total+=a.insur;
        if(a.insur>INSURC){
            cout << "$" << a.insur-INSURC << " over budget." << endl;
        }else if(a.insur<INSURC){
            cout << "$" << INSURC-a.insur << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Entertainment: ";
    total+=a.entertain;
        if(a.entertain>ENTRMT){
            cout << "$" << a.entertain-ENTRMT << " over budget." << endl;
        }else if(a.entertain<ENTRMT){
            cout << "$" << ENTRMT-a.entertain << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Clothing: ";
    total+=a.clothing;
        if(a.clothing>CLTHNG){
            cout << "$" << a.clothing-CLTHNG << " over budget." << endl;
        }else if(a.clothing<CLTHNG){
            cout << "$" << CLTHNG-a.clothing << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "  Miscellaneous: ";
    total+=a.misc;
        if(a.misc>MISC){
            cout << "$" << a.misc-MISC << " over budget." << endl;
        }else if(a.misc<MISC){
            cout << "$" << MISC-a.misc << " under budget." << endl;
        }else{
            cout << "On budget." << endl;
        }
    
    cout << "Total: ";
        if(total>TOTAL){
            cout << "$" << total-TOTAL << " over whole monthly budget." << endl;
        }else if(total<TOTAL){
            cout << "$" << TOTAL-total << " under whole monthly budget." << endl;
        }else{
            cout << "On budget for the whole monthly budget." << endl;
        }
}