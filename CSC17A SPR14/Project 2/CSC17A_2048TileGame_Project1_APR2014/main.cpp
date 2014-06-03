/*! \mainpage 2048 Tile Game
 * 
 *  \section Introduction
 *   2048 is an online game that was released in March 2014. It is the product 
 *   of a bored web-developer, who described it as a clone of a previously 
 *   released game called 1024. 
     The object of the game is to get the number 2048 by colliding identical 
 *   numbered squares, which are then added. 
 *   This is really a game of strategy, as you try to move the tiles in such a 
 *   way that adds tiles, and reduces the number of spaces filled. Once all 
 *   tiles are filled and no legal moves are allowed, the game is over.
 * 
 *  \section Game Play
 *   At the start of the game you will be prompted to enter your name, to be 
 *   stored for later recording of your statistics.
 *   You will then be presented with a 4x4 board with two number 2’s randomly 
 *   placed, and all other squares will be filled with zeroes, indicating an 
 *   empty square. At this point you are prompted on which direction you would 
 *   like to shift tiles – up, down, left, or right. Once you make your choice, 
 *   all numbered tiles will move in the direction you chose. If any tiles touch 
 *   another of the same number, the tiles will “collide” and combine in addition. 
 *   And then you continue to make another move.
 *   Each collision will result in some power of 2. The object of game is to reach 
 *   the number 2048. If you successfully obtain the number 2048 on your game board, 
 *   you will be prompted on whether you would like to continue for more points 
 *   or stop (points are awarded based on each addition you make). Otherwise, the 
 *   game continues until there are no more legal moves on the board (there are no 
 *   more blank spaces and none of the tiles are adjacent to like tiles).
 *   When the game is over you will be shown your score. You will then be prompted 
 *   on whether you would like to start another game with a new player. If you 
 *   choose to, you will be prompted for a new name and a new board will appear. 
 *   Whenever you choose not to start a new game, statistics for each player will 
 *   be displayed: name, score, time elapsed, and whether they won or lost.
 */

/*! \file main.cpp 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on April 17, 2014, 9:51 PM
 * CSC17 A Project 1
 * 2048 Tile Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User-defined Libraries
#include "TileGame.h"
#include "PlayerInfo.h"

//Global Constants

//Function Prototypes
void prntStats(Player[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int DIMSN=4; //Dimension length for both rows and columns of board
    int users=10; //Number of users available to store for current game play
    Player stats[users]; //Array to store multiple player statistics
    int player=0; //Counter to determine current player
    bool newPlyr; //validate creation of new player or not
    
    do{
        srand(static_cast<unsigned int>(time(0)));
        TileGame game(DIMSN,DIMSN);
        int points=0; //Counter to store points
        stats[player].win=false;
        
        //Start game
        cout << "What is your name? ";
        cin >> stats[player].name;
        cout << endl;
        int start=time(0);
        //Print board
        game.prntBrd();
        //Play game
        char choice;
        int next;
        do{
            cout << "Make a move:\n"
                    "t, for UP\n"
                    "v, for DOWN\n"
                    "f, for LEFT\n"
                    "g, for RIGHT\n";
            cin >> choice;
            game.gamePly(static_cast<Move>(choice),points);
            game.prntBrd();
            next=game.result();
            if(next==1){
                stats[player].win=true;
                cout << "Would you like to continue for more points? Y/N: ";
                cin >> choice;
                if(choice=='Y'||choice=='y')next=2;
            }
        }while(next==2);
        //Display Statistics
        int end=time(0);
        stats[player].time=end-start;
        stats[player].score=points;
        cout << "Your final score: " << stats[player].score << " points " << endl;
        //New Player?
        cout << "What would you like to do next? \n"
                "  1. Start a new game\n"
                "  2. Print statistics from current and/or previous games\n";
        cin >> choice;
        if(choice=='1'){
            ++player;
            newPlyr=true;
        }else{
            prntStats(stats,player);
            newPlyr=false;
        }
    }while(newPlyr);
    //Exit
    return 0;
}

/*! \fn prntStats
         *  \brief This function will print final statistics for all players.
 * 
 *   \param a[] Player array of statistics
 *   \param n integer variable of how many total players created
*/
void prntStats(Player a[],int n){
    for(int i=0;i<=n;i++){
        cout << endl;
        cout << "Name: " << a[i].name << endl;
        cout << "Score: " << a[i].score << endl;
        cout << "Time: " << a[i].time << " seconds" << endl;
        cout << "Win? ";
        if(a[i].win)cout << "Yes " << endl;
        else cout << "No " << endl;
    }
    cout << endl;
}