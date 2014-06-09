/*! \file ResumeGame.cpp 
 * File:   ResumeGame.cpp
 * Author: Victoria
 * 
 * Created on June 8, 2014, 6:51 PM
 */

//User-defined Libraries
#include "ResumeGame.h"

ResumeGame::~ResumeGame(){
    for(int i=0;i<row;i++){
        delete [] temp[i];
    }
    delete [] temp;
}

int ResumeGame::getPoints(){
    int temp;
    ifstream points;
    points.open("Points.txt");
    points >> temp;
    points.close();
    
    return temp;
}