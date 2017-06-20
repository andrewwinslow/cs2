
#ifndef CANVAS_H
#define CANVAS_H

#include <string>

using namespace std;


// In this homework, you'll manipulate ASCII art images
// consisting of a rectangular grid of chararacter pixels. 
class Canvas
{
	public:
		// Allocates a canvas of the given width and height
		// consisting of ' ' chars.
		Canvas(int width, int height);

		// Allocates a canvas with width 5 and height 5 that looks like:
		//
		//  ###       ####        ####     ####
		// #   #      #   #      #         #   #
		// #####  or  ####   or  #      or #   #
		// #   #      #   #      #         #   #
		// #   #      ####        ####     ####
		//
		// depending upon which character ('A', 'B', 'C', or 'D') is 
		// given as a parameter. If some other character is given, 
		// allocates a canvas of ' ' chars with width 5 and height 5.
		Canvas(char x); 

		// Allocates a canvas containing the sequence of characters
		// in the string with 2 columns of space between each pair 
		// of adjacent characters. For instance, Canvas("BADCAB") 
		// should yield:
		//
		// ####    ###   ####    ####   ###   ####  
		// #   #  #   #  #   #  #      #   #  #   #
		// ####   #####  #   #  #      #####  ####
		// #   #  #   #  #   #  #      #   #  #   # 
		// ####   #   #  ####    ####  #   #  #### 
		// 
		// Any characters in s not from {'A', 'B', 'C', 'D'} should be 
		// replaced with empty 5x5 space, just like previous constructor.
		Canvas(string s);
			
		// Returns the width of the canvas.
		int width();

		// Returns the height of the canvas.
		int height(); 

		// Returns the entire canvas as a single string, consisting of each row
		// of the canvas, followed by endl.
		string to_string(); 
		
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

		// Returns a new canvas twice the width and height, where each pixel 
		// in the old canvas corresponds to a 2x2 region of pixels in the new canvas. 
		// 
		// For instance:
		//
		//  ###              ######
		// #   #             ######
		// #####  becomes  ##      ##
		// #   #           ##      ##
		// #   #           ##########
		//                 ##########
		//                 ##      ##
		//                 ##      ##
		//                 ##      ##
		//                 ##      ##
		//
		void embiggen();
		
		// Destructor. Deallocates all of the memory allocated by the canvas.
		~Canvas();

	private:
		// A canvas is represented as a 2D char array, i.e. 
		// an array of pointers to char (sub)arrays.
		// Each subarray corresponds to a column of the image.
		char** C;
		int _width;
		int _height;
};

#endif

