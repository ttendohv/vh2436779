/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 31, 2014, 11:50 PM
 * Chapter 11 Problems
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User-defined Libraries
#include "WthrStats.h"
#include "CustmrInfo.h"
#include "SpkrInfo.h"
#include "Budget.h"
#include "StudentInfo.h"
#include "InventoryBins.h"
#include "DrinkMachine.h"

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
        //Problem5
void problem5();
void inpData(WthrData[],int);
float rainfall(WthrData[],int,float&,float&);
void sort(WthrData[],int[],int[],int);
string monthN(int);
        //Problem8
void problem8();
void menuChc(Account[],int,char);
void newData(Account[],int&);
void chgData(Account[],int);
void prntData(Account[],int);
bool srch(Account[],int);
        //Problem10
void problem10();
void menuChc(Speaker[],int,char);
void newData(Speaker[],int&);
void chgData(Speaker[],int);
void prntData(Speaker[],int);
bool srch(Speaker[],int);
        //Problem11
void problem11();
void input(MonthlyBudget&);
void display(MonthlyBudget);
        //Problem12
void problem12();
void alloc(Student*,int,int);
void inpData(Student*,int,int);
float findAvg(int*,int);
char findGrd(float);
void prntData(Student*,int);
        //Problem13
void problem13();
void initial(Drink[],int);
void display(Drink[],int);
void select(Drink[],float&);
        //Problem14
void problem14();
void initial(Inventory[]);
void display(Inventory[],int);
void addPrts(Inventory[],int);
void remPrts(Inventory[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem5();break;
            case 2:    problem8();break;
            case 3:    problem10();break;
            case 4:    problem11();break;
            case 5:    problem12();break;
            case 6:    problem13();break;
            case 7:    problem14();break;
            default:   def(inN);}
    }while(inN>=1&&inN<=7);
    
    //Exit
    return 0;
}

