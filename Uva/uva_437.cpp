/* UVa problem: 437
 *
 * Topic: Graph Traversal
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	The babylonians had n types of blocks, and an unlimited supply of blocks of each type.
 *	Each type-i block was a rectangular solid with linear dimensions (xi, yi, zi). A block could
 *	be reoriented so that any two of its three dimensions determined the dimensions of the base
 *	and the other dimension was the height. They wanted to construct the tallest tower possible 
 *	by stacking blocks. The problem was that, in building a tower, one block could only be placed 
 *	on top of another block as long as the two base dimensions of the upper block were both 
 *	strictly smaller than the corresponding base dimensions of the lower block. This meant, for 
 *	example, that blocks oriented to have equal-sized bases couldn’t be stacked. Your job is to 
 *	write a program that determines the height of the tallest tower the babylonians can build 
 *	with a given set of blocks. The input file will contain one or more test cases. The first 
 *	line of each test case contains an integer n, representing the number of different blocks 
 *	in the following data set. The maximum value for n is 30. Each of the next n lines contains 
 *	three integers representing the values xi, yi and zi. Input is terminated by a value of zero 
 *	(0) for n. For each test case, print one line containing the case number (they are numbered 
 *	sequentially starting from 1) and the height of the tallest possible tower in the format
 *	‘Case case: maximum height = height’
 * 
 * Solution Summary:
 *	
 *	We can use the idea for the longest increasing subsequence. First we take in each orientation 
 *	of each block into a vector. We then use a custom sort function to sort the vector from 
 *	smallest length and width to largest. We the find the total height of each possible subsequence
 *	and simply print the longest one.
 *
 * Used Resources:
 *
 *	https://en.wikipedia.org/wiki/Longest_increasing_subsequence
 *	https://en.wikipedia.org/wiki/Directed_acyclic_graph
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
#include <algorithm>
#include <stack>
using namespace std;

//Struct to hold dimensions of each block
struct block{
	int l;
	int w;
	int h;
};

vector<block> blocks; //Vector to hold blocks

//Inserts each permutation of the dimensions of a block into the vector
void InsertBlocks(int x, int y, int z){
	block b;

	b.l = x;
	b.w = y; 
	b.h = z;
	blocks.push_back(b);

	b.l = x;
	b.w = z; 
	b.h = y;
	blocks.push_back(b);

	b.l = y;
	b.w = z;
	b.h = x;
	blocks.push_back(b);

	b.l = y;
	b.w = x; 
	b.h = z;
	blocks.push_back(b);

	b.l = z;
	b.w = x;
	b.h = y;
	blocks.push_back(b);

	b.l = z;
	b.w = y; 
	b.h = x;
	blocks.push_back(b);
}

//Comparison function to sort the vector of blocks
bool CompareBase(const block &a, const block &b) {
    if (a.l == b.l){
        return a.w < b.w;
    }
    return a.l < b.l;
}

int main(){
	int caseNumber = 0;
	int n;
	int x, y, z;
	int maxHeight;
	vector<int> heights; //Vector to hold the heights of each subsequence

	while(cin >> n){
		if(n == 0){
			break;
		}
		blocks.clear();
		for(int i = 0; i < n; i++){
			cin >> x >> y >> z;
			InsertBlocks(x, y, z);
		}
		sort(blocks.begin(), blocks.end(), CompareBase);

		/*
		cout << endl;
		for(int i = 0; i < blocks.size(); i++){
			cout << blocks[i].l << " " << blocks[i].w << " " << blocks[i].h << endl;
		}
		
		cout << endl;
		*/

		heights.clear();

        for (int i = 0; i < n*6; i++) { //End subsequences at each element
            heights.push_back(blocks[i].h); //Insert the height of the last element in the subsequence
            for (int j = 0; j < i; j++){
                if (blocks[j].l < blocks[i].l && blocks[j].w < blocks[i].w && heights[j] + blocks[i].h > heights[i]){ 
                    heights[i] = heights[j] + blocks[i].h; //Reset the total height if the previous block has a smaller length and  
                }										   //width and if the previous total height plus the height of the last block 
            }											   //in the sequence is greater than the current total height.
        }
        /*
        for(int i = 0; i < heights.size(); i++){
			cout << heights[i] << endl;
		}
		*/
        caseNumber++;
        maxHeight = *max_element(heights.begin(), heights.end()); //Find the max height
        cout << "Case " << caseNumber << ": maximum height = " << maxHeight << endl; //
	}
	return 0;
}