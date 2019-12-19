#include "Board.h"

Board::Board()
{
	board = {};
	checkingBoard = {};
}

//Initializes board with correct values
void Board::boardInit()
{
	board = { '1','2','3','4','5','6','7','8','9' };
	checkingBoard = board;
}

//Checks to see if any win conditions are fulfilled,
//returning whether the game has ended
bool Board::checkBoard()
{
	//horizontal check
	for (int i = 0; i < 7; i += 3)
	{

		if (board[i] == board[i + 1] && board[i] == board[i + 2])
		{
			//cout << board[i] << board[i + 1] << board[i + 2] << " horizontally equal" << endl;
			return true;
		}
		else
		{
			//cout << board[i] << board[i + 1] << board[i + 2] << " horizontally do not equal" << endl;
		}
	}
	//vertical check
	for (int i = 0; i < 3; i++)
	{
		if (board[i] == board[i + 3] && board[i] == board[i + 6])
		{
			//cout << board[i] << board[i + 3] << board[i + 6] << " vertically equal" << endl;
			return true;
		}
		else
		{
			//cout << board[i] << board[i+3] << board[i + 6] << " vertically do not equal" << endl;
		}
	}
	//diagonal check
	if (board[0] == board[4] && board[0] == board[8])
	{
		return true;
	}
	if(board[2] == board[4] && board[2] == board[6])
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Board::checkCat()
{
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] == checkingBoard[i])
		{
			
			return false;
		}
		else
		{
			//cout << board[i] << " not equal " << checkingBoard[i] << endl;
		}
	}
	return true;
}

//Pass in 0 for a normal board to be printed
//Uses recursion because it's fun
void Board::printBoard(int line)
{
	if (line < 7)
	{
		if (line % 3 == 0)
		{
			cout << " " << board[line] << " | "
				<< board[line + 1] << " | "
				<< board[line + 2] << endl;
			printBoard(line + 1);

		}
		else
		{
			cout << "__________" << endl;
			printBoard(line + 2);
		}
	}
}

void Board::chooseLoc(char location, char player)
{
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] == location)
		{
			//cout << board[i] << " equals " << location << endl;
			board[i] = player;
		}
		else
		{
			//cout << board[i] << " does not equal " << location << endl;
		}
	}
}

bool Board::validLoc(char choice)
{

	//Loop over board and see if choice equals any of the components of the board array
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] == choice)
		{
			//cout << board[i] << " equals " << choice << endl;
			return true;
		}
		else
		{
			//cout << board[i] << " does not equal " << choice << endl;
		}
	}
	return false;

}