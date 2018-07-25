/* UVa problem: 408
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	 Your program will determine if choices of STEP and MOD will generate a uniform distribution of
 * 	 pseudo-random numbers. Each line of input will contain a pair of integers for STEP and MOD in 
 * 	 that order (1 ≤ ST EP, MOD ≤ 100000). For each line of input, your program should print the STEP 
 * 	 value right- justified in columns 1 through 10, the MOD value right-justified in columns 11 
 * 	 through 20 and either ‘Good Choice’ or ‘Bad Choice’ left-justified starting in column 25. The 
 * 	 ‘Good Choice’ message should be printed when the selection of STEP and MOD will generate all the 
 * 	 numbers between and including 0 and MOD − 1 when MOD numbers are generated. Otherwise, your 
 * 	 program should print the message ‘Bad Choice’. After each output test set, your program should 
 * 	 print exactly one blank line.
 *
 * Solution Summary:
 *
 *	 We simply compute the GCD of STEP and MOD. If the STEP and MOD are coprime (gcd = 1) then it's
 * 	 possible to generate all numbers between 0 and MOD - 1. If the GVD isn't 1, then some numbers
 * 	 would never appear.
 *	
 * Used Resources:
 *	
 * gcd function taken from the CMPUT 403 code archive:
 * https://github.com/UAPSPC/Code-Archive/blob/737810b431e43f932a8778539a2d744431ed1935/num_theory/gcd.cpp
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Rishi Barnwal
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//Function to get GCD of a and b
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){
	long long STEP, MOD;
	vector<long long> inputs; //Vector of STEPs and MODs

	while(cin >> STEP >> MOD){ //Read in inputs
		inputs.push_back(STEP);
		inputs.push_back(MOD); 
	}

	for(int i = 0; i < inputs.size(); i+=2){

		STEP = inputs[i];
		MOD = inputs[i+1];

		cout << setw(10) << right << STEP << setw(10) << right <<  MOD; 

		if(gcd(STEP, MOD) == 1){
			cout << "    Good Choice" << endl << endl;
		}else{
			cout << "    Bad Choice" << endl << endl;
		}
	}
	return 0;
}