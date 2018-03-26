/* UVa problem: 374
 *
 * Topic: Number Theory
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *   Calculate R := B^P mod M for large values of B, P, and M using an efficient algorithm.
 *
 * Solution Summary:
 *	  
 *	First convert the exponent P into binary. Then iterate through each bit starting from the 
 * 	least significant one. If the bit is one, set the result R to (R*B)%M. B is then set to (B*B)%M. 
 *	
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
#include <math.h>
#include <vector>
using namespace std;


long long B; //Base
long long P; //Exponent
long long M; //Modulo
long long R; //Result

vector<long long> binary; //Vector to hold binary bits

int main(){

	while(cin >> B >> P >> M){
		binary.clear();

		while(P != 0){ //Convert P to binary and store the bits in the vector backwards
			binary.push_back(P % 2);
			P /= 2;
		}

		R = 1; //Initialize result to 1

		for(int i = 0; i < binary.size(); i++){ //Iterate through each bit
			if(binary[i] == 1){
				R = (R*B) % M;
			}
			B = (B*B) % M;
		}
		cout << R << endl;
	}

	return 0;
}