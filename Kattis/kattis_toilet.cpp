//Kattis problem ID: toilet

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

//Policy 1: Always leave up
//Policy 2: Always leave down
//Policy 3: Always leave as you like it

int main(){
	string input;
	char seatPosition1;
	char seatPosition2;
	char seatPosition3;
	int pol1 = 0;
	int pol2 = 0; 
	int pol3 = 0;

	cin >> input;

	seatPosition1 = input[0];
	seatPosition2 = input[0];
	seatPosition3 = input[0];


	for(int i = 1; i < input.length(); i++){
		//Policy 1
		if(seatPosition1 != input[i]){
			seatPosition1 = input[i];
			pol1++;
		}
		if(seatPosition1 == 'D'){
			seatPosition1 = 'U';
			pol1++;
		}

		//Policy 2
		if(seatPosition2 != input[i]){
			seatPosition2 = input[i];
			pol2++;
		}
		if(seatPosition2 == 'U'){
			seatPosition2 = 'D';
			pol2++;
		}

		//Policy 3
		if(seatPosition3 != input[i]){
			seatPosition3 = input[i];
			pol3++;
		}
	}

	cout << pol1 << endl;
	cout << pol2 << endl;
	cout << pol3 << endl;
	return 0;
}
