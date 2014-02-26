/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 17, 2014, 5:38 PM
 * Savitch 8th Edition Chapter 3 Problem 1
 * Rock, Paper, Scissors
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
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
    
    //Exit
    return 0;
}

