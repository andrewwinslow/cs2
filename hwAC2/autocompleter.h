
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <string>

using namespace std;

class Autocompleter
{
	public:
		// Same as hwAC1
		Autocompleter();
		void add(string x);
		int size();
		int completion_count(string x);
		void completions(string x, string* suggestions);

	private:
		// A helper class that implements
		// a basic binary search tree node.
		class Node
		{
			public:
				Node(string s)
				{
					this->s = s;
					left = right = 0;
				}

				string s;
				Node* left;
				Node* right;
		};

		// Helper method for size()
		int size_recurse(Node* root);
	
		// Helper method for completion_count().
		// Here's a (recursive) algorithm:
		//
		// Base case: 
		// If root == 0, then return 0.
		//
		// Inductive case:
		// -If x < root->s and root->s does not start with x, recurse into left subtree.
		// -If x < root->s and root->s starts with x, recurse into both subtrees.
		// -If x > root->s, recurse into right subtree.
		// -Return the sum of the recursive calls plus:
		//     0 if root->s does not start with x.
		//     1 if root->s does start with x.  
		int completion_count_recurse(string x, Node* root);

		// Helper method for completions().
		// Here's a (recursive) algorithm:
		//
		// Base case:
		// If root == 0, then return.
		// If the last entry of the suggestions array is not "", then return
		// (completions() has already found 5 suggestions).
		//
		// Inductive case:
		// -Use recursion to visit all nodes containing x like in completion_count_recurse().
		// -Make sure this recursion visits nodes in the following order:
		//  1. Left subtree.
		//  2. Root.
		//  3. Right subtree.
		// -At each node visited, look at suggestions array.
		// -Store the node's string into the first array location whose string is "".
		void completions_recurse(string x, string* suggestions, Node* root);

		// The data structure should be a binary search tree
		Node* root;
};

#endif

