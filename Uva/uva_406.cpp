/* UVa problem: 406
 *
 * Topic: Number Theory
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Each input set will be on a line by itself and will consist of 2 numbers. The first number (1 ≤ N ≤ 1000)
 *	is the maximum number in the complete list of prime numbers between 1 and N. The second number
 *	(1 ≤ C ≤ N) defines the 2C prime numbers to be printed from the center of the list if the length of
 *	the list is even; or the 2C − 1 numbers to be printed from the center of the list if the length of the list
 *	is odd. For each input set, you should print the number N beginning in column 1 followed by a space, then by
 *	the number C, then by a colon (:), and then by the center numbers from the list of prime numbers as
 *	defined above. If the size of the center list exceeds the limits of the list of prime numbers between 1
 *	and N, the list of prime numbers between 1 and N (inclusive) should be printed. Each number from
 *	the center of the list should be preceded by exactly one blank. Each line of output should be followed
 *	by a blank line.
 * 
 * Solution Summary:
 *	
 *	Generate primes from 1 to N and put them in a vector. Then use simple logic statements to 
 * 	find the middle 2C or 2C-1 elements. 
 *
 * Used Resources:
 *
 *	CMPUT 403 Code library: https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/primes.c
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
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> primes;
int psize;

//Next two functions are used to generate all primes between 1 to N
//Taken from the cmput 403 code library and modified to use vectors 
//And fit the parameters of the problem
void getPrimes(int N){
  int i, j, isprime;
  
  psize = 1;
  primes.push_back(1);
  if(N > 1){
  	psize++;
  	primes.push_back(2);
  }
  for(i = 3; i <= N; i+= 2){
    for(isprime = j = 1; j < psize; j++){
      if(i % primes[j] == 0){
		isprime = 0;
		break;
      }
      	if(1.0*primes[j]*primes[j] > i){
      		break;
      }
    }
    if(isprime){ 
    	psize++;
    	primes.push_back(i);
    }
  }
}

int isPrime(int x){
  int i;
  
  if(x <= 1) return 0;
  for(i = 0; i < psize && primes[i]*primes[i] <= x; i++){
    if(x % primes[i] == 0) return 0;
  }
  return 1;
}

int main(){
	int N;
	int C;
	vector<int> inputs;
	while(cin >> N >> C){ //Get input
		inputs.push_back(N);
		inputs.push_back(C);
	}

	for(int i = 0; i < inputs.size(); i += 2){
		primes.clear();
		N = inputs[i];
		C = inputs[i+1];
		getPrimes(N); //Get primes
	
		/*
		for(int i = 0; i < psize; i++){
			cout << primes[i] << " ";
		}
		cout << endl;
		*/

		cout << N << " " << C << ": ";

		if(psize % 2 == 0){ //Check if number of primes is odd or even
			if(2*C > psize){ //If 2C is larger than the number of primes, print them all
				for(int i = 0; i < psize; i++){
					cout << primes[i];
					if(i != psize - 1){ //Need these because Uva is stupid and counts it as 
						cout << " ";    //wrong if there's an extra space after every line
					}
				}
			}else{
				for(int i = (psize)/2 - C; i < (psize)/2 + C; i++){
					cout << primes[i];
					if(i != (psize)/2 + C - 1){
						cout << " ";
					}
				}
			}
		}else{
			if(2*C > psize){
				for(int i = 0; i < psize; i++){
					cout << primes[i];
					if(i != psize - 1){
						cout << " ";
					}
				}
			}else{
				for(int i = (psize-1)/2 - (2*C - 1)/2; i < (psize-1)/2 + (2*C)/2; i++){
					cout << primes[i];
					if(i != (psize-1)/2 + (2*C)/2 - 1){
						cout << " ";
					}
				}
			}
		}
		cout << endl << endl;
	}
	return 0;
}