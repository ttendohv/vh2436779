/* 
 * File:   PlayerInfo.h
 * Author: Victoria
 *
 * Created on April 18, 2014, 1:55 PM
 */

#ifndef PLAYERINFO_H
#define	PLAYERINFO_H

/*! \struct Player
    \brief This struct stores the statistics for each player.
*/

struct Player{
    string name; //!< Player name
    int score; //!< Player's final score
    int time; //!< Total time to complete game
    bool win; //!< Result of winning or losing the game
};

#endif	/* PLAYERINFO_H */