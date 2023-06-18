#include "System.h"



void System::logout()
{
	currentAdmin = nullptr;
	currentPlayer = nullptr;
	numberOfMoves = MAX_MOVES;
}

void System::attack(Player* left, Player* right, Hero* leftHero, Hero* rightHero)
{
	if (!rightHero)
	{
		right->removeMoney(leftHero->getPower());
		left->addMoney(ATTACK_EMPTY_REWARD);
		return;
	}
	if (rightHero->getDefending())
	{
		if (leftHero->getIntElement() == 0 && rightHero->getIntElement() == 1 || leftHero->getIntElement() == 1 && rightHero->getIntElement() == 2 || leftHero->getIntElement() == 2 && rightHero->getIntElement() == 0)
		{
			//left element wins
			if (leftHero->getPower() * 2 > rightHero->getPower())
			{
				
				left->addMoney(leftHero->getPower() * 2 - rightHero->getPower());
				rightHero->setAlive(false);
				MyString def("Default");
				rightHero->setOwner(def);
				return;
			}
			else if (leftHero->getPower() * 2 == rightHero->getPower())
			{
				left->removeMoney(EQUAL_POWER_LOSE);
				return;
			}
			else
			{
				right->addMoney(DEFEND_MONEY);
				left->removeMoney((leftHero->getPower() * 2 - rightHero->getPower())*2);
				leftHero->setAlive(false);
				MyString def("Default");
				leftHero->setOwner(def);
				return;
			}
		}
		else if (leftHero->getIntElement() == rightHero->getIntElement())
		{
			if (leftHero->getPower() > rightHero->getPower())
			{
				
				left->addMoney(leftHero->getPower() - rightHero->getPower());
				MyString def("Default");
				rightHero->setOwner(def);
				rightHero->setAlive(false);
				return;
			}
			else if (leftHero->getPower() == rightHero->getPower())
			{
				left->removeMoney(EQUAL_POWER_LOSE);
				return;
			}
			else
			{
				right->addMoney(DEFEND_MONEY);
				left->removeMoney((rightHero->getPower() - leftHero->getPower()) * 2);
				MyString def("Default");
				leftHero->setOwner(def);
				leftHero->setAlive(false);
				return;
			}
		}
		else
		{
			//right element wins
			if (leftHero->getPower() > rightHero->getPower() * 2)
			{
				right->removeMoney(leftHero->getPower() - rightHero->getPower() * 2);
				left->addMoney(leftHero->getPower() - rightHero->getPower() * 2);
				MyString def("Default");
				rightHero->setOwner(def);
				rightHero->setAlive(false);
				return;
			}
			else if (leftHero->getPower() == rightHero->getPower() * 2)
			{
				left->removeMoney(EQUAL_POWER_LOSE);
				return;
			}
			else
			{
				right->addMoney(DEFEND_MONEY);
				left->removeMoney((rightHero->getPower() * 2 - leftHero->getPower()) * 2);
				MyString def("Default");
				leftHero->setOwner(def);
				leftHero->setAlive(false);
				return;
			}
		}
	}
	if (leftHero->getIntElement() == 0 && rightHero->getIntElement() == 1 || leftHero->getIntElement() == 1 && rightHero->getIntElement() == 2 || leftHero->getIntElement() == 2 && rightHero->getIntElement() == 0)
	{
		//left element wins
		if (leftHero->getPower() * 2 > rightHero->getPower())
		{
			right->removeMoney(leftHero->getPower() * 2 - rightHero->getPower());
			left->addMoney(leftHero->getPower() * 2 - rightHero->getPower());
			rightHero->setAlive(false);
			MyString def("Default");
			rightHero->setOwner(def);
			return;
		}
		else if (leftHero->getPower() * 2 == rightHero->getPower())
		{
			left->removeMoney(EQUAL_POWER_LOSE);
			return;
		}
		else
		{
			right->addMoney(DEFEND_MONEY);
			left->removeMoney((leftHero->getPower() * 2 - rightHero->getPower()) * 2);
			leftHero->setAlive(false);
			MyString def("Default");
			leftHero->setOwner(def);
			return;
		}
	}
	else if (leftHero->getIntElement() == rightHero->getIntElement())
	{
		if (leftHero->getPower() > rightHero->getPower())
		{
			right->removeMoney(leftHero->getPower() - rightHero->getPower());
			left->addMoney(leftHero->getPower() - rightHero->getPower());
			rightHero->setAlive(false);
			MyString def("Default");
			rightHero->setOwner(def);
			return;
		}
		else if (leftHero->getPower() == rightHero->getPower())
		{
			left->removeMoney(EQUAL_POWER_LOSE);
			return;
		}
		else
		{
			right->addMoney(DEFEND_MONEY);
			left->removeMoney((rightHero->getPower() - leftHero->getPower()) * 2);
			leftHero->setAlive(false);
			MyString def("Default");
			leftHero->setOwner(def);
			return;
		}
	}
	else
	{
		//right element wins
		if (leftHero->getPower() > rightHero->getPower() * 2)
		{
			right->removeMoney(leftHero->getPower() - rightHero->getPower() * 2);
			left->addMoney(leftHero->getPower() - rightHero->getPower() * 2);
			rightHero->setAlive(false);
			MyString def("Default");
			rightHero->setOwner(def);
			return;
		}
		else if (leftHero->getPower() == rightHero->getPower() * 2)
		{
			left->removeMoney(EQUAL_POWER_LOSE);
			return;
		}
		else
		{
			right->addMoney(DEFEND_MONEY);
			left->removeMoney((rightHero->getPower() * 2 - leftHero->getPower()) * 2);
			leftHero->setAlive(false);
			MyString def("Default");
			leftHero->setOwner(def);
			return;
		}
	}
}

