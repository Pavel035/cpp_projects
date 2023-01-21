#include "GameFunctions.h"
#include "Leaderboard.h"
#include <iostream>
#include "Menu.h"
#include "MainFunctions.h"

void GameOver(int score, char* name, int size)
{
	int a = checkScore(name, score, size);
	if (a == 6)
	{
		std::cout << "Game Over\n";
	}
	else
	{
		std::cout << "You are in position: " << a << "\n";
	}
	press();
}

bool checkGame(int** array, int size, int &count)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (array[i][j] == 0)
			{
				count = 0;
				return true;
			}
		}
	count++;
	if (count == 2)
		return false;
	
}

char getMove()
{
	char move = 'r';
	do
	{
		std::cout << "\nPress w(up)s(down)a(left)d(right) and ENTER\nPress q to quit\n";
		std::cin.ignore();
		std::cin >> move;
	} while (move != 'w' && move != 's' && move != 'a' && move != 'd' && move!='q');
		return move;
}


bool Move(int size, int** array)
{
	switch (getMove())
	{
	case 'w': 
	{
		for (int i = size-1; i >= 0; i--)
			for (int j = 0; j < size; j++)
			{
				for (int k = size-1; k > 0; k--)
				{
					if (array[k][j] != 0)
					{
						if (array[k - 1][j] == 0)
						{
							array[k - 1][j] = array[k][j];
							array[k][j] = 0;
						}
						else if (array[k - 1][j] == array[k][j])
						{
							array[k - 1][j] *= 2;
							array[k][j] = 0;
						}
					}
				}
			}
		break;
	}
	case 'd':
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size-1; k++)
				{
					if (array[i][k] != 0) {
						if (array[i][k + 1] == 0)
						{
							array[i][k + 1] = array[i][k];
							array[i][k] = 0;
						}
						else if (array[i][k+1] == array[i][k])
						{
							array[i][k+1] *= 2;
							array[i][k] = 0;
						}
					}
				}
			}
		break;
	}
	case 's':
	{
		for (int i = 0; i <size; i++)
			for (int j = 0; j < size; j++)
			{
				for(int k = 0; k < size-1; k++)
				{
					if (array[k][j] != 0)
					{
						if (array[k + 1][j] == 0)
						{
							array[k + 1][j] = array[k][j];
							array[k][j] = 0;
						}
						else if (array[k + 1][j] == array[k][j])
						{
							array[k + 1][j] *= 2;
							array[k][j] = 0;
						}
					}
				}
			}
		break;
	}
	case 'a':
	{
		for (int i = 0; i < size; i++)
			for (int j = size-1; j >= 0; j--)
			{
				for (int k = size-1; k > 0; k--)
				{
					if (array[i][k] != 0) {
						if (array[i][k - 1] == 0)
						{
							array[i][k - 1] = array[i][k];
							array[i][k] = 0;
						}
						else if (array[i][k - 1] == array[i][k])
						{
							array[i][k - 1] *= 2;
							array[i][k] = 0;
						}
					}
				}
			}
		break;
	}
	case 'q': 
	{
		return false;
		break;
	}
	 default: break;
	}
	return true;
}

void Generate(int &score, int** array, int size)
{
	int** empty = new int*[size * size];
	int p = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (array[i][j] == 0)
			{
				empty[p] = new int[2];
				empty[p][0] = i;
				empty[p][1] = j;
				p++;

			}
		}

	
	if (p > 0) {
		int randomnumber = rand() % p;
		if (score < 60)
		{
			array[empty[randomnumber][0]][empty[randomnumber][1]] = 2;
			score += 2;
		}
		else if (score < 110)
		{
			if (rand() % 2 == 0)
			{
				array[empty[randomnumber][0]][empty[randomnumber][1]] = 2;
				score += 2;
			}
			else
			{
				array[empty[randomnumber][0]][empty[randomnumber][1]] = 4;
				score += 4;
			}
		}
		else
		{
			switch (rand() % 3)
			{
			case 0:
			{
				array[empty[randomnumber][0]][empty[randomnumber][1]] = 2;
				score += 2;
			}
			case 1:
			{
				array[empty[randomnumber][0]][empty[randomnumber][1]] = 4;
				score += 4;
			}
			case 2:
			{
				array[empty[randomnumber][0]][empty[randomnumber][1]] = 8;
				score += 8;
			}
			}
		}
		
	}
	delete[] empty;
}
