/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 30, 2014, 11:23 AM
 * WIN14 CSC5 RCC Project 1
 * Minesweeper
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants
const unsigned int COL = 26;

//Function Prototypes
void initial(char[][COL],int,int);
void chsLevel(int,int&,char[][COL],int&,int&);
void play(char[][COL],char[][COL],int,int,int);
bool mkMove(char,int&,int&,int,int);
bool winLose(char[][COL], char[][COL], int,int, int, int);
void display(char[][COL],int,int);
void cascade(char[][COL],char[][COL],int,int,int);
void uncvCnr(char[][COL],char[][COL],int,int,int);
void readSol(char[][COL],int,int,ifstream&);
void wnrsBrd(char[][COL],int,int,char*);
void points(int,int,int,int);
void srtWnrs();
void swap(int &,int &);
void swap(string &,string &);
void minPos(vector<string> &,vector<int> &,int);
void mrkSort(vector<string> &,vector<int> &);

//Execution Begins
int main(int argc, char** argv) {
    //Declare variables
    const unsigned int rows = 26;
    int choice,mines,actlRow,actlCol;
    char board[rows][COL], soltn[rows][COL];
    //Start game
    cout << "Welcome to Minesweeper!" << endl;
    //Choose level
    cout << "Choose the difficulty by typing in the corresponding "
            "number:" << endl;
    cout << "   1) Easy" << endl;
    cout << "   2) Not so Easy" << endl;
    cin >> choice;
    chsLevel(choice,mines,soltn,actlRow,actlCol);
    //Initialize board
    initial(board,actlRow,actlCol);
    //Display board
    display(board,actlRow,actlCol);
    //Start play
    play(board,soltn,actlRow,actlCol,mines);
    //Exit
    return 0;
}

//Initialize game board
//Input
//      board, row, col
//Output
//      none
//      reference board array
void initial(char board[][COL],int row,int col){
    for(int n=0; n<row; n++){
        for(int x=0; x<col; x++){
            board[n][x] = 'M';
        }
    }
}

//Begin play
//Input
//      board, soltn, row, col, mines
//Output
//      none
//      reference board array
void play(char board[][COL],char soltn[][COL],int row,int col,int mines){
    char num1;
    int num2,num3;
    string winner;
    ofstream allWnrs;
    char *wnnrs = new char[row*col];
    bool gameOvr,invInpt;
    int begin = time(0);
    do{
        do{
            //Make move
            cout << "Choose which square to uncover (i.e. A1) ";
            cin >> num1 >> num2;
            invInpt = mkMove(num1,num2,num3,row,col);
            cout << endl;
        }while(invInpt);
        //Determine if lost or may continue
        gameOvr = winLose(board,soltn,row,col,num3,num2);
        //Determine if won
        unsigned int count = 0;
        for (int n=0; n<row; n++){
            for(int x=0; x<col; x++){
                if(board[n][x] == soltn[n][x]) count++;
            }
        }
        if(count == ((row*col)-mines)){
            cout << "Congratulations! You win!" << endl;
            cout << endl;
            int end = time(0);
            //Print out winners board with flags
            wnrsBrd(soltn,row,col,wnnrs);
            cout << "Please enter your name to record you as a winner: ";
            cin >> winner;
            winner += " ";
            allWnrs.open("Winners.txt",ios::app);
            allWnrs << winner << endl;
            allWnrs.close();
            //Display time and score
            points(begin,end,mines,row);
            gameOvr = true;
        }
    }while(!gameOvr);
}

//Manipulate choice user made to 
//determine move
//Validate choice
//Input
//      num1, num2, num3,rows,cols
//Output
//      bool = true or false
//      reference num2,num3
bool mkMove(char num1, int& num2,int& num3,int rows,int cols){
    num1 = toupper(num1);
    num3 = static_cast<int>(num1 - 'A');
    num2--;
    if ((num2<0||num2>cols-1)||(num3<0||num3>rows-1)){ 
        cout << "    Invalid choice. Please try again." << endl;
        return true;
    }
    else
        return false;
}

//Determine if won or may continue
//Input
//      board, soltn, rows, cols, num1, num2
//Output
//      none
//      reference board
bool winLose(char board[][COL], char soltn[][COL], int rows,
                               int cols, int num1, int num2){
    if (soltn[num1][num2] == '*'){
        board[num1][num2] = soltn[num1][num2];
        display(board, rows,cols);
        cout << "Game Over. You lose!" << endl;
        return true;
    }else{
        cascade(board,soltn,rows,num1,num2);
        display(board,rows,cols);
        return false;
    }
}

//Display game board
//Input
//      board, rows, cols
//Output
//      none
void display(char board[][COL], int rows, int cols){
    //Print out A-I for rows, 1-9 for columns
    char row = 'A';
    cout << " ";
    for(int i=0; i<cols; i++){
        cout << setw(4);
        cout << i+1;
    }
    cout << endl << endl;
    int *r=&rows,*c=&cols;
    for(int n=0; n<*r; n++){
        cout << row << "   ";
        for(int x=0; x<*c; x++){
            cout << board[n][x] << "   ";
        }
        cout << endl;
        row++;
    }
    cout << endl;
}

