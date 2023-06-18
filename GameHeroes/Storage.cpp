#include "Storage.h"
#include "Hero.h"



bool Storage::deletePlayer(const MyString& username)
{
	for (size_t i = 0; i < players.getSize(); i++)
	{
		if (players[i].getUsername() == username)
		{
			players.popAt(i);
			return true;
		}
	}
	return false;
}

void Storage::printPlayers()
{
	std::cout << "Players: " << std::endl;
	for (size_t i = 0; i < players.getSize(); i++)
	{
		std::cout << "Name: " << players[i].getUsername() << " Balance: " << players[i].getMoney() << std::endl;
		printHeroes(players[i].getUsername());
	}
}

void Storage::printAdmins() const
{
	std::cout << "Admins: " << std::endl;
	for (size_t i = 0; i < admins.getSize(); i++)
	{
		std::cout << "FirstName: " << admins[i].getFirstName() << std::endl;
		std::cout << "LastName: " << admins[i].getLastName() << std::endl;
		std::cout << "Email: " << admins[i].getEmail() << std::endl<<std::endl;
	}
}

void Storage::printHeroes(MyString& username) const
{
	for (size_t i = 0; i < heroes.getSize(); i++)
	{
		if (heroes[i].getOwner() == username&&heroes[i].isAlive())
		{
			std::cout << heroes[i].getNickname() << " " << heroes[i].getElement()<<std::endl;
		}
	}
}

void Storage::printMarket() const
{
	std::cout << "Market: " << std::endl;
	for (size_t i = 0; i < heroes.getSize(); i++)
	{
		if (heroes[i].isAvailable()&&heroes[i].isAlive())
		{
			std::cout << heroes[i].getNickname() << " " <<"Price: "<<heroes[i].getPrice() << heroes[i].getElement() <<" power: "<<heroes[i].getPower() << std::endl;
		}
	}
}

void Storage::printGraveyard() const
{
	std::cout << "Graveyard: " << std::endl;
	for (size_t i = 0; i < heroes.getSize(); i++)
	{
		if (!heroes[i].isAlive())
		{
			std::cout << heroes[i].getNickname() << " " << "Price: " << heroes[i].getPrice() << heroes[i].getElement() << " power: " << heroes[i].getPower() << std::endl;
		}
	}
}

bool Storage::isMarketEmpty() const
{
	for (size_t i = 0; i < heroes.getSize(); i++)
	{
		if (heroes[i].isAvailable()&&heroes[i].isAlive())
		{
			return false;
		}
	}
	return true;
}

bool Storage::hasHeroes(MyString& username) 
{
	for (size_t i = 0; i < heroes.getSize(); i++)
	{
		if (heroes[i].getOwner()==username && heroes[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

void Storage::showOther(Player* cur)
{
	std::cout << "Players: " << std::endl;
	for (size_t i = 0; i < players.getSize(); i++)
	{
		if (players[i].getUsername() != cur->getUsername())
		{
			std::cout << "Name: " << players[i].getUsername() << " Balance: " << players[i].getMoney() << std::endl;
			printHeroes(players[i].getUsername());
		}
	}
}
