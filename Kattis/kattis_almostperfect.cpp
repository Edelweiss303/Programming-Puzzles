/* Kattis problem: almostperfect
 *
 * Topic: Arithmetic
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   A positive integer pp is called a perfect number if all the proper divisors of pp sum to pp exactly. 
 *   Integer dd is a proper divisor of pp if 1≤d≤p−11≤d≤p−1 and pp is evenly divisible by dd. 
 *   For example, the number 2828 is a perfect number, since its proper divisors 
 *   (which are 11, 22, 44, 77 and 1414) add up to 2828.

 *   Perfect numbers are rare; only 1010 of them are known. 
 *   Perhaps the definition of perfection is a little too strict. 
 *   Instead, we will consider numbers that we’ll call almost perfect. 
 *   Positive integer pp is almost perfect if the proper divisors of pp sum to a value that differs 
 *   from pp by no more than two.
 *
 *
 * Solution Summary:
 *
 *  Find all the factors of the input integer, searching up to sqrt(input), adding them up, 
 *  subtracting the input from that total, and, if the input is a perfect square, subtracting the square
 *  root of the input from the total.
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
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> 

using namespace std;

vector <int> inputVector;
vector <int> factors;
int input;
int total = 0;
int k;
int main(){
	while(cin >> input){
		inputVector.push_back(input);
		k = 1;
		factors.clear();
		while(k*k <= input){
			if(input % k == 0){
				factors.push_back(k);
				factors.push_back(input/k);
			}
			k++;
		}

		total = 0;

		for(int i = 0; i < factors.size(); i++){
			total += factors[i];
		}

		total = total - input;

		if(find(factors.begin(), factors.end(), sqrt(input)) != factors.end()){
			total = total - sqrt(input);
		}

		if(total == input){
			printf("%d perfect\n", input);
		}else if(abs(total - input) <= 2){
			printf("%d almost perfect\n", input);
		}else{
			printf("%d not perfect\n", input);
		}
	}
}








