
#ifndef REPEATS_H
#define REPEATS_H

// Removes all but the first occurrence of each character in the string.
// For instance:
// "abcda" becomes "abcd" (2nd occurrence of 'a' removed)
// "aabbcc" becomes "abc" (2nd occurrences of 'a', 'b', 'c' removed)
// "  a  b  c  " becomes " abc" (2nd through 8th occurrences of ' ' removed)
// "!a!a!b!b!c!c" becomes "!abc" (2nd through 6th occurrences of '!' removed, 
//                                2nd occurrences of 'a', 'b', 'c' removed)
string remove_repeats(string s);

#endif

