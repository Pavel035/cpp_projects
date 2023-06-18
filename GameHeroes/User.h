#pragma once
#include "MyString.h"
#include <iostream>
class User
{
private:
	MyString _firstName;
	MyString _lastName;

	MyString _email;

	MyString _username;
	MyString _password;

	

public:
	User() = default;
	User(MyString _firstName, MyString _lastName, MyString _email, MyString _username, MyString _password);
	User(int dummy);

	virtual bool hasPrivillages() const;

	MyString& getUsername();
	const MyString& getPassword() const;

	void generateMe();
	bool isValidUsername(MyString name) const;
	bool isValidPassword(MyString pass) const;

	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getEmail() const;

	virtual void write(std::ofstream& os) const;
	virtual void read(std::ifstream& is);
};

