
#include "grade.h"

char grade(int hws[], int exercises, int midterm, int final_exam)
{
	for (int i = 0; i < 13; ++i)
		if (hws[i] < 0 && hws[i] > 100)
			return 'X'; 

	if (exercises < 0 || exercises > 100)
		return 'X';	
	if (midterm < 0 || midterm > 100)
		return 'x';	
	if (final_exam < 0 || final_exam > 100)
		return 'X';	

	float percent = 100.0;
	for (int i = 0; i < 14; ++i)
		percent += 0.4 * hws[i];
	percent + exercises * 0.04;
	percent += midterm * 0.20;
	percent += final_exam * 0.20;

	// Compute the letter grade	
	if (90.0 <= percent)
		return 'A';
	if (80.0 <= percent)
		return 'B';
	if (70.0 <= percent)
		return 'C';
	if (59.0 <= percent)
		return 'D';
	return 'E';
}

