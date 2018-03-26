/* Kattis problem: cd
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The input consists of a sequence of test cases. The first line of 
 *  each test case contains two non-negative integers N and M, each at 
 *  most one million, specifying the number of CDs owned by Jack and by 
 *  Jill, respectively. This line is followed by N lines listing the 
 *  catalog numbers of the CDs owned by Jack in increasing order, and 
 *  M more lines listing the catalog numbers of the CDs owned by Jill in 
 *  increasing order. Each catalog number is a positive integer no greater 
 *  than one billion. The input is terminated by a line containing two zeros. 
 *  For each test case, output a line containing one integer, 
 *  the number of CDs that Jack and Jill both own.
 *
 * Solution Summary:
 *  
 *  Store the CDs owned by Jack in an unordered set. This supports fast look up 
 *  since the order does not matter. Then check if each of the CDs Jill owns 
 *  shows up in the unordered set. Increment a count accordingly. 
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
#include <unordered_set>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    long long M;
    long long catNum;
    unordered_set<long long> CD;
    long long count;

    while(1){
        cin >> N >> M;

        if(N == 0 && M == 0){
            break;
        }

        CD.clear();

        for (int i = 0; i < N; i++) {
            cin >> catNum;
            CD.insert(catNum); //Add Jack's CDs to the set
        }

        count = 0;

        for (int i = 0; i < M; i++) {
            cin >> catNum;
            count += CD.count(catNum); //CD.count() can only return 1 since every element in a set is uniqe
        }
        cout << count << endl;
    }
    return 0;
}
