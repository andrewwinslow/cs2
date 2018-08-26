
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
		enum PokeType {Normal, Fighting, Flying, Poison};

		// Initializes a single-type Pokemon using the information provided
		Pokemon(string name, int ndex, PokeType type1);

		// Initializes a multi-type Pokemon using the information provided
		Pokemon(string name, int ndex, PokeType type1, PokeType type2);

		// Returns the name of the pokemon 
		string name();

		// Returns the Ndex (national index) of the Pokemon
		int Ndex();

		// Returns the first (and possibly only) type of the Pokemon
		PokeType type1();

		// Returns whether the Pokemon has multiple types
		bool is_multitype();

		// If the Pokemon has two types, returns the second type of the Pokemon.
		// Otherwise returns the Pokemon's only type.
		PokeType type2();


		// The damage multiplier of a move against a Pokemon 
		// is the product of the multiplier for each of the Pokemon's types.
		// Reference: http://bulbapedia.bulbagarden.net/wiki/Type/Type_chart#Generation_I 
                //
		// Normal attacks have multiplier 1.0 against all Pokemon types.
		// Fighting attacks have multipliers:
                // -2.0 against Normal Pokemon.
                // -0.5 against Flying and Poison Pokemon.
                // -1.0 against Fighting Pokemon.
		// Flying attacks have multipliers: 
                // -1.0 against Normal, Flying, and Poison Pokemon.
                // -2.0 against Fighting.
		// Poison attacks have multipliers:
                // -1.0 against Normal, Fight, and Flying Pokemon.
                // -0.5 against Poison.
                // 
                // Example 1: a Fighting attack against a Poison Pokemon.
                // Damage multipler is 0.5.
                //
		// Example 2: a Fighting attack against a Normal and Poison Pokemon.
                // Damage multiplier is 2.0 * 0.5 = 1.0.
		//
		// Example 3: a Flying attack against a Normal and Fighting Pokemon.
                // Damage multiplier is 1.0 * 2.0 = 2.0.
                //
		// Returns the damage multiplier against this Pokemon 
		// from an attack of the parameter type.
		float damage_multiplier(PokeType attack_type);

	private:
		int _ndex;         // Stores the Pokemon's Ndex
		string _name;      // Stores the Pokemon's name 
		PokeType types[2]; // Stores the Pokemon's types (1 or 2 of them)
		int type_count;    // Stores how many types the Pokemon has
};

#endif

