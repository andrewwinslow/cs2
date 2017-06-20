
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <fstream>
#include "pokedex.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	// ***** Test Pokemon *****


	// Test type_to_string()
	test(type_to_string(Pokemon::Normal) == "Normal");
	test(type_to_string(Pokemon::Fighting) == "Fighting");
	test(type_to_string(Pokemon::Flying) == "Flying");
	test(type_to_string(Pokemon::Poison) == "Poison");

	
	// Test string_to_type()
	test(string_to_type("Normal") == Pokemon::Normal); 
	test(string_to_type("Fighting") == Pokemon::Fighting); 
	test(string_to_type("Flying") == Pokemon::Flying); 
	test(string_to_type("Poison") == Pokemon::Poison); 
	string_to_type("Sleepy");


	// Test string-based constructor via
	// checking that instance variables were set correctly.
	Pokemon bouffalant("Bouffalant, #626, Normal,");
	Pokemon mankey("Mankey, #056, Fighting,");
	Pokemon tornadus("Tornadus, #641, Flying,");
	Pokemon grimer("Grimer, #088, Poison,");
	Pokemon timburr("Timburr, #532, Fighting,");
	Pokemon tonkamon("Tonkamon, #001, Flying,");
	
	Pokemon pidgey("Pidgey, #016, Normal, Flying,");
	Pokemon fletchling("Fletchling, #661, Normal, Flying,");
	Pokemon zubat("Zubat, #041, Poison, Flying,");
	Pokemon toxicroak("Toxicroak, #454, Poison, Fighting,");
	Pokemon golbat("Golbat, #042, Poison, Flying,");
	Pokemon hoothoot("Hoothoot, #163, Normal, Flying,");

	// Check that _name was set correctly 
	test(bouffalant.name() == "Bouffalant");
	test(mankey.name() == "Mankey");
	test(tornadus.name() == "Tornadus");
	test(grimer.name() == "Grimer");
	test(timburr.name() == "Timburr");
	test(tonkamon.name() == "Tonkamon");

	test(pidgey.name() == "Pidgey");
	test(fletchling.name() == "Fletchling");
	test(zubat.name() == "Zubat");
	test(toxicroak.name() == "Toxicroak");
	test(golbat.name() == "Golbat");	
	test(hoothoot.name() == "Hoothoot");

	// Check that _ndex was set correctly 
	test(bouffalant.Ndex() == 626);
	test(mankey.Ndex() == 56);
	test(tornadus.Ndex() == 641);
	test(grimer.Ndex() == 88);
	test(timburr.Ndex() == 532);
	test(tonkamon.Ndex() == 1);

	test(pidgey.Ndex() == 16);
	test(fletchling.Ndex() == 661);
	test(zubat.Ndex() == 41);
	test(toxicroak.Ndex() == 454);
	test(golbat.Ndex() == 42);
	test(hoothoot.Ndex() == 163);

	// Check that types were set correctly
	test(bouffalant.type1() == Pokemon::Normal);
	test(!bouffalant.is_multitype());

	test(mankey.type1() == Pokemon::Fighting);	
	test(!mankey.is_multitype());

	test(tornadus.type1() == Pokemon::Flying);
	test(!tornadus.is_multitype());

	test(grimer.type1() == Pokemon::Poison);
	test(!grimer.is_multitype());

	test(timburr.type1() == Pokemon::Fighting);
	test(!timburr.is_multitype());

	test(tonkamon.type1() == Pokemon::Flying);
	test(!tonkamon.is_multitype());

	test(pidgey.type1() == Pokemon::Normal);
	test(pidgey.is_multitype());
	test(pidgey.type2() == Pokemon::Flying);
	
	test(fletchling.type1() == Pokemon::Normal);
	test(fletchling.is_multitype());
	test(fletchling.type2() == Pokemon::Flying);
	
	test(zubat.type1() == Pokemon::Poison);
	test(zubat.is_multitype());
	test(zubat.type2() == Pokemon::Flying);
	
	test(toxicroak.type1() == Pokemon::Poison);
	test(toxicroak.is_multitype());
	test(toxicroak.type2() == Pokemon::Fighting);
	
	test(golbat.type1() == Pokemon::Poison);
	test(golbat.is_multitype());
	test(golbat.type2() == Pokemon::Flying);

	test(hoothoot.type1() == Pokemon::Normal);
	test(hoothoot.is_multitype());
	test(hoothoot.type2() == Pokemon::Flying);
	

	// Test summary()	
	test(bouffalant.summary() == "Bouffalant, #626, Normal,");
	test(mankey.summary() == "Mankey, #056, Fighting,");
	test(tornadus.summary() == "Tornadus, #641, Flying,");
	test(grimer.summary() == "Grimer, #088, Poison,");
	test(timburr.summary() == "Timburr, #532, Fighting,");
	test(tonkamon.summary() == "Tonkamon, #001, Flying,");

	test(pidgey.summary() == "Pidgey, #016, Normal, Flying,");
	test(fletchling.summary() == "Fletchling, #661, Normal, Flying,");
	test(zubat.summary() == "Zubat, #041, Poison, Flying,");
	test(toxicroak.summary() == "Toxicroak, #454, Poison, Fighting,");
	test(golbat.summary() == "Golbat, #042, Poison, Flying,");
	test(hoothoot.summary() == "Hoothoot, #163, Normal, Flying,");




	// ***** Test Pokedex ***** 

	Pokedex d1;

	// Test add() and size()
	test(d1.size() == 0);
	d1.add(&bouffalant);
	test(d1.size() == 1);
	d1.add(&mankey);
	test(d1.size() == 2);
	d1.add(&tornadus);
	test(d1.size() == 3);
	d1.add(&grimer);
	test(d1.size() == 4);
	d1.add(&timburr);
	test(d1.size() == 5);
	d1.add(&tonkamon);
	test(d1.size() == 6);
	
	d1.add(&pidgey);
	test(d1.size() == 7);
	d1.add(&fletchling);
	test(d1.size() == 8);
	d1.add(&zubat);
	test(d1.size() == 9);
	d1.add(&toxicroak);
	test(d1.size() == 10);
	d1.add(&golbat);
	test(d1.size() == 11);
	d1.add(&hoothoot);
	test(d1.size() == 12);

	d1.add(&bouffalant);
	test(d1.size() == 12);
	d1.add(&hoothoot);	
	test(d1.size() == 12);


	// Test add(), lookup_by_Ndex()
	test(d1.lookup_by_Ndex(626) == &bouffalant);
	test(d1.lookup_by_Ndex(56) == &mankey);
	test(d1.lookup_by_Ndex(641) == &tornadus);
	test(d1.lookup_by_Ndex(88) == &grimer);
	test(d1.lookup_by_Ndex(532) == &timburr);
	test(d1.lookup_by_Ndex(1) == &tonkamon);
	test(d1.lookup_by_Ndex(16) == &pidgey);
	test(d1.lookup_by_Ndex(661) == &fletchling);
	test(d1.lookup_by_Ndex(41) == &zubat);
	test(d1.lookup_by_Ndex(454) == &toxicroak);
	test(d1.lookup_by_Ndex(42) == &golbat);
	test(d1.lookup_by_Ndex(163) == &hoothoot);

	test(d1.lookup_by_Ndex(12) == 0);
	test(d1.lookup_by_Ndex(34) == 0);
	test(d1.lookup_by_Ndex(567) == 0);


	// Test lookup_by_name()
	test(d1.lookup_by_name("Bouffalant") == &bouffalant);
	test(d1.lookup_by_name("Mankey") == &mankey);
	test(d1.lookup_by_name("Tornadus") == &tornadus);
	test(d1.lookup_by_name("Grimer") == &grimer);
	test(d1.lookup_by_name("Timburr") == &timburr);
	test(d1.lookup_by_name("Tonkamon") == &tonkamon);
	test(d1.lookup_by_name("Pidgey") == &pidgey);
	test(d1.lookup_by_name("Fletchling") == &fletchling);
	test(d1.lookup_by_name("Zubat") == &zubat);
	test(d1.lookup_by_name("Toxicroak") == &toxicroak);
	test(d1.lookup_by_name("Golbat") == &golbat);
	test(d1.lookup_by_name("Hoothoot") == &hoothoot);

	test(d1.lookup_by_name("Lemon") == 0);	
	test(d1.lookup_by_name("Fakemon") == 0);	
	test(d1.lookup_by_name("Notarealmon") == 0);	


	// Test remove()
	test(d1.size() == 12);
	test(d1.lookup_by_name("Bouffalant") == &bouffalant);
	test(d1.lookup_by_Ndex(626) == &bouffalant);
	test(d1.lookup_by_name("Zubat") == &zubat);
	test(d1.lookup_by_Ndex(41) == &zubat);
	test(d1.lookup_by_name("Hoothoot") == &hoothoot);
	test(d1.lookup_by_Ndex(163) == &hoothoot);

	d1.remove(&bouffalant);
	test(d1.size() == 11);
	test(d1.lookup_by_name("Bouffalant") == 0);
	test(d1.lookup_by_Ndex(626) == 0);

	d1.remove(&zubat);
	test(d1.size() == 10);
	test(d1.lookup_by_name("Zubat") == 0);
	test(d1.lookup_by_Ndex(41) == 0);

	d1.remove(&hoothoot);
	test(d1.size() == 9);
	test(d1.lookup_by_name("Hoothoot") == 0);
	test(d1.lookup_by_Ndex(163) == 0);

	test(d1.lookup_by_name("Mankey") == &mankey);
	test(d1.lookup_by_name("Tornadus") == &tornadus);
	test(d1.lookup_by_name("Grimer") == &grimer);
	test(d1.lookup_by_name("Timburr") == &timburr);
	test(d1.lookup_by_name("Tonkamon") == &tonkamon);
	test(d1.lookup_by_name("Pidgey") == &pidgey);
	test(d1.lookup_by_name("Fletchling") == &fletchling);
	test(d1.lookup_by_name("Golbat") == &golbat);
	test(d1.lookup_by_name("Toxicroak") == &toxicroak);
	

	// Test save() and load(). 
	// This will create and modify files on your computer 
	// in the directory where the program lives.

	// Delete any old pokedex1.txt still around
	remove("./pokedex1.txt");
	// Save Mankey, Tornadus, Grimer, Timburr, Tonkamon,
	//      Pidgey, Fletchling, Golbat, Toxicroak	
	d1.save("./pokedex1.txt"); 
	                           

	// Create a Pokedex with:
	// Mankey, Tornadus, Grimer, Timburr, Tonkamon,
	// Pidgey, Fletchling, Golbat, Toxicroak	
	Pokedex d2("./pokedex1.txt");

	test(d2.size() == 9);	

	test(d2.lookup_by_name("Bouffalant") == 0);

	Pokemon* p = d2.lookup_by_name("Mankey");
	test(p != 0);
	test(p->name() == mankey.name());
	test(p->Ndex() == mankey.Ndex());
	test(p->type1() == mankey.type1());
	test(p->is_multitype() == mankey.is_multitype());

	p = d2.lookup_by_name("Tornadus");
	test(p != 0);
	test(p->Ndex() == tornadus.Ndex());

	p = d2.lookup_by_name("Grimer");
	test(p != 0);
	test(p->Ndex() == grimer.Ndex());

	p = d2.lookup_by_name("Timburr");
	test(p != 0);
	test(p->Ndex() == timburr.Ndex());

	p = d2.lookup_by_name("Tonkamon");
	test(p != 0);
	test(p->Ndex() == tonkamon.Ndex());

	p = d2.lookup_by_name("Pidgey");
	test(p != 0);
	test(p->name() == pidgey.name());
	test(p->Ndex() == pidgey.Ndex());
	test(p->type1() == pidgey.type1());
	test(p->is_multitype() == pidgey.is_multitype());
	test(p->type2() == pidgey.type2());

	p = d2.lookup_by_name("Fletchling");
	test(p != 0);
	test(p->Ndex() == fletchling.Ndex());
	
	test(d2.lookup_by_name("Zubat") == 0);

	p = d2.lookup_by_name("Toxicroak");
	test(p != 0);
	test(p->Ndex() == toxicroak.Ndex());

	p = d2.lookup_by_name("Golbat");
	test(p != 0);
	test(p->Ndex() == golbat.Ndex());

	test(d2.lookup_by_name("Hoothoot") == 0);

		
	d2.add(&bouffalant);
	d2.add(&zubat);
	d2.add(&hoothoot);
	d2.remove(&mankey);
	d2.remove(&toxicroak);
	test(d2.size() == 10);


	// Save Bouffalant, Tornadus, Grimer, Timburr, Tonkamon,
	//      Pidgey, Fletchling, Zubat, Golbat, Hoothoot 	
	remove("./pokedex2.txt");
	d2.save("./pokedex2.txt");

	// Create a Pokedex with:
	// Bouffalant, Tornadus, Grimer, Timburr, Tonkamon,
	// Pidgey, Fletchling, Zubat, Golbat, Hoothoot 	
	Pokedex d3("./pokedex2.txt"); 	

	test(d3.size() == 10);

	p = d3.lookup_by_name("Bouffalant");
	test(p->name() == bouffalant.name());
	test(p->Ndex() == bouffalant.Ndex());
	test(p->type1() == bouffalant.type1());
	test(p->is_multitype() == bouffalant.is_multitype());

	test(d3.lookup_by_name("Mankey") == 0);

	p = d3.lookup_by_name("Tornadus");
	test(p != 0);
	test(p->Ndex() == tornadus.Ndex());

	p = d3.lookup_by_name("Grimer");
	test(p != 0);
	test(p->Ndex() == grimer.Ndex());

	p = d3.lookup_by_name("Timburr");
	test(p != 0);
	test(p->Ndex() == timburr.Ndex());

	p = d3.lookup_by_name("Tonkamon");
	test(p != 0);
	test(p->Ndex() == tonkamon.Ndex());

	p = d3.lookup_by_name("Pidgey");
	test(p != 0);
	test(p->name() == pidgey.name());
	test(p->Ndex() == pidgey.Ndex());
	test(p->type1() == pidgey.type1());
	test(p->is_multitype() == pidgey.is_multitype());
	test(p->type2() == pidgey.type2());
	
	p = d3.lookup_by_name("Fletchling");
	test(p != 0);
	test(p->Ndex() == fletchling.Ndex());
	
	p = d3.lookup_by_name("Zubat");
	test(p != 0);
	test(p->Ndex() == zubat.Ndex());

	p = d3.lookup_by_name("Golbat");
	test(p != 0);
	test(p->Ndex() == golbat.Ndex());

	test(d3.lookup_by_name("Toxicroak") == 0);

	p = d3.lookup_by_name("Hoothoot");
	test(p != 0);
	test(p->Ndex() == hoothoot.Ndex());


	ifstream f;
	f.open("./pokedex.txt");
	assert(f.is_open()); // If this fails, you're missing pokedex.txt
	f.close();
 
	Pokedex d4("./pokedex.txt");	
	test(d4.size() == 125);

	
	cout << "Assignment complete." << endl; 
}

