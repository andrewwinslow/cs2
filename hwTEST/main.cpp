
#include <cstdlib>
#include <iostream>
#include "repeats.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	// ADD YOUR TESTS HERE
	// Example:
	test(remove_repeats("abcda") == "abcd");

	cout << "Assignment complete." << endl;
}




