#include "Board.h"
#pragma once

using namespace std;

class Game
{
private:
	Board myBoard;
	bool gameOver;
	char human;
	char computer;

public:
	Game();
	void play();
	void humanTurn();
	void computerTurn();

};