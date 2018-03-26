/* UVa problem: 10608
 *
 * Topic: Data Structures
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Input consists of several datasets. The first line of the input consists of a line with the number of test
 *	 cases to follow.
 *	 The first line of each dataset contains the numbers N and M, where N is the number of town’s
 *	 citizens (1 ≤ N ≤ 30000) and M is the number of pairs of people (0 ≤ M ≤ 500000), which are known
 *	 to be friends. Each of the following M lines consists of two integers A and B (1 ≤ A ≤ N, 1 ≤ B ≤ N,
 *	 A ̸= B) which describe that A and B are friends. There could be repetitions among the given pairs.
 *
 * Solution Summary:
 *
 *   Using the disjoint-set data structure, we start with creating N different sets. Each set containing
 *   1 integer from 1 to N. We then compare every pair A, B and if they have different representatives within
 *   their sets, we join those two sets. After all pairs are compared, we find the lengths of each set and print
 *   the largest one. 
 *
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

int numDataSets = 0; //Number of data sets to follow
int N; //Population
int M; //Number of pairs which are known to be friends
int A, B; //Pairs which are known to be friends 
vector <int> pairs; //Vector for those pairs
vector <vector<int>> listOfSets; //Vector of int vectors representing disjoint sets
vector <int> friendLengths;

//This funtion joins the set containing A and the set containing B
void Union(int A, int B){
	int index1;
	int index2;
	for(int i = 0; i < listOfSets.size(); i++){
		if(find(listOfSets[i].begin(), listOfSets[i].end(), A) != listOfSets[i].end()){
			index1 = i;
		}		
	}
	for(int j = 0; j < listOfSets.size(); j++){
		if(find(listOfSets[j].begin(), listOfSets[j].end(), B) != listOfSets[j].end()){
			index2 = j;
		}		
	}

	listOfSets[index1].insert(listOfSets[index1].end(), listOfSets[index2].begin(), listOfSets[index2].end());
	sort(listOfSets[index1].begin(), listOfSets[index1].end());
	listOfSets.erase(listOfSets.begin() + index2);

}

//This function finds the 'representative' (the largest element of a disjoint set) 
//of whatever set an element belongs to
int Find(int element){
	for(int i = 0; i < listOfSets.size(); i++){
		if(find(listOfSets[i].begin(), listOfSets[i].end(), element) != listOfSets[i].end()){
			return *max_element(listOfSets[i].begin(), listOfSets[i].end());
		}		
	}
	return 0;
}

//create N different sets, each one containing a single int from 1 to N
void Create(int N){
	for(int k = 0; k < N; k++){
		vector<int> set; //a single set
    	set.push_back(k+1);
    	listOfSets.push_back(set);
	}

}





int main(){

	scanf("%d\n", &numDataSets);
	for(int i = 0; i < numDataSets; i++){
		pairs.clear();
		listOfSets.clear();
		friendLengths.clear();
		scanf("%d %d\n", &N, &M);

		for(int j = 0; j < M; j++){
			scanf("%d %d\n", &A, &B);
			//printf("A: %d B: %d\n", A, B);
			pairs.push_back(A);
			pairs.push_back(B);
		}

		Create(N);

		//Compare 
		for(int l = 0; l < M*2; l+=2){
			A = pairs[l];
			B = pairs[l+1];
			//printf("A: %d B: %d\n", A, B);
			if(Find(A) != Find(B)){
				Union(A, B);
			}
		}

		//Find the lengths of each set and add them to a vector
		for(int k = 0; k < listOfSets.size(); k++){
			//printf("%lu\n", listOfSets[k].size());
			friendLengths.push_back(listOfSets[k].size());
		}

		//Print the length of the longest set
		printf("%d\n", *max_element(friendLengths.begin(), friendLengths.end()));
	}
	return 0;
}





























