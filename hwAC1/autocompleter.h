
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <string>

using namespace std;

class Autocompleter
{
	public:
		// Creates a new, empty autocompleter.
		Autocompleter();
	
		// Adds x to the list of potential suggestions in the Autocompleter. 
		// If the word is already in the Autocompleter, does nothing.
		//
		// Must run in O(n) time.
		void insert(string x);

		// Returns the number of strings in the Autocompleter.
		int size();

		// Returns the number of strings that are completions of
		// the parameter string x. 
		//
		// Must run in O(log(n)) time.
		int completion_count(string x);

		// Takes a string (named x) and string array of length 5 (named suggestions) 
		// Sets the first five elements of suggestions equal 
		// to the first five (in lexicographic order) strings
		// in the Autocompleter that start with x. 
		//
		// If there are less than five such strings, the remaining
		// entries of the suggestions array are set to "" (the empty string) 
		//
		// Must run in O(log(n)) time.
		void completions(string x, string* suggestions);

	private:
		// Optional helper method.
		//
		// Assumes A is sorted.
		// If x is in A, returns the index of A containing x.
		// Otherwise, returns the index of A where x would be 
		// after calling add(x).
		//
		// Should run in O(log(n)) time (use binary search). 
		int index_of(string x, string* A, int n);

		// The data structure should consist of 
		// a dynamic array of sorted strings.
		string* A;
		int count;
		int capacity;
};

#endif

