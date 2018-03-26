/* Uva problem: 11512
 *
 * Topic: Strings
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *	 The first line of the input contains an integer T specifying the number of test cases (1 ≤ T ≤ 100). Each
 *	 test case consists of a single line of text that represents a DNA sequence S of length n (1 ≤ n ≤ 1000).
 *	 You can suppose that each sequence S only contains the letters ‘A’, ‘C’, ‘G’ and ‘T’.
 * 	 For each sequence in the input, print a single line specifying the largest substring of S that appears two
 * 	 or more times repeated in S, followed by a space, and the number of ocurrences of the substring in S.
 *	 If there are two or more substrings of maximal length that are repeated, you must choose the least
 * 	 according to the lexicographic order.
 *   If there is no repetition in S, print ‘No repetitions found!’.
 *
 *
 * Solution Summary:
 *
 *  We first compute the suffix array for the given input. I accomplished this by creating a vector
 *  of structs consisting of a string (the suffix) and integer (index). This vector was then sorted
 *  alphabetically by the string, thus reordering the indexes into the suffix array. I then used this 
 *  suffix array to build an LCP array using Kasai's Algorithm. The maximum value value of the LCP array
 *  is the length of the longest common substring. The position of this max value in the LCP array 
 *  is also the position of the longest common substring in the suffix vector. 
 *  I then count how many times this substring appears in the current input.
 *	
 * Used Resources:
 *   https://en.wikipedia.org/wiki/Suffix_array
 *   https://en.wikipedia.org/wiki/LCP_array
 *   I used the code here to compute the LCP array: http://codeforces.com/blog/entry/12796
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Rishi Barnwal
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Information about a suffix to store in a vector
struct suffix{
    string suffix;
    int index;
    
};

// Used by sort() to compare two suffixes and put them in alpabetical order
int compare(struct suffix a, struct suffix b){
    return strcmp(a.suffix.c_str(), b.suffix.c_str()) < 0 ? 1 : 0;
}

int N; // Number of test cases
vector <string> sequences; // List of inputs
vector <suffix> suffixVector; // Suffix array

string input;
int maxLCP; // Maximum of all LCPs
int pos; // Position of max LCP
int lcp; // LCP counter



int main(){

	struct suffix s;
	cin >> N; //Number of inputs
	for(int i = 0; i < N; i++){
		cin >> input;
		sequences.push_back(input); //add inputs to vector
	}

	for (int i = 0; i < sequences.size(); i++){ // Iterate through each input

		string currentInput = sequences[i]; 
		suffixVector.clear(); // Clear the vector of suffixes
		N = currentInput.length(); // Get the length of the currentInput

        vector <int> rankVector(N, 0); // Initialize the rank array to the length of the current input
        vector <int> lcpVector(N, 0); // Initialize the LCP array to the length of the current input


        // Build the suffix array here
		for (int i = N - 1; i >= 0; i--){
			s.index = i;
			s.suffix = currentInput.substr(i);
			suffixVector.push_back(s);
        }

        sort(suffixVector.begin(), suffixVector.end(), compare); // Sort the suffix array

         // Build the rank vector here
         // Also called the inverse suffix array
         for (int i = 0; i < N; i++){
            rankVector[suffixVector[i].index] = i;
         }

         // This for loop is Kasai's algorithm to build the LCP array using the suffix and rank array
         for(int i = 0; i < N; i++, lcp ? lcp-- : 0){

            if(rankVector[i] == N - 1){
                lcp = 0;
                continue;
            }

            int j = suffixVector[rankVector[i] + 1].index;

            while(i + lcp < N && j + lcp < N && currentInput.substr(i+lcp, 1) == currentInput.substr(j+lcp, 1)){
                lcp++;
            }
            lcpVector[rankVector[i]] = lcp;
        }

        maxLCP = *max_element(lcpVector.begin(), lcpVector.end()); // Get the longest LCP
        pos = find(lcpVector.begin(), lcpVector.end(), maxLCP) - lcpVector.begin(); // Get position of longest LCP
         
        string LCSS = suffixVector[pos].suffix.substr(0, maxLCP); // Get the longest common substring

        int start = 0; // Start point of window
        int counter = 0; // Number of times LCSS appears in currentInput

        //Find the number of times LCSS appears in currentInput
        while((start = currentInput.find(LCSS, start)) != std::string::npos) {
            start++; 
            counter++;
        } 

        if(maxLCP != 0){ // If there is no common prefix, no matches are found
            cout << LCSS << " " << counter << endl;
        }else{
            cout << "No repetitions found!" << endl;
        }
	}  
	return 0;
}

















