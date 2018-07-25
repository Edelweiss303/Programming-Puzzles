/* Kattis problem: squaredeal
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Given the dimensions of three rectangles, determine if all three can be 
 *	glued together, touching just on the edges, to form a square. You may 
 *	rotate the rectangles. For example, Figure 1 shows successful constructions 
 *	for the first two sample inputs. The input consists of three lines, with 
 *	line j containing integers Hj and Wj, designating the height and width of a 
 *	rectangle, such that 100≥Hj≥Wj≥1, and such that H1≥H2≥H3. Output a line 
 *	saying YES if they can be glued together to form a square. Output NO otherwise.
 *	
 *
 * Solution Summary:
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

using namespace std;

int main(){
	
	//Height and Width of each rectangle
	int H1, W1; 
	int H2, W2;
	int H3, W3;
	string result = "NO";

	cin >> H1 >> W1	>> H2 >> W2	>> H3 >> W3;

	if(H1 + H2 + H3 == W1){
		result = "YES";
	}else if(W1 + W2 + W3 == H1){
		result = "YES";
	}else if(W1 + W2 == H2 + W3){
		result = "YES";
	}else if(W1 + W3 == H3 + W2){
		result = "YES";
	}else if(W2 + W3 == H2 + W1){
		result = "YES";
	}else if(H1 + W2 + W3 == H1){
		result = "YES";
	}else if(H2 + W1 + W3 == H3){
		result = "YES";
	}else if(H3 + W1 + W2 == H2){
		result = "YES";
	}

	cout << result << endl;

	return 0;
}