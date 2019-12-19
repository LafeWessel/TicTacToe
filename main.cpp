#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <typeinfo>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
	srand(time(NULL));

	Game myGame;
	myGame.play();

	cin.get();
	return 0;
}