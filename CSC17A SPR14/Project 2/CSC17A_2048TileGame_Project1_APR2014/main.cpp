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
 *   At the start of the game you will be prompted on whether you would like to 
 *   resume the last game saved or to start a new game. If you resume a game, 
 *   the previous game board will be uploaded along with the accumulated points 
 *   from before. If you choose to start a new game, you will be given a fresh 
 *   board. In either case, you then will be asked to enter your name, to be 
 *   stored for later recording of your statistics.
 * 
 *   Assuming you started a new game, you will then be presented with a 4x4 
 *   board with two number 2’s randomly placed, and all other squares will be 
 *   filled with zeroes, indicating an empty square. At this point you are 
 *   prompted on which direction you would like to shift tiles – up, down, 
 *   left, or right. Once you make your choice, all numbered tiles will move 
 *   in the direction you chose. If any tiles touch another of the same number, 
 *   the tiles will “collide” and combine in addition. And then you continue to 
 *   make another move.
 * 
 *   Each collision will result in some power of 2. The object of game is to 
 *   reach the number 2048. If you successfully obtain the number 2048 on your 
 *   game board, you will be prompted on whether you would like to continue for 
 *   more points or stop (points are awarded based on each addition you make). 
 *   Otherwise, the game continues until there are no more legal moves on the 
 *   board (there are no more blank spaces and none of the tiles are adjacent 
 *   to like tiles).
 * 
 *   Also note that at any point during the game you are given the option to 
 *   save your game board and points, at which point the current game will be over.
 * 
 *   When the game is over you will be shown your score and other statistics, 
 *   such as time elapsed and whether you won or lost.
 */

/*! \file main.cpp 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on April 17, 2014, 9:51 PM
 * Last Updated on June 8, 2014
 * CSC17 A Project 1
 * 2048 Tile Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User-defined Libraries
#include "ResumeGame.h"
#include "PlayerInfo.h"

//Global Constants

//Function Prototypes
void checkChoice(char);
void checkChoice1(char);
void prntStats(Player);
template<class T>void startGame(T game,Player,int&);
void checkChoice(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int DIMSN=4; //Dimension length for both rows and columns of board
    Player stats; //Store player statistics
    
    //Set random seed generator
    srand(static_cast<unsigned int>(time(0)));
    int points=0; //Counter to store points
    stats.win=false;
    int option;
    
    //Resume or Start New game?
    try{
        cout << "Would you like to...\n"
                " 1) resume the last saved game OR\n"
                " 2) start a new game?\n" << endl;
        cin >> option;
        checkChoice(option);
        //Start game
        if(option==1){
            //Resume with ResumeGame object
            ResumeGame game(DIMSN,DIMSN);
            points = game.getPoints();
            startGame(game,stats,points);
        }else{
            //New game with TileGame object
            TileGame game(DIMSN,DIMSN);
            startGame(game,stats,points);
        }
    }catch(string invalid){
        cout << invalid << endl;
    }
    //Exit
    return 0;
}

/*! \fn checkChoice
 *  \brief This function will perform a check on user input.
 * 
 *   \param c choice for starting game
*/
void checkChoice(int c){
    if(c!=1&&c!=2){
        string invalid = "Invalid choice";
        throw invalid;
    }
}

/*! \fn startGame
 *  \brief This function will perform necessary operations for game play.
 * 
 *   This templated function will allow the use of either the
 *   TileGame class object or the ResumeGame class object
 *   \param game class object for game play
 *   \param stats struct object to hold player statistics
 *   \param &points accumulate points
*/
template<class T>
void startGame(T game, Player stats, int& points){
        int start=time(0);
        cout << "What is your name? ";
        cin >> stats.name;
        cout << endl;
        //Print board
        game.prntBrd();
        //Play game
        char choice;
        int next;
        do{
            bool tryAgn = true;
            while(tryAgn){
                try{
                    cout << "Make a move:\n"
                            " t, for UP\n"
                            " v, for DOWN\n"
                            " f, for LEFT\n"
                            " g, for RIGHT\n\n"
                            " s, to SAVE game\n";
                    cin >> choice;
                    checkChoice(choice);
                    //If no exception was thrown, following
                    //statements will execute
                    tryAgn = false;
                    if(choice=='s'){
                        game.save(points);
                        next=-1;
                    }else{
                        game.gamePly(static_cast<Move>(choice),points);
                        game.prntBrd();
                        next=game.result();
                        if(next==1){
                            stats.win=true;
                            //Prompt to continue
                            tryAgn = true;
                            while(tryAgn){
                                try{
                                    cout << "Would you like to continue for more points? Y/N: ";
                                    cin >> choice;
                                    checkChoice1(choice);
                                    //If no exception was thrown, following
                                    //statements will execute
                                    tryAgn = false;
                                    if(choice=='Y'||choice=='y')next=2;
                                }catch(string twoOptns){
                                    cout << twoOptns << endl;
                                }
                            }
                        }
                    }
                }catch(string exception){
                    cout << exception << endl;
                }
            }
        }while(next==2);
        //Display Statistics
        int end=time(0);
        //Calculate time
        stats.time=end-start;
        stats.score=points;
        cout << "Your final score: " << stats.score << " points " << endl;
        prntStats(stats);
}

/*! \fn checkChoice
 *  \brief This function will perform a check on user input.
 * 
 *   \param c choice for board move
*/
void checkChoice(char c){
    if(c!='t'&&c!='v'&&c!='f'&&c!='g'&&c!='s'){
        string exception = "Invalid choice. Try again.";
        throw exception;
    }
}

/*! \fn checkChoice1
 *  \brief This function will perform a check on user input.
 * 
 *   \param c choice for continuing game
*/
void checkChoice1(char c){
    if(c!='y'&&c!='Y'&&c!='n'&&c!='N'){
        string twoOptns = "Please enter in Y or N";
        throw twoOptns;
    }
}

/*! \fn prntStats
 *  \brief This function will print final statistics for all players.
 * 
 *   \param a Player object for statistics
*/
void prntStats(Player a){
    cout << endl;
    cout << "Name: " << a.name << endl;
    cout << "Score: " << a.score << endl;
    cout << "Time: " << a.time << " seconds" << endl;
    cout << "Win? ";
    //Determine if won or lost
    if(a.win)cout << "Yes " << endl;
    else cout << "No " << endl;
    cout << endl;
}