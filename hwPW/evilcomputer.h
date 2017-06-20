
#ifndef EVILCOMPUTER_H
#define EVILCOMPUTER_H

#include <string>

using namespace std;


class EvilComputer
{
	public:
		// Creates a new evil computer with random passwords.
		EvilComputer();

		// Creates a new evil computer with specific passwords.
		EvilComputer(string dave_pw, string mr_mean_pw, string ms_chief_pw, string dr_evil_pw);

		// Guess a password for an agent.
		// Returns whether the password guessed is correct.
		bool guess(string user, string guess);

		// Returns whether an agent's password has been correctly guessed.
		bool is_hacked(string user);

	private:
		int index(string user);
		char random_char();

		string passwords[5];
		bool hacked[5];
};

#endif

