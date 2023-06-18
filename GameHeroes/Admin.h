#pragma once
#include "User.h"


class Admin : public User
{
public:
    Admin() : User() {};
    Admin(MyString firstName, MyString lastName, MyString email, MyString username, MyString password) : User(firstName, lastName, email, username, password) {}
    Admin(int dummy) : User(1) {}

    bool hasPrivillages() const override;

};

