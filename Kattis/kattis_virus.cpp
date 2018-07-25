//Kattis Problem ID: virus

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;


int main(){
	string dna;
	string virus;
	cin >> dna >> virus;

	int virLen = virus.length() - 1;
	int dnaLen = dna.length() - 1;

	int i = 0;
	while(virus[i] == dna[i]){
		i++;
	}

	while(virus[virLen] == dna[dnaLen]){
		virLen--;
		dnaLen--;
	}
	
	int a = max(virLen - i + 1, 0);
	int b = virus.length() - dna.length();

	cout << max(a, b) << endl;
	return 0;
}
