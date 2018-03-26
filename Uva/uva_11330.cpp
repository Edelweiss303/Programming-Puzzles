/* UVa problem: 11330
 *
 * Topic: Combinatorics
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	 As usual, the first line contains the number of test cases. Each test case consists of a single line starting
 *	 with total number of pairs of shoes n. The following 2n numbers describe the initial arrangement of
 * 	 shoes on the rack. Each shoe is labeled by a positive integer at most 10,000 where two shoes share the
 * 	 same label if and only if they are part of the same pair. Both the left and right shoes of a given pair
 * 	 will be present (remember that left and right shoes alternate). For each test case, output one line 
 * 	 containing a single number – the minimum number of swaps needed to pair up all shoes.
 *	
 * 
 * Solution Summary:
 *	
 *	 Start by storing the left shoes as indexes that point to the right shoes. Find the first place where the 
 * 	 index does not match the shoe and set that shoe as the current shoe. We set a temp shoe to shoes[currentShoe]
 *	 and set shoes[currentShoe] to currentShoe. A count is then incremented and the new current shoe is set to temp. 
 * 	 This is continued until the list of all shoes is equal to their indices. The result is the sum of all the counts.
 *
 * Used Resources:
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
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//Why does this only work as a global variable????????
int shoes[10005]; //Array of shoes. 

  
int main() { 
	int numTestCases;
	int numShoes;
	int numSwaps;
	int left; //left shoe
	int right; //right shoe
	int currentShoe; //Shoe we're currently looking at
	int count; //Intermediate counts to add to numSwaps
	int temp; //temporary placeholder for shoe

    cin >> numTestCases;  
    for (int i = 0; i < numTestCases; i++){  
    	cin >> numShoes; 
    	 
    	for (int j = 0; j < numShoes; j++) {  
        	cin >> left >> right; //Take in left and right shoes
        	shoes[left] = right;  //Store the left shoe as an index which points to the right shoe
    	}  

    	numSwaps = 0; //Initialize number of swaps to zero

    	//start j at 1 because shoes[0] = 0
    	for (int j = 1; j <= 10005; j++) {  //WHY DOES THIS HAVE TO BE 10005 and not 10000????????????
        	if(j != shoes[j]){ //Check if there's a mismatch
        		count = 0;  
        		currentShoe = shoes[j]; //set first shoe  
        		shoes[j] = j; //Set that shoe to its index
        		while(shoes[currentShoe] != currentShoe){  
            		count++;  //increment count
            		temp = shoes[currentShoe]; //Set temp shoe 
            		shoes[currentShoe] = currentShoe;  //Set the shoe at current shoe to current shoe
            		currentShoe = temp; //Set next currentShoe

        		}  
        	numSwaps += count; //Add to total
        	}  
    	} 
    	/*
    	for(int i = 1; i <= numShoes; i++){
    		cout << shoes[i] << " ";
    	}
    	cout << endl;
    	*/
    	cout << numSwaps << endl; 
    }  
    return 0;  
}  