#pragma once
#include "User.h"

const size_t DEFAULT_MONEY = 1000;

class Player : public User
{
private:
    size_t _money = DEFAULT_MONEY;
public:
    
    Player() : User() {};
    Player(int dummy) : User(1) {}

    bool hasPrivillages() const override;

    size_t getMoney() const;

    void addMoney(size_t money);
    void removeMoney(size_t money);

    void write(std::ofstream& os) const override;
    void read(std::ifstream& is) override;
};

