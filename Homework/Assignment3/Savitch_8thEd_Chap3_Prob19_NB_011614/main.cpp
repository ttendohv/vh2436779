/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 16, 2014, 6:53 PM
 * Savitch 8th Edition Chapter 3 Problem 19
 * The game of "23"
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
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
        cout << "Would you like to play again? ";
        cin >> response;
        cout << endl;
    }while (response == 'y' || response == 'Y');
    //Exit
    return 0;
}

