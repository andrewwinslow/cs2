
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
	// Array used later
	int hws[15];
	int exams[2];

	
	// Test a few cases where an invalid grade has been given
	for (int i = 0; i < 15; ++i)
		hws[i] = 100;	
	exams[0] = 100;	
	exams[1] = 100;	

	hws[0] = -1;
	test(grade(hws, exams[0], exams[1]) == 'X');
	hws[0] = 101;
	test(grade(hws, exams[0], exams[1]) == 'X');
	hws[0] = 100;

	hws[9] = -1;
	test(grade(hws, exams[0], exams[1]) == 'X');
	hws[9] = 101;
	test(grade(hws, exams[0], exams[1]) == 'X');
	hws[9] = 100;

	hws[14] = -1;
	test(grade(hws, exams[0], exams[1]) == 'X');
	hws[14] = 101;
	test(grade(hws, exams[0], exams[1]) == 'X');
	hws[14] = 100;

	exams[0] = -1;
	test(grade(hws, exams[0], exams[1]) == 'X');
	exams[0] = 101;
	test(grade(hws, exams[0], exams[1]) == 'X');
	exams[0] = 100;

	exams[1] = -1;
	test(grade(hws, exams[0], exams[1]) == 'X');
	exams[1] = 101;
	test(grade(hws, exams[0], exams[1]) == 'X');
	exams[1] = 100;

	test(grade(hws, exams[0], exams[1]) == 'A');


	// Set all scores to 90	to test a few borderline cases
	for (int i = 0; i < 15; ++i)
		hws[i] = 90;	
	exams[0] = 90;	
	exams[1] = 90;	
	
	hws[7] = 91;	
	test(grade(hws, exams[0], exams[1]) == 'A');
	hws[7] = 89;	
	test(grade(hws, exams[0], exams[1]) == 'B');
	hws[7] = 90;	

	exams[0] = 91;
	test(grade(hws, exams[0], exams[1]) == 'A');
	exams[0] = 89;
	test(grade(hws, exams[0], exams[1]) == 'B');
	exams[0] = 90;

	exams[1] = 91;
	test(grade(hws, exams[0], exams[1]) == 'A');
	exams[1] = 89;
	test(grade(hws, exams[0], exams[1]) == 'B');
	exams[1] = 90;


	// 100 on homeworks
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 100; 
	exams[0] = 100;
	exams[1] = 100;
	test(grade(hws, exams[0], exams[1]) == 'A');

	// 70 on homeworks
	// 100 on midterm
	// 100 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 70;	
	exams[0] = 100;
	exams[1] = 100;
	test(grade(hws, exams[0], exams[1]) == 'B');

	// 100 on homeworks
	// 60 on midterm
	// 100 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 100;	
	exams[0] = 60;
	exams[1] = 100;
	test(grade(hws, exams[0], exams[1]) == 'B');

	// 100 on homeworks
	// 100 on midterm
	// 60 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 100;	
	exams[0] = 100;
	exams[1] = 60;
	test(grade(hws, exams[0], exams[1]) == 'B');

	// 100 on homeworks
	// 100 on midterm
	// 60 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 100;	
	exams[0] = 100;
	exams[1] = 60;
	test(grade(hws, exams[0], exams[1]) == 'B');

	// 70 on homeworks
	// 81 on midterm
	// 81 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 70;	
	exams[0] = 81;
	exams[1] = 81;
	test(grade(hws, exams[0], exams[1]) == 'C');

	// 100 on homeworks
	// 0 on midterm
	// 100 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 100;	
	exams[0] = 0;
	exams[1] = 100;
	test(grade(hws, exams[0], exams[1]) == 'C');
	
	// 62 on homeworks
	// 81 on midterm
	// 81 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 62;	
	exams[0] = 81;
	exams[1] = 81;
	test(grade(hws, exams[0], exams[1]) == 'C');
	
	// 62 on homeworks
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 62;	
        exams[0] = 75;
        exams[1] = 75;
	test(grade(hws, exams[0], exams[1]) == 'D');
	
	// 44 on homeworks
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 48;	
        exams[0] = 75;
        exams[1] = 75;
	test(grade(hws, exams[0], exams[1]) == 'D');

	// 36 on homeworks
	// 75 on midterm
	// 75 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 42;	
        exams[0] = 75;
        exams[1] = 75;
	test(grade(hws, exams[0], exams[1]) == 'F');

	// 0 on homeworks
	// 100 midterm
	// 100 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 0;	
        exams[0] = 100;
        exams[1] = 100;
	test(grade(hws, exams[0], exams[1]) == 'F');

	// 100 on homeworks
	// 0 midterm
	// 0 on final
	for (int i = 0; i < 15; ++i)
		hws[i] = 100;	
        exams[0] = 0;
        exams[1] = 0;
	test(grade(hws, exams[0], exams[1]) == 'F');

	cout << "Assignment complete." << endl;	
}



