/* 
 * File:   ResumeGame.h
 * Author: Victoria
 *
 * Created on June 7, 2014, 7:45 PM
 */

#ifndef RESUMEGAME_H
#define	RESUMEGAME_H

/*! \class ResumeGame
    \brief Includes functions to read in previous game board
 *         and points to resume game play
 * 
 *  This class extends from the TileGame class, using 
 *  necessary TileGame functions to continue game play.
*/

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User-defined Libraries
#include "TileGame.h"

class ResumeGame : public TileGame {
    private:
        int **temp; //!< Temporary array to read in board before assigning to board
    public:
        /*! \fn ResumeGame
         *  \brief Class Constructor
         * 
         *  Set rows and columns, and fill board
         *  Fill board by reading in a previously saved game board
         *  from a file.
         *  \param r integer argument for rows
         *  \param c integer argument for columnns
         *  \sa TileGame(int,int)
         */
        ResumeGame(int r,int c):TileGame(r,c){
            row=r;
            col=c;
            
            //Allocate memory
            temp = new int*[row];
            for(int i=0;i<col;i++){
                temp[i] = new int[col];
            }
            
            //Read in saved game board
            bool tryAgn = true;
            string fileName;
            
            while(tryAgn){
                try{
                    while(tryAgn){
                        try{
                            fileName="";
                            cout << "Enter the file name of your saved game"
                                    " (exclude the file extension): ";
                            cin >> fileName;

                            string temp = "    ";
                            int length = fileName.length();
                            for(int i=3,j=length-1;i>=0,j>=0;i--,j--){
                                temp[i]=fileName[j];
                            }

                            //Check if they already entered a file extension
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
                    tryAgn = true;
                    fileName+=".txt";
                    ifstream input;
                    input.open(fileName.c_str());

                    //Check if file exists
                    if(input){
                        tryAgn = false;
                        for(int i=0;i<row;i++){
                            for(int j=0;j<col;j++){
                                input >> temp[i][j];
                            }
                        }

            //            //Test
            //            for(int i=0;i<row;i++){
            //                for(int j=0;j<col;j++){
            //                    cout << temp[i][j];
            //                }
            //            }

                        //Assign elements of temporary array to
                        //board game array
                        for(int i=0;i<row;i++){
                            for(int j=0;j<col;j++){
                                board[i][j]=temp[i][j];
                            }
                        }

                        input.close();
                    }else{
                        throw FileName(fileName);
                    }
                }catch(TileGame::FileName n){
                    cout << "The file " << n.getFName() << 
                            " does not exist. " << endl;
                }
            }
        }
        /*! \fn ~ResumeGame
         *  \brief Class Destructor
         * 
         *  Delete allocated memory
         */
        ~ResumeGame();
        /*! \fn getPoints
         *  \brief Read in saved points from a file from 
         *   a previously saved game
         * 
         *  \return number of points
         */
        int getPoints();        
};

#endif	/* RESUMEGAME_H */