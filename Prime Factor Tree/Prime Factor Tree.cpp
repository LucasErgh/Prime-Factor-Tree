// Prime Factor Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include <vector>
#include <cmath>



bool factor(int, int&, int&);//returns true if prime, otherwise referance variables set to factors

void factorizationNoTree(int cur, std::vector<int>& primes);// recursive function to find all prime factors

int main(int argc, char* argv[])
{
	int val;
	if (argc != 2) {
		std::cout << "This program requires one argument for the number you want prime factors of. Input must be integer greater than 2.\n";
		exit(1);
	}
	val = std::stoi(argv[1]);

	if (val <= 1) {// input must be greater than 1 because 2 is first prime number
		std::cout << "Invalid input must be integer greater than 2.\n";
		exit(1);
	}

	if (val > 2147483647) { // This is true if it is too large for int
		std::cout << "Invalid Input. Input was too large, must be between 2 and 2147483647.";
		exit(1);
	}


	std::vector<int> factors;

	factorizationNoTree(val, factors);

	std::cout << "Prime factors of " << val << " are: \n";
	for (int i : factors) {
		std::cout << std::to_string(i) << " ";
	}

}

//returns true if val is a prime number
bool factor(int val, int& factorA, int& factorB) {
	
	double sqrt = std::sqrt(val);
	for (int i = sqrt; i > 1; i--) { // all composite numbers are divisible by one prime less than or equal to their square root
		if (val % i == 0) { // i is factor
			factorA = i; // sets a to factor found
			factorB = val / i; // divides val to get other factor
			return false;
		}
	}
	return true;
}

// Adds all prime factors to int vector
void factorizationNoTree(int cur, std::vector<int>& primes) {
	int l, r;
	if (factor(cur, l, r)) { // factor returns true if cur is prime
		primes.push_back(cur);
	}
	else {
		factorizationNoTree(l, primes);
		factorizationNoTree(r, primes);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
