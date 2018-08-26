
#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <sstream>

using namespace std;

class Pokemon
{
	public:
		// Same as hwPKM1
		enum PokeType {Normal, Fighting, Flying, Poison};


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
		//
		// Hint: check out the ostringstream class in <sstream>
		string summary();


		// Same as hwPKM1
		Pokemon(string name, int ndex, PokeType type1);
		Pokemon(string name, int ndex, PokeType type1, PokeType type2);
		string name();
		int Ndex();
		PokeType type1();
		bool is_multitype();
		PokeType type2();
		float damage_multiplier(PokeType attack_type);

	private:
                // Same as hwPKM1
		int _ndex;       
		string _name;    
		PokeType types[2];
		int type_count;    
};

// Returns a string corresponding to the type. Examples:
// 1. type_to_string(Pokemon::Poison) returns "Poison".
// 2. type_to_string(Pokemon::Normal) returns "Normal". 
string type_to_string(Pokemon::PokeType t);

// Returns the type corresponding to a string. Examples:
// 1. string_to_type("Poison") returns Pokemon::Poison.
// 2. string_to_type("Normal") returns Pokemon::Normal.
// 3. Allowed to return anything if given string doesn't 
//    correspond to a Pokemon type.
Pokemon::PokeType string_to_type(string s);

#endif

