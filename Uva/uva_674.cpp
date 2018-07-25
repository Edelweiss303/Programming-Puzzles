/* UVa problem: 674
 *
 * Topic: Dynamic Programming
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *	
 *	Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent. We want to make
 *	changes with these coins for a given amount of money. Write a program to find the total number of 
 *	different ways of making changes for any amount of money in cents. Your program should be able to 
 *	handle up to 7489 cents. The input file contains any number of lines, each one consisting of a 
 *	number for the amount of money in cents. For each input line, output a line containing the number 
 *	of different ways of making changes with the above 5 types of coins.
 *
 * Solution Summary:
 *	  
 *	We pre-compute a matrix of size 7489x5 to hold all the possible combinations of change for each
 *	number of cents from 1 to 7489. We then print the corresponding value of the number of
 *	at the number of cents in the input. 0 cents is a special case and 1 is outputted insted. 
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
#include <math.h>
#include <vector>
using namespace std;



int main(){
	long long change[7490][5]; //Matrix of possible change combinations
	long long numCoins; //number of coins required
	int coins[5] = {50, 25, 10, 5, 1}; //All the different types of coins
	int cents; //input cents

	for(int i = 0; i < 7490; i++){ //Iterate through each value for cents

        numCoins = 0;

        for(int j = 0; j < 5; j++){
			
			//subtract the current coin from the cents 
            if(i - coins[j] == 0){ //If result is zero, increment numCoins by 1
                numCoins++; 
            }else if(i - coins[j] > 0){ //If result is greater than zero, increment numCoins by the numCoins of the result
                numCoins += change[i - coins[j]][j];
            }

            change[i][j] = numCoins; //Set numCoins for the current coin at the current cent value
        }
    }

	while(cin >> cents){
		if(cents == 0){ //Special case of 0
			cout << 1 << endl;
		}else{
			cout << change[cents][4] << endl;
		}
	}
	return 0;
}