void System::endOfRound()
{
	for (size_t i = 0; i < storage.players.getSize(); i++)
	{
		storage.players[i].addMoney(END_OF_ROUND);
	}
}

void System::start_game()
{
	
	Admin cur = Admin(MyString("Default"), MyString("Default"), MyString("admin@email"), MyString("admin"), MyString("admin")); //default admin
	storage.admins.pushBack(cur);

	MyString data("");

	currentAdmin = &storage.admins[0];
	std::cout << "Logged as default admin username: admin password: admin" << std::endl;
	
	while (true)
	{
		
		while (!currentAdmin && !currentPlayer)
			getLogin();
		if (currentAdmin)
		{
			std::cout << "Enter command or help for command list: "; std::cin >> data;
			if (data == MyString("help"))
				this->showCommandsAdmin();
			if (data == MyString("clearconsole"))
			{
				clearConsole();
			}
			if (data == MyString("logout"))
			{
				logout();
			}
			if (data == MyString("addadmin"))
			{
				addAdmin();
			}
			if (data == MyString("addplayer"))
			{
				addPlayer();
			}
			if (data == MyString("deleteplayer"))
			{
				deletePlayer();
			}
			if (data == MyString("showall"))
			{
				showAll();
			}
			if (data == MyString("addhero"))
			{
				addHero();
			}
			if (data == MyString("endgame"))
			{
				clearConsole();
				showLeaderboard();
				return;
			}
			if (data == MyString("load"))
			{
				std::ifstream is("savegame.txt", std::ios::binary);
				storage.players.clear();
				storage.admins.clear();
				storage.heroes.clear();
				this->read(is);
			}
			if (data == MyString("save"))
			{
				std::ofstream os("savegame.txt", std::ios::binary);
				this->write(os);
			}
			
		}
		else
		{
			std::cout << "Enter command or help for command list: "; std::cin >> data;
			if (data == MyString("help"))
				this->showCommandsPlayer();
			if (data == MyString("clearconsole"))
			{
				clearConsole();
			}
			if (data == MyString("logout"))
			{
				logout();
			}
			if (data == MyString("deleteme"))
			{
				deleteMe();
				logout();
			}
			if (data == MyString("showplayers"))
			{
				storage.printPlayers();
			}
			if (data == MyString("showmarket"))
			{
				storage.printMarket();
			}
			if (data == MyString("buyhero"))
			{
				if (numberOfMoves == 0)
					std::cout << "No more moves" << std::endl;
				else
				{
					buyHero();
					numberOfMoves--;
				}
			}
			if (data == MyString("showleaderboard"))
			{
				showLeaderboard();
			}
			if (data == MyString("attack"))
			{
				if (numberOfMoves == 0)
					std::cout << "No more moves" << std::endl;
				else
				{
				attackPlayer();
				numberOfMoves--;
				}
			}
			if (data == MyString("makedefensive"))
			{
				if (numberOfMoves == 0)
					std::cout << "No more moves" << std::endl;
				else
				{
				makeDefensive();
				numberOfMoves--;
				}
			}
			if (data == MyString("makeattacking"))
			{
				if (numberOfMoves == 0)
					std::cout << "No more moves" << std::endl;
				else
				{
				makeAttacking();
				numberOfMoves--;
				}
			}
			
		}
	}

	
}

