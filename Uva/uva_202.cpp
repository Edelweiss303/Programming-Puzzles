/* UVa problem: 202
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *	 The decimal expansion of the fraction 1/33 is 0.03, where the 03 is used to indicate that the cycle 03
 *	 repeats indefinitely with no intervening digits. In fact, the decimal expansion of every rational number
 *	 (fraction) has a repeating cycle as opposed to decimal expansions of irrational numbers, which have no
 *	 such repeating cycles. Write a program that reads numerators and denominators of fractions and determines 
 *   their repeating cycles.
 * 
 *
 *
 *
 * Solution Summary:
 *
 *
 *  Since the mod division will give us the remainder of a division, we take the initial numerator and 
 *  repeatedly mod divide it by the denominator and store the remainders as keys in a map. Each time, 
 *  we multiply the remainder by 10, so the division isn't 0. The values of the keys will be the position 
 *  in n/d at which that remainder would normally be encountered. This is done until a repition is found.
 *
 *	
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Rishi Barnwal
 */
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

using namespace std;

int n; //Numerator
int d; //Denominator
int f; //Floor division of numerator and denominator
int remainder; //Remainder
map <int, int> remainderMap; //Map of remainders as keys and positions as the value


int main(){
	while (scanf("%d %d", &n, &d) != EOF){

		remainder = (n % d); //Get the first remainder 
		remainderMap.clear(); //Clear the map
		string s1; //Initialize the repeating sequence 
		string s2; //Initialize the non-repeating sequence

		while ((remainderMap.find(remainder) == remainderMap.end())){

        	remainderMap[remainder] = s2.length(); //The length of the current total string works as position
        	remainder *= 10; //Multiply the remainder by 10 so the floor division doesn't equal 0

        	s2 += to_string(remainder / d); //Add the floor division to the total string
        	remainder %= d; //Get the new remainder
    	}


 		f = n/d; //Initial floor division
 		s1 = s2.substr(0, remainderMap[remainder]); //Non-repeating sequence is just the total sequence from 0 to the last remainder

 		//Check if the length of the repeating sequence is longer than 50
 		if(s2.length() > 50 - s1.length()){
 			printf("%d/%d = %d.%s(%s...)\n", n, d, f, s1.c_str(), s2.substr(remainderMap[remainder]).substr(0, 50 - s1.length()).c_str());
 		}else{
 			printf("%d/%d = %d.%s(%s)\n", n, d, f, s1.c_str(), s2.substr(remainderMap[remainder]).c_str());
 		}

 		printf("   %lu = number of digits in repeating cycle\n\n", s2.substr(remainderMap[remainder]).length());
		
	}
	return 0;
}




















