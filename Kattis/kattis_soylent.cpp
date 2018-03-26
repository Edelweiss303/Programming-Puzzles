/* Kattis problem: soylent
 *
 * Topic: Other
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	Yraglac can only consume an integer number of bottles, and needs to 
 *	consume at least his daily calorie requirement. The first line contains 
 *	a single integer T≤1000 giving the number of test cases. Each test case 
 *	consists of a single line with an integer N (0≤N≤10000), the number of 
 *	calories Yraglac needs in a day. For each test case, output a single 
 *	line containing the number of bottles Yraglac needs to consume for the day.
 *
 * Solution Summary:
 *  
 * 	We take N mod 400. If it is zero, output N/400, otherwise output (N/400) + 1. 
 * 	This is because he can ony consume integer numbers of bottles and the code always rounds
 *	down.
 *
 * Used Resources:
 *
 *	  
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

using namespace std;

int main() {

	int T;
	int calories;
	vector<int> N;
	cin >> T;

	for(int i = 0; i < T; i++){
		cin >> calories;
		N.push_back(calories);
	}

	for(int i = 0; i < T; i++){
		if(N[i]%400 == 0){
			cout << N[i]/400 << endl;
		}else{
			cout << N[i]/400 + 1 << endl;
		}
	}
}
