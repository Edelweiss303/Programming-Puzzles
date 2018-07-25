/* Kattis problem: oddities
 * 
 * Rishi Barnwal
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define LL long long

using namespace std;


int main(){
	int N;
	int x;
	cin >> N;

	while(N--){
		cin >> x;
		if(x % 2 == 0){
			cout << x << " is even" << endl;
		}else{
			cout << x << " is odd" << endl;
		}
	}
	
}
