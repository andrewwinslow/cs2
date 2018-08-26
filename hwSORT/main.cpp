
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include "sort.h"

using namespace std;
using namespace chrono;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


// A basic sorting algorithm (merge sort) to compare 
// against your sorting algorithm for correctness and speed.
void benchmark_sort(int* A, int n)
{
	if (n < 2)
		return;
	int halfway = n/2;
	benchmark_sort(A, halfway);
	benchmark_sort(&(A[n/2]), n - halfway);
	int i, j, copied_elements;
	i = 0;
	j = halfway;
	copied_elements = 0;
	int* sorted_A = new int[n];
	while (copied_elements < n)
	{
                if (j == n)
                {
                        sorted_A[copied_elements] = A[i];
                        ++i;
                }
		else if (i == halfway)
		{
			sorted_A[copied_elements] = A[j];
			++j;
		}
		else if (A[i] < A[j])
		{
			sorted_A[copied_elements] = A[i];
			++i;
		}
		else 
		{
			sorted_A[copied_elements] = A[j];
			++j;
		}
		++copied_elements;
	}
	for (int i = 0; i < n; ++i)
		A[i] = sorted_A[i];
	delete[] sorted_A;
}


int main()
{
	srand(2018 + 's'); // Initializes random number generation
	system_clock::time_point start, end;
	float dur;


	// Variables used later
	const int n = 5000000;
	int* A = new int[n];
	int* B = new int[n];
	float total_duration = 0;
	float total_benchmark_duration = 0;


	// Test 1: already in sorted order
        A[0] = 1;
	for (int i = 1; i < n; ++i)
		A[i] = A[i-1] + (rand() % 5); 
	for (int i = 0; i < n; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur;
	cout << "Test #1 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur;

	for (int i = 0; i < n; ++i)
		test(A[i] == B[i]);



	// Test 2: reverse sorted order
        A[0] = n + (rand() % n);
	for (int i = 1; i < n; ++i)
		A[i] = A[i-1] - (rand() % 5);
	for (int i = 0; i < n; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur; 
	cout << "Test #2 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < n; ++i)
		test(A[i] == B[i]);

		

	// Test 3: in "mostly" sorted order
        A[0] = 1;
	for (int i = 0; i < n; ++i)
		A[i] = A[i-1] + (rand() % 5); 
	for (int i = 0; i < 10000; ++i)
        {
                int index1 = (rand() % (n - 50));
                int index2 = index1 + (rand() % 30);
		swap(A[index1], A[index2]);
        }
	for (int i = 0; i < n; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur;
	cout << "Test #3 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < n; ++i)
		test(A[i] == B[i]);
	


	// Test 4: random ints
	for (int i = 0; i < n; ++i)
		A[i] = rand(); 
	for (int i = 0; i < n; ++i)
		B[i] = A[i];
	
	start = system_clock::now();
	sort(A, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur; 
	cout << "Test #4 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < n; ++i)
		test(A[i] == B[i]);


	
	// Test 5: lots of repeats 
	for (int i = 0; i < n; ++i)
		A[i] = rand() % 10; 
	for (int i = 0; i < n; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur;
	cout << "Test #5 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < n; ++i)
		test(A[i] == B[i]);



	// Summary stuff

	// Print out the total time spent by your sort on all tests
	cout << "Total time: " << total_duration << " seconds." << endl;

	// Check that you beat the benchmark (basic merge sort)
	test(total_duration < total_benchmark_duration);
	cout << "Assignment complete." << endl;	
}