void System::write(std::ofstream& os) const
{
	size_t playerscount = storage.players.getSize();
	os.write((const char*)&playerscount, sizeof(size_t));

	size_t adminscount = storage.admins.getSize();
	os.write((const char*)&adminscount, sizeof(size_t));

	size_t heroescount = storage.heroes.getSize();
	os.write((const char*)&heroescount, sizeof(size_t));
		
	for (size_t i = 0; i < playerscount; i++)
	{
		storage.players[i].write(os);
	}
	for (size_t i = 0; i < adminscount; i++)
	{
		storage.admins[i].write(os);
	}
	for (size_t i = 0; i < heroescount; i++)
	{
		storage.heroes[i].write(os);
	}
}

void System::read(std::ifstream& is)
{
	size_t playerscount = storage.players.getSize();
	is.read((char*)&playerscount, sizeof(size_t));

	size_t adminscount = storage.admins.getSize();
	is.read((char*)&adminscount, sizeof(size_t));

	size_t heroescount = storage.heroes.getSize();
	is.read((char*)&heroescount, sizeof(size_t));

	for (size_t i = 0; i < playerscount; i++)
	{
		storage.players.pushBack(Player());
		storage.players[i].read(is);
	}
	for (size_t i = 0; i < adminscount; i++)
	{
		storage.admins.pushBack(Admin());
		storage.admins[i].read(is);
	}
	for (size_t i = 0; i < heroescount; i++)
	{
		storage.heroes.pushBack(Hero());
		storage.heroes[i].read(is);
	}
}

void System::getLogin()
{
	MyString data("");
	while (true)
	{
		std::cout << "Enter user type(admin/player): ";
		std::cin >> data;
		if (data == MyString("admin"))
		{
			currentAdmin=adminLogin();
			return;
		}
		if (data == MyString("player"))
		{
			playerLogin();
			return;
		}
		clearConsole();
		std::cout << "Incorrect user type"<<std::endl;

	}
}

Admin* System::adminLogin() 
{
	MyString username("");
	MyString password("");
	while (true)
	{
		std::cout << "Enter username: ";
		std::cin >> username;
		if (username == MyString("exit")) return nullptr;
		std::cout << "Enter password: ";
		std::cin >> password;
		for (size_t i = 0; i < storage.admins.getSize(); i++)
		{
			if (storage.admins[i].getUsername() == username && storage.admins[i].getPassword() == password)
			{
				std::cout << "successfully logged" << std::endl;
				if (storage.isMarketEmpty())
				{
					addHero();
					addHero();
					addHero();
				}
				return &storage.admins[i];
			}
		}
		clearConsole();
		std::cout << "No such admin" << std::endl;

	}
}

