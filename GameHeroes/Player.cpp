#include "Player.h"

bool Player::hasPrivillages() const
{
    return false;
}

size_t Player::getMoney() const
{
    return _money;
}

void Player::addMoney(size_t money)
{
    _money += money;
}

void Player::removeMoney(size_t money)
{
    if (money >= _money)
        _money = 0;
    else _money -= money;
}

void Player::write(std::ofstream& os) const
{
    this->User::write(os);
    os.write((const char*)&_money, sizeof(size_t));
}

void Player::read(std::ifstream& is)
{
    this->User::read(is);
    is.read((char*)&_money, sizeof(size_t));
}

