/* Kattis problem: mirror
 *
 * Topic: Other
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	Atrebla is developing a new smartphone camera app that she believe will be the 
 * 	next big hit on the app store. Camera apps usually display the image mirrored 
 *	left-to-right on the screen, so that what you see on the screen matches the 
 *	movement of your face. To help her camera app stand out from the rest, Atrebla 
 *	will be adding a unique effect that mirrors an image both left-to-right and 
 *	top-to-bottom. Help her implement this feature. The first line contains a 
 *	single integer T≤100 giving the number of test cases. Each test case starts 
 *	with a line containing an integer R (1≤R≤20), the number of rows in the image, 
 *	and an integer C (1≤C≤20), the number of columns. The next R lines contain C 
 *	characters, all of which are either . or *. For each test case, output a line 
 *	containing “Test x” where x is the test case number starting from 1. After that, 
 *	output the mirrored image.
 *
 * Solution Summary:
 *
 *	Simply store each row in a string of vectors. Reverse each row, then reverse
 *	the whole vector and then print each row.
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

	int numCases; //Number of test cases
	int R, C; //Rows and columns. C is unnecessary 
	string row; //Each row
	vector<string> rowList; //Vector to hold rows

	cin >> numCases;

	for(int i = 0; i < numCases; i++){
		
		cin >> R >> C;
		rowList.clear();

		for(int j = 0; j < R; j++){
			cin >> row;
			reverse(row.begin(), row.end()); //reverse the row before putting it in the vector
			rowList.push_back(row);
		}

		reverse(rowList.begin(), rowList.end()); //reverse the vector

		cout << "Test " << i + 1 << endl;
		for(int j = 0; j < R; j++){
			cout << rowList[j] << endl;
		}
	}

	return 0;
}