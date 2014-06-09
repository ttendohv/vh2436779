/*! \file TileGame.cpp 
 * File:   TileGame.cpp
 * Author: Victoria
 * 
 * Created on April 17, 2014, 9:51 PM
 */

//System libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

//User-defined libraries
#include "TileGame.h"
#include "PlayerInfo.h"

TileGame::TileGame(){
    setRow(0);
    setCol(0);
}

TileGame::TileGame(int a,int b) {
    //Set dimensions
    try{
        setRow(a);
        setCol(b);
        
        //Initialize
        initialize();
    }catch(TileGame::WrongDimension){
        cout << "Error: Wrong dimensions provided. " << endl;
        
        setRow(3);
        setCol(3);
        
        //Initialize
        initialize();
    }
}

TileGame::~TileGame() {
    for(int i=0;i<row;i++){
        delete [] board[i];
    }
    delete [] board;
}

void TileGame::setRow(int n){
    if(n!=4){
        throw WrongDimension();
    }else{
        row=n;
    }
}
    
void TileGame::setCol(int n){
    if(n!=4){
        throw WrongDimension();
    }else{
        col=n;
    }
}

void TileGame::initialize(){
    //Allocate memory
    board = new int*[row];
    for(int i=0;i<row;i++)
        board[i]=new int[col];
    
    //Initialize
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            board[i][j]=0;
        }
    }
    //Randomly choose starting pieces
    int indx1,indx2;
    indx1=rand()%row;
    indx2=rand()%col;
    board[indx1][indx2]=2;
    
    int indx3,indx4;
    do{
        indx3=rand()%row;
        indx4=rand()%col;
    }while(indx3==indx1&&indx4==indx2);
    board[indx3][indx4]=2;
}

void TileGame::prntBrd(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << setw(5) << board[i][j];
        }
        cout << endl;
    }
}

void TileGame::gamePly(Move x,int& pts){
    switch(x){
        case UP:
            for(int n=0;n<4;n++){
                for(int i=0;i<row-1;i++){
                    for(int j=0;j<col;j++){
                        if(board[i][j]==0)
                            swap(board[i][j],board[i+1][j]);
                    }
                }
            }
            add(x,pts);
            if(this->result()!=0)
                random();
            break;
        case DOWN:
            for(int n=0;n<4;n++){
                for(int i=row-1;i>0;i--){
                    for(int j=0;j<col;j++){
                        if(board[i][j]==0)
                            swap(board[i][j],board[i-1][j]);
                    }
                }
            }    
            add(x,pts);
            if(this->result()!=0)
                random();
            break;
        case LEFT:
            for(int n=0;n<4;n++){
                for(int i=0;i<row;i++){
                    for(int j=0;j<col-1;j++){
                        if(board[i][j]==0)
                            swap(board[i][j],board[i][j+1]);
                    }
                }            
            }
            add(x,pts);
            if(this->result()!=0)
                random();
            break;
        case RIGHT:
            for(int n=0;n<4;n++){
                for(int i=0;i<row;i++){
                    for(int j=col-1;j>0;j--){
                        if(board[i][j]==0)
                            swap(board[i][j],board[i][j-1]);
                    }
                }
            }
            add(x,pts);
            if(this->result()!=0)
                random();
            break;
    }
}

void TileGame::swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}

void TileGame::random(){
    int num;
    int two=0,zero=0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){
            if(board[i][j]==2)two++;
            if(board[i][j]==0)zero++;
        }
    if(two>0)num=2;
    else if(zero>2)num=2;
    else num=4;
    //Choose next pieces
    int indx1,indx2;
    //Check availability
    int avail=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==0)avail++;
        }
    }
    if(avail>0){
        do{
            indx1=rand()%row;
            indx2=rand()%col;
        }while(board[indx1][indx2]!=0);
        board[indx1][indx2]=num;
    }
}

