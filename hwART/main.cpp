#include <string>
#include <cstdlib>
#include <iostream>
#include "canvas.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


void interactive_mode(char ink)
{
	cout << "Enter a string and press Enter ";
	cout << "to see the ASCII art version." << endl;
	while (cin)
	{
		string line;
		getline(cin, line);
		if (line.size() > 0)
		{
			Canvas C(line);
			C.replace('#', ink);
			cout << C.str();
		}
	}

	exit(0);
}


int main()
{
	// Interactive mode.
	// Uncomment the "interactive_mode..." line below to 
	// use your Canvas implementation interactively.
	// 
	// The parameter specifies the character used to fill letters.
	// 
	//interactive_mode('@');


	// Test Canvas(char)
	Canvas C1('A');
	test(C1.str() == string(" ### \n")
                              + "#   #\n"
                              + "#####\n"
                              + "#   #\n"
                              + "#   #\n");
	Canvas C2('B');
	test(C2.str() == string("#### \n")
                              + "#   #\n"
                              + "#### \n"
                              + "#   #\n"
                              + "#### \n");
	Canvas C3('C');
	test(C3.str() == string(" ####\n")
                              + "#    \n"
                              + "#    \n"
                              + "#    \n"
                              + " ####\n");
	Canvas C4('X');
	test(C4.str() == string("#   #\n")
                              + " # # \n"
                              + "  #  \n"
                              + " # # \n"
                              + "#   #\n");
	Canvas C5('Y');
	test(C5.str() == string("#   #\n")
                              + " # # \n"
                              + "  #  \n"
                              + "  #  \n"
                              + "  #  \n");
	Canvas C6('Z');
	test(C6.str() == string("#####\n")
                              + "   # \n"
                              + "  #  \n"
                              + " #   \n"
                              + "#####\n");
	Canvas C7('!');
	test(C7.str() == string("     \n")
                              + "     \n"
                              + "     \n"
                              + "     \n"
                              + "     \n");


	// Test replace()
        Canvas C8('D');
	C8.replace('#', '@');
	test(C8.str() == string("@@@@ \n")
                              + "@   @\n"
                              + "@   @\n"
                              + "@   @\n"
                              + "@@@@ \n");
	C8.replace(' ', '-');
	test(C8.str() == string("@@@@-\n")
                              + "@---@\n"
                              + "@---@\n"
                              + "@---@\n"
                              + "@@@@-\n");
	C8.replace('@', '-');
	test(C8.str() == string("-----\n")
                              + "-----\n"
                              + "-----\n"
                              + "-----\n"
                              + "-----\n");
	C8.replace('-', '#');
	test(C8.str() == string("#####\n")
                              + "#####\n"
                              + "#####\n"
                              + "#####\n"
                              + "#####\n");
	C8.replace('#', ' ');
	test(C8.str() == string("     \n")
                              + "     \n"
                              + "     \n"
                              + "     \n"
                              + "     \n");

	
	// Test Canvas(string)
	Canvas C9("ABC");
	test(C9.str() == string(" ###   ####    ####\n")
                              + "#   #  #   #  #    \n"
                              + "#####  ####   #    \n"
                              + "#   #  #   #  #    \n"
                              + "#   #  ####    ####\n");
	Canvas C10("DEF");
	test(C10.str() == string("####   #####  #####\n")
                               + "#   #  #      #    \n"
                               + "#   #  #####  #####\n"
                               + "#   #  #      #    \n"
                               + "####   #####  #    \n");
	Canvas C11("HELLO");
	test(C11.str() == string("#   #  #####  #      #       ### \n")
                               + "#   #  #      #      #      #   #\n"
                               + "#####  #####  #      #      #   #\n"
                               + "#   #  #      #      #      #   #\n"
                               + "#   #  #####  #####  #####   ### \n");
	Canvas C12("T$U!V#");
	test(C12.str() == string("#####         #   #         #   #       \n")
                               + "  #           #   #         #   #       \n"
                               + "  #           #   #         #   #       \n"
                               + "  #           #   #          # #        \n"
                               + "  #            ###            #         \n");
	Canvas C13("ASCII");
	test(C13.str() == string(" ###    ####   ####  #####  #####\n")
                               + "#   #  #      #        #      #  \n"
                               + "#####   ###   #        #      #  \n"
                               + "#   #      #  #        #      #  \n"
                               + "#   #  ####    ####  #####  #####\n");


        // Test reflect()
        Canvas C14('B');
        C14.reflect();
	test(C14.str() == string(" ####\n")
                               + "#   #\n"
                               + " ####\n"
                               + "#   #\n"
                               + " ####\n");
        Canvas C15('N');
        C15.reflect(); 
	test(C15.str() == string("#   #\n")
                               + "#  ##\n"
                               + "# # #\n"
                               + "##  #\n"
                               + "#   #\n");
        Canvas C16("XYZ");
        C16.reflect(); 
	test(C16.str() == string("#####  #   #  #   #\n")
	                       + " #      # #    # # \n"
	                       + "  #      #      #  \n"
	                       + "   #     #     # # \n"
	                       + "#####    #    #   #\n");
	Canvas C17("MIRROR");
        C17.reflect();
	test(C17.str() == string(" ####   ###    ####   ####  #####  #   #\n")
	                       + "#   #  #   #  #   #  #   #    #    ## ##\n"
	                       + " ####  #   #   ####   ####    #    # # #\n"
                               + " #  #  #   #   #  #   #  #    #    #   #\n"
                               + "#   #   ###   #   #  #   #  #####  #   #\n");

	
        cout << "Assignment complete." << endl;
}





