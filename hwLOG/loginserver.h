
#ifndef LOGINSERVER_H
#define LOGINSERVER_H

#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class LoginServer
{
	public:
		// Creates a new server with no accounts. 
		LoginServer();

		// Adds a user to the system with the 
		// parameter username and password.
		// Returns false if the LoginServer already has an
		// account with the parameter username. Otherwise returns true.
		bool create_user(string username, string password);

		// Deletes a user from the system with the specified info.
		// Returns true if the parameter information was valid
		// (and the user was successfully deleted). 
		// Otherwise returns false.
		bool delete_user(string username, string password);

		// Returns the total number of accounts in the system.
		int total_user_count();

		// Tries to log in a user.
		// Returns true if there is a user with this password
		// that is not already logged in (i.e. whether login occurred).
		// Otherwise returns false.
		bool login(string username, string password);

		// Tries to log out a user.
		// Returns true if a user with this user name was logged in.
		// Otherwise returns false.
		bool logout(string username);

		// Returns true if a user with this name is logged in.
		// Otherwise returns false.
		bool is_logged_in(string username);

		// Returns the number of logged-in users.
		int active_user_count();

		// Logs out all users.
		void logout_everyone();

		// Changes a user's password.
		// Returns true if there is an account with the parameter 
		// username and password old_pw (i.e. the password changed).
		// Otherwise returns false.
		bool change_password(string username, string old_pw, 
			string new_pw);


	private:
		// Stores the usernames of logged-in users 
		unordered_set<string> S;

		// Stores the mapping from usernames to passwords.
		unordered_map<string, string> M;	
};

#endif

