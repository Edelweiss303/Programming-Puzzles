/* Kattis problem: yoda
 *
 * Topic: Other
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	A long, long time ago in a galaxy far, far away a big collision of integers is taking place 
 *	right now. What happens when two integers collide? During collision, each digit of one number 
 *	compares itself to the corresponding digit of the other number (the least significant digit 
 *	with the other’s least significant digit, and so on). The smaller digit “falls out” of the 
 *	number containing it. Additionally, if the digits are the same, nothing happens. If a number 
 *	doesn’t consist of a corresponding digit, then we consider it to be zero. After all 
 *	comparisons of corresponding digits, the leftover digits in the number come closer and create 
 *	a new number. Write a programme that will, for two given integers, determine their values after 
 *	collision. If it happens that all the digits of one number fell out, then for that number output 
 *	the message “YODA”. The first line of input contains the integer N (1≤N≤109), one of the 
 *	integers from the task. The second line of input contains the integer M (1≤N≤109), one of the 
 *	integers from the task. The first line of output must contain the new value of the first given 
 *	integer from the task. The second line of output must contain the new value of the second given 
 *	integer from the task.
 *
 * Solution Summary:
 *
 *	We take in the input as strings, reverse each one, and add zeros until their lengths are equal
 *	so that we can compare each digit. Iterating through each digit, we compare them and add the
 *	appropriate one to a new string depending on if one is greater than or lower than or equal to
 *	the other. We then do a check to make remove all trailing zeros, reverse the output strings, and
 *	then print the output.
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
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	string n, m; //input strings
	string n2, m2; //output strings

	cin >> n >> m;

	//reverse input
	reverse(n.begin(), n.end());
	reverse(m.begin(), m.end());

	//pad the inputs with trailing zeros
	while(n.length() > m.length()){
		m.push_back('0');
	}
	while(n.length() < m.length()){
		n.push_back('0');
	}

	//compare each digit in the input and add the appropriate value to one of the output strings
	for(int i = 0; i < n.length(); i++){
		if(n[i] == m[i]){
			n2.push_back(n[i]);
			m2.push_back(n[i]);
		}else if(n[i] < m[i]){
			m2.push_back(m[i]);
		}else if(n[i] > m[i]){
			n2.push_back(n[i]);
		}
	}

	//remove trailing zeros
	while(n2[n2.length()-1] == '0' && n2.length() > 1) {
        n2.pop_back();
    }
    while(m2[m2.length()-1] == '0' && m2.length() > 1) {
        m2.pop_back();
    }

    //reverse output strings
    reverse(n2.begin(), n2.end());
    reverse(m2.begin(), m2.end());

    //Print the outputs, YODA if the length of the string is 0
    if(n2.length() == 0) {
        cout << "YODA";
    }else{
        cout << n2;
    }
    cout << endl;

    if(m2.length() == 0) {
        cout << "YODA";
    }else{
        cout << m2;
    }
    cout << endl;

	return 0;
}