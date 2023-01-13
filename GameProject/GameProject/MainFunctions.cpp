#include <iostream>



void clearConsole()
{
	std::cout << "\033[;H"; // Moves cursor to the top left
	std::cout << "\033[J"; // Clears the console
}

void press()
{
	char k;
	std::cout << "Press anything and ENTER to continue\n";
	std::cin >> k;
}

char* getNickname()
{
	char* nickname = new char[50];
	std::cout << "Enter nickname: ";
	std::cin.sync();
	std::cin.ignore();
	std::cin.getline(nickname, 50);
	clearConsole();
	return nickname;
}
int getSize()
{
	int fieldSize = 0;
	do {
		std::cout << "Enter size (3<size<11): ";
		if (!(std::cin >> fieldSize))
		{
			std::cin.clear();
			std::cin.ignore();
		}
		clearConsole();
	} while (fieldSize < 4 || fieldSize>10);
	
	return fieldSize;
}

int sizeOfNumber(int a)
{
	if (a == 0) return 1;
	int tempa = a, counter = 0;
	while (tempa != 0)
	{
		counter++;
		tempa /= 10;
	}
	return counter;
}
