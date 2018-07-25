/* UVa problem: 755
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The first line of the input contains the number of datasets in the input. A blank line follows. The first
 *	line of each dataset specifies the number of telephone numbers in the directory (up to 100,000) as a
 *	positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with
 *	each number alone on a line. Each telephone number consists of a string composed of decimal digits,
 *	uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will
 *	be digits or letters.
 *	There’s a blank line between datasets.
 *	Generate a line of output for each telephone number that appears more than once in any form. The
 *	line should give the telephone number in standard form, followed by a space, followed by the number
 *	of times the telephone number appears in the directory. Arrange the output lines by telephone number
 *	in ascending lexicographical order. If there are no duplicates in the input print the line:
 *	No duplicates.
 *	Print a blank line between the output of consecutive datasets.
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
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//Struct representing each phone number as a string and a counter indicating how many times it's appeared
struct element{
	string phoneNumber;
	int n; //Number of occurrences 
};

bool sortNumber(const element a, const element b){
	return a.phoneNumber < b.phoneNumber;
}

int main(){

	int numDataSets;
	int numPhoneNumbers;
	string input;

	cin >> numDataSets;

	for(int x = 0; x < numDataSets; x++){

		cin >> numPhoneNumbers;
		vector<string> directory;
		vector<string> hasAppeard;

		for(int y = 0; y < numPhoneNumbers; y++){
			cin >> input;
			string standardNumber;

			for(int i = 0; i < input.length(); i++){ //Replace letters with their associated number
				if(standardNumber.length() == 8){
					break;
				}

				if(standardNumber.length() == 3){
					standardNumber.append("-");
				}

				if(input[i] == '0'){
					standardNumber.append("0");
				}else if(input[i] == '1'){
					standardNumber.append("1");
				}else if(input[i] == 'A' || input[i] == 'B' || input[i] == 'C' || input[i] == '2'){
					standardNumber.append("2");
				}else if(input[i] == 'D' || input[i] == 'E' || input[i] == 'F' || input[i] == '3'){
					standardNumber.append("3");
				}else if(input[i] == 'G' || input[i] == 'H' || input[i] == 'I' || input[i] == '4'){
					standardNumber.append("4");
				}else if(input[i] == 'J' || input[i] == 'K' || input[i] == 'L' || input[i] == '5'){
					standardNumber.append("5");
				}else if(input[i] == 'M' || input[i] == 'N' || input[i] == 'O' || input[i] == '6'){
					standardNumber.append("6");
				}else if(input[i] == 'P' || input[i] == 'R' || input[i] == 'S' || input[i] == '7'){
					standardNumber.append("7");
				}else if(input[i] == 'T' || input[i] == 'U' || input[i] == 'V' || input[i] == '8'){
					standardNumber.append("8");
				}else if(input[i] == 'W' || input[i] == 'X' || input[i] == 'Y' || input[i] == '9'){
					standardNumber.append("9");
				}
			}
			if(find(hasAppeard.begin(), hasAppeard.end(), standardNumber) == hasAppeard.end()){
				hasAppeard.push_back(standardNumber);
			}else{
				directory.push_back(standardNumber);
			}
		}

		sort(hasAppeard.begin(), hasAppeard.end()); //Sort the dictionary by the phone number

		if(directory.size() == 0){
			cout << "No duplicates." << endl;
		}else{
			for(int i = 0; i < hasAppeard.size(); i++){

				string currentNum = hasAppeard[i];
				int n = 1;
				for (int j = 0; j < directory.size(); j++){
					if(directory[j] == currentNum){
						n++;
					}
				}

				if(n > 1){
					cout << hasAppeard[i] << " " << n << endl;
				}
			}
		}

		if(numDataSets){ //Uva formatting trash
			cout << endl;
		}
	}
	return 0;
}