void Menu(){
    cout << endl << endl;
    cout<<"Chapter 11 Homework"<<endl;
    cout<<"Type 1 for problem 5"<<endl;
    cout<<"Type 2 for problem 8"<<endl;
    cout<<"Type 3 for problem 10"<<endl;
    cout<<"Type 4 for problem 11"<<endl;
    cout<<"Type 5 for problem 12"<<endl;
    cout<<"Type 6 for problem 13"<<endl;
    cout<<"Type 7 for problem 14"<<endl;
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

//Weather Statistics
void problem5(){
    //Declare variables
    int SIZE=12;
    WthrData year1[SIZE];
    float avgRain,totRain,avgTmp;
    int highTmp[SIZE],lowTmp[SIZE];
    //Input
    inpData(year1,SIZE);
    for(int i=0;i<SIZE;i++){
        highTmp[i]=i;
        lowTmp[i]=i;
    }
    //Totals and averages
    avgRain=rainfall(year1,SIZE,totRain,avgTmp);
    //Sort temperatures
    sort(year1,highTmp,lowTmp,SIZE);
    //Print
    cout << "Testing: " << APRIL+1 << " " 
            << year1[APRIL].totRain << endl; 
    cout << setprecision(2) << fixed << showpoint;
    cout << "Average monthly rainfall: " << avgRain << endl;
    cout << "Total rainfall for the year: " << totRain << endl;
    cout << "Highest temperature for the year: " << year1[highTmp[0]].highTmp 
           << " in " << monthN(highTmp[0]) << endl;
    cout << "Lowest temperature for the year: " << year1[lowTmp[0]].lowTmp 
           << " in " << monthN(lowTmp[0]) << endl;
    cout << "Average temperature for the year: " << avgTmp << endl;
}

string monthN(int m){
    switch(m){
        case JANUARY:
            return "January";
            break;
        case FEBRUARY:
            return "February";
            break;
        case MARCH:
            return "March";
            break;
        case APRIL:
            return "April";
            break;
        case MAY:
            return "May";
            break;
        case JUNE:
            return "June";
            break;
        case JULY:
            return "July";
            break;
        case AUGUST:
            return "August";
            break;
        case SEPTEMBER:
            return "September";
            break;
        case OCTOBER:
            return "October";
            break;
        case NOVEMBER:
            return "November";
            break;
        case DECEMBER:
            return "December";
            break;
    }
    
}

void inpData(WthrData a[],int size){
    //Month index=JANUARY;
    cout << "Please enter weather data for the "
            "entire year, starting with January\n"
            "(Temperatures must be between -100 and 145"
            "degrees Fahrenheiht) " 
            << endl << endl;
    for(int index=JANUARY;index<size;index++){
        cout << "Month " << index+1 << ": " << endl;
        cout << "Total Rainfall: ";
        cin >> a[index].totRain;
        do{
            cout << "High Temperature: ";
            cin >> a[index].highTmp;
        }while(a[index].highTmp>145||a[index].highTmp<-100);
        do{
            cout << "Low Temperature: ";
            cin >> a[index].lowTmp;
        }while(a[index].lowTmp>145||a[index].lowTmp<-100);
        a[index].avgTmp=((a[index].highTmp+a[index].lowTmp)/2.0);
        cout << setprecision(2) << fixed << showpoint;
        cout << "Average Temperature: " << a[index].avgTmp << endl;
        cout << endl;
    }
}

float rainfall(WthrData a[],int size,float &total,float &temp){
    float sum=0.0;
    for(int index=JANUARY;index<size;index++){
        sum+=a[index].avgTmp;
    }
    temp=sum/size;
    sum=0.0;    
    for(int index=JANUARY;index<size;index++)
        sum+=a[index].totRain;
    total=sum;
    return sum/size;
}

void sort(WthrData a[],int indx[],int indx1[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((a[indx[i]].highTmp)<(a[indx[j]].highTmp)){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((a[indx1[i]].lowTmp)>(a[indx1[j]].lowTmp)){
                int temp=indx1[i];
                indx1[i]=indx1[j];
                indx1[j]=temp;
            }
        }
    }
}

//Customer Accounts
void problem8(){
    //Declare variables
    int SIZE=20;
    char choice;
    Account customer[SIZE];
    
    //Display Menu
    do{
        cout << "Enter the corresponding number to make a choice:\n"
                "  1. Enter in new customer data\n"
                "  2. Change any customer data\n"
                "  3. Display customer data\n"
                "  \nEnter anything else to quit.\n";
        cin >> choice;
        menuChc(customer,SIZE,choice);
    }while(choice=='1'||choice=='2'||choice=='3');     
}

void menuChc(Account c[],int size,char choice){
    static int pos=0;
    
    switch(choice){
        case '1':
            //Insert new data
            newData(c,pos);
            break;
        case '2':
            //Change data
            chgData(c,size);
            break;
        case '3':
            //Print all data entered
            for(int i=0;i<pos;i++){
                prntData(c,i);
            }
            break;
        default:
            break;
    }
    
}

void newData(Account c[],int &pos){
    char i;
    do{
        cout << endl;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,c[pos].name);
        cout << "Address (House number and Street only): ";
        getline(cin,c[pos].address);
        cout << "City: ";
        getline(cin,c[pos].city);
        cout << "State: ";
        getline(cin,c[pos].state);
        cout << "Zip Code: ";
        getline(cin,c[pos].zip);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,c[pos].number);
        cout << "Account balance: $";
        cin >> c[pos].balance;
        cin.ignore(1,'\n');
        cout << "Date of Last Payment: ";
        getline(cin,c[pos].date);
        
        cout << endl;
        cout << "Enter 0 to enter in data for a new account, "
                "enter in anything else to quit: ";
        cin >> i;
        pos++;
        cout << endl;
    }while(i=='0');
}

