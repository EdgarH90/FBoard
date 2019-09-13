/*********************************************************************
** Author: Edgar Hernandez
** Date: 8/11/2019
** Description: This program uses the HalfOpenCylinder and Vase classes.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include "FBoard.hpp"
#include <cmath>

int main()
{
	FBoard testBoard;

	testBoard.showBoard();

	testBoard.moveX(-1, 1);

	//testBoard.showBoard();

	testBoard.moveX(1, 1);
	testBoard.moveX(2, 2);
	testBoard.moveX(3, 3);
	testBoard.moveX(3, 3);
	testBoard.moveX(4, 4);
	testBoard.moveO(6, 6, 5, 5);
	testBoard.moveO(5, 5, 6, 4);
	testBoard.moveX(5, 5); 

	testBoard.showBoard();

	//testBoard.getGameState();


	testBoard.moveO(7, 7, 6, 6);
	testBoard.moveO(5, 7, 4, 6);
	testBoard.moveO(6, 6, 5, 7);
	testBoard.moveX(6, 6);
	testBoard.moveX(7, 7);

	testBoard.showBoard();
	testBoard.moveO(6, 4, 5, 5);
	testBoard.showBoard();
	testBoard.getGameState();
	testBoard.moveO(4, 6, 3, 5);
	testBoard.showBoard();

	return 0;
}