Player* System::playerLogin() 
{
	MyString username("");
	MyString password("");
	while (true)
	{
		std::cout << "Enter username: ";
		std::cin >> username;
		if (username == MyString("exit")) return nullptr;
		std::cout << "Enter password: ";
		std::cin >> password;
		for (size_t i = 0; i < storage.players.getSize(); i++)
		{
			if (storage.players[i].getUsername() == username && storage.players[i].getPassword() == password)
			{
				std::cout << "successfully logged" << std::endl;
				if (!firstPlayer)
				{
					firstPlayer = &storage.players[i];
				}
				else if(currentPlayer==firstPlayer)
				{
					endOfRound();
				}
				currentPlayer = &storage.players[i];
				return &storage.players[i];
			}
		}
		clearConsole();
		std::cout << "No such player" << std::endl;

	}
}

void System::showCommandsAdmin() const
{
	std::cout << "addadmin" << std::endl;
	std::cout << "addplayer" << std::endl;
	std::cout << "deleteplayer" << std::endl;
	std::cout << "showall" << std::endl;
	std::cout << "addhero" << std::endl;
	std::cout << "logout" << std::endl;
	std::cout << "clearconsole" << std::endl;
	std::cout << "endgame" << std::endl;
	std::cout << "load" << std::endl;
	std::cout << "save" << std::endl;
}

void System::showCommandsPlayer() const
{
	std::cout << "deleteme" << std::endl;
	std::cout << "showplayers" << std::endl;
	std::cout << "showmarket" << std::endl;
	std::cout << "buyhero" << std::endl;
	std::cout << "showleaderboard" << std::endl;
	std::cout << "attack" << std::endl;
	std::cout << "makedefensive" << std::endl;
	std::cout << "makeattacking" << std::endl;
	std::cout << "logout" << std::endl;
	std::cout << "clearconsole" << std::endl;
}

void System::clearConsole() const
{
	std::cout << "\x1B[2J\x1B[H";
}

void System::deleteMe()
{
	for (size_t i = 0; i < storage.heroes.getSize(); i++)
	{
		if (storage.heroes[i].getOwner() == currentPlayer->getUsername())
		{
			MyString def("Default");
			storage.heroes[i].setOwner(def);
		}
	}
	for (size_t i = 0; i < storage.players.getSize(); i++)
	{
		if (&storage.players[i] == currentPlayer)
		{
			storage.players.popAt(i);
			return;
		}
	}
}

void System::buyHero()
{
	MyString data("");
	storage.printMarket();
	while (true)
	{
		std::cout << "Enter hero nickname: ";
		std::cin >> data;
		if (data == MyString("exit")) return;
		for (size_t i = 0; i < storage.heroes.getSize(); i++)
		{
			if (storage.heroes[i].getNickname() == data && storage.heroes[i].isAlive() && storage.heroes[i].isAvailable())
			{
				if (currentPlayer->getMoney() < storage.heroes[i].getPrice())
				{
					std::cout << "You don't have enough money" << std::endl;
					return;
				}
				storage.heroes[i].setOwner(currentPlayer->getUsername());
				storage.heroes[i].setAvailable(false);
				currentPlayer->removeMoney(storage.heroes[i].getPrice());
				std::cout << "Hero bought successfully" << std::endl;
				return;
			}
		}
	}
}