void chgData(Account c[],int size){
    //Search for item to change    
    int indx;
    bool found;
    //Print available 
    cout << endl;
    cout << "Enter in the corresponding number to "
            "change information: " << endl;
    found=srch(c,size);
    if(found){
        cin >> indx;
        indx--;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,c[indx].name);
        cout << "Address (House number and Street only): ";
        getline(cin,c[indx].address);
        cout << "City: ";
        getline(cin,c[indx].city);
        cout << "State: ";
        getline(cin,c[indx].state);
        cout << "Zip Code: ";
        getline(cin,c[indx].zip);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,c[indx].number);
        cout << "Account balance: ";
        cin >> c[indx].balance;
        cin.ignore(1,'\n');
        cout << "Date of Last Payment (MM/DD/YYYY): ";
        getline(cin,c[indx].date);
    }

    cout << endl;
}

void prntData(Account c[],int pos){
    cout << endl;
    cout << "Name: " << c[pos].name << endl;
    cout << "Address: " << c[pos].address << endl;
    cout << c[pos].city << ", " << c[pos].state << " " 
            << c[pos].zip << endl;
    cout << "Telephone Number: " << c[pos].number << endl;
    cout << "Account Balance: $" << c[pos].balance << endl;
    cout << "Date of Last Payment: " << c[pos].date << endl;
    cout << endl;
}

bool srch(Account c[],int size){
    string name;
    int found,notFnd=0;
    
    cout << "Enter in the name or part of the name you "
            "want to search for: ";
    cin >> name;
    cout << endl;
    
    for(int i=0;i<size;i++){
        found=(c[i].name).find(name,0);
        if(found!=string::npos){
            cout << i+1 << ". ";
            prntData(c,i);
        }
    }if(notFnd==size){
        cout << "No matches found. " << endl;
        return false;
    }else return true;
}

//Speakers' Bureau
void problem10(){
    //Declare variables
    int SIZE=10;
    char choice;
    Speaker people[SIZE];
    
    //Display Menu
    do{
        cout << "Enter the corresponding number to make a choice:\n"
                "  1. Enter in new speaker information\n"
                "  2. Change any speaker's information\n"
                "  3. Display speakers' information\n"
                "  \nEnter anything else to quit.\n";
        cin >> choice;
        menuChc(people,SIZE,choice);
    }while(choice=='1'||choice=='2'||choice=='3');     
}

void menuChc(Speaker p[],int size,char choice){
    static int pos=0;
    
    switch(choice){
        case '1':
            //Insert new data
            newData(p,pos);
            break;
        case '2':
            //Change data
            chgData(p,size);
            break;
        case '3':
            //Print all data entered
            for(int i=0;i<pos;i++){
                prntData(p,i);
            }
            break;
        default:
            break;
    }
    
}

void newData(Speaker p[],int &pos){
    char i;
    do{
        cout << endl;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,p[pos].name);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,p[pos].number);
        cout << "Speaking topic: ";
        getline(cin,p[pos].topic);
        cout << "Fee Required: $";
        cin >> p[pos].fee;
        
        cout << endl;
        cout << "Enter 0 to enter in information for another speaker, "
                "enter in anything else to quit: ";
        cin >> i;
        pos++;
        cout << endl;
    }while(i=='0');
}

void chgData(Speaker p[],int size){
    //Search for item to change    
    int indx;
    bool found;
    //Print available 
    cout << endl;
    cout << "Enter in the corresponding number to "
            "change information: " << endl;
    found=srch(p,size);
    if(found){
        cin >> indx;
        indx--;
        cin.ignore(1,'\n');
        cout << "Name: ";
        getline(cin,p[indx].name);
        cout << "Telephone Number (XXX-XXX-XXXX): ";
        getline(cin,p[indx].number);
        cout << "Speaking topic: ";
        getline(cin,p[indx].topic);
        cout << "Fee Required: $";
        cin >> p[indx].fee;
    }    
    cout << endl;
}

void prntData(Speaker p[],int pos){
    cout << endl;
    cout << "Name: " << p[pos].name << endl;
    cout << "Telephone Number: " << p[pos].number << endl;
    cout << "Speaking Topic: " << p[pos].topic << endl;
    cout << "Required Fee: $" << p[pos].fee << endl;
    cout << endl;
}

