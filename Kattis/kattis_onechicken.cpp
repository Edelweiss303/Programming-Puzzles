/* Kattis problem: onechicken
 * Rishi Barnwal
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


int main(){

	int N, M;
	int X;

	cin >> N >> M;

	X = abs(N - M);

	if(N < M){
		if(X > 1){
			cout << "Dr. Chaz will have " << X << " pieces of chicken left over!" << endl;
		}else{
			cout << "Dr. Chaz will have " << X << " piece of chicken left over!" << endl;	
		}
	}else{
		if(X > 1){
			cout << "Dr. Chaz needs " << X << " more pieces of chicken!" << endl;
		}else{
			cout << "Dr. Chaz needs " << X << " more piece of chicken!" << endl;
		}
	}

	return 0;
}