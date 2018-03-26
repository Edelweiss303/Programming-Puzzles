/* UVa problem: 11955
 *
 * Topic: Arithmetic
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   There is a number of tests T (T ≤ 100) on the first line. After T test follows. Each test is written on a
 * 	 single line in form of ‘(a+b)^k’. Where a and b are same variables names. Variables names are strings
 * 	 constructed from ‘a’–‘z’ characters. For each test output a single line ‘Case N: T’. Where N is the test number 
 *	 (starting from 1) and T is an expanded expression.
 *
 * Solution Summary:
 *	  First compute the first 50 rows of Pascal's triangle and store it in a 2D array. These values are the coefficents
 *	  for the expanded equations. For each case, parse the string for each term, a and b, and the power n. Then 
 * 	  initialize a blank string and iteratively add to to it using the formula 
 * 	  (a + b)^n = a^k + a^(k−1)b + a^(k−2)b^2 + . . . + b^k. Also add the coefficents from the nth row of the 
 * 	  previously calculated triangle only if it is not 1. Same rule applies for the exponents. 
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
#include <sstream>
#include <algorithm>

using namespace std;


int numCases; //Number of test cases.
string inputLine; //Each test case.
vector <string> cases; //Vector of all the test cases.
long long coefficients[51][51]; //2D array to hold the pascal triangle

int main(int argc, char** argv) {
	
    cin >> numCases; //Take in number of test cases
    for(int i = 0; i <= numCases; i++){ //Take in the next numLines 
        getline(cin, inputLine);
        cases.push_back(inputLine);
    }
    cases.erase(cases.begin()); //Erase the first element in the vector because it's just a blank line.

  	for (int line = 0; line <= 50; line++){ //Calculate the first 50 rows of Pascal's triangle here
    	for (int i = 0; i <= line; i++){
      		if (line == i || i == 0){
           		coefficients[line][i] = 1; //Edges of the triangle are just 1
      		}else{ 
      			coefficients[line][i] = coefficients[line-1][i-1] + coefficients[line-1][i]; //Inner values are the sum of the two values just above it
      		}
    	}
  	}

    for(int i = 0; i < cases.size(); i++){
    	string expanded = "Case " + to_string(i+1) + ": "; //Initialize the blank string with case number
    	int n = stoi(cases[i].substr(cases[i].find('^') + 1)); //Get the exponent
    	cases[i].erase(cases[i].find('('), 1); 
    	string a = cases[i].substr(0, cases[i].find('+')); //Get the first term, a
    	string b = cases[i].substr(cases[i].find('+') + 1, cases[i].find(')') - cases[i].find('+') - 1); //Get the second term, b
    	if (n == 1){
    		expanded += a + "+" + b; //If exponent is 1, just output a + b
    	}else{
    		int j = 0;
    		while(j <= n){
    			if(j == 0){ //If at the beginning of the string, add a^n
    				expanded += a + "^" + to_string(n) + "+";
    			}else if(j == n){ //If at the end of the string, add b^n
    				expanded += b + "^" + to_string(n);       
    			}else{
    				if(n - j == 1){ //Only output exponent if it isn't 1
    					expanded += to_string(coefficients[n][n-j]) + "*" + a + "*";
    				}else{
    					expanded += to_string(coefficients[n][n-j]) + "*" + a + "^" + to_string(n-j) + "*";
    				}

    				if(j == 1){ //Only output exponent if it isn't 1
    					expanded += b + "+";
    				}else{
    					expanded += b + "^" + to_string(j) + "+";
    				}
    			}
    			j++;
    		}
    	}
    	cout << expanded << endl; //Output the expanded equation
    }

   return 0;
}













