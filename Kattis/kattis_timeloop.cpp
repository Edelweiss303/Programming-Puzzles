/* Kattis problem: timeloop
 *
 * Topic: Other
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	Input consists of a single integer N (1≤N≤100).
 *	Output the entire wizard’s spell by counting from 1 to N, giving one number and “Abracadabra” per line.
 *
 * Solution Summary:
 *
 *	Take N as input and output n Abracadabra per line from a for loop from n = 1 to N;
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
#include <string>
#include <algorithm>

using namespace std;

int main(){

	int N;
	cin >> N;

	for(int i = 1; i <= N; i++){
		cout << i << " Abracadabra" << endl;
	}
	return 0;
}