void System::showLeaderboard()
{
	if (storage.players.getSize() == 0) return;
	size_t n = storage.players.getSize();
	size_t* array = new size_t[n];
	for (size_t i = 0; i < n; i++)
		array[i] = i;

	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = 0; j < n - i - 1; j++) {
			if (storage.players[array[j]].getMoney() < storage.players[array[j + 1]].getMoney())
			{
				size_t temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
		for (size_t i = 0; i < n; i++)
			std::cout << i + 1 << ". " << storage.players[array[i]].getUsername() << " Balance: " << storage.players[array[i]].getMoney() << std::endl;
		delete[] array;
}

void System::attackPlayer() 
{
	Player* otherPlayer = nullptr;
	MyString data("");
	while (true)
	{
		storage.showOther(currentPlayer);
		std::cout << "Enter enemy username: ";
		std::cin >> data;
		if (data == MyString("exit")) return;

		for (size_t i = 0; i < storage.players.getSize(); i++)
		{
			if (storage.players[i].getUsername() == data)
			{
				otherPlayer = &storage.players[i];
				break;
			}
		}
		if (otherPlayer) break;
		clearConsole();
		std::cout << "No such player" << std::endl;
	}
	clearConsole();
	storage.printHeroes(currentPlayer->getUsername());
	while (true)
	{
		storage.printHeroes(currentPlayer->getUsername());
		std::cout << "Enter your hero nickname: ";
		std::cin >> data;
		if (data == MyString("exit")) return;

		for (size_t i = 0; i < storage.heroes.getSize(); i++)
		{
			if (storage.heroes[i].getNickname() == data)
			{
				if (!storage.hasHeroes(otherPlayer->getUsername()))
				{
					attack(currentPlayer, otherPlayer, &storage.heroes[i], nullptr);
					return;
				}
				while (true)
				{
					storage.printHeroes(otherPlayer->getUsername());
					std::cout << "Enter enemy hero nickname: ";
					std::cin >> data;
					if (data == MyString("exit")) return;

					for (size_t j = 0; j < storage.heroes.getSize(); j++)
					{
						if (storage.heroes[j].getNickname() == data && storage.heroes[j].getOwner()==otherPlayer->getUsername())
						{
							attack(currentPlayer, otherPlayer, &storage.heroes[i], &storage.heroes[j]);
							return;
						}
					}

					clearConsole();
					std::cout << "No such hero" << std::endl;
				}
			}
		}
		
		clearConsole();
		std::cout << "No such hero" << std::endl;
	}
}

void System::makeDefensive() 
{
	MyString data("");
	while (true)
	{
		std::cout << "Enter hero nickname: ";
		std::cin >> data;
		if (data == MyString("exit")) return;

		for (size_t i = 0; i < storage.heroes.getSize(); i++)
		{
			if (storage.heroes[i].getNickname() == data)
			{
				storage.heroes[i].setToDefence();
				return;
			}
		}
		clearConsole();
		std::cout << "No such hero" << std::endl;
	}
	
}

void System::makeAttacking()
{
	MyString data("");
	while (true)
	{
		std::cout << "Enter hero nickname: ";
		std::cin >> data;
		if (data == MyString("exit")) return;

		for (size_t i = 0; i < storage.heroes.getSize(); i++)
		{
			if (storage.heroes[i].getNickname() == data)
			{
				storage.heroes[i].setToAttack();
				return;
			}
		}
		clearConsole();
		std::cout << "No such hero" << std::endl;
	}
}

void System::addAdmin()
{
	storage.admins.pushBack(Admin(1));
}

void System::addPlayer()
{
		storage.players.pushBack(Player(1));
}

void System::deletePlayer()
{
	MyString data("");
	while (true)
	{
		std::cout << "Enter player username: ";
		std::cin >> data;
		if (data == MyString("exit")) return;

		for (size_t i = 0; i < storage.players.getSize(); i++)
		{
			if (storage.players[i].getUsername() == data)
			{
				storage.players.popAt(i);
				return;
			}
		}
		clearConsole();
		std::cout << "No such player" << std::endl;
	}
}

void System::showAll()
{
	storage.printAdmins();
	storage.printPlayers();
}

void System::addHero()
{
	MyString data("");
	while (true)
	{
		std::cout << "Enter hero type(graveyard/new): ";
		std::cin >> data;
		if (data == MyString("exit")) return;

		if (data == MyString("graveyard"))
		{
			storage.printGraveyard();
			while (true)
			{
				std::cout << "Enter hero nickname: ";
				std::cin >> data;
				if (data == MyString("exit")) return;

				for (size_t i = 0; i < storage.heroes.getSize(); i++)
				{
					if (storage.heroes[i].getNickname() == data&&!storage.heroes[i].isAlive())
					{
						storage.heroes[i].setAlive(1);
						storage.heroes[i].setAvailable(1);
						return;
					}
				}
				clearConsole();
				std::cout << "No such hero" << std::endl;
			}
			return;
		}
		if (data == MyString("new"))
		{
			storage.heroes.pushBack(Hero(1));
			return;
		}
		clearConsole();
		std::cout << "Incorrect hero type" << std::endl;

	}
}


