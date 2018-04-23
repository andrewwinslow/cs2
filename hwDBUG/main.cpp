
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "grade.h"

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
	// Variables used later
	int hws[14];
	int exercises;
	int midterm;
	int final_exam;

	
	// Test invalid grades
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 100;
	midterm = 100;
	final_exam = 100;

	hws[0] = -1;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	hws[0] = 101;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	hws[0] = 100;

	hws[9] = -1;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	hws[9] = 101;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	hws[9] = 100;

	hws[13] = -1;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	hws[13] = 101;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	hws[13] = 100;

	exercises = -1;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	exercises = 101;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	exercises = 100;
	
	midterm = -1;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	midterm = 101;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	midterm = 100;

	final_exam = -1;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	final_exam = 101;
	test(grade(hws, exercises, midterm, final_exam) == 'X');
	final_exam = 100;

	test(grade(hws, exercises, midterm, final_exam) == 'A');


	// Set all scores to 90	to test a few borderline cases
	for (int i = 0; i < 14; ++i)
		hws[i] = 90;	
	exercises = 90;
	midterm = 90;	
	final_exam = 90;	
	
	hws[7] = 91;	
	test(grade(hws, exercises, midterm, final_exam) == 'A');
	hws[7] = 89;	
	test(grade(hws, exercises, midterm, final_exam) == 'B');
	hws[7] = 90;	
	
	exercises = 91;
	test(grade(hws, exercises, midterm, final_exam) == 'A');
	exercises = 89;
	test(grade(hws, exercises, midterm, final_exam) == 'B');
	exercises = 90;

	midterm = 91;
	test(grade(hws, exercises, midterm, final_exam) == 'A');
	midterm = 89;
	test(grade(hws, exercises, midterm, final_exam) == 'B');
	midterm = 90;

	final_exam = 91;
	test(grade(hws, exercises, midterm, final_exam) == 'A');
	final_exam = 89;
	test(grade(hws, exercises, midterm, final_exam) == 'B');
	final_exam = 90;


	// 100 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100; 
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'A');

	// 70 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 70;	
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'B');

	// 100 on homeworks
	// 0 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 0;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'A');

	// 90 on homeworks
	// 0 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 90;
	exercises = 0;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'A');

	// 90 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 90;
	exercises = 0;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'A');

	// 50 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 50;
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'C');

	// 45 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 45;
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'D');

	// 100 on homeworks
	// 100 on exercises
	// 60 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 100;
	midterm = 60;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'A');

	// 100 on homeworks
	// 100 on exercises
	// 40 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 100;
	midterm = 40;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'B');

	// 100 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 60 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 100;
	midterm = 100;
	final_exam = 60;
	test(grade(hws, exercises, midterm, final_exam) == 'A');

	// 100 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 40 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 100;
	midterm = 100;
	final_exam = 40;
	test(grade(hws, exercises, midterm, final_exam) == 'B');

	// 70 on homeworks
	// 100 on exercises
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 70;	
	exercises = 100;
	midterm = 75;
	final_exam = 75;
	test(grade(hws, exercises, midterm, final_exam) == 'C');

	// 70 on homeworks
	// 0 on exercises
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 70;	
	exercises = 0;
	midterm = 75;
	final_exam = 75;
	test(grade(hws, exercises, midterm, final_exam) == 'D');

	// 70 on homeworks
	// 50 on exercises
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 70;	
	exercises = 50;
	midterm = 75;
	final_exam = 75;
	test(grade(hws, exercises, midterm, final_exam) == 'C');

	// 70 on homeworks
	// 10 on exercises
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 70;	
	exercises = 10;
	midterm = 75;
	final_exam = 75;
	test(grade(hws, exercises, midterm, final_exam) == 'D');

	// 100 on homeworks
	// 50 on exercises
	// 0 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 100;	
	exercises = 50;
	midterm = 0;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'C');
	
	// 60 on homeworks
	// 50 on exercises
	// 20 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 60;	
	exercises = 50;
	midterm = 20;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'F');
	
	// 60 on homeworks
	// 100 on exercises
	// 20 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 60;	
	exercises = 100;
	midterm = 20;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'D');
	
	// 60 on homeworks
	// 100 on exercises
	// 20 on midterm
	// 90 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 60;	
	exercises = 100;
	midterm = 20;
	final_exam = 90;
	test(grade(hws, exercises, midterm, final_exam) == 'F');
	
	// 0 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 0;	
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'F');
	
	// 25 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 25;	
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'F');
	
	// 30 on homeworks
	// 100 on exercises
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 14; ++i)
		hws[i] = 30;	
	exercises = 100;
	midterm = 100;
	final_exam = 100;
	test(grade(hws, exercises, midterm, final_exam) == 'D');
	

	cout << "Assignment complete." << endl;	
}



