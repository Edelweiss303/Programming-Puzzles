/* UVa problem: 482
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The input begins with a single positive integer on a line by itself indicating the number of the cases
 *	following, each of them as described below. This line is followed by a blank line, and there is also a
 *	blank line between two consecutive inputs.
 *	Each input set will contain two lines of numbers. The first line will be an index array p containing
 *	the integers 1 . . . n, where n is the number of integers in the list. The numbers in the first line will have
 *	been permuted in some fashion. The second line will contain a list numbers in floating point format.
 *	For each test case, the output must follow the description below. The outputs of two consecutive cases
 *	will be separated by a blank line.
 *  The output for this program will be the list of floating point numbers from the input set, ordered
 *	according to the permutation array from the input file. The output numbers must be printed one per
 *	line in the same format in which they each appeared in the input file
 * 
 * Solution Summary:
 *	
 *	Make a custom struct with two elements, one for each line. Take in the input into a vector of structs
 *	and sort that vector by the first line of inputs. Then print the values from the second line. 
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
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct element{
	int index;
	string floatNum;
};

//Sort function to sort elements by index
bool sortByInt(const element &a, const element &b) {
    return a.index < b.index;
}

int main(){

	int numCases; //number of test cases
	string line; //Each line

	int index;
	string floatNum;

	cin >> numCases;
	getline(cin, line); //Allow for spaces

	while(numCases--){

		vector<element> result;

		getline(cin, line); //Also allow for spaces

        getline(cin, line);
		stringstream ss1(line);

		getline(cin, line);
		stringstream ss2(line);

		while (ss1 >> index) { //First line
            ss2 >> floatNum; //Second Line
            element e;
            e.index = index;
            e.floatNum = floatNum;
            result.push_back(e);
        }

        sort(result.begin(), result.end(), sortByInt); //Sort by first value

		

		for(int i = 0; i < result.size(); i++){
			cout << result[i].floatNum << endl;
		}
		
		if(numCases){
			cout << endl;
		}
		
	}
	return 0;
}