//Uncover tiles, determine if more than one
//may be uncovered
//Input
//      board, soltn, rows, num1, num2
//Output
//      none
//      reference board
void cascade(char board[][COL], char soltn[][COL], 
                     int rows, int num1, int num2){
    int count = 0;
    //Test center of board
    //If any mines surround the chosen tile, only 
    //uncover the chosen tile
    if ((num1>0 && num1<rows-1)&&(num2>0 && num2<rows-1)){
        for(int n=(num1-1); n<=(num1+1); n++){
            for(int x=(num2-1); x<=(num2+1); x++){
                if (soltn[n][x] == '*'){
                    count++;
                }
            }
        }
        if(count > 0){
            board[num1][num2] = soltn[num1][num2];
            return;
        }
        //If no mines surround the chosen tile, uncover
        //all adjacent to the chosen tile
        else{
            for(int n=(num1-1); n<=(num1+1); n++){
                for(int x=(num2-1); x<=(num2+1); x++){
                    board[n][x] = soltn[n][x];
                }
            }
        }
    //Test corners, only a partial cascade to remain in bounds of array
    }else{
        uncvCnr(board,soltn,rows,num1,num2);
    }
}

//Test corners, uncover only what's in the array
//Input
//      board, soltn, rows, num1, num2
//Output
//      none
//      reference board
void uncvCnr(char board[][COL], char soltn[][COL], 
                     int rows, int num1, int num2){
    if(num1==0){
            if(num2==0){
                if((soltn[num1][num2+1] == '*')||(soltn[num1+1][num2+1] == '*')
                    ||(soltn[num1+1][num2] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1][num2+1] = soltn[num1][num2+1];
                    board[num1+1][num2] = soltn[num1+1][num2];
                    board[num1+1][num2+1] = soltn[num1+1][num2+1];
                }
            }else if(num2>0 && num2<rows-1){
                if((soltn[num1][num2-1] == '*')||(soltn[num1][num2+1] == '*')
                    ||(soltn[num1+1][num2-1] == '*')
                    ||(soltn[num1+1][num2+1] == '*')
                    ||(soltn[num1+1][num2] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1][num2-1] = soltn[num1][num2-1];
                    board[num1][num2+1] = soltn[num1][num2+1];
                    board[num1+1][num2] = soltn[num1+1][num2];
                    board[num1+1][num2+1] = soltn[num1+1][num2+1];
                    board[num1+1][num2-1] = soltn[num1+1][num2-1];
                }
            }else{//if num2==8
                if((soltn[num1][num2-1] == '*')||(soltn[num1+1][num2-1] == '*')
                    ||(soltn[num1+1][num2] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1][num2-1] = soltn[num1][num2-1];
                    board[num1+1][num2] = soltn[num1+1][num2];
                    board[num1+1][num2-1] = soltn[num1+1][num2-1];
                }
            }
        }else if(num1>0 && num1<rows-1){
            if(num2==0){
                if((soltn[num1-1][num2] == '*')||(soltn[num1-1][num2+1] == '*')
                    ||(soltn[num1][num2+1] == '*')||(soltn[num1+1][num2] == '*')
                    ||(soltn[num1+1][num2+1] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1-1][num2] = soltn[num1-1][num2];
                    board[num1-1][num2+1] = soltn[num1-1][num2+1];
                    board[num1][num2+1] = soltn[num1][num2+1];
                    board[num1+1][num2] = soltn[num1+1][num2];
                    board[num1+1][num2+1] = soltn[num1+1][num2+1];
                }
            }else{//if num2==8
                if((soltn[num1-1][num2] == '*')||(soltn[num1-1][num2-1] == '*')
                    ||(soltn[num1][num2-1] == '*')||(soltn[num1+1][num2] == '*')
                    ||(soltn[num1+1][num2-1] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1-1][num2] = soltn[num1-1][num2];
                    board[num1-1][num2-1] = soltn[num1-1][num2-1];
                    board[num1][num2-1] = soltn[num1][num2-1];
                    board[num1+1][num2] = soltn[num1+1][num2];
                    board[num1+1][num2-1] = soltn[num1+1][num2-1];
                }
            }
        }else{//if num1==8
            if(num2==0){
                if((soltn[num1-1][num2] == '*')||(soltn[num1-1][num2+1] == '*')
                    ||(soltn[num1][num2+1] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }
                else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1-1][num2] = soltn[num1-1][num2];
                    board[num1-1][num2+1] = soltn[num1-1][num2+1];
                    board[num1][num2+1] = soltn[num1][num2+1];
                }
            }else if(num2>0 && num2<rows-1){
                if((soltn[num1][num2-1] == '*')||(soltn[num1][num2+1] == '*')
                    ||(soltn[num1-1][num2-1] == '*')
                    ||(soltn[num1-1][num2] == '*')
                    ||(soltn[num1-1][num2+1] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1][num2-1] = soltn[num1][num2-1];
                    board[num1][num2+1] = soltn[num1][num2+1];
                    board[num1-1][num2-1] = soltn[num1-1][num2-1];
                    board[num1-1][num2] = soltn[num1-1][num2];
                    board[num1-1][num2+1] = soltn[num1-1][num2+1];
                }
            }else{//if num2==8
                if((soltn[num1][num2-1] == '*')||(soltn[num1-1][num2-1] == '*')
                    ||(soltn[num1-1][num2] == '*')){
                    board[num1][num2] = soltn[num1][num2];
                    return;
                }else{
                    board[num1][num2] = soltn[num1][num2];
                    board[num1][num2-1] = soltn[num1][num2-1];
                    board[num1-1][num2-1] = soltn[num1-1][num2-1];
                    board[num1-1][num2] = soltn[num1-1][num2];
                }
            }
        }
}

