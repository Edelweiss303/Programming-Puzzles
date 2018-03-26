/* Kattis problem: bond
 *
 * Topic: Other
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *	 The first line will contain an integer NN, the number of Jimmy Bonds and missions (1≤N≤201≤N≤20).
 *	 The following N lines will contain NN integers between 00 and 100100, inclusive. 
 *	 The j:th integer on the ii:th line is the probability that Jimmy Bond i would successfully complete mission j, 
 *	 given as a percentage.
 * 
 *
 *
 *
 * Solution Summary:
 *
 *
 *  
 *
 *	
 * Used Resources:
 *
 *   ...
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
#include <map>
#include <string>

using namespace std;


int N; //Matrix dimensions
double percent; //
double dp[(1<<21)];
int main(){

	cin >> N;

	double matrix[N][N];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> percent;
			matrix[i][j] = percent/100;
		}
	}



	return 0;
}