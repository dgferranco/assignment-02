/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
*                  2015 TODO(David Ferranco) TODO(dgferranco@csu.fullerton.edu)>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;


int main()
{
	
	ofstream infilename("input.txt");
	ofstream outfilename("composite.txt");
	ofstream outfilename2("primes.txt");
	if (!infilename.is_open() || !outfilename.is_open() || !outfilename2.is_open())
	{
		cout << "Failed to open file." << endl;
		return -1;
	}

	int n = 0, input = 0, max = 0;
	int sieve[65536];
	cout << "Enter integers between 1 and 65535. Enter '0' to continue." << endl;

	do
	{
		sieve[n] = input;									// Fills the array of size 65336 with the user's input
		n++;												// Moves on to the next index of the array
		infilename << input << " ";							// Outputs the user's inputs to the input.txt that will later be used to find primes and composites
		cin >> input;										// User input's the numbers that want to be checked if prime or composite

	} while (input != 0);

	for (int i = 0; i < 65535; i++)							// Finds the maximum value in the input.txt file
	{
		if (sieve[n] > max)
		{
			max = sieve[n];
		}
		return max;											// Returns the value of max
	}

	int find_max(const string& infilename);					/*GIVEN*/

	void sieve(const int size, bool primes[]);
	for (n = 0; n < max; n++)
	{
		if (sieve[n] / n = 1;)								// If the input file's values are divded and output 1, they are a prime number. --> Error; How to read values?
		{
			outfilename << n;								// Outputs prime numbers to the composites txt
		}
		else
			outfilename2 << n;								// Outputes numbers that are not prime to this txt
	}


	int max = find_max("input.txt");							/*GIVEN*/
	if (max == -1) {
		cout << "ERROR in `find_max()`" << endl;
		return 1;  // error
	}

	// - Runtime sized arrays are a C99 feature, and a GCC and Clang extension.						
	//   Thus `bool primes[max+1];` is not standards compliant.  It should work
	//   on Xcode (which uses Clang) and in Linux (where most people use either
	//   GCC or Clang), but Visual Studio appears not to allow it.
	bool * primes = (bool *)malloc(sizeof(bool) * (max + 1));
	sieve(max + 1, primes);

	int ret;  // for storing return values, to check for error codes
	//
	ret = write_primes(max + 1, primes, "input.txt", "primes.txt");
	if (ret == -1) {
		cout << "ERROR in `write_primes()`" << endl;
		return 1;  // error
	}
	//
	ret = write_composites(max + 1, primes, "input.txt", "composites.txt");
	if (ret == -1) {
		cout << "ERROR in `write_composites()`" << endl;
		return 1;  // error
	}

	return 0;

}