void TileGame::add(Move x,int& pts){
    switch(x){
        case UP:
            for(int j=0;j<col;j++){
                if(board[0][j]==board[1][j]){
                    board[0][j]+=board[1][j];
                    board[1][j]=0;
                    pts+=board[0][j];//Award points
                    swap(board[1][j],board[2][j]);
                    swap(board[2][j],board[3][j]);
                    
                    if(board[1][j]==board[2][j]){
                        board[1][j]+=board[2][j];
                        board[2][j]=0;
                        pts+=board[1][j];//Award points
                        swap(board[2][j],board[3][j]);
                        
                        if(board[2][j]==board[3][j]){
                            board[2][j]+=board[3][j];
                            board[3][j]=0;
                            pts+=board[2][j];//Award points
                        }
                    }else if(board[2][j]==board[3][j]){
                        board[2][j]+=board[3][j];
                        board[3][j]=0;
                        pts+=board[2][j];//Award points
                    }
                }else if(board[1][j]==board[2][j]){
                    board[1][j]+=board[2][j];
                    board[2][j]=0;
                    pts+=board[1][j];//Award points
                    swap(board[2][j],board[3][j]);
                    
                    if(board[2][j]==board[3][j]){
                        board[2][j]+=board[3][j];
                        board[3][j]=0;
                        pts+=board[2][j];//Award points
                    }       
                }else if(board[2][j]==board[3][j]){
                    board[2][j]+=board[3][j];
                    board[3][j]=0;
                    pts+=board[2][j];//Award points;
                }
            }
            break;
        case DOWN:
            for(int j=0;j<col;j++){
                if(board[3][j]==board[2][j]){
                    board[3][j]+=board[2][j];
                    board[2][j]=0;
                    pts+=board[3][j];//Award points;
                    swap(board[2][j],board[1][j]);
                    swap(board[1][j],board[0][j]);
                    
                    if(board[2][j]==board[1][j]){
                        board[2][j]+=board[1][j];
                        board[1][j]=0;
                        pts+=board[2][j];//Award points;
                        swap(board[1][j],board[0][j]);
                        
                        if(board[1][j]==board[0][j]){
                            board[1][j]+=board[0][j];
                            board[0][j]=0;
                            pts+=board[1][j];//Award points;
                        }
                    }else if(board[1][j]==board[0][j]){
                        board[1][j]+=board[0][j];
                        board[0][j]=0;
                        pts+=board[1][j];//Award points;
                    }
                }else if(board[2][j]==board[1][j]){
                    board[2][j]+=board[1][j];
                    board[1][j]=0;
                    pts+=board[2][j];//Award points;
                    swap(board[1][j],board[0][j]);
                    
                    if(board[1][j]==board[0][j]){
                        board[1][j]+=board[0][j];
                        board[0][j]=0;
                        pts+=board[1][j];//Award points;
                    }       
                }else if(board[1][j]==board[0][j]){
                    board[1][j]+=board[0][j];
                    board[0][j]=0;
                    pts+=board[1][j];//Award points;
                }
            }
            break;
        case LEFT:
            for(int i=0;i<row;i++){
                if(board[i][0]==board[i][1]){
                    board[i][0]+=board[i][1];
                    board[i][1]=0;
                    pts+=board[i][0];//Award points;
                    swap(board[i][1],board[i][2]);
                    swap(board[i][2],board[i][3]);
                    
                    if(board[i][1]==board[i][2]){
                        board[i][1]+=board[i][2];
                        board[i][2]=0;
                        pts+=board[i][1];//Award points;
                        swap(board[i][2],board[i][3]);
                        
                        if(board[i][2]==board[i][3]){
                            board[i][2]+=board[i][3];
                            board[i][3]=0;
                            pts+=board[i][2];//Award points;
                        }
                    }else if(board[i][2]==board[i][3]){
                        board[i][2]+=board[i][3];
                        board[i][3]=0;
                        pts+=board[i][2];//Award points;
                    }
                }else if(board[i][1]==board[i][2]){
                    board[i][1]+=board[i][2];
                    board[i][2]=0;
                    pts+=board[i][1];//Award points;
                    swap(board[i][2],board[i][3]);
                    
                    if(board[i][2]==board[i][3]){
                        board[i][2]+=board[i][3];
                        board[i][3]=0;
                        pts+=board[i][2];//Award points;
                    }        
                }else if(board[i][2]==board[i][3]){
                    board[i][2]+=board[i][3];
                    board[i][3]=0;
                    pts+=board[i][2];//Award points;
                }
            }
            break;
        case RIGHT:
            for(int i=0;i<row;i++){
                if(board[i][3]==board[i][2]){
                    board[i][3]+=board[i][2];
                    board[i][2]=0;
                    pts+=board[i][3];//Award points;
                    swap(board[i][2],board[i][1]);
                    swap(board[i][1],board[i][0]);
                    
                    if(board[i][2]==board[i][1]){
                        board[i][2]+=board[i][1];
                        board[i][1]=0;
                        pts+=board[i][2];//Award points;
                        swap(board[i][1],board[i][0]);
                        
                        if(board[i][1]==board[i][0]){
                            board[i][1]+=board[i][0];
                            board[i][0]=0;
                            pts+=board[i][1];//Award points;
                        }
                    }else if(board[i][1]==board[i][0]){
                        board[i][1]+=board[i][0];
                        board[i][0]=0;
                        pts+=board[i][1];//Award points;
                    }
                }else if(board[i][2]==board[i][1]){
                    board[i][2]+=board[i][1];
                    board[i][1]=0;
                    pts+=board[i][2];//Award points;
                    swap(board[i][1],board[i][0]);
                    
                    if(board[i][1]==board[i][0]){
                        board[i][1]+=board[i][0];
                        board[i][0]=0;
                        pts+=board[i][1];//Award points;
                    }
                            
                }else if(board[i][1]==board[i][0]){
                    board[i][1]+=board[i][0];
                    board[i][0]=0;
                    pts+=board[i][1];//Award points;
                }
            }
            break;
    }
}

