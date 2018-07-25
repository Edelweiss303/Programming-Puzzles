/* Kattis problem: faktor
 * Rishi Barnwal
 */
#include <iostream>
#include <stdlib.h>

using namespace std;


int main(){

	int A, I;

	cin >> A >> I;

	cout << (A * (I - 1)) + 1 << endl;

	return 0;
}