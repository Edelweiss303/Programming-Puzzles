 /* UVa problem: 136
 *
 * Topic: Data Structures
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
 *	 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
 * 	 shows the first 11 ugly numbers. By convention, 1 is included.
 *   Write a program to find and print the 1500’th ugly number.
 *
 *
 * Solution Summary:
 *
 *   An ugly number is an example of a 5-Smooth number. These numbers can be created with a certain combination
 *   of multiples of 2, 3, 5. We can find the 1500th one by dynamically creating a vector with the first 1500
 *   ugly numbers. We do this by creating 3 pointer indexes that point to the next multiple of 2, 3, and 5 
 *   respectively. First we initilize a vector containing 1. We then choose the smallest of the 3 
 *   multiples as the next ugly number, in this case, 2. 2 is then added to the vector and the index for 
 *   2 is incremented and now the next lowest multiple would be 3. 3 is added to the vector and the 
 *   index for 3 is incremented. And so on and so on until the vector is filled with 1500 numbers. 
 *
 *   
 *
 * Used Resources:
 *
 *   Wikipedia article for Smooth Numbers: https://en.wikipedia.org/wiki/Smooth_number
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Rishi Barnwal
 */

#include<stdio.h>
#include<math.h>
#include<vector>
#include <algorithm>

using namespace std;

vector <int> uglyNumberVector;
int uglyNumber;

int index2 = 0; //index pointing to multiples of 2
int index3 = 0; //index pointing to multiples of 3
int index5 = 0; //index pointing to multiples of 5

int multiple2 = 2; //multiples of 2
int multiple3 = 3; //multiples of 3
int multiple5 = 5; //multiples of 5


int main(){

	uglyNumberVector.push_back(1); //Initialize Vector containing 1;

	for (int i = 1; i < 1500; i++ ) {
    	uglyNumber = min({multiple2, multiple3, multiple5}); //choose the lowest of the 3 multiples 
    	uglyNumberVector.push_back(uglyNumber); //add that to the vector       

    	//Increment the respective indexes 
    	if (uglyNumber == multiple2){             
        	index2++;        
        	multiple2 = uglyNumberVector[index2] * 2;
    	}
    	if (uglyNumber == multiple3){             
        	index3++;       
        	multiple3 = uglyNumberVector[index3] * 3;
    	}
    	if (uglyNumber == multiple5){             
        	index5++;       
        	multiple5 = uglyNumberVector[index5] * 5;
    	}
	}

	printf("The 1500'th ugly number is %d.\n", uglyNumber); //print the 1500th ugly number 

}