/* UVa problem: 10003
 *
 * Topic: Dynamic Programming
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *  
 *  You have to cut a wood stick into pieces. The most affordable company, The Analog Cutting Machinery,
 *  Inc. (ACM), charges money according to the length of the stick being cut. Their procedure of work
 *  requires that they only make one cut at a time. It is easy to notice that different selections in 
 *  the order of cutting can led to different prices. For example, consider a stick of length 10 meters 
 *  that has to be cut at 2, 4 and 7 meters from one end. There are several choices. One can be cutting 
 *  first at 2, then at 4, then at 7. This leads to a price of 10 + 8 + 6 = 24 because the first stick 
 *  was of 10 meters, the resulting of 8 and the last one of 6. Another choice could be cutting at 4, 
 *  then at 2, then at 7. This would lead to a price of 10 + 4 + 6 = 20, which is a better price. The 
 *  input will consist of several input cases. The first line of each test case will contain a positive
 *  number l that represents the length of the stick to be cut. You can assume l < 1000. The next line 
 *  will contain the number n (n < 50) of cuts to be made. The next line consists of n positive numbers 
 *  ci (0 < ci < l) representing the places where the cuts have to be done, given in strictly increasing 
 *  order. An input case with l = 0 will represent the end of the input. You have to print the cost of 
 *  the optimal solution of the cutting problem, that is the minimum cost of cutting the given stick. 
 *
 * Solution Summary:
 *  
 *  After each cut, the stick is divided into 2 sub problems. Some of these problems will need to be 
 *  calculated more than once so we just need to store the results of each of the sub problems in a 
 *  memoization table. 
 *
 * Used Resources:
 *
 *  https://en.wikipedia.org/wiki/Memoization
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
#include <math.h>
#include <algorithm>

using namespace std;


int main() {
      
    int l; //Length of stick
    int n; //Number of cuts
    int c; //A single cut
    vector<int> cuts; //List of cuts to be made
    int table[50][50]; //table to store results of sub problems

    while (1) {

        cin >> l;
        if(l == 0){
            break;
        }

        cuts.clear();
        cuts.push_back(0); //First value is at 0 since this means the beginning of the stick

        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> c;
            cuts.push_back(c);
        }
        
        cuts.push_back(l); //last value is the length since this means the end of the stick
        n++; //increment n by 1 since we add l to the list of cuts

        for (int i = 1; i <= n; i++){ 
            for (int j = i - 1; j >= 0; j--) {
                if (j + 1 == i){ //The base case of 1 board with no more cuts to be made
                    table[j][i] = 0; //The cost of that board is 0
                }else {
                    table[j][i] = 2147483647; //Max int value
                    for (int k = j + 1; k < i; k++) {
                        if (table[j][k] + table[k][i] < table[j][i]){
                            table[j][i] = table[j][k] + table[k][i]; //Costs of each of the sub problems
                        }
                    }
                    table[j][i] += cuts[i] - cuts[j]; //cuts[i] - cuts[j] is the cost of making a cut
                }
            }
        }
        cout << "The minimum cutting is " << table[0][n] << "." << endl;
    }

    return 0;
}












