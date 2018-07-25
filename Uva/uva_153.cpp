/* UVa problem: 153
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	 Write a program that will read in a string and determine its position in the ordered sequence
 *	 of permutations of its constituent characters. Note that numbers of permutations can get very large;
 * 	 however we guarantee that no string will be given whose position is more than 2^31 − 1 = 2,147,483,647. 
 * 	 Input will consist of a series of lines, each line containing one string. Each string will consist of up 
 * 	 to 30 lower case letters, not necessarily distinct. The file will be terminated by a line consisting of 
 * 	 a single ‘#’. Output will consist of a series of lines, one for each line of the input. Each line will 
 *	 consist of the position of the string in its sequence, right justified in a field of width 10.
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
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	vector<unsigned long long> factorials;
	string input;
	vector<string> inputList;

	factorials.push_back(1); //precompute a vector filled with 1! to 30!
    for(int i = 2; i <= 30; i++){
        factorials.push_back(factorials[i - 2] * i);
    }   

	while(cin >> input){
		if(input == "#"){
			break;
		}
		inputList.push_back(input);
	}

	for(int i = 0; i < inputList.size(); i++){
		int position = 1;
		input = inputList[i];
		string inputCopy = inputList[i];
		

		for(int j = 0; j < input.length(); j++){
			sort(inputCopy.begin() + 1, inputCopy.end());
			if(input == inputCopy){
				break;
			}

			int index = i + (position / factorials[inputCopy.length() - i - 2]); //Get the index of the character we want to swap this iteration
			swap(input[i], input[index]); //Swap characters
			position += factorials[input.length() - i - 2];
		}
		cout << setw(10) << right <<  position << endl;

	}

	return 0;
}