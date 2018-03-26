/* UVa problem: 10327
 *
 * Topic: Sorting
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *   The input will start with a positive integer N (N ≤ 1000). In next few lines there will be N integers.
 *   Input will be terminated by EOF. For each data set print ‘Minimum exchange operations : M’ where M is 
 *   the minimum flip operations required to perform sorting. Use a seperate line for each case.
 *
 * Solution Summary:
 *  
 *   We simply iterate through each element and count how many elements after it are less than it.   
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

using namespace std;




int main() {
    
    int numInts;
    int numExchangeOps;
    vector<long long> inputs(1001); //Why does it have to be 1001 and not 1000?

    while(cin >> numInts){
        
        for(int i = 0; i < numInts; i++){
            cin >> inputs[i];
        }

        numExchangeOps = 0;

        for (int i = 0; i < numInts; i++) { //Compare each element with all the elements after it
            for (int j = i + 1; j < numInts; j++){
                if (inputs[i] > inputs[j]){ //Increment numExchangeOps if the next element is less than the current
                    numExchangeOps++;
                }
            }
        }

        cout << "Minimum exchange operations : " << numExchangeOps << endl;

    } 
    return 0;	
}




