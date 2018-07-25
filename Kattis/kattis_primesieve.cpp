/* Kattis problem: primesieve
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The first line of input consists of two integers n, q, where 1≤n≤108 
 *	and 1≤q≤20000. Then follow q lines, each containing an integer x satisfying 1≤x≤n.
 *	On the first line of output, write one line giving the number of prime numbers 
 *	less than or equal to n. Then for each query x, output 1 if x is a prime and ouput 
 *	0 if x is composite.
 *
 *
 * Solution Summary:
 *
 *	Implement the Sieve of Eratosthenes using a bit array (here, a vector of booleans) 
 *	to save memory. Then count the number of TRUEs in the vector. Then for each x, 
 *	check if the vector[x] is true or not and print out 1 or 0 accordingly.
 *
 * Used Resources:
 *
 *	https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes   
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Rishi Barnwal
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

	long int n;
	long int q;
	long int x;
	vector <long int> xValues;

	cin >> n >> q;

	vector<bool> primes(n+1, true); //Initialize vector of bools of size n+1, all true

	primes[0] = false; //First value is false since we don't use it
	primes[1] = false; //Second value is false because 1 is not a prime number

	for(long long i = 0; i < q; i++){
		cin >> x;
		xValues.push_back(x);
	}

	
	for (int jump = 2; jump < 10000; jump++){ //Sieve of Eratosthenes. Basically cross out all multiples
											  //of each prime number until only the prime numbers remain
		if(primes[jump] == false){ //If the next starting index is already set to false, we ignore it
			continue;
		}else if(jump*jump > n){ //Stop if the square of the starting index is bigger than your range
			break;
		}

		for(int i = jump*2; i <= n; i+=jump){ //Check every j-th bit in the vector
			if(primes[i] == true && i % jump == 0){ //if it isn't set to false, set it to false
				primes[i] = false;
			}

		}
	}


	cout << count(primes.begin(), primes.end(), true) << endl; //Count the number of TRUEs


	for(long long i = 0; i < xValues.size(); i++){ //Check if x values are prime or not
		if(primes[xValues[i]] == true){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
		
	}







	return 0;
}