/* UVa problem: 100
 *
 * Topic: Other
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   For any two numbers i and j you are to determine the maximum cycle length over all numbers
 *	 between and including both i and j
 *
 * Solution Summary:
 *
 *   Iterate through every number between i and j, calculate the cycle length for each one, store that length 
 *	 in an array and print the largest one. 
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
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <algorithm> 
#include <string>
#include <sstream>

using namespace std;

int main(){
	int i;
	vector <int> i_vec; 
	int j;
	vector <int> j_vec;
	string input = "";
	string line = "";
	int range;
	int counter = 0;
	int max = 0;
	int currentInt;
	vector <int> maxValues;

  	while (getline(cin, line)) {
    	if (line == ""){
        	break;
    	}
    	input += " " + line;
  	}
  	stringstream stream(input);

  	while(1) {
  		int n;
  		stream >> n;
  		if(counter % 2 == 0){
  			i_vec.push_back(n);
  		}else{
  			j_vec.push_back(n);
  		}
  		counter++;
  		if(!stream){
  			counter = 0;
  			break;
  		}
  	}
  	int size = static_cast<int>(i_vec.size());

  	for(int c = 0; c <= size-2; c++){
  		i = i_vec[c];
  		j = j_vec[c];
  		range = abs(i - j);
	  	int cycleLengths[range];
	  	if(i > j){
	  		for(int n = j; n <= i; n++){
	  			currentInt = n;
	  			counter = 1;
	  			while(currentInt != 1){
	  				if(currentInt % 2 == 1){
	  					currentInt = (3*currentInt)+1;
	  					counter++;
	  				}else{
	  					currentInt = currentInt/2;
	  					counter++;
	  				}
	  			}
	  			cycleLengths[range - (i-n)] = counter;
	  		}
	  	}else{
	  		for(int n = i; n <= j; n++){
	  			currentInt = n;
	  			counter = 1;
	  			while(currentInt != 1){
	  				if(currentInt % 2 == 1){
	  					currentInt = (3*currentInt)+1;
	  					counter++;
	  				}else{
	  					currentInt = currentInt/2;
	  					counter++;
	  				}
	  			}
	  			cycleLengths[range - (j-n)] = counter;
	  		}

	  	}
	  	max = 0;
	  	for(int k = 0; k <= range; k++){
	  		if(cycleLengths[k] > max){
	  			max = cycleLengths[k];
	  		}
	  	}
	   	maxValues.push_back(max);
	   	printf("%d %d %d\n", i, j, max);
	}

	return 0;
}