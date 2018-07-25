/* Uva problem: 429
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Given a dictionary of words from which to make transformations, plus a list of starting and ending
 *	words, your team is to write a program to determine the number of steps in the shortest possible
 *	transformation.
 *
 *	The first line of the input is an integer N, indicating the number of test set that your correct program
 *	should test followed by a blank line.
 * 	Each test set will have two sections. The first section will be the dictionary of available words with
 *	one word per line, terminated by a line containing an asterisk (*) rather than a word. There can be
 *	up to 200 words in the dictionary; all words will be alphabetic and in lower case, and no word will be
 *	longer than ten characters. Words can appear in the dictionary in any order.
 *	Following the dictionary are pairs of words, one pair per line, with the words in the pair separated
 *	by a single space. These pairs represent the starting and ending words in a transformation. All pairs
 *	are guaranteed to have a transformation using the dictionary given. The starting and ending words
 *	will appear in the dictionary.
 *	Two consecutive input set will separated by a blank line.
 *
 *	The output should contain one line per word pair for each test set, and must include the starting word,
 *	the ending word, and the number of steps in the shortest possible transformation, separated by single
 *	spaces.
 *	Two consecutive output set will be separated by a blank line.	
 *
 * Solution Summary:
 *
 *	Implement a depth first search where each word is a node and its adjacent nodes are the words that
 *	differ by one letter. The depth of the search is our answer.
 *
 * Used Resources:
 *
 *	The canChance function was taken from: 
 *	https://stackoverflow.com/questions/35005078/fastest-way-to-determine-if-two-strings-differ-by-a-single-character
 *	https://stackoverflow.com/questions/31247634/how-to-keep-track-of-depth-in-breadth-first-search
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
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
struct element{
	string word;
	bool visited;
};

//This function returns true if strings A and B differ by 1 letter
bool canChange(string const& strA, string const& strB){
    bool single_mismatch = false;
    if (strA.size() == strB.size()){
        typedef string::const_iterator ci; 
        typedef pair<ci, ci> mismatch_result;

        ci begA(strA.begin()), endA(strA.end());

        mismatch_result result = std::mismatch(begA, endA, strB.begin());

        if(result.first != endA){//found a mismatch
        
            char letter = *(result.first);
            size_t index = distance(begA, result.first);

            //now look for a second mismatch
            advance(result.first, 1);
            advance(result.second, 1);

            single_mismatch = (mismatch(result.first, endA, result.second).first == endA);
        }
    }
    return single_mismatch;
}

int main(){
	int numTests;
	
	vector<element> queue;

	string word1, word2;

	cin >> numTests;
	while(numTests--){

		vector<element> dictionary;

		while(cin >> word1, word1 != "*"){
			element e;
			e.word = word1;
			e.visited = false;
			dictionary.push_back(e);
		}

		cin.ignore();

		string line;
		while(getline(cin, line) && !line.empty()){

			stringstream ss(line);
			ss >> word1 >> word2;

			for(int j = 0; j < dictionary.size(); j++){ //Reset all the visited to false
				dictionary[j].visited = false;
				
			}

			

			for(int j = 0; j < dictionary.size(); j++){ //find root of queue
				if(dictionary[j].word == word1){
					dictionary[j].visited = true;
					queue.push_back(dictionary[j]); //Enqueue it
					break;
				}
			}

			int depth = 1;

			element EOL; //Blank element signifying end of level
			EOL.word = "END OF LEVEL";
			EOL.visited = false;
			queue.push_back(EOL);
			
			element e;

			while(queue.size() != 0 && word1 != word2){
				//Dequeue first element
				e = queue[0];
				if(e.word == "END OF LEVEL"){ //If end of level is reached, increase depth by 1

					depth++;
					queue.push_back(EOL);

					if(queue[1].word == "END OF LEVEL"){
						break;
					}else{
						e = queue[1];
						queue.erase(queue.begin());
						continue;
					}
				}

				queue.erase(queue.begin());

				for(int j = 0; j < dictionary.size(); j++){
					//Check if element was visited and that it differs by one letter
					if(dictionary[j].visited == false && canChange(e.word, dictionary[j].word)){

						dictionary[j].visited = true;
						queue.push_back(dictionary[j]);
						/*
						cout << "adding to queue: " << dictionary[j].word << endl;
						cout << "queue is now: ";
						for(int k = 0; k < queue.size(); k++){
							cout << queue[k].word << " <- ";
						}
						cout << endl;
						*/
						if(dictionary[j].word == word2){
							queue.clear();
							break;
						}	
					}
				}
			}

			cout << word1 << " " << word2 << " ";
			if(word1 == word2){
				cout << 0 << endl;
			}else{
				cout << depth << endl;
			}
		
			

		}
		if(numTests){
			cout << endl;
		}
	}


	return 0;
}