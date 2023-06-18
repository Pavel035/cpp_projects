#include "Hero.h"

Hero::Hero(int dummy)
{
    std::cout << "Enter first name: "; std::cin >> firstName;
    std::cout << "Enter last name: "; std::cin >> lastName;

    std::cout << "Enter nickname: "; std::cin >> nickname;

    element = getElement();

    std::cout << "Enter power: "; std::cin >> power;
    std::cout << "Enter price: "; std::cin >> price;
    owner = MyString("Default");
}

void Hero::setToDefence()
{
    is_defending = 1;
}

void Hero::setToAttack()
{
    is_defending = 0;
}

const MyString& Hero::getOwner() const
{
    return owner;
}

void Hero::setOwner(MyString& _owner)
{
    owner = _owner;
}



const MyString& Hero::getNickname() const
{
    return nickname;
}

const MyString Hero::getElement() const
{
    switch (element)
    {
    case 0: return MyString("Fire");
    case 1: return MyString("Earth");
    case 2: return MyString("Water");
    }
}

bool Hero::isAvailable() const
{
    return available;
}

size_t Hero::getPrice() const
{
    return price;
}

bool Hero::isAlive() const
{
    return alive;
}

size_t Hero::getPower() const
{
    return power;
}


void Hero::setAvailable(bool a)
{
    available = a;
}


int Hero::getIntElement() const
{
    return element;
    
}

void Hero::write(std::ofstream& os) const
{
    firstName.write(os);
    lastName.write(os);
    nickname.write(os);
    os.write((const char*)&element, sizeof(Elements));
    os.write((const char*)&power, sizeof(size_t));
    os.write((const char*)&price, sizeof(size_t));
    os.write((const char*)&is_defending, sizeof(bool));
    owner.write(os);
    os.write((const char*)&available, sizeof(bool));
    os.write((const char*)&alive, sizeof(bool));
}

void Hero::read(std::ifstream& is)
{
    firstName.read(is);
    lastName.read(is);
    nickname.read(is);
    is.read((char*)&element, sizeof(Elements));
    is.read((char*)&power, sizeof(size_t));
    is.read((char*)&price, sizeof(size_t));
    is.read((char*)&is_defending, sizeof(bool));
    owner.read(is);
    is.read((char*)&available, sizeof(bool));
    is.read((char*)&alive, sizeof(bool));
}



bool Hero::getDefending() const
{
    return is_defending;
}



void Hero::setAlive(bool a)
{
    alive = a;
}



Elements Hero::getElement()
{
    MyString data;
    while (true)
    {
        std::cout << "Enter element(Fire, Earth, Water): ";
        std::cin >> data;
        if (data == "Fire") return Elements::fire;
        if (data == "Earth") return Elements::earth;
        if (data == "Water") return Elements::water;
    }
}
