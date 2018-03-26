/* Kattis problem: euclidsgame
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Two players, Stan and Ollie, play, starting with two natural numbers. 
 *	Stan, the first player, subtracts any positive multiple of the lesser 
 *	of the two numbers from the greater of the two numbers, provided that 
 *	the resulting number must be nonnegative. Then Ollie, the second player, 
 *	does the same with the two resulting numbers, then Stan, etc., alternately, 
 *	until one player is able to subtract a multiple of the lesser number from 
 *	the greater to reach 0, and thereby wins. The input consists of a number 
 *	of lines. Each line contains two positive integers less than 231 giving 
 *	the starting two numbers of the game. Stan always starts. For each line 
 *	of input, output one line saying either Stan wins or Ollie wins assuming 
 *	that both of them play perfectly.
 *
 * Solution Summary:
 *
 *
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
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "BigIntegerLibrary.hh"

using namespace std;

int main(){

	long long X;
	long long Y;
	vector <long long> inputs;

	while(cin >> X >> Y){
		if(X == 0 && Y == 0){
			break;
		}
		inputs.push_back(X);
		inputs.push_back(Y);
	}

	for(int i = 0; i < inputs.size(); i+=2){
		if(inputs[i] < inputs[i+1]){ //Make sure X is always the lower number
			X = inputs[i];
			Y = inputs[i+1]
		}else{
			X = inputs[i+1];
			Y = inputs[i]
		}


	}
	return 0;
}