
#ifndef LOGINSERVER_H
#define LOGINSERVER_H

#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class LoginServer
{
	public:
		// Creates a new server with no accounts 
		LoginServer();

		// Adds a user to the system with the specified info.
		// Returns whether there was not already an 
		// account with that username.
		bool create_user(string username, string password, int id);

		// Deletes a user from the system with the specified info.
		// Returns whether the user existed and had the
		// the given password.
		bool delete_user(string username, string password);

		// Returns the total number of users that 
		// exist within the system (logged in or not).
		int total_user_count();

		// Tries to log in a user.
		// Returns whether there's a user with this password
		// that is not already logged in.
		bool login(string username, string password);

		// Tries to log out a user.
		// Returns whether this user was logged in.
		bool logout(string username);

		// Returns whether a user with this name is logged in.
		bool is_logged_in(string username);

		// Returns the number of logged-in users.
		int active_user_count();

		// Logs out all users.
		void logout_everyone();

		// Tries to change a user's password.
		// Returns whether there was a user with the given old password.
		bool change_password(string username, string old_pw, 
			string new_pw);


	private:
		// A helper class that stores a user's information
		class UserInfo
		{
			public:
				string password;
				int ID;
		};

		// Stores the usernames of logged-in users 
		set<string> L;

		// Stores the mapping from usernames to
		// account information (including password)
		unordered_map<string, UserInfo> A;	
};

#endif

