
#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon
{
	public:
		// This works like a custom type with just four values.
		// Inside Pokemon methods, reference them by their names, e.g.:
		// "if (x == Fighting)", "if (y != Poison)", etc.
		enum Type {Normal, Fighting, Flying, Poison};

		// Initializes a single-type Pokemon using the information provided
		Pokemon(string name, int ndex, Type type1);

		// Initializes a multi-type Pokemon using the information provided
		Pokemon(string name, int ndex, Type type1, Type type2);

		// Returns the name of the pokemon 
		string name();
		// Returns the Ndex (national index) of the Pokemon
		int Ndex();
		// Returns the first (and possibly only) type of the Pokemon
		Type type1();
		// Returns whether the Pokemon has multiple types
		bool is_multitype();
		// Returns the second type of the Pokemon (if it has one)
		// and otherwise the Pokemon's only type
		Type type2();

		// The damage multiplier of a move against a Pokemon 
		// is the product of the multiplier for each of the Pokemon's types.
		// Reference: http://bulbapedia.bulbagarden.net/wiki/Type/Type_chart#Generation_I 

		// Example 1: a move with a 2.0 multiplier against Fighting and Flying Pokemon
		// has a 4.0 multiplier against a Pokemon that is both Fighting and Flying. 
		
		// Example 2: a move with a 0.5 multiplier against Flying and Poison Pokemon
		// has a 0.5 multiplier against a Pokemon that is both Flying and Poison.

		// Normal moves: 1.0 against all Pokemon types.
		// Fighting moves: 2.0 against Normal, 0.5 against Flying and Poison, 1.0 against Fighting.
		// Flying moves: 1.0 against all types except Fighting, 2.0 against Fighting.
		// Poison moves: 1.0 against all types except Poison, 0.5 against Poison.

		// Returns the damage multiplier against this Pokemon 
		// for a move of the parameter type.
		float damage_multiplier(Type attack_type);

	private:
		int _ndex;       // Stores the Pokemon's Ndex
		string _name;    // Stores the Pokemon's name 
		Type types[2];  // Stores the Pokemon's types (1 or 2 of them)
		int type_count; // Stores how many types the Pokemon has
};

#endif

