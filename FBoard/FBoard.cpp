/*******************************************************************************************
** Author: Edgar Hernandez
** Date: 8/11/2019
** Description: This file contains the implementation for the FBoard class. This contains methods
** and members for playing a game, where player x is trying to get her piece to corner square (7, 7),
** and player o is trying to make it so player x doesn't have any legal moves.
********************************************************************************************/

#include <iostream>
#include "FBoard.hpp"
#include <iomanip>
#include <cmath>


/*********************************************************************
*					FBoard::checkLegalMoves(int,int)
* This private function determines whether there are any legal moves for
* 'x' to make. It returns true if a legal move can be made. This is similar
* to the moveX function, but it does not modify the array.
*********************************************************************/
bool FBoard::checkLegalMoves(int moveRow, int moveCol)
{
	// Returns true if 'x' can make a legal diagonal move within the array bounds
	if (((moveRow <= 7) && (moveRow >= 0)) && ((moveCol <= 7) && (moveCol >= 0)))
	{
		if ((position[moveRow][moveCol] != 'o'))
		{
			if ((std::abs(moveRow - xRowPos) == 1) && (std::abs(moveCol - xColPos) == 1))
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

/*********************************************************************
*					FBoard::Fboard()
* This is the default constructor that initializes the board to empty using
* the "-" character. It puts four "o" pieces at (5,7),(6,6),(7,5), and (7,7).
* It puts an "x" piece at (0,0) and it initializes the other data members.
*********************************************************************/

FBoard::FBoard()
{
	for (int row = 0; row < 8; row++) //Initialize empty array using '-' character
	{	for (int column = 0; column < 8; column++)
			{
				position[row][column] = '-';
			}
	}

	position[5][7] = position[6][6] = position[7][5] = position[7][7] = 'o'; //Initialize 'o' coordinates
	position[0][0] = 'x'; //Initialize 'x' coordinate

	currentState = UNFINISHED; //Initialize gameState
	
	// Initialize tracking of x-coordinates
	xRowPos = 0;
	xColPos = 0;
}

/*********************************************************************
*					FBoard::getGameState()
* This function prints out the current state of the game by returning
* the value for the gameState enumerated data member.
*********************************************************************/

gameState FBoard::getGameState()
{	
	// Set state to X_WON if the 'x' is in position (7,7) 
	if ((xRowPos == 7) && (xColPos == 7))
	{
		currentState = X_WON;
		std::cout << "X_WON" << std::endl;
	}

	// Set state to O_WON if there are no legal moves left for 'x' 
	else if	(!(checkLegalMoves(xRowPos + 1, xColPos + 1) ||
			 checkLegalMoves(xRowPos - 1, xColPos - 1) ||
			 checkLegalMoves(xRowPos + 1, xColPos - 1) ||
			 checkLegalMoves(xRowPos - 1, xColPos + 1)))
	{
		currentState = O_WON;
		std::cout << "O_WON" << std::endl;
	}

	// Otherwise set the state to UNFINISHED
	else
	{ 
		currentState = UNFINISHED;
		std::cout << "UNFINISHED----" << std::endl;
	}
	return currentState; 


}

/*********************************************************************
*					FBoard::moveX(int,int)
* This function takes the row and the column of the square to move the 'x' value
* to as parameters. It returns false if the move is not allowed or if the game
* has been won. Otherwise, it makes the desired move and returns true. A piece
* can move diagonally in any direction unless it is off the board or the place 
* is already occupied.
*********************************************************************/

bool FBoard::moveX(int moveRow, int moveCol)
{	
	if (((moveRow <= 7) && (moveRow >= 0)) && ((moveCol <= 7) && (moveCol >= 0))) //Checks for array bounds
	{
		if ((position[moveRow][moveCol] != 'o')) //Cannot be in an 'o' position
		{
			if ((std::abs(moveRow - xRowPos) == 1) && (std::abs(moveCol - xColPos) == 1)) //Must be diagonal
			{
				position[xRowPos][xColPos] = '-';
				position[moveRow][moveCol] = 'x';
				xRowPos = moveRow;
				xColPos = moveCol;
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

/*********************************************************************
*					FBoard::moveO(int,int,int,int)
* This function takes as parameters takes as parameters
* the row and column to move from, and the row and column to move to
* for the 'o' value. If the first pair of coordindates does not currently
* hold 'o', or if the move is illegal, or if the game has been won
* then the function returns false. Otherwise it makes the desired move
* and returns true.
*********************************************************************/

bool FBoard::moveO(int rowFrom, int colFrom, int rowTo, int colTo)
{

	if ((std::abs(rowTo - rowFrom) == 1) && (std::abs(colTo - colFrom) == 1)) //Check for diagonal move
	{
		if ((position[rowFrom][colFrom] == 'o') && (getGameState() == UNFINISHED)) //Checks game status and previous position
		{
			if ((rowTo - rowFrom == 1) && (colTo - colFrom == 1)) //Row and column cannot both increase
			{
				return false;
			}
			else if (position[rowTo][colTo] == '-') //Must move to existing value to stay within bounds
			{
				position[rowFrom][colFrom] = '-';
				position[rowTo][colTo] = 'o';
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


/*********************************************************************
*					FBoard::showBoard(char board[])
* This function prints out the current state of the game board by printing
* the values in the position character array.
*********************************************************************/

void FBoard::showBoard()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			std::cout << std::setw(5) << position[row][col] << " "; //Displays values in grid format
		}
		std::cout << std::endl;
	}
	std::cout << " " << std::endl;
}