bool srch(Speaker p[],int size){
    string key;
    int found,notFnd=0;
    
    cout << "Enter in a key word of the topic you "
            "want to search for: ";
    cin >> key;
    cout << endl;
    
    for(int i=0;i<size;i++){
        found=(p[i].topic).find(key,0);
        if(found!=string::npos){
            cout << i+1 << ". ";
            prntData(p,i);
        }else notFnd++;
    }if (notFnd==size){
        cout << "No matches found." << endl;
        return false;
    }else return true;
}

//Monthly Budget
void problem11(){
    //Declare variables
    MonthlyBudget thisMth;
    //Input Amounts for the month
    input(thisMth);
    //Display month's report
    display(thisMth);
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

//Course Grade
void problem12(){
    //Declare variables
    int students,tests;
    
    cout << "How many students? ";
    cin >> students;
    Student *group = new Student[students];
    cout << "How many tests? ";
    cin >> tests;
    alloc(group,students,tests);
    //Input
    inpData(group,students,tests);
    //Print
    prntData(group,students);
}

void alloc(Student *a,int students,int tests){
    for(int i=0;i<students;i++){
        a[i].tests=new int[tests];
    }
}

void inpData(Student *a,int students,int test){
    //Input 
    for(int i=0;i<students;i++){
        cout << "Name: ";
        cin >> a[i].name;
        cout << "ID#: ";
        cin >> a[i].ID;
        cout << "Enter the following tests: " << endl;
        for(int j=0;j<test;j++){
            cout << "Test #" << j+1 << ": ";
            cin >> a[i].tests[j];
        }
        a[i].average=findAvg(a[i].tests,test);
        a[i].grade=findGrd(a[i].average);
        cout << endl;
    }
}

float findAvg(int *a,int size){
    int sum=0.0;
    for(int i=0;i<size;i++){
        sum+=a[i];
    }
    return sum/size;
}

char findGrd(float a){
    if(a>=91.0)
        return 'A';
    else if (a>=81)
        return 'B';
    else if (a>=71)
        return 'C';
    else if (a>=61)
        return 'D';
    else
        return 'F';
}

//Formatting
void prntData(Student *a,int size){
    cout << endl;
    cout << setw(40) << "Average" << endl;
    cout << setw(16) << "Student Name" << setw(12) << "ID Number" << setw(14) 
            << "Test Score" << setw(16) << "Course Grade" << endl;
    for(int i=0;i<size;i++)
        cout << setw(14) << a[i].name << setw(13) << a[i].ID << setw(12)
                << a[i].average << setw(14) << a[i].grade << endl;
}

//Drink Machine Simulator
void problem13(){
    //Declare variables
    int SIZE=5;
    Drink machine[SIZE];
    bool quit;
    char choice;
    float total=0.0;
    //Initialize
    initial(machine,SIZE);
    //Display
    do{
        display(machine,SIZE);
        cout << "Press 1 to pick a drink and anything "
                "else to quit. ";
        cin >> choice;
        if(choice=='1'){
            quit=false;
            select(machine,total);
        }else quit=true;
    }while(!quit);
    cout << setprecision(2) << fixed << showpoint;
    cout << "This machine earned a total of $" << total << endl;
}

void select(Drink a[],float &total){
    int choice;
    float money;
    bool repeat;
    
    do{
        repeat=false;
        do{
            cout << "Enter the corresponding number to choose "
                    "a drink. ";
            cin >> choice;
        }while(choice<1||choice>5);
        if(a[choice-1].numDrnk==0){
            cout << a[choice-1].name << " is sold out. Please make another "
                    "selection." << endl;
            repeat=true;
        }
    }while(repeat);
    
    do{
        cout << setprecision(2) << fixed << showpoint;
        cout << "Please enter at least $" << a[choice-1].cost << ", but "
                "no more than $1.00\n $";
        cin >> money;
    }while(money>1||money<a[choice-1].cost);
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Your change is $" << money-a[choice-1].cost << endl;
    total+=a[choice-1].cost;
    a[choice-1].numDrnk--;
    cout << endl;
}

void display(Drink a[],int n){
    cout << endl;
    for(int i=0;i<n;i++){
        cout << setprecision(2) << fixed << showpoint;
        cout << i+1 << ". " << setw(12) <<  a[i].name 
                << setw(5) << a[i].cost << endl;
    }
    cout << endl;
}

void initial(Drink a[],int n){
    //Cola
    a[0].name="Cola";
    a[0].cost=0.75;
    //Root Beer
    a[1].name="Root Beer";
    a[1].cost=0.75;
    //Lemon-Lime
    a[2].name="Lemon-Lime";
    a[2].cost=0.75;
    //Grape Soda
    a[3].name="Grape Soda";
    a[3].cost=0.80;
    //Cream Soda
    a[4].name="Cream Soda";
    a[4].cost=0.80;
    //All
    for(int i=0;i<n;i++){
        a[i].numDrnk=20;
    }
}

//Inventory Bins
void problem14(){
    //Declare variables
    int SIZE=10,bin;
    Inventory parts[SIZE];
    bool quit;
    char choice;
    //Initialize
    initial(parts);
    
    do{
        display(parts,SIZE);
        cout << "Enter 1 to choose a bin or anything else to quit: ";
        cin >> choice;
        if(choice=='1'){
            quit=false;
            cout << "Enter in corresponding number to choose a bin: ";
            cin >> bin;
            cout << "Enter 1 to add parts or 2 to remove parts: ";
            cin >> choice;
            if(choice=='1')
                addPrts(parts,bin-1);
            else
                remPrts(parts,bin-1);
        }else quit=true;
    }while(!quit);
}

void addPrts(Inventory a[],int bin){
    int temp = a[bin].numPrts,
        add;
    bool repeat;
    
    do{
        repeat=false;
        do{
        cout << endl;
            cout << "How many parts would you like to "
                    "add to this bin? (Must be greater than 0). ";
            cin >> add;
        }while(add<0);
        if((temp+add)>30){
            cout << "You have added too many parts. Items "
                    "in bin cannot exceed 30. Please try again." << endl;
            repeat=true;
        }else{
            a[bin].numPrts+=add;
        }
    }while(repeat);
}

void remPrts(Inventory a[],int bin){
    int temp = a[bin].numPrts,
        remv;
    bool repeat;
    
    do{
        repeat=false;
        do{
        cout << endl;
            cout << "How many parts would you like to "
                    "remove from this bin? (Must be greater than 0). ";
            cin >> remv;
        }while(remv<0);
        if((temp-remv)<0){
            cout << "You have chosen to remove too many parts. "
                    "Please try again." << endl;
            repeat=true;
        }else{
            a[bin].numPrts-=remv;
        }
    }while(repeat);
}

void display(Inventory a[],int n){
    cout << endl;
    for (int i=0;i<n;i++){
        cout << setw(2) << i+1 << ". " << setw(15) << a[i].name 
                << setw(3) << a[i].numPrts << endl;
    }
    cout << endl;
}

void initial(Inventory a[]){
    //Initialize
        //Valve
        a[0].name="Valve";
        a[0].numPrts=10;
        //Bearing
        a[1].name="Bearing";
        a[1].numPrts=5;
        //Bushing
        a[2].name="Bushing";
        a[2].numPrts=15;
        //Coupling
        a[3].name="Coupling";
        a[3].numPrts=21;
        //Flange
        a[4].name="Flange";
        a[4].numPrts=7;
        //Gear
        a[5].name="Gear";
        a[5].numPrts=5;
        //Gear Housing
        a[6].name="Gear Housing";
        a[6].numPrts=5;
        //Vacuum Gripper
        a[7].name="Vacuum Gripper";
        a[7].numPrts=25;
        //Cable
        a[8].name="Cable";
        a[8].numPrts=18;
        //Rod
        a[9].name="Rod";
        a[9].numPrts=12;
}