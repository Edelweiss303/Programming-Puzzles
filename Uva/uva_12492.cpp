/* UVa problem: 12492
 *
 * Topic: Combinatorics
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	An interesting property of the Rubik’s Cube is that any sequence of movements, if applied repeatedly,
 *  causes the cube to return to its original state (the state it had before the first application of the
 *  sequence). For example, after four applications of the sequence B the cube returns to its original state.
 *  You must write a program that, given a sequence of movements, determines the minimum number
 *  of complete applications of that sequence to make the cube return to its original state.
 *  The input contains several test cases. Each test case is described in a single line, which contains the
 *  sequence of movements. For each test case your program must print a single line, containing a single 
 *  integer, indicating the minimum number of complete applications of the given sequence to make the hub 
 *  return to its original state.
 * 
 * Solution Summary:
 *	
 *	We can represent the Rubik's cube using an array from 0 to 53, with each square on the cube represented 
 *	as shown at the bottom of the page. Using a function to rotate each face clockwise and counter clockise
 *	as well as a function to rotate the edge along each face clockwise and counter clockwise, we can simulate
 *	any sequence of moves. We simply repeat each move until the array return to 0 to 53 and count how many times
 *	the sequence was repeated.
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

int cube[54]; //The cube array

//This function rotates a face clockwise by reassigning elements in the array.
//We ignore the centre square because it never moves
void RotateFaceClockwise(int a, int b, int c, int d, int e, int f, int g, int h){
	int tempA = cube[a];
	int tempB = cube[b];
	cube[a] = cube[g];
	cube[b] = cube[h];
	cube[g] = cube[e];
	cube[h] = cube[f];
	cube[e] = cube[c];
	cube[f] = cube[d];
	cube[c] = tempA;
	cube[d] = tempB;
}
//Same idea, except counter clockwise
void RotateFaceCounterClockwise(int a, int b, int c, int d, int e, int f, int g, int h){
	int tempA = cube[a];
	int tempB = cube[b];
	cube[a] = cube[c];
	cube[b] = cube[d];
	cube[c] = cube[e];
	cube[d] = cube[f];
	cube[e] = cube[g];
	cube[f] = cube[h];
	cube[g] = tempA;
	cube[h] = tempB;
}
//Same idea as above, except with the edges surrounding a face
void RotateBorderClockwise(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l){
	int tempA = cube[a];
	int tempB = cube[b];
	int tempC = cube[c];
	cube[a] = cube[j];
	cube[b] = cube[k];
	cube[c] = cube[l];
	cube[j] = cube[g];
	cube[k] = cube[h];
	cube[l] = cube[i];
	cube[g] = cube[d];
	cube[h] = cube[e];
	cube[i] = cube[f];
	cube[d] = tempA;
	cube[e] = tempB;
	cube[f] = tempC;
}
//Same idea, except counter clockwise
void RotateBorderCounterClockwise(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l){
	int tempA = cube[a];
	int tempB = cube[b];
	int tempC = cube[c];
	cube[a] = cube[d];
	cube[b] = cube[e];
	cube[c] = cube[f];
	cube[d] = cube[g];
	cube[e] = cube[h];
	cube[f] = cube[i];
	cube[g] = cube[j];
	cube[h] = cube[k];
	cube[i] = cube[l];
	cube[j] = tempA;
	cube[k] = tempB;
	cube[l] = tempC;
}

bool CompareCubes(){
	for(int i=0; i<54; i++) {
        if (cube[i] != i){
        	return false;
        }
    }
    return true;
}


int main() { 

	string input;
	int count;
	
	while(cin >> input){
		for(int i = 0; i < 54; i++){ //Reset the array for every new sequence
			cube[i] = i;
		}
		count = 0;
		//The following do-while loop executes each sequence using the mapping shown at the bottom of the page
		do{
			for(string::iterator it = input.begin(); it != input.end(); it++){
				if(*it == 'F'){
					RotateFaceClockwise(9, 10, 11, 14, 17, 16, 15, 12);
					RotateBorderClockwise(6, 7, 8, 45, 48, 51, 20, 19, 18, 44, 41, 38);
				}else if(*it == 'f'){
					RotateFaceCounterClockwise(9, 10, 11, 14, 17, 16, 15, 12);
					RotateBorderCounterClockwise(6, 7, 8, 45, 48, 51, 20, 19, 18, 44, 41, 38);
				}else if(*it == 'B'){
					RotateFaceClockwise(27, 28, 29, 32, 35, 34, 33, 30);
					RotateBorderClockwise(24, 25, 26, 53, 50, 47, 2, 1, 0, 36, 39, 42);
				}else if(*it == 'b'){
					RotateFaceCounterClockwise(27, 28, 29, 32, 35, 34, 33, 30);
					RotateBorderCounterClockwise(24, 25, 26, 53, 50, 47, 2, 1, 0, 36, 39, 42);
				}else if(*it == 'U'){
					RotateFaceClockwise(0, 1, 2, 5, 8, 7, 6, 3);
					RotateBorderClockwise(33, 34, 35, 47, 46, 45, 11, 10, 9, 38, 37, 36);
				}else if(*it == 'u'){
					RotateFaceCounterClockwise(0, 1, 2, 5, 8, 7, 6, 3);
					RotateBorderCounterClockwise(33, 34, 35, 47, 46, 45, 11, 10, 9, 38, 37, 36);
				}else if(*it == 'D'){
					RotateFaceClockwise(18, 19, 20, 23, 26, 25, 24, 21);
					RotateBorderClockwise(15, 16, 17, 51, 52, 53, 29, 28, 27, 42, 43, 44);
				}else if(*it == 'd'){
					RotateFaceCounterClockwise(18, 19, 20, 23, 26, 25, 24, 21);
					RotateBorderCounterClockwise(15, 16, 17, 51, 52, 53, 29, 28, 27, 42, 43, 44);
				}else if(*it == 'L'){
					RotateFaceClockwise(36, 37, 38, 41, 44, 43, 42, 39);
					RotateBorderClockwise(0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33);
				}else if(*it == 'l'){
					RotateFaceCounterClockwise(36, 37, 38, 41, 44, 43, 42, 39);
					RotateBorderCounterClockwise(0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33);
				}else if(*it == 'R'){
					RotateFaceClockwise(45, 46, 47, 50, 53, 52, 51, 48);
					RotateBorderClockwise(8, 5, 2, 35, 32, 29, 26, 23, 20, 17, 14, 11);
				}else if(*it == 'r'){
					RotateFaceCounterClockwise(45, 46, 47, 50, 53, 52, 51, 48);
					RotateBorderCounterClockwise(8, 5, 2, 35, 32, 29, 26, 23, 20, 17, 14, 11);
				}
	    		
			}
			count++;
			
		}while(!CompareCubes());

		cout << count << endl;
	}
	/*
			UP
				0	1	2 
				3	4	5
				6	7	8

LEFT			FRONT			RIGHT
36	37	38		9	10	11		45	46	47
39	40	41		12	13	14		48	49	50
42	43	44		15	16	17		51	52	53
			
		DOWN	18	19	20
				21	22	23
				24	25	26

		BACK	27	28	29
				30	31	32
				33	34	35
	*/
    return 0;  
}  