int TileGame::result(){
    //Count blanks
    int blanks=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==0)blanks++;
        }
    }
    //Check if any are the winning number
    int winNum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==2048)winNum++;
        }
    }
    //If found 2048, WON
    if(winNum>0){
        cout << "Congratulations, you win!" << endl;
        return 1;
    }else{
        //Check for available moves left
        int availMvs=0;
        if(blanks>0)return 2;//Continue game
        else{
            
            if(board[0][0]==board[1][0]||board[0][0]==board[0][1]
               ||board[0][1]==board[0][2]||board[0][1]==board[1][1]
                ||board[0][2]==board[0][3]||board[0][2]==board[1][2]
                 ||board[1][0]==board[1][1]||board[1][0]==board[2][0]
                  ||board[1][1]==board[1][2]||board[1][1]==board[2][1]
                   ||board[1][2]==board[1][3]||board[1][2]==board[2][2]
                    ||board[1][3]==board[0][3]||board[1][3]==board[2][3]
                     ||board[2][0]==board[2][1]||board[2][0]==board[3][0]
                      ||board[2][1]==board[2][2]||board[2][1]==board[3][1]
                       ||board[2][2]==board[2][3]||board[2][2]==board[3][2]
                        ||board[3][1]==board[3][0]||board[3][1]==board[3][2]
                         ||board[3][3]==board[2][3]||board[3][3]==board[3][2])
                availMvs++;
            }
            //Available moves?
            if(availMvs>0)return 2;//Continue game
            else{
                cout << "Game Over." << endl;
                return 0;
            }
        }
}

void TileGame::save(int pts){
    ofstream points;
    points.open("Points.txt", ios::out);
    points << pts;
    points.close();
    
    bool tryAgn = true;
    string fileName;
    
    while(tryAgn){
        try{
            fileName="";
            cout << "Enter a file name for your game to save"
                    " (exclude the file extension): ";
            cin >> fileName;

            string temp = "    ";
            int length = fileName.length();
            for(int i=3,j=length-1;i>=0,j>=0;i--,j--){
                temp[i]=fileName[j];
            }

            //Check if they already added a file extension
            if(temp[0]=='.'||temp==".txt"){
                throw FileName(fileName);
            }else{
                tryAgn = false;
            }
        }catch(TileGame::FileName n){
            cout << "Error: " << n.getFName() << " is an invalid file name. "
                    "Please try again. " << endl;
        }
    }
    
    fileName+=".txt";
    ofstream file;
    file.open(fileName.c_str());
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            file << board[i][j] << " ";
        }
    }
    
    file.close();
}