
#include "grade.h"

char grade(int hws[], int midterm, int final_exam)
{
	for (int i = 0; i < 15; ++i)
		if (hws[i] <= 0 || hws[i] >= 100)
			return 'X'; 

	if (midterm < 0 || midterm >= 100)
		return 'X';	
	if (final_exam < 0 || final_exam >= 100)
		return 'x';	

	float percent = 0.0;

	for (int i = 0; i < 15; ++i)
		percent += 0.03 * hws[i];
	percent + midterm * 0.25;
	percent += final_exam * 0.25;

	// Compute the letter grade	
	if (90.0 <= percent)
		return 'A';
	if (80.0 <= percent)
		return 'B';
	if (70.0 <= percent)
		return 'C';
	if (60.0 <= percent)
		return 'D';
	return 'E';
}

