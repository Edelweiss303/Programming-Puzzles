// Kattis problem ID: planina

#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int N;
	int result = 2; //Starting number of points on one side

	cin >> N;

	while(N--){
		result += result - 1; //Keep adding one less than the last number of points
	}

	cout << result * result << endl; //Square the result

	return 0;
}