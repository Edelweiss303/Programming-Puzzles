/* Kattis problem: perfectpowers
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	We say that x is a perfect square if, for some integer b, x=b2. 
 *	Similarly, x is a perfect cube if, for some integer b, x=b3. 
 *	More generally, x is a perfect pth power if, for some integer 
 *	b, x=bp. Given an integer x you are to determine the largest 
 *	integer p such that x is a perfect pth power.
 *	Each test case is given by a line of input containing x. The 
 *	value of x will have magnitude at least 2 and be within the 
 *	range of a (32-bit) int in C, C++, and Java. A line containing 
 *	0 follows the last test case.
 *	For each test case, output a line giving the largest integer p 
 *	such that x is a perfect pth power.
 *
 * Solution Summary:
 *
 *	We know that any number can be broken down into a factor of its primes. 
 *	The GCD of all the exponents of those primes is equal to the largest p 
 *  of x such that x = b^p. For negative x, we simply take the absolute 
 *	value, find p and the answer is the largest odd b such that a*b = p
 *
 * Used Resources:
 *
 *	  CMPUT 403 code archive: https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/primefactor.c
 *	  CMPUT 403 code archive: https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/gcd.cpp
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
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAXN 46340
#define MAXP 5000

int primes[MAXP];
int psize;

void getPrimes(){
  int i, j, isprime;
  
  psize = 0;
  primes[psize++] = 2;
  for(i = 3; i <= MAXN; i+= 2){
    for(isprime = j = 1; j < psize; j++){
      if(i % primes[j] == 0){
	isprime = 0;
	break;
      }
      if(1.0*primes[j]*primes[j] > i) break;
    }
    if(isprime) primes[psize++] = i;
  }
}

typedef struct{
  int size;
  int f[32];
} Factors;

Factors getPFactor(int n){
  Factors x;
  int i;

  x.size = 0;
  for(i = 0; i < psize; i++){
    while(n % primes[i] == 0){
      x.f[x.size++] = primes[i];
      n /= primes[i];
    }
    if(1.0*primes[i]*primes[i] > n) break;
  }
  if(n > 1){
    x.f[x.size++] = n;
  }
  return x;
}

//finds the GCD
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

//finds the GCD of all the items in a vector
int vectorGCD(vector<int> p){
    int result = p[0];
    for (int i = 1; i < p.size(); i++)
        result = GCD(p[i], result);
 
    return result;
}

int main(){
	int x;
	Factors n;
	
	getPrimes();
	while(cin >> x && x){
		bool isNegative = false;
		if(x < 0){ //Check if input is negative
			x = -x;
			isNegative = true;
		}

		n = getPFactor(x); //Get all the prime factors
		vector<int> powers;

		for(int i = 0; i < n.size;){ //Count the number of each prime factor
			int count = 1;
			int current = n.f[i];
			for(int j = i + 1; j < n.size; j++){
				if(current == n.f[j]){
					count++;
				}else{
					break;
				}
			}
			
			powers.push_back(count); //Put them in a vector
			i += count;
		}

		if(isNegative){ 
			int p = vectorGCD(powers); 		//If the input was negative, 
			for(int i = p; i >= 0; i--){ 	//find the largest odd b such that a*b = p
				if(p % i == 0 && i % 2 == 1){
					p = i;
					break;
				}
			}
			cout << p << endl;
		}else{
			cout << vectorGCD(powers) << endl; //If the input was positive, simply output the GCD of all the numbers in the vector
		}

	}
	return 0;
}