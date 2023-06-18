#pragma once
#include "Storage.h"

const size_t MAX_MOVES = 3;
const size_t ATTACK_EMPTY_REWARD = 500;
const size_t EQUAL_POWER_LOSE = 250;
const size_t DEFEND_MONEY = 350;
const size_t END_OF_ROUND = 500;

class System
{
private:
	Player* firstPlayer = nullptr;


	size_t numberOfMoves = MAX_MOVES;
	Storage storage;				

	void getLogin();

	Admin* currentAdmin = nullptr;		//outer resource
	Player* currentPlayer = nullptr;    //outer resource

	Admin* adminLogin();
	Player* playerLogin();
	
	void showCommandsAdmin() const;   
	void showCommandsPlayer() const;   
	void clearConsole() const;

	//Player fumctions
	void deleteMe();
	void buyHero();							
	void showLeaderboard();					
	void attackPlayer();
	void makeDefensive();
	void makeAttacking();

	//Admin functions
	void addAdmin();
	void addPlayer();
	void deletePlayer();
	void showAll();
	void addHero();

	void logout();
	void attack(Player* left, Player* right, Hero* leftHero, Hero* rightHero);

	void endOfRound();

public:
	void start_game(); 

	void write(std::ofstream& os) const;
	void read(std::ifstream& is);
};

