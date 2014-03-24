/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 24, 2014, 4:17 PM
 * Gaddis Chapter 10 Problem 17
 * Morse Code Converter
 */

//System Libraries
#include <iostream>
using namespace std;

//Abstract Data Types
enum Num { ZERO, ONE, TWO, THREE, FOUR,
           FIVE, SIX, SEVEN, EIGHT, NINE };
enum Letter { A, B, C, D, E, F, G, H, I, J,
              K, L, M, N, O, P, Q, R, S, T,
              U, V, W, X, Y, Z };
enum Other { SPACE, COMMA, PERIOD, QUESTION };
//Global Constants

//Function Prototypes
void initNum(string[]);
void initLtr(string[]);
void initOtr(string[]);

//Execution
int main(int argc, char** argv) {
    //Declare and initialize variables
    string morsNum[10],morsLtr[26],morsOtr[4];
    initNum(morsNum);
    initLtr(morsLtr);
    initOtr(morsOtr);
    //Exit
    return 0;
}

void initNum(string num){
    num[ZERO]="-----";
    num[ONE]=".----";
    num[TWO]="..---";
    num[THREE]="...--";
    num[FOUR]="....-";
    num[FIVE]=".....";
    num[SIX]="-....";
    num[SEVEN]="--...";
    num[EIGHT]="---..";
    num[NINE]="----.";
}

initLtr(string ltr){
    ltr[A]=".-";
    ltr[B]="-...";
    ltr[C]="-.-.";
    ltr[D]="-..";
    ltr[E]=".";
    ltr[F]="..-.";
    
}