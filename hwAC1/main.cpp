
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <chrono>
#include "autocompleter.h"

using namespace std;
using namespace chrono;

inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


string random_string(int length)
{
	string s;
	for (int i = 0; i < length; ++i)
		s += 'a' + (rand() % 26); 
	return s;
} 

void interactive_mode()
{
	Autocompleter dictionary;

	// Fill autocompleter with words
	ifstream f;
	f.open("words_10000.txt", ios::in);
	assert(f.is_open()); // If this fails, you're missing above file
	string line;
	while (getline(f, line))
		dictionary.add(line);
	f.close();

	string results[5];
	while (cin)
	{
		string line;
		getline(cin, line);
		dictionary.completions(line, results);
		for (int i = 0; i < 5; ++i)
			if (results[i] != "") 
				cout << "    " << results[i] << endl; 
	}
	exit(0);
}

int main()
{
	srand(2017); // Initialize random number generation, e.g. rand()
	string results[5]; // Used to hold output suggestions in some tests


	// Uncomment line below to use your Autocompleter interactively.
	// Enter a string and press Enter - the autocompletions
	// results from the 10000 most common words are printed.
	// 
	//interactive_mode();


	// Test a small Autocompleter with animal names
	Autocompleter animals;
	test(animals.size() == 0);

	animals.add("aardvark");
	animals.add("albatross");
	animals.add("alpaca");
	animals.add("armadillo");
	animals.add("camel");
	animals.add("cat");
	animals.add("crocodile");
	animals.add("crow");
	animals.add("giraffe");
	animals.add("goat");
	animals.add("goose");
	animals.add("gorilla");
	test(animals.size() == 12);

	animals.add("gorilla"); // Already in the Autocompleter
	test(animals.size() == 12);

	test(animals.completion_count("a") == 4);
	test(animals.completion_count("al") == 2);
	test(animals.completion_count("cro") == 2);
	test(animals.completion_count("gir") == 1);
	test(animals.completion_count("go") == 3);

	test(animals.completion_count("") == 12);

	test(animals.completion_count("an") == 0);
	test(animals.completion_count("q") == 0);
	test(animals.completion_count("goat-billed carp") == 0);


	// Create an autocompleter of the 10000 most common
	// American English words and test for correctness.
	Autocompleter dictionary;

	// Fill autocompleter with words
	ifstream f;
	f.open("words_10000.txt", ios::in);
	assert(f.is_open()); // If this fails, you're missing above file
	string line;
	while (getline(f, line))
		dictionary.add(line);
	f.close();
	test(dictionary.size() == 9990); // There are some duplicates 

	test(dictionary.completion_count("bir") == 5);
	test(dictionary.completion_count("hap") == 6);	
	test(dictionary.completion_count("program") == 7);
	test(dictionary.completion_count("foo") == 8);


	// Test completions() on animals Autocompleter already made.
	animals.completions("a", results);
	test(results[0] == "aardvark");
	test(results[1] == "albatross");
	test(results[2] == "alpaca");
	test(results[3] == "armadillo");
	test(results[4] == "");

	animals.completions("al", results);
	test(results[0] == "albatross");
	test(results[1] == "alpaca");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");

	animals.completions("cro", results);
	test(results[0] == "crocodile");	
	test(results[1] == "crow");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");

	animals.completions("gir", results);
	test(results[0] == "giraffe");
	test(results[1] == "");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");

	animals.completions("go", results);
	test(results[0] == "goat");
	test(results[1] == "goose");
	test(results[2] == "gorilla");	
	test(results[3] == "");
	test(results[4] == "");

	animals.completions("", results);
	test(results[0] == "aardvark");
	test(results[1] == "albatross");
	test(results[2] == "alpaca");
	test(results[3] == "armadillo");
	test(results[4] == "camel");

	animals.completions("an", results);
	test(results[0] == "");
	test(results[1] == "");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");

	animals.completions("q", results);
	test(results[0] == "");
	test(results[1] == "");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");

	animals.completions("goat-billed carp", results);
	test(results[0] == "");
	test(results[1] == "");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");


	// Test completions() on dictionary Autocompleter already made.
	dictionary.completions("bir", results);
	test(results[0] == "bird");
	test(results[1] == "birds");
	test(results[2] == "birmingham");
	test(results[3] == "birth");
	test(results[4] == "birthday");

	dictionary.completions("hap", results);
	test(results[0] == "happen");
	test(results[1] == "happened");
	test(results[2] == "happening");
	test(results[3] == "happens");
	test(results[4] == "happiness");

	dictionary.completions("program", results);
	test(results[0] == "program");
	test(results[1] == "programme");
	test(results[2] == "programmer");
	test(results[3] == "programmers");
	test(results[4] == "programmes");

	dictionary.completions("foo", results);
	test(results[0] == "foo");
	test(results[1] == "food");
	test(results[2] == "foods");
	test(results[3] == "fool");
	test(results[4] == "foot");


	// Test Autocompleter for completing 100000 words
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < 100000; ++i)
		dictionary.completion_count(random_string(5));
	system_clock::time_point end = system_clock::now();
	float dur = duration<float>(end - start).count();

	cout << "100000 calls to completion_count() took "; 
	cout << dur << " seconds." << endl;
	test(dur < 3.0);	

	start = system_clock::now();
	for (int i = 0; i < 100000; ++i)
		dictionary.completions(random_string(5), results);
	end = system_clock::now();
	dur = duration<float>(end - start).count();

	cout << "100000 calls to completions() took "; 
	cout << dur << " seconds." << endl;
	test(dur < 3.0);	

	cout << "Assignment complete." << endl;
}



