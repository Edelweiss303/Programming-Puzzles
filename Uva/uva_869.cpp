/* UVa problem: 869
 *
 * Topic: Graph Algorithms
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	An airline catalog consists of a list of flights between pairs of cities. A trip may be built by sequencing
 *	flights. Two airline companies are equivalent if they offer connections between the same pairs of cities,
 *	irrespective of the number of scales in between. Given the catalogs of two airline companies, determine if 
 *	they are equivalent or not. The input begins with a single positive integer on a line by itself indicating 
 *	the number of the cases following, each of them as described below. This line is followed by a blank line, 
 *	and there is also a blank line between two consecutive inputs. The input contains:
 *	• First line: the number N of flights in the catalog of the first company;
 *	• N subsequent lines: two uppercase alphabet characters separated by one space, for the names of
 *	  the origin and destination cities of a flight;
 *	• Line N + 2: the number M of flights in the catalog of the second company;
 *	• M subsequent lines: two uppercase alphabet characters separated by one space, for the names of
 *	the origin and destination cities of a flight.
 *	For each test case, the output must follow the description below. The outputs of two consecutive cases
 *	will be separated by a blank line. One line containing ‘YES’ or ‘NO’
 * 
 * Solution Summary:
 *	
 *	We represent each airlines trips as a 26x26 matrix and simply iterate through all possible combinations of trips 
 *	with each route. If it's possible to make a trip from city A to city B, the value at matric[A][B] is set to 1. 
 *	Both matrices are compared at the end to give us our output. 
 *
 * Used Resources:
 *
 *	http://en.cppreference.com/w/cpp/language/ascii
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
#include <string>
using namespace std;

int main(){

	int numCases;

	int N, M; //number of flights for each airline

	char origin, destination; //Origin and destination flights

	//Two matrices representing the flights for each airline, instantiate all trips to 0
	vector<vector<int>> airline1(26, vector<int>(26, 0)); //Size is 26 for each letter of the alphabet
	vector<vector<int>> airline2(26, vector<int>(26, 0)); 

	cin >> numCases;

	for(int i = 0; i < numCases; i++){
		//Why do these cause runtime errors?
		//airline1.clear(); 
		//airline2.clear(); 

		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> origin >> destination;
			//trip exists from origin to destination, so set it to 1
			airline1[origin-65][destination-65] = 1; //Value of capital letters starts at 65. Subtract 65 to start index at 0
		}

		for (int j = 0; j < 26; j++){ //Iterate through each combination of letter
            for (int k = 0; k < 26; k++){
                for (int l = 0; l < 26; l++){
                    if(airline1[k][j] && airline1[j][l]){ //If there's a path between a to b and b to c, 
                        airline1[k][l] = 1;				  //there must be a path from a to c
                    }
                }
            }
		}


		cin >> M; //repeat same process for the second airline
		for(int j = 0; j < M; j++){
			cin >> origin >> destination;
			airline2[origin-65][destination-65] = 1;
		}

		for (int j = 0; j < 26; j++){
            for (int k = 0; k < 26; k++){
                for (int l = 0; l < 26; l++){
                    if(airline2[k][j] && airline2[j][l]){
                        airline2[k][l] = 1;
                    }
                }
            }
		}

		if(airline1 == airline2){ //Airlines are equivalent if the two matrices are equivalent
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}

		if(i != numCases - 1){ //MORE STUPID UVA FORMATTING AAAAAAGGGHHHH
			cout << endl;
		}
	}
	return 0;
}