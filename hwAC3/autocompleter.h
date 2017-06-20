
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <string>

using namespace std;

class Autocompleter
{
	public:
		// Same as hwAC2
		Autocompleter();
		int completion_count(string x);
		int size();
	
		// Adds x to the list of potential suggestions in the Autocompleter, 
		// with specified frequency (higher frequency = more common).
		// If the word is already in the Autocompleter, does nothing.
		void add(string x, int freq);

		// Returns the most frequent string that starts with x 
		// Returns "" if there is are no strings 
		// starting with x in the Autocompleter.
		string most_frequent_completion(string x);

		// Takes a string (x) and a string array of length 5 (suggestions) 
		// Sets the first five elements of suggestions equal 
		// to the most frequent five strings in the Autocompleter
		// that start with x.
		//
		// If there are less than five such strings, the remaining
		// entries of the suggestions array are set to "" (the empty string) 
		void completions(string x, string* suggestions);

	private:
		// A helper class that stores
		// a string and a frequency.
		class Entry
		{
			public:
				string s;
				int freq;	
		};

		// A helper class that implements
		// a basic binary search tree node.
		class Node
		{
			public:
				Node (string s, int freq)
				{
					this->e.s = s;
					this->e.freq = freq;
					left = right = 0;
				}

				Entry e;
				Node* left;
				Node* right;
		};

		// Helper methods for add(), most_frequent_completion(), 
		// completion_count(), and size().
		Entry most_frequent_completion_recurse(string x, Node* root);
		int completion_count_recurse(string x, Node* root);
		int size_recurse(Node* root);

		// Helper method for completions().
		// Here's an idea for how to do this:
		// -Make an array of 5 entries ("mfc" = "most-frequent-completion entries")
		// -Use recursion to visit every node containing x like in completion_count_recurse().
		// -At each node visited during the recursion, look at the node's entry:
		//  ~If the entry's string starts with x, compare the frequency 
		//   of the entry with the smallest frequency of an Entry in mfc.
		//  ~If it's larger, overwrite the entry in mfc with smallest frequency.
		void completions_recurse(string x, Entry* mfc, Node* root);

		// The data structure should be a binary search tree
		Node* root;
};

#endif

