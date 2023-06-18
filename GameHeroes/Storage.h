#pragma once
#include "Hero.h"
#include "Admin.h"
#include "Player.h"
#include "Vector.hpp"

class Storage
{
	
public: 
	Storage() = default;

	Storage(const Storage& other) = delete;
	Storage* operator=(const Storage& other) = delete;

	

	Vector<Player> players;
	Vector<Admin> admins;
	Vector<Hero> heroes;

	bool deletePlayer(const MyString& username);
	void printPlayers();
	void printAdmins() const;
	void printHeroes(MyString& username) const;
	void printMarket() const;
	void printGraveyard() const;
	bool isMarketEmpty() const;
	bool hasHeroes(MyString& username);
	void showOther(Player* cur);
};

