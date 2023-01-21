#include "Menu.h"
#include "Game.h"
#include "Leaderboard.h"
#include "MainFunctions.h"
#include <iostream>

void drawMenu()
{
	int k = 0;
	clearConsole();
	do {
		std::cout << "Choose one:" << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Leaderboard" << std::endl;
		std::cout << "3. Quit" << std::endl;
		if (!(std::cin >> k))
		{
			std::cin.clear();
			std::cin.ignore();
		}
		clearConsole();
	} while (k < 1 || k>3);
	switch (k)
	{
	case 1: startGame(); break;
	case 2: printLeaderboard(getSize()); break;
	case 3: exit(0);
	}

}