//Choose level and assign board accordingly
//Input
//      choice, mines, soltn, rows, cols
//Output
//      none
//      reference mines, rows, cols
void chsLevel(int choice, int& mines, char soltn[][COL], int& rows, int& cols){
    ifstream game;
    switch(choice){
        case 1:{
            cout << "You have chosen Level: Easy " << endl;
            cout << endl;
            game.open("Game1.txt");
            rows = cols = 9;
            mines = 10;
            //Read in solution
            //read from file into soltn array
            readSol(soltn,rows,cols,game);
            break;}
        case 2:{
            cout << "You have chosen Level: Not so Easy " << endl;
            cout << endl;
            game.open("Game2.txt");
            rows = cols = 16;
            mines = 40;
            readSol(soltn,rows,cols,game);
            break;}
        default:
            break;
    }
}

//Read in solution from file
//Input
//      game, rows, cols, mineswp
//Output
//      none
//      reference game
void readSol(char game[][COL], int rows, int cols, ifstream& mineswp){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            mineswp >> game[i][j];
        }
    }
    mineswp.close();
    //Test input
//    for(int i=0; i<ROWS; i++){
//        for(int j=0; j<COL; j++){
//            cout << game[i][j];
//        }
//        cout << endl;
//    }
}

//Display flags on the winners board
//Input
//      soltn, rows, cols, winner
//Output
//      none
//      reference winner
void wnrsBrd(char soltn[][COL],int rows,int cols,char *winner){
    int x=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols;j++){
            if(soltn[i][j]=='*')winner[x++]='F';
            else winner[x++]=soltn[i][j];
        }
    }
    //Output winners board
    for(int x=0; x<rows*cols; x++){
        cout << winner[x] << "   ";
        if(x%cols==cols-1){
            cout << endl;
        }
    }
}

//Calculate total time and points awarded
//Display points
//Input
//      begin, end, mines, rows
//Output
//      none
void points(int begin, int end, int mines, int rows){
    //Display amount of time
    int totTime =  end - begin;
    cout << "You completed this level in " 
            << totTime << " seconds. " << endl;
    //Calculate points
    int pts = 0;
    //2 points for every mine survived
    pts += mines * 3;
    //1 point for each tile on the board
    pts += rows*rows;
    //Subtract points for time
    if (totTime > 40){
        totTime -= 40;
        //Subtract 3 points for every 5 seconds over 40
        pts -= (totTime%5) * 3;
    }
    //Display points
    cout << "You have been awarded " << pts << " points!" << endl;
    //Write points to file
    ofstream points;
    points.open("Points.txt",ios::app);
    points << setw(4);
    points << pts;
    points.close();
    //Sort winners
    srtWnrs();
}

//Sort winners and print top 5 high scores
//to file
//Input
//      none
//Output
//      none
void srtWnrs(){
    ifstream win, point;
    string name;
    int num;
    vector<string> names;
    vector<int> numbers;
    win.open("Winners.txt");
    point.open("Points.txt");
    //Read in values into vectors
    while(!win.eof()){
        win >> name;
        names.push_back(name);
    }
    
    while(!point.eof()){
        point >> num;
        numbers.push_back(num);
    }
    //Sort points in order from highest to lowest
    mrkSort(names,numbers);
    
//    //Print out all scores to console
//    cout << endl;
//    cout << "Order of Scores" << endl << endl;
//    for(int i=0; i<numbers.size(); i++){
//        cout << names[i] << " ";
//        cout << numbers[i];
//        cout << endl;
//    }
    //Write top 5 scores to file
    ofstream topScr;
    topScr.open("HighScores.txt");
    for(int i=0;(i<numbers.size()&&i!=5);i++){
        topScr << i+1 << ". " << names[i]
                << ": " << numbers[i] << " " << endl;
    }
    win.close();
    point.close();
    topScr.close();
}

//Sort scores and names from highest score
//to lowest score
//For functions
//      mrkSort,minPos,swap,swap
void mrkSort(vector<string> &a,vector<int> &b){
    for(int i=0;i<b.size()-1;i++){
        minPos(a,b,i);
    }
}

void minPos(vector<string> &a,vector<int> &b,int pos){
    for(int i=pos+1;i<b.size();i++){
        if(b[pos]<b[i]){
            swap(a[pos],a[i]);
            swap(b[pos],b[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swap(string &a,string &b){
    string temp=a;
    a=b;
    b=temp;
}