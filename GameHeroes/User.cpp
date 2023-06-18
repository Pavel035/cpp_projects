#include "User.h"

const MyString& User::getFirstName() const
{
	return _firstName;
}

const MyString& User::getLastName() const
{
	return _lastName;
}

const MyString& User::getEmail() const
{
	return _email;
}

void User::write(std::ofstream& os) const
{
	_firstName.write(os);
	_lastName.write(os);

	_email.write(os);

	_username.write(os);
	_password.write(os);
}

void User::read(std::ifstream& is)
{
	_firstName.read(is);
	_lastName.read(is);

	_email.read(is);

	_username.read(is);
	_password.read(is);
}



User::User(MyString firstName, MyString lastName, MyString email, MyString username, MyString password)
{
	_firstName = firstName;
	_lastName = lastName;
	_email = email;
	_username = username;
	_password = password;
}

User::User(int dummy)
{
	generateMe();
}

bool User::hasPrivillages() const
{
	return false;
}

 MyString& User::getUsername() 
{
	return _username;
}

const MyString& User::getPassword() const
{
	return _password;
}

void User::generateMe()
{
	std::cout << "Enter first name: "; std::cin >> _firstName;
	std::cout << "Enter last name: "; std::cin >> _lastName;

	std::cout << "Enter email: "; std::cin >> _email;

	MyString data("0");
	while (true)
	{
		std::cout << "Enter username: "; std::cin >> data;;
		if (!isValidUsername(data))
			std::cout << "Invalid username" << std::endl;
		else break;
	}
	_username = data;
	while (true)
	{
		std::cout << "Enter password: "; std::cin >> data;
		if (!isValidPassword(data))
			std::cout << "Invalid password" << std::endl;
		else break;
	}
	_password = data;
}

bool User::isValidUsername(MyString name) const
{
	if (name.length() > 16) return false;
	for (size_t i = 0; i < name.length(); i++)
	{
		if ((int)name[i] < 97 || (int)name[i] > 122)
			return false;
	}
	return true;
}

bool User::isValidPassword(MyString pass) const
{
	bool crit1 = 0, crit2 = 0, crit3 = 0;
	for (size_t i = 0; i < pass.length(); i++)
	{
		if ((int)pass[i] >= 65 && (int)pass[i] <= 90) crit1 = 1;
		if ((int)pass[i] >= 97 && (int)pass[i] <= 122) crit2 = 1;
		if ((int)pass[i] >= 48 && (int)pass[i] <= 57) crit3 = 1;
	}
	return crit1 && crit2 && crit3;
}
