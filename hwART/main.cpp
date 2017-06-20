
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


int main()
{
	Canvas C1(3, 3);
	test(C1.width() == 3);
	test(C1.height() == 3);
	test(C1.to_string() == string("   \n") 
	                            + "   \n"
	                            + "   \n");

	Canvas C2(4, 6);
	test(C2.width() == 4);
	test(C2.height() == 6);
	test(C2.to_string() == string("    \n")
	                            + "    \n"
	                            + "    \n"
	                            + "    \n"
	                            + "    \n"
	                            + "    \n");


	Canvas C3('A');
	test(C3.width() == 5);
	test(C3.height() == 5);
	test(C3.to_string() == string(" ### \n")
	                            + "#   #\n"
	                            + "#####\n"
	                            + "#   #\n"
	                            + "#   #\n");

	Canvas C4('B');
	test(C4.width() == 5);
	test(C4.height() == 5);
	test(C4.to_string() == string("#### \n")
	                            + "#   #\n"
	                            + "#### \n"
	                            + "#   #\n"
	                            + "#### \n");

	Canvas C5('C');
	test(C5.width() == 5);
	test(C5.height() == 5);
	test(C5.to_string() == string(" ####\n")
	                            + "#    \n"
	                            + "#    \n"
	                            + "#    \n"
	                            + " ####\n");

	Canvas C6('D');
	test(C6.width() == 5);
	test(C6.height() == 5);
	test(C6.to_string() == string("#### \n")
	                            + "#   #\n"
	                            + "#   #\n"
	                            + "#   #\n"
	                            + "#### \n");

	Canvas C7('E');
	test(C7.width() == 5);
	test(C7.height() == 5);
	test(C7.to_string() == string("     \n")
	                            + "     \n"
	                            + "     \n"
	                            + "     \n"
	                            + "     \n");


	C4.replace('#', '@');
	test(C4.to_string() == string("@@@@ \n")
	                            + "@   @\n"
	                            + "@@@@ \n"
	                            + "@   @\n"
	                            + "@@@@ \n");

	C4.replace(' ', '-');
	test(C4.to_string() == string("@@@@-\n")
	                            + "@---@\n"
	                            + "@@@@-\n"
	                            + "@---@\n"
	                            + "@@@@-\n");

	C4.replace('-', '@');
	test(C4.to_string() == string("@@@@@\n")
	                            + "@@@@@\n"
	                            + "@@@@@\n"
	                            + "@@@@@\n"
	                            + "@@@@@\n");

	Canvas C8(2, 6);
	C8.replace(' ', 'X');	
	test(C8.to_string() == string("XX\n")
	                            + "XX\n"
	                            + "XX\n"
	                            + "XX\n"
	                            + "XX\n"
	                            + "XX\n");

	
	Canvas C9('A');
	C9.embiggen();
	test(C9.width() == 10);	
	test(C9.height() == 10);	
	test(C9.to_string() == string("  ######  \n")
	                            + "  ######  \n"
	                            + "##      ##\n"
	                            + "##      ##\n"
	                            + "##########\n"
	                            + "##########\n"
	                            + "##      ##\n"
	                            + "##      ##\n"
	                            + "##      ##\n"
	                            + "##      ##\n");
	
	Canvas C10('B');
	C10.embiggen();
	test(C10.width() == 10);	
	test(C10.height() == 10);	
	test(C10.to_string() == string("########  \n")
	                             + "########  \n"
	                             + "##      ##\n"
	                             + "##      ##\n"
	                             + "########  \n"
	                             + "########  \n"
	                             + "##      ##\n"
	                             + "##      ##\n"
	                             + "########  \n"
	                             + "########  \n");

	Canvas C11(2, 3);
	C11.embiggen();
	test(C11.width() == 4);	
	test(C11.height() == 6);	
	C11.embiggen();
	test(C11.width() == 8);	
	test(C11.height() == 12);	
	C11.embiggen();
	test(C11.width() == 16);	
	test(C11.height() == 24);	


	Canvas C12("A");
	test(C12.width() == 5);	
	test(C12.height() == 5);	
	test(C12.to_string() == string(" ### \n")
	                             + "#   #\n"
	                             + "#####\n"
	                             + "#   #\n"
	                             + "#   #\n");

	Canvas C13("AB");
	test(C13.width() == 12);	
	test(C13.height() == 5);	
	test(C13.to_string() == string(" ###   #### \n")
	                             + "#   #  #   #\n"
	                             + "#####  #### \n"
	                             + "#   #  #   #\n"
	                             + "#   #  #### \n");

	Canvas C14("CAB");
	test(C14.width() == 19);	
	test(C14.height() == 5);	
	test(C14.to_string() == string(" ####   ###   #### \n")
	                             + "#      #   #  #   #\n"
	                             + "#      #####  #### \n"
	                             + "#      #   #  #   #\n"
	                             + " ####  #   #  #### \n");

	Canvas C15("!BAD!");
	test(C15.width() == 33);	
	test(C15.height() == 5);	
	test(C15.to_string() == string("       ####    ###   ####        \n")
	                             + "       #   #  #   #  #   #       \n"
	                             + "       ####   #####  #   #       \n"
	                             + "       #   #  #   #  #   #       \n"
	                             + "       ####   #   #  ####        \n");

	Canvas C16("DAD CAB");
	test(C16.width() == 47);	
	test(C16.height() == 5);	
	test(C16.to_string() == string("####    ###   ####           ####   ###   #### \n")
	                             + "#   #  #   #  #   #         #      #   #  #   #\n"
	                             + "#   #  #####  #   #         #      #####  #### \n"
	                             + "#   #  #   #  #   #         #      #   #  #   #\n"
	                             + "####   #   #  ####           ####  #   #  #### \n");

	cout << "Assignment complete." << endl;
}





