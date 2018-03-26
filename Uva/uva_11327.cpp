/* Uva problem: 11327
 *
 * Topic: Number Theory
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	The input consists of a series of test cases. Each test case consists of a single integer 1 ≤ k ≤
 *	12, 158, 598, 919. Input is terminated by ‘0’; this case should not be processed.
 *	For each test case, output the k-th fraction that would be printed by the program above in 
 * 	the format n/d.
 *
 *
 *
 * Solution Summary:
 *
 *	The number of fractions of a denominator j has is equaled to Phi(j). Except for the special cases
 *	of 1 and 2, which have 2 and 1 fractions respectively. We store 2 and 1 in a list then compute
 *	phi for the ints from 3 to 20,000 and store them in the same list. The denominator is found by 
 * 	iterating through all the Phi values and adding them to a total until we reach k. The numerator is
 *	is the nth number from 1 to the denominator that is coprime with the denominator. Here, n is
 *  k minus the total just before we hit k.
 *  
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Euler%27s_totient_function
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Rishi Barnwal
 */


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

//Calculate the greatest commond divisor of a and b
long long GCD(long long a, long long b){
    if (a == 0){
        return b;
    }
    return GCD(b%a, a);
}

//Euler's phi function
int Phi(int n){
	int i, count, res = 1;
  
  	for(i = 2; i*i <= n; i++){
    	count = 0;
    	while(n % i == 0){
      		n /= i;
      		count++;
    	}
    	if(count > 0){
    		res *= (pow(i, count)-pow(i, count-1));
    	}
  	}
  	if(n > 1){
  		res *= (n-1);
  	}
  	return res;
}


int main(){

	long long input;
	vector <long long> inputVector;
	vector <long long> phiValues;
	vector <long long> numDenominators;
	long long totient;
	long long currentPlace;
	long long numerator;
	long long denominator;


	phiValues.push_back(2); //phi(1) and phi(2) are special cases
	phiValues.push_back(1);
	for(long long i = 3; i <= 200000; i++){ //Calculate phi for all integers from 3 to 20000 and store them 
		long long current = i;
		totient = Phi(current);
		/* 
		//My Euler Phi function. The one from the CMPUT 403 Code library is faster.
		totient = current;
		for(long long k = 2; k*k <= i; k++){
			if(current % k == 0){
				totient -= totient / k;
				while(current % k == 0){
					current /= k;
				}
			}
		}
		if(current > 1){
			totient -= totient / current;
		}
		*/
		phiValues.push_back(totient);
	}

	while(cin >> input){
		if(input == 0){
			break;
		}
		inputVector.push_back(input);
	}
	
	/*
	for(long long i = 0; i < inputVector.size(); i++){
		long long N = inputVector[i];
		currentPlace = 1;
		for(long long j = 0; j <= phiValues.size(); j++){
			if(currentPlace >= N){
				if(N == 1){ //For the case of N = 1
					denominator = 1;
				}else{ 
					denominator = j; 
				}
				currentPlace -= phiValues[j-1]; 
				break;
			}
			currentPlace += phiValues[j];

		}
		long long index = 0;
		for(long long j = 1; j <= denominator; j++){
			if(GCD(j, denominator) == 1){
				index++;
				if(index == N - currentPlace){
					numerator = j;
					break;
				}
			}
		}
		cout << numerator << "/" << denominator << endl;
	}
	*/	
	//cout << phiValues[0] << " " << phiValues[1] << " " << phiValues[2] << " " << phiValues[3] << " " << endl;
	for(long long i = 0; i < inputVector.size(); i++){ //WHY DOES THIS WORK AND NOT THE OLD ONE?????????????????????
		long long N = inputVector[i];
		
		if(N == 1){ //Special cases for N == 1 and N == 2
			numerator = 0;
			denominator = 1;
		}else if(N == 2){
			numerator = 1;
			denominator = 1;
		}else{
			currentPlace = 0; //Initialize the current place in the sequence
			for(long long j = 0; j <= phiValues.size(); j++){
				if(currentPlace >= N){ //If N is reached or exceeded, set the denominator to j 
					denominator = j;
					currentPlace -= phiValues[j-1]; //Go back to previous sum
					break;
				}
				currentPlace += phiValues[j]; //Add the Phi[j] to the total since the number of fractions j has is equal to Phi[j]
			}
			long long index = 0;
			for(long long j = 1; j <= denominator; j++){
				if(GCD(j, denominator) == 1){
					index++;
					if(index == N - currentPlace){
						numerator = j;
						break;
					}
				}
			}		
		}
		cout << numerator << "/" << denominator << endl;
	}
	return 0;
}