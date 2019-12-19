#include <stdlib.h>
#include <vector>
#include <iostream>
#pragma once

using namespace std;

class Board
{
private:
	vector<char> board;
	vector<char> checkingBoard;

public:
	Board();
	void printBoard(int line);
	void boardInit();
	void chooseLoc(char location, char player);
	bool validLoc(char location);
	bool checkBoard();
	bool checkCat();
};
