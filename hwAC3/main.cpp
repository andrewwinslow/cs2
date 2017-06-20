
#include <iostream>
#include <cstdlib>
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


// Used later for testing
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
	
	ifstream f;
	f.open("words_4400-w-freq.txt", ios::in);
	assert(f.is_open()); // If this fails, you're missing above file.
	string line;
	while (getline(f, line))
	{
		string s = line.substr(0, line.find(" "));
		int freq = atoi(line.substr(line.find(" ")+1).c_str());
		dictionary.add(s, freq);
	}
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
	// Setup
	srand(2017);
	string results[5];


	// Uncomment line below to use your Autocompleter interactively.
	// Enter a string and press Enter - the autocompletions
	// results from the 10000 most common words are printed.
	// 
	// interactive_mode();


	// Create a small Autocompleter with animal names
	Autocompleter animals;
	test(animals.size() == 0);

	animals.add("aardvark", 17);
	test(animals.size() == 1);
	animals.add("albatross", 18);
	test(animals.size() == 2);
	animals.add("alpaca", 25);
	test(animals.size() == 3);
	animals.add("armadillo", 42);
	test(animals.size() == 4);

	animals.add("camel", 31);
	test(animals.size() == 5);
	animals.add("cat", 231);
	test(animals.size() == 6);
	animals.add("crocodile", 95);
	test(animals.size() == 7);
	animals.add("crow", 162);
	test(animals.size() == 8);
	animals.add("giraffe", 32);
	test(animals.size() == 9);
	animals.add("goat", 171);
	test(animals.size() == 10);
	animals.add("goose", 154);
	test(animals.size() == 11);
	animals.add("gorilla", 63);
	test(animals.size() == 12);

	animals.add("gorilla", 63); // Already in the Autocompleter
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

	test(animals.most_frequent_completion("a") == "armadillo");
	test(animals.most_frequent_completion("al") == "alpaca");
	test(animals.most_frequent_completion("cro") == "crow");
	test(animals.most_frequent_completion("gir") == "giraffe");
	test(animals.most_frequent_completion("go") == "goat");

	test(animals.most_frequent_completion("an") == "");
	test(animals.most_frequent_completion("q") == "");
	test(animals.most_frequent_completion("") == "cat");
	test(animals.most_frequent_completion("goat-billed carp") == "");

	
	// Test an Autocompleter containing 4400
	// common American English words.
	Autocompleter dictionary;
	
	ifstream f;
	f.open("words_4400-w-freq.txt", ios::in);
	assert(f.is_open()); // If this fails, you're missing above file.
	string line;
	while (getline(f, line))
	{
		string s = line.substr(0, line.find(" "));
		int freq = atoi(line.substr(line.find(" ")+1).c_str());
		dictionary.add(s, freq);
	}
	f.close();
	test(dictionary.size() == 4354); // There are some duplicates 

	test(dictionary.completion_count("bir") == 3);
	test(dictionary.completion_count("hap") == 4);	
	test(dictionary.completion_count("program") == 3);
	test(dictionary.completion_count("bat") == 6);

	test(dictionary.most_frequent_completion("bir") == "bird");
	test(dictionary.most_frequent_completion("hap") == "happen");
	test(dictionary.most_frequent_completion("program") == "program");
	test(dictionary.most_frequent_completion("bat") == "battle");


	// Create an Autocompleter containing 50000 
	// common American English words.

	// Source: https://gist.github.com/h3xx/1976236
	f.open("words_50000.txt", ios::in);
	assert(f.is_open()); // If this fails, you're missing above file.

	// Time how long it takes to create this 50000-word autocompleter
	Autocompleter dictionary_50k;
	system_clock::time_point start = system_clock::now();
	while (getline(f, line))
		dictionary_50k.add(line, 1);
	system_clock::time_point end = system_clock::now();
	float dur = duration<float>(end - start).count();
	f.close();

	test(dictionary_50k.size() == 42895); // There are some duplicates
	cout << "Creating an Autocompleter of 50000 words took ";
	cout << dur << " seconds." << endl;
	test(dur < 3.0); 

	start = system_clock::now();
	for (int i = 0; i < 100000; ++i)
		dictionary_50k.most_frequent_completion(random_string(5));
	end = system_clock::now();
	dur = duration<float>(end - start).count();

	cout << "100000 calls to most_frequent_completion() on ";
	cout << "this Autocompleter took " << dur << " seconds." << endl;
	test(dur < 3.0);	


	// Test completions() on the animals Autocompleter already made.
	animals.completions("a", results);
	test(results[0] == "armadillo");
	test(results[1] == "alpaca");
	test(results[2] == "albatross");
	test(results[3] == "aardvark");
	test(results[4] == "");

	animals.completions("al", results);
	test(results[0] == "alpaca");
	test(results[1] == "albatross");
	test(results[2] == "");
	test(results[3] == "");
	test(results[4] == "");
	
	animals.completions("cro", results);
	test(results[0] == "crow");
	test(results[1] == "crocodile");	
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
	test(results[0] == "cat");
	test(results[1] == "goat");
	test(results[2] == "crow");
	test(results[3] == "goose");
	test(results[4] == "crocodile");
	
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

	start = system_clock::now();
	for (int i = 0; i < 100000; ++i)
		dictionary_50k.completions(random_string(5), results);
	end = system_clock::now();
	dur = duration<float>(end - start).count();

	cout << "100000 calls to completions() on ";
	cout << "this Autocompleter took " << dur << " seconds." << endl;
	test(dur < 3.0);	

	cout << "Assignment complete." << endl;
}



