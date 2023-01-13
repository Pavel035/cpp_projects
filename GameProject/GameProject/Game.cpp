#include "Game.h"
#include <iostream>



void DrawGame(int size, int** numbersArray, int& score)
{
	clearConsole();
	int width = size * 8;
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << numbersArray[i][j];
			int numberSize = sizeOfNumber(numbersArray[i][j]);
			for (int k = numberSize; k <= 6; k++)
			{
				std::cout << " ";
			}
			std::cout << "|";
		}
		std::cout << std::endl;
		for (int m = 0; m < width; m++)
		{
			std::cout << "_";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\nScore: " << score;
}
void Game(int fieldSize, char* nickname)
{
	int score = 0;
	int** numbers = new int* [fieldSize];
	for (int i = 0; i < fieldSize; i++)
	{
		numbers[i] = new int[fieldSize]();
	}
	int count = 0;
	while (checkGame(numbers, fieldSize, count))
	{
		Generate(score, numbers, fieldSize);
		DrawGame(fieldSize, numbers, score);
		if (!Move(fieldSize, numbers))break;
	}
	GameOver(score, nickname, fieldSize);
}

void startGame()
{
	Game(getSize(), getNickname());
}