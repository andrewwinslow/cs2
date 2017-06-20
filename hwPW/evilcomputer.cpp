
#include <string>
#include <cstdlib>
#include <iostream>
#include "evilcomputer.h"

using namespace std;

EvilComputer :: EvilComputer(string dave_pw, string mr_mean_pw, string ms_chief_pw, string dr_evil_pw)
{
	for (int i = 0; i < 5; ++i)
		hacked[i] = false;
	passwords[index("Guest")] = "password123";
	passwords[index("Dave")] = dave_pw;
	passwords[index("Mr. Mean")] = mr_mean_pw;
	passwords[index("Ms. Chief")] = ms_chief_pw;
	passwords[index("Dr. Evil")] = dr_evil_pw;
}

EvilComputer :: EvilComputer()
{
	for (int i = 0; i < 5; ++i)
		hacked[i] = false;
	
	passwords[index("Guest")] = "password123";

	string password;
	int length;

	password = "";
	while (password.length() < 4)
		password += '0' + (rand() % 10);
	passwords[index("Dave")] = password;

	password = "";
	length = 1 + rand() % 8;
	while (password.length() < length)
	{
		if (rand() % 2)
			password += 'g';
		else
			password += 'r';
	}
	passwords[index("Mr. Mean")] = password;

	password = "haha";
	length = 1 + rand() % 8;
	while (password.length() < length)
		password += random_char();
	passwords[index("Ms. Chief")] = password;

	password = "";
	length = 4 + rand() % 5;
	while (password.length() < length - 4)
		password += random_char();
	if (rand() % 2 == 0)
		password = "gato" + password; 
	else
		password = password + "gato";
	passwords[index("Dr. Evil")] = password;
}

char EvilComputer :: random_char()
{
	char c = rand() % 36;
	if (c < 10)
		c += 48;
	else
		c += (97-10);
	return c;
}

bool EvilComputer :: guess(string user, string guess)
{
	int user_index = index(user);
	if (user_index == -1)
		return false;

	if (guess != passwords[user_index])
                return false;
        hacked[user_index] = true;
        return true;
}

bool EvilComputer :: is_hacked(string user)
{
	return hacked[index(user)];
}

int EvilComputer :: index(string user)
{
	if (user == "Mr. Mean")
		return 0;
	else if (user == "Ms. Chief")
		return 1;
	else if (user == "Dr. Evil")
		return 2;
	else if (user == "Dave")
		return 3;
	else if (user == "Guest")
		return 4;
	return -1;
}




