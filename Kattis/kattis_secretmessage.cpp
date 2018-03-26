/* Kattis problem: divideby100
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Let L be the length of the original message, and M be the smallest square 
 *	number greater than or equal to L. Add (M−L) asterisks to the message, 
 *	giving a padded message with length M. Use the padded message to fill a 
 *	table of size K×K, where K^2=M. Fill the table in row-major order 
 *	(top to bottom row, left to right column in each row). Rotate the table 90 
 *	degrees clockwise. The encrypted message comes from reading the message in 
 *	row-major order from the rotated table, omitting any asterisks.
 *	The first line of input is the number of original messages, 1≤N≤100. The 
 *	following N lines each have a message to encrypt. Each message contains only 
 *	characters a–z (lower and upper case), and has length 1≤L≤10000.
 *	For each original message, output the secret message.
 *
 * Solution Summary:
 *
 *	Precompute all squares under 10,000 and find the first one equal to or greater
 *	than the message length L. Add M-L '*'s to the original message then, working from 
 * 	the last character - K backwards, iteratively add every Kth letter to a new string only if it
 * 	isn't a '*'. Once the beginning is reached, start again from the last character -K + 1 and so on.
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
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
	int N;
	string msg;
	vector<string> messages;
	vector<int> squares;
	cin >> N;
	int L;
	int M;
	int k = 1;

	while(1) { //Pre-calculate all squares under 10,000
		if(k*k > 10000){ 
			break;
		}
		squares.push_back(k*k);
		k++;
	}

	for(int i = 0; i < N; i++){
		cin >> msg;
		messages.push_back(msg);
	}

	for(int i = 0; i < messages.size(); i++){
		msg = messages[i];
		L = msg.size();

		for(int j = 0; j < squares.size(); j++){ //Find the first square equal to or larger than M
			if(squares[j] >= L){
				M = squares[j];
				break;
			}
		}

		for(int j = 0; j < M - L; j++){ //Append '*'s
			msg.append("*");
		}

		int K = sqrt(M);
		string scrtMsg = ""; //Initialize result
		int index = M - K;
		int pass = 1; //Current passes through string

		while(scrtMsg.length() != M - (M-L)){

			if(msg[index] != '*'){
				scrtMsg += msg[index]; //Add character to result if it isn't '*'
			}

			if(index - K < 0){ //Beginning is reached
				index = M - K + pass; //Reset index
				pass++;
			}else{
				index -= K; //Every Kth character
			}
		}

		cout << scrtMsg << endl;

	}




	return 0;
}