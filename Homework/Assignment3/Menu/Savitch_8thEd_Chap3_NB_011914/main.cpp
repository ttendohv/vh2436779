/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 19, 2014, 3:45 PM
 * Display menu for all problems in Chapter 3
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

//Global Constants
//For Problem 2
const float FIR_INT = 0.015; //Interest rate on first $1000
const float EXT_INT = 0.01; //Extra interest after first $1000
const float DEF_MIN_PY = 10.0; //Default minimum payment, $10
const float MIN_PY_PRCT = 0.1; //Minimum payment, 10%, if more than $10
//For Problem 5
const float MF_DAY_RT = 0.40; //$ per minute, M-F, 8am-6pm
const float MF_MR_NI_RT = 0.25; //$ per minute, M-F, before 8am, after 6pm
const float SAT_SUN_RT = 0.15; //$ per minute, Sat/Sun 
//For Problem 7
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
//For Problem 9
const int MTH_YR = 12; //Months in year
const int CNV_PERC = 100; //Convert percentage to decimal
const float MTH_PYT = 0.05; //Monthly payment is 5% of loan amount
//For Problem 15
const float SP_WGT_WTR = 62.4; //Specific weight of water, lb/ft^3
const double PI = 3.141592653589793;
//For Problem 17
const int CHOC_BAR = 230; //calories in typical chocolate bar

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Setup menu
    bool loop = true;
    int choice;
    do{
        //Display selection
        cout << endl;
        cout << "Please enter..." << endl;
        cout << "  1  for Problem #1" << endl;
        cout << "  2  for Problem #2" << endl;
        cout << "  3  for Problem #5" << endl;
        cout << "  4  for Problem #7" << endl;
        cout << "  5  for Problem #9" << endl;
        cout << "  6  for Problem #12" << endl;
        cout << "  7  for Problem #15" << endl;
        cout << "  8  for Problem #16" << endl;
        cout << "  9  for Problem #17" << endl;
        cout << " 10  for Problem #19" << endl;
        cout << "Enter anything else to quit." << endl;
        //Get choice
        cin >> choice;
        cout << endl;
        //Begin corresponding program
        switch(choice){
            case 1:{
                //Savitch 8th Edition Chapter 3 Problem 1
                //Paper, Rock, Scissor Game
                //Declare variables
                char user1, user2, response;
                bool repeat; //repeat prompt if invalid response
                //Start Game
                cout << "---------------------------------------" << endl;
                cout << "Let's play the paper-rock-scissor game!" << endl;
                cout << "---------------------------------------" << endl;
                do{ 
                    //User 1
                    do{
                        cout << "Player 1: Enter \"P\" for Paper, \"R\" for Rock, "
                                "or \"S\" for Scissor to make your move: ";
                        cin >> user1;
                        cout << endl;
                        switch (user1){
                            case 'P':
                            case 'p':
                            case 'R':
                            case 'r':
                            case 'S':
                            case 's':
                                repeat = false;
                                break;
                            default:
                                cout << "Invalid response. Please try again." << endl;
                                repeat = true;
                        }
                    }while (repeat);
                    //User 2
                    do{
                        cout << "Player 2: Enter \"P\" for Paper, \"R\" for Rock, "
                                "or \"S\" for Scissor to make your move: ";
                        cin >> user2;
                        cout << endl;
                        switch (user2){
                            case 'P':
                            case 'p':
                            case 'R':
                            case 'r':
                            case 'S':
                            case 's':
                                repeat = false;
                                break;
                            default:
                                cout << "Invalid response. Please try again." << endl;
                                repeat = true;
                        }
                    }while (repeat);
                    //Determine winner
                    switch (user1){
                        case 'P':
                        case 'p':
                            if (user2 == 'P' || user2 == 'p'){
                                cout << "Nobody wins." << endl;
                            }else if (user2 == 'R' || user2 == 'r'){
                                cout << "Paper covers Rock." << endl;
                            }else{
                                cout << "Scissors cut Paper." << endl;
                            }
                            break;
                        case 'R':
                        case 'r':
                            if (user2 == 'P' || user2 == 'p'){
                                cout << "Paper covers Rock." << endl;
                            }else if (user2 == 'R' || user2 == 'r'){
                                cout << "Nobody wins." << endl;
                            }else{
                                cout << "Rock breaks Scissors." << endl;
                            }
                            break;
                        case 'S':
                        case 's':
                            if (user2 == 'P' || user2 == 'p'){
                                cout << "Scissors cut Paper." << endl;
                            }else if (user2 == 'R' || user2 == 'r'){
                                cout << "Rock breaks Scissors." << endl;
                            }else{
                                cout << "Nobody wins." << endl;
                            }
                            break;
                    }
                    cout << endl;
                    cout << "Would you like to play again? Y/N: ";
                    cin >> response;        
                }while (response == 'y' || response == 'Y');
                break;}
            case 2:{
                //Savitch 8th Edition Chapter 3 Problem 2
                //Interest in Revolving Credit Account
                //Declare variables
                float accntBal, intrDue, amtDue, minPymt; 
                char response;
                do{
                    //Input account balance
                    cout << "What is your account balance? $";
                    cin >> accntBal;
                    //Calculate interest due and total amount due
                    if (accntBal > 1000){
                        intrDue = 1000 * FIR_INT + (accntBal - 1000) * EXT_INT;
                        amtDue = accntBal + intrDue;
                    }else{
                        intrDue = accntBal * FIR_INT;
                        amtDue = accntBal + intrDue;
                    }
                    //Calculate minimum payment due
                    if (amtDue > DEF_MIN_PY){
                        if (DEF_MIN_PY >= (MIN_PY_PRCT * amtDue)){
                            minPymt = DEF_MIN_PY;
                        }else{
                            minPymt = MIN_PY_PRCT * amtDue;
                        }
                    }else{
                        minPymt = amtDue;
                    }
                    //Output account balance, interest due, total amount due, 
                    //and minimum payment due
                    cout << fixed << showpoint << setprecision(2);
                    cout << "Account Summary: " << endl;
                    cout << "  Account Balance: $" << accntBal << endl;
                    cout << "  Interest Due: $" << intrDue << endl;
                    cout << "  Total Amount Due: $" << amtDue << endl;
                    cout << "  Minimum Payment: $" << minPymt << endl;
                    //Prompt for repeat
                    cout << "\nWould you like to repeat for another account? Y/N: ";
                    cin >> response;
                    cout << endl;
                }while (response == 'y' || response == 'Y');
                break;}
            case 3:{
                //Savitch 8th Edition Chapter 3 Problem 5
                //Cost of Long-Distance Call
                //Declare variables
                char dayFirI, daySecI; //first and second initials for day of week
                char response;
                int timeHr, timeMin, callTime;
                float callCst;
                do{
                    bool repeat;
                    do{
                        do{
                            //Input day of week
                            cout << "Enter the first two letters of the day your call started: ";
                            cin >> dayFirI >> daySecI;
                            switch (dayFirI){
                                case 'M':
                                case 'm':
                                    if (daySecI == 'O' || daySecI == 'o'){
                                        repeat = false;
                                    }else{
                                        cout << "Invalid input. Please start over." << endl;
                                        repeat = true;
                                    }
                                    break;
                                case 'T':
                                case 't':
                                    if (daySecI == 'U' || daySecI == 'u'
                                        || daySecI == 'H' || daySecI == 'h'){
                                        repeat = false;
                                    }else{
                                        cout << "Invalid input. Please start over." << endl;
                                        repeat = true;
                                    }
                                    break;
                                case 'W':
                                case 'w':
                                    if (daySecI == 'E' || daySecI == 'e'){
                                        repeat = false;
                                    }else{
                                        cout << "Invalid input. Please start over." << endl;
                                        repeat = true;
                                    }
                                    break;
                                case 'F':
                                case 'f':
                                    if (daySecI == 'R' || daySecI == 'r'){
                                        repeat = false;
                                    }else{
                                        cout << "Invalid input. Please start over." << endl;
                                        repeat = true;
                                    }
                                    break;
                                case 'S':
                                case 's':
                                    if (daySecI == 'A' || daySecI == 'a'
                                        || daySecI == 'U' || daySecI == 'u'){
                                        repeat = false;
                                    }else{
                                        cout << "Invalid input. Please start over." << endl;
                                        repeat = true;
                                    }
                                    break;
                                default:
                                    cout << "Invalid input. Please start over." << endl;
                                    repeat = true;
                                    break;
                            }
                        }while(repeat);
                        do{
                            //Input time of call
                            cout << "Enter the time the call started in 24-hour notation." << endl;
                            cout << " Please input the hour (HH), press Enter, and then "
                                 << "input the minutes (MM), and press Enter: " << endl;
                            cin >> timeHr >> timeMin;
                            if (timeHr < 0 || timeHr > 23){
                                cout << "Invalid input. Please enter a new time." << endl;
                                repeat = true;
                            }else if (timeMin < 0 || timeMin > 59){
                                cout << "Invalid input. Please enter a new time." << endl;
                                repeat = true;
                            }else{
                                repeat = false;
                            }
                        }while (repeat);
                        //Input call time
                        cout << "Enter the length of your call in minutes: ";
                        cin >> callTime;
                        cout << endl;
                        //Compute call cost
                        switch (dayFirI){
                            case 'M':
                            case 'm':
                            case 'T':
                            case 't':
                            case 'W':
                            case 'w':
                            case 'F':
                            case 'f':
                                    if (timeHr >= 8 && timeHr <= 17){
                                        callCst = callTime * MF_DAY_RT;
                                    }else if (timeHr == 6 && timeMin == 00){
                                        callCst = callTime * MF_DAY_RT;
                                    }else{
                                        callCst = callTime * MF_MR_NI_RT;
                                    }
                                    break;
                            case 'S':
                            case 's':
                                    callCst = callTime * SAT_SUN_RT;
                                    break;
                        }
                    }while (repeat);
                    //Output cost of call
                    cout << endl;
                    cout << "Your call started on [" << dayFirI << daySecI << "] at "
                         << timeHr << ":" << timeMin << "." << endl;
                    cout << fixed << showpoint << setprecision(2);
                    cout << "The cost of your call is: $" << callCst << endl;
                    //Prompt for repeat
                    cout << "\nWould you like to compute the cost for another call? Y/N: ";
                    cin >> response;
                }while (response == 'y' || response == 'Y');
                break;}
            case 4:{
                //Savitch 8th Edition Chapter 3 Problem 7
                //Convert years to Roman Numerals
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
                break;}
            case 5:{
                //Savitch 8th Edition Chapter 3 Problem 9
                //Interest on Loan
                //Declare variables
                float loanAmt, loanBal, intstRt, mthPymt, 
                      balPyd, mthInt, totInt = 0;
                char response; //to prompt for repeat

                do{
                    int month = 1; //Keep track of how many months it
                                   //took to pay off loan
                    //Input loan amount and interest rate
                    cout << "What is the loan amount? $";
                    cin >> loanAmt;
                    cout << "What is the interest rate on the loan? %";
                    cin >> intstRt;
                    //Convert interest rate
                    intstRt /= CNV_PERC;
                    //Calculate monthly payment
                    loanBal = loanAmt;
                    mthPymt = loanBal * MTH_PYT;
                    //Output heading
                    cout << endl;
                    cout << "Month     Loan Balance     Monthly Payment  Interest Payed  "
                            "Balance Payed" << endl;
                    cout << fixed << showpoint << setprecision(2);
                    cout << setw(3) << "0" << setw(10) << "$" << loanBal 
                         << setw(11) << "$" << mthPymt 
                         << setw(14) << " - " << setw(15) << " - " << endl;
                    do {
                        //Calculate interest
                        mthInt = (intstRt * loanBal)/MTH_YR;
                        //Calculate loan balance
                        balPyd = mthPymt - mthInt;
                        if (balPyd <= loanBal){
                            loanBal -= balPyd;
                        }else{
                            //Do not overpay loan
                            balPyd = loanBal;
                            loanBal = 0;
                        }
                        //Output monthly payment and loan balance
                        cout << fixed << showpoint << setprecision(2);
                        cout << setw(3) << month;
                        cout << setw(10) << "$" << setw(8) << right << loanBal; 
                        cout << setw(11) << "$" << right << mthPymt; 
                        cout << setw(10) << "$" << setw(6) << right << mthInt; 
                        cout << setw(9) << "$" << setw(6) << right << balPyd;
                        cout << endl;
                        //Increment month and add total interest
                        month++;
                        totInt += mthInt;
                    }while(loanBal > 0);
                    //Output total interest payed overtime
                    cout << endl;
                    cout << "The total interest paid over the life of the loan is $"
                         << fixed << showpoint << setprecision(2) << totInt << endl;
                    //Determine simple annualized percentage paid in interest
                    float loanYrs = static_cast<float>(month)/MTH_YR;
                    float annInt = totInt/loanYrs;
                    float annPerc = annInt/loanAmt;
                    annPerc *= 100; //Convert to percentage
                    //Output annualized interest and percentage
                    cout << "It took " << loanYrs << " years to pay off your loan of $"
                         << loanAmt << "." << endl;
                    cout << "Therefore, your annualized interest paid was $"
                         << annInt << ", which is " << annPerc << "% of the $" << loanAmt
                         << " loan amount." << endl;
                    //Prompt for repeat
                    cout << endl;
                    cout << "Would you like to repeat this calculation for a new loan "
                         << "amount? Y/N: ";
                    cin >> response;
                    cout << endl;
                }while (response == 'y' || response == 'Y');
                break;}
            case 6:{
                //Savitch 8th Edition Chapter 3 Problem 12
                //Approximating PI
                //Declare variables
                int nTerms; //number of terms to approximate PI
                float term, apprxPI;
                char response; //allow for repetition

                do{
                    apprxPI = 0.0; //reinitialize each loop if the
                                   //user wants to repeat program
                    //Input n terms
                    cout << "Input the number of terms you want to "
                         << "use to approximate PI: ";
                    cin >> nTerms;
                    //Calculate PI approximation
                    for (int n = 0; n < nTerms; n++){
                        term = 4.0; //product for each term in 
                                         //PI approximation
                                         //reinitialize each loop
                        term *= ((pow(-1, n))/(2 * n + 1));
                        apprxPI += term;
                    }
                    //Output approximation of PI
                    cout << "The approximation for PI with " << nTerms 
                         << " terms is " << apprxPI << endl;
                    //Prompt for repeat
                    cout << "Would you like to make another approximation? Y/N: ";
                    cin >> response;
                    cout << endl;
                }while (response == 'y' || response == 'Y');
                break;}
            case 7:{
                //Savitch 8th Edition Chapter 3 Problem 15
                //Buoyancy
                //Declare variables
                float sphWgt, sphRad, sphVol, //weight, radius and volume of sphere
                      buoyFrc;
                //Input weight and radius
                cout << "What is the weight of the sphere in pounds? ";
                cin >> sphWgt;
                cout << endl;
                cout << "What is the radius of the sphere in feet? ";
                cin >> sphRad;
                cout << endl;
                //Calculate volume
                sphVol = (4/3)*PI*(sphRad*sphRad*sphRad);
                //Calculate buoyant force
                buoyFrc = sphVol * SP_WGT_WTR;
                //Check if the sphere will float or sink
                if (buoyFrc >= sphWgt){
                    cout << "The sphere will float." << endl;
                }else{
                    cout << "The sphere will sink." << endl;
                }
                break;}
            case 8:{
                //Savitch 8th Edition Chapter 3 Problem 16
                //Comparing Celsius and Fahrenheit
                //Declare variables
                int tempC, tempF;
                //Loop to find same Celsius and Fahrenheit degress
                for (tempC = 100; tempC != tempF; --tempC){
                    tempF = ((9*tempC)/5)+ 32;
                }
                cout << "Temperature in Celsius is " << tempC << " degrees\n"
                     << "Temperature in Fahrenheit is " << tempF << " degrees\n"
                     << "The temperatures are the same at this point." << endl;
                break;}
            case 9:{
                //Savitch 8th Edition Chapter 3 Problem 17
                //Basal Metabolic Rate
                //Declare variables
                float weight, basMeRt;
                int height, age, numBars;
                char gender, response;
                //Input weight, height, age, gender
                cout << "Please input the following: \n"
                     << "\tWeight, in pounds: ";
                cin >> weight;
                cout << "\tHeight, in inches: ";
                cin >> height;
                cout << "\tAge, in years: ";
                cin >> age;
                cout << "\tGender, M or F: ";
                cin >> gender;
                //Calculate initial BMR
                if (gender == 'F' || gender == 'f')
                    basMeRt = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
                else
                    basMeRt = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
                //Input activity
                do{
                    cout << "Are you: "
                         << "\n  (A) Sedentary"
                         << "\n  (B) Somewhat active (exercise occasionally)"
                         << "\n  (C) Active (exercise 3-4 days per week)"
                         << "\n  (D) Highly active (exercise every day)"
                         << "\n\n Please enter either A, B, C, or D, for your response: ";
                    cin >> response;
                    //Calculate final BMR based on activity
                    switch (response){
                        case 'A':
                        case 'a':
                            basMeRt *= (1 + 0.20);
                            break;
                        case 'B':
                        case 'b':
                            basMeRt *= (1 + 0.30);
                            break;
                        case 'C':
                        case 'c':
                            basMeRt *= (1 + 0.40);
                            break;
                        case 'D':
                        case 'd':
                            basMeRt *= (1 + 0.50);
                            break;
                        default:
                            cout << "Invalid response. Please try again." << endl;
                            response = -1;
                }}while(response == -1);
                //Output number of chocolate bars to be consumed
                cout << "You should consume " << fixed << showpoint << setprecision(2)
                     << basMeRt/CHOC_BAR << " chocolate bars to maintain your current weight." << endl;
                break;}
            case 10:{
                //Savitch 8th Edition Chapter 3 Problem 19
                //The Game of "23"
                //Declare variables
                int pileTP, user, cmptr;
                bool escape;
                string loser;
                char response;
                do{
                    //Start Game
                    pileTP = 23; //initialize pile at start of each game
                    cout << "--------------------------" << endl;
                    cout << "Let's play a game of \"23\"!" << endl;
                    cout << "--------------------------" << endl;
                    cout << "\nCurrently: " << pileTP << " toothpick(s) in "
                         << "the pile." << endl;
                    do{
                        //Human turn
                        do{
                            cout << "\nHow many toothpicks would you like to remove? "
                                 << "You may remove either 1, 2, 3: ";
                            cin >> user;
                            if (user > pileTP){
                                cout << "\nYou are trying to remove more toothpicks "
                                     << "than what's in the pile.\nMake a new "
                                     << "selection." << endl;
                                escape = true;
                            }else if (user < 1 || user > 3){
                                cout << "\nInvalid choice. Please try again." << endl;
                                escape = true;
                            }else{
                                pileTP -= user;
                                cout << "\nCurrently: " << pileTP << " toothpick(s) in "
                                     << "the pile." << endl;
                                if (pileTP == 0){
                                    loser = "Human";
                                    break;
                                }
                                escape = false;
                            }
                        }while (escape);
                        //Computer turn
                        if (pileTP != 0){
                            cout << "\nIt is now the computer's turn..." << endl;
                            if (pileTP > 4){
                                cmptr = 4 - user;
                            }else if (pileTP >= 2 && pileTP <= 4){
                                cmptr = pileTP - 1;
                            }else{
                                cmptr = 1;
                            }
                            pileTP -= cmptr;
                            cout << "\nThe computer removed " << cmptr << " toothpick(s)." << endl;
                            cout << "Currently: " << pileTP << " toothpick(s) in "
                                 << "the pile." << endl;
                            if (pileTP == 0){
                                loser = "Computer";
                            }
                        }
                    }while(pileTP != 0);
                    //Result 
                    cout << "\nGame over! " << loser << " loses the game!" << endl;
                    cout << "Would you like to play again? Y/N: ";
                    cin >> response;
                    cout << endl;
                }while (response == 'y' || response == 'Y');
                break;}
            default:{
                cout << "Exiting program now..." << endl;
                loop = false;
                break;}
        }
    }while(loop);
    //Exit
    return 0;
}

