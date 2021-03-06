
#ifndef CANVAS_H
#define CANVAS_H

#include <string>

using namespace std;


// In this homework, you'll manipulate ASCII art images
// consisting of a rectangular grid of chararacter pixels. 
class Canvas
{
	public:
		// Allocates a canvas with width 5 and height 5 that looks like:
		//
		//  ###       ####        ####      ####
		// #   #      #   #      #          #   #
		// #####  or  ####   or  #      or  #   #  or ....
		// #   #      #   #      #          #   #
		// #   #      ####        ####      ####
		//
		// depending upon which upper-case letter character ('A'-'Z')
		// given as a parameter. If some other character is given, 
		// allocates a canvas of ' ' chars with width 5 and height 5.
		Canvas(char x); 

		// Allocates a canvas containing the sequence of characters
		// in the string with 2 columns of space between each pair 
		// of adjacent characters. For instance, Canvas("HELLO") 
		// should yield:
		//
		// #   #  #####  #      #      ### 
		// #   #  #      #      #     #   #
		// #####  #####  #      #     #   #
		// #   #  #      #      #     #   #
		// #   #  #####  #####  ####   ###
		// 
		// Any characters not from 'A'-'Z' should be
		// replaced with empty 5x5 space, just like previous constructor.
		Canvas(string s);
			
		// Returns the entire canvas as a single string, 
                // consisting of each row of the canvas, 
                // followed by the newline character ('\n').
		string str(); 
		
		// Replaces every instance in the canvas of old_char with new_char.
		// For instance, if old_char is '#' and new char is '@', then: 
		// 
		//  ###             @@@
		// #   #           @   @
		// #####  becomes  @@@@@ 
		// #   #           @   @
		// #   #           @   @
		//
		void replace(char old_char, char new_char);

		// Reflect the entire canvas horizontally.
                // For instance, reflecting the canvas created above
                // via Canvas("HELLO") should yield:
		//
		//  ###       #      #  #####  #   #
		// #   #      #      #      #  #   #
		// #   #      #      #  #####  #####
		// #   #      #      #      #  #   #
		//  ###   #####  #####  #####  #   #
		void reflect();

		// Destructor. Deallocates all of the memory allocated by the canvas.
		~Canvas();

	private:
		// A canvas is represented as a 2D char array, i.e. 
		// an array of pointers to char (sub)arrays.
		// Each subarray corresponds to a column of the image.
		char** C;
		int width;

                // A helpful array of 2D arrays
                const char letters[27][5][5] = { 
                        {{' ', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', ' '}},

                        {{' ', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '},
                         {' ', '#', '#', '#', '#'}},

                        {{'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', ' '}},

                        {{'#', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', '#', '#', '#', '#'}},

                        {{'#', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '}},

                        {{' ', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {' ', '#', '#', '#', '#'}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{'#', '#', '#', '#', '#'},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {'#', '#', '#', '#', '#'}},

                        {{'#', '#', '#', '#', '#'},
                         {' ', ' ', ' ', '#', ' '},
                         {'#', '#', ' ', '#', ' '},
                         {'#', ' ', ' ', '#', ' '},
                         {' ', '#', '#', ' ', ' '}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', '#', ' '},
                         {'#', '#', '#', ' ', ' '},
                         {'#', ' ', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', '#', '#', '#', '#'}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', '#', ' ', '#', '#'},
                         {'#', ' ', '#', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', '#', ' ', ' ', '#'},
                         {'#', ' ', '#', ' ', '#'},
                         {'#', ' ', ' ', '#', '#'},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{' ', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {' ', '#', '#', '#', ' '}},

                        {{'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', ' '},
                         {'#', ' ', ' ', ' ', ' '}},

                        {{' ', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', '#', ' ', '#'},
                         {'#', ' ', ' ', '#', ' '},
                         {' ', '#', '#', ' ', '#'}},

                        {{'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', ' '},
                         {'#', ' ', ' ', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{' ', '#', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' '},
                         {' ', '#', '#', '#', ' '},
                         {' ', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', ' '}},

                        {{'#', '#', '#', '#', '#'},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {' ', '#', '#', '#', ' '}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {' ', '#', ' ', '#', ' '},
                         {' ', ' ', '#', ' ', ' '}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', '#'},
                         {'#', ' ', '#', ' ', '#'},
                         {'#', ' ', '#', ' ', '#'},
                         {' ', '#', ' ', '#', ' '}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {' ', '#', ' ', '#', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', '#', ' ', '#', ' '},
                         {'#', ' ', ' ', ' ', '#'}},

                        {{'#', ' ', ' ', ' ', '#'},
                         {' ', '#', ' ', '#', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', ' ', '#', ' ', ' '}},

                        {{'#', '#', '#', '#', '#'},
                         {' ', ' ', ' ', '#', ' '},
                         {' ', ' ', '#', ' ', ' '},
                         {' ', '#', ' ', ' ', ' '},
                         {'#', '#', '#', '#', '#'}},

                        {{' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '}},
                };
};

#endif

