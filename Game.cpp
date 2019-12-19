#include "Game.h"

Game::Game()
{
	gameOver = false;
	myBoard.boardInit();
	human = 'X';
	computer = 'O';
	//cout << human << computer << gameOver << endl;
}

void Game::play()
{
	myBoard.printBoard(0);
	while (!gameOver)
	{
		//cout << "another turn, game is not over" << endl;
		humanTurn();
		//cout << "human turn over" << endl << endl;
		computerTurn();
		//cout << "computer turn over" << endl << endl;
		myBoard.printBoard(0);
	}
}

void Game::humanTurn()
{
	if (gameOver)
	{
		return;
	}
	char choice = 0;
	while (!myBoard.validLoc(choice))
	{
		cout << "Type the number of the space that you would like to choose." << endl;
		cin >> choice;
		//cout << "You chose a: " << typeid(choice).name() << " which is: " << choice << endl;

	}
	//cout << choice << " was valid" << endl;
	myBoard.chooseLoc(choice, human);
	//cout << "location chosen" << endl;
	gameOver = myBoard.checkBoard();
	//cout << "board checked" << endl;
	if (gameOver)
	{
		cout << "You have won!" << endl;
	}
	else
	{
		gameOver = myBoard.checkCat();
	}
}

void Game::computerTurn()
{
	if (gameOver)
	{
		return;
	}
	int randomChoice = 0;
	char choice;
	while (!myBoard.validLoc(randomChoice + '0'))
	{
		//cout << randomChoice << " was not valid" << endl;
		randomChoice = rand() % 9 + 1;
	}
	//cout << randomChoice <<" was valid" << endl;
	choice = randomChoice + '0';

	//cout << "Computer chose: " << randomChoice << endl;
	myBoard.chooseLoc(choice, computer);
	//cout << "location chosen" << endl;
	gameOver = myBoard.checkBoard();
	//cout << "board checked" << endl;
	if (gameOver)
	{
		cout << "The computer has won!" << endl;
	}
	else
	{
		gameOver = myBoard.checkCat();
	}
}