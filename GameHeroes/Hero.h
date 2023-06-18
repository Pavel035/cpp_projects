#pragma once
#include "MyString.h"
#include "Player.h"
enum Elements
{
	fire = 0,
	earth = 1,
	water = 2,
};
class Hero
{
	MyString firstName;
	MyString lastName;
	MyString nickname;
	Elements element;
	size_t power;
	size_t price;
	bool is_defending = 0;
	MyString owner;
	
	bool available = 1;   //available in market
	bool alive = 1;	  //is in graveyard


	Elements getElement();
public:
	Hero(int dummy);
	Hero() = default;
	

	void setToDefence();
	void setToAttack();

	const MyString& getOwner() const;
	void setOwner(MyString& _owner);

	const MyString& getNickname() const;
	const MyString getElement() const;
	bool isAvailable() const;
	bool isAlive() const;

	void setAvailable(bool a);
	void setAlive(bool a);

	size_t getPrice() const;
	size_t getPower() const;

	bool getDefending() const;
	int getIntElement() const;

	void write(std::ofstream& os) const;
	void read(std::ifstream& is);
};

