/* Kattis problem: jughard
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Given the volumes of the two jugs, is it possible to have one jug with some specific volume of water?
 *	The first line contains T, the number of test cases (1≤T≤100000). Each test case is composed of three 
 *	integers: a, b, and d, where a and b (1≤a,b≤10000000) are the volumes of the two jugs, and d is the 
 *	desired volume of water to be generated. You can assume that d≤max(a,b).
 *	For each of the T test cases, output either Yes or No, depending on whether the specific volume of 
 *	water can be placed in one of the two jugs.
 * 
 * Solution Summary:
 *	
 *	If the volume of water we want is divisible by the gcd of the volume of the two jugs, then we can 
 *	place that volume in one of the jugs. 
 *
 * Used Resources:
 *
 *	gcd function from the CMPUT 403 Code library: 
 *	https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/gcd.cpp
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
using namespace std;

//calculate gcd
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){

	int T;
	int a, b, d;

	cin >> T;

	while(T--){
		cin >> a >> b >> d;

		if(d % gcd(a, b) == 0){ //The main calculation. see if the gcd divides d
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}