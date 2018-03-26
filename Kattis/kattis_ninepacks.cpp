/* Kattis problem: ninepacks
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The first input line starts with an integer, H, the number of hotdog packs available. 
 *	This is followed by H integers, h1…hH, the number of hotdogs in each pack. The second 
 *	input line starts with an integer, B, giving the number of bun packs available. 
 *	This is followed by B integers, b1…bB, indicating the number of buns in each pack. 
 *	The values H and B are between 0 and 100, inclusive, and the sizes of the packs are 
 *	between 1 and 1000, inclusive. 
 *
 *
 * Solution Summary:
 *
 *
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

int main() {
    int inf = 1 << 29;
    int size;

    vector<int> h(100002, inf);
    vector<int> b(100002, inf);
    h[0] = 0;
    b[0] = 0;

    // Find all combinations of hotdogs
    cin >> size;
    for(int i = 0; i < size; i++) {
        int num;
        cin >> num;
        for(int j = h.size()-num-1; j >= 0; j--) {
            if(h[j] < h[j+num]) {
                h[j+num] = h[j]+1;
            }
        }
    }

    // Find all combinations of buns
    cin >> size;
    for(int i = 0; i < size; i++) {
        int num;
        cin >> num;
        for(int j = b.size()-num-1; j >= 0; j--) {
            if(b[j] < b[j+num]) {
                b[j+num] = b[j]+1;
            }
        }
    }

    // Get answer
    int best = inf;
    for(int i = 1; i < h.size(); i++) {
        if(h[i] + b[i] < best) {
            best = h[i] + b[i];
        }
    }

    if(best >= inf/2) {
        cout << "impossible" << endl;
    }else{
    	cout << best << endl;
    }
    return 0;
}
