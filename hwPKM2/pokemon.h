
#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon
{
	public:
		// Same as hwPKM1
		enum Type {Normal, Fighting, Flying, Poison};


		// A summary string is a single string that contains 
		// all of a Pokemon's information.
		// 
		// A Pokemon with one type and Ndex 1 has 
		// a summary string of the form:
		// "Name, #001, type1,"
		// 
		// Similarly, a Pokemon with two types and Ndex 2 has 
		// a summary string of the form:
		// "Name, #002, type1, type2," 
		
		// Initializes a Pokemon from a summary string
		//
		// Hint: check out the stoi function in <string>
		Pokemon(string summary);

		// Returns the summary string of the Pokemon
		string summary();


		// Same as hwPKM1
		Pokemon(string name, int ndex, Type type1);
		Pokemon(string name, int ndex, Type type1, Type type2);
		string name();
		int Ndex();
		Type type1();
		bool is_multitype();
		Type type2();
		float damage_multiplier(Type attack_type);

	private:
		int _ndex;       // Stores the Pokemon's Ndex
		string _name;    // Stores the Pokemon's name 
		Type types[2];   // Stores the Pokemon's types (1 or 2 of them)
		int type_count;  // Stores how many types the Pokemon has
};

// Returns a string corresponding to the type. Examples:
// 1. type_to_string(Pokemon::Poison) returns "Poison".
// 2. type_to_string(Pokemon::Normal) returns "Normal". 
string type_to_string(Pokemon::Type t);

// Returns the type corresponding to a string. Examples:
// 1. string_to_type("Poison") returns Pokemon::Poison.
// 2. string_to_type("Normal") returns Pokemon::Normal.
// 3. Allowed to return anything if given string doesn't 
//    correspond to a Pokemon type.
Pokemon::Type string_to_type(string s);

#endif

