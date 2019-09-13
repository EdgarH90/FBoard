/*******************************************************************************************
** Author: Edgar Hernandez
** Date: 8/11/2019
** Description: This file contains the specification for the FBoard class. This contains methods
** and members for playing a game, where player x is trying to get her piece to corner square (7, 7),
** and player o is trying to make it so player x doesn't have any legal moves.
********************************************************************************************/

#include <iostream>
#ifndef FBOARD_HPP
#define FBOARD_HPP

//Create enumerated data type

enum gameState { X_WON, O_WON, UNFINISHED };

//FBoard class declaration
class FBoard
{
private:
	char position[8][8]; // Initial board
	gameState currentState; // Enumerated data type member for state of game
	int xRowPos; // Returns current 'x' row position
	int xColPos; // Returns current 'x' column position
	bool checkLegalMoves(int,int); // Checks whether 'x' can make a move
public:
	FBoard(); // Default constructor that initializes empty array
	gameState getGameState(); // Returns state of game
	bool moveX(int, int);
	bool moveO(int, int, int, int);
	void showBoard(); // Displays the current board state
};
#endif