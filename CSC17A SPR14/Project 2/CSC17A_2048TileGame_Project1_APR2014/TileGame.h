/* 
 * File:   TileGame.h
 * Author: Victoria
 *
 * Created on April 17, 2014, 9:51 PM
 */

#ifndef TILEGAME_H
#define	TILEGAME_H

/*! \class TileGame
    \brief Contains all fields functions
 *         necessary for game play
*/

/** Enumerated type for making a move  
*/
enum Move{
    UP='t',   //!< Shift tiles up
    DOWN='v', //!< Shift tiles down
    LEFT='f', //!< Shift tiles left
    RIGHT='g' //!< Shift tiles right
};
        
class TileGame {
    private:
        int row; //!< Rows for board
        int col; //!< Columns for board
        int **board; //!< Two-dimensional array board for game play
        /*! \fn setRow
         *  \brief Mutator function to set the rows
         */
        void setRow(int);
        /*! \fn setCol
         *  \brief Mutator function to set the columns
         */
        void setCol(int);
        /*! \fn initialize
         *  \brief Initialize the board for game play
         * 
         *  Board will be dynamically allocated, initialized with 0's
         *  and have two 2's randomly placed
         */
        void initialize();
    public:
        /*! \fn TileGame
         *  \brief Class Constructor
         * 
         *  Set rows and columns, and initialize board
         *  \param a integer argument for rows
         *  \param b integer argument for columnns
         *  \sa setRow, setCol, initialize
         */
        TileGame(int a,int b);
        /*! \fn ~TileGame
         *  \brief Class Destructor
         * 
         *  Delete allocated memory
         */
        ~TileGame();
        /*! \fn prntBrd
         *  \brief Print current state of the game board
         */
        void prntBrd();
        /*! \fn gamePly
         *  \brief The bulk of the game
         * 
         *  Depending on the direction chosen to move tiles, this function
         *  will check for empty tiles, swap tiles, add identical adjacent 
         *  tiles, and randomly place a 2 somewhere on the board if there is
         *  space.
         *  \param x enumerated argument type Move for player's move
         *  \param pts reference integer argument to store points
         *  \sa add, result, random
         */
        void gamePly(Move x,int& pts);
        /*! \fn add
         *  \brief Add touching tiles of same value after shifting tiles
         * 
         *  \param x enumerated argument type Move for player's move
         *  \param pts reference integer argument to store points
         *  \sa swap
         */
        void add(Move x,int& pts);
        /*! \fn random
         *  \brief Randomly place a number 2 on the board in any available space
         */
        void random();
        /*! \fn swap
         *  \brief Swap tiles in the direction chosen in order to shift tiles
         * 
         *  \param a integer argument for one tile's value
         *  \param b integer argument for another tile's value
         */
        void swap(int& a,int& b);
        /*! \fn result
         *  \brief Determine current state of game
         *  
         *  This function checks for available moves and if the number 2048
         *  was obtained. Either you win, lose or continue with available moves.
         *  \return integer value indicating state of game
         */
        int result();
};

#endif	/* TILEGAME_H */