/* UVa problem: 10815
 *
 * Topic: Data Structures
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Write a program that lists all the different words in the input text. In this
 *   problem, a word is defined as a consecutive sequence
 *   of alphabets, in upper and/or lower case.
 *   Words with only one letter are also to be considered. Furthermore, your program must be CaSe InSeNsItIvE.
 *   For example, words like “Apple”, “apple” or “APPLE” must be considered the same.
 *
 * Solution Summary:
 *   Read the input line by line and replace every number and punctuation with a space.
 *   Then put everything to lower case and insert it into a vector if it isn't in there already.
 *   The vector is then sorted and printed. 
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
#include <string>
#include <sstream> 
#include <algorithm>
#include <vector>

using namespace std;

string input;
vector <string> dictionary;

int main(){

	while(cin >> input){
		replace_if (input.begin(), input.end(), ::ispunct, ' '); //Replace punctuation with spaces
		replace_if (input.begin(), input.end(), ::isdigit, ' '); //Replace numbers with spaces

		//Set everything to lowercase
		for (int i = 0; i < input.length(); i++){
    		input[i] = tolower(input[i]);
		}

		istringstream iss(input);
    	string word;
    	
    	while(iss >> word) {
    		//Add words to the vector
    		if(find(dictionary.begin(), dictionary.end(), word) == dictionary.end()) {
    			//printf("help pls\n");
    			dictionary.push_back(word); 
			}
    	}   	
	}
	//Sort the vector
    sort(dictionary.begin(), dictionary.end());
    //Print every item in the vector
	for(int i = 0; i < dictionary.size(); i++){
		cout << dictionary[i] << "\n";
	}

	return 0;
}









