/* Kattis problem: sumkindofproblem
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *  The first line of input contains a single integer P, (1≤P≤10000), which is the 
 *  number of data sets that follow. Each data set should be processed identically 
 *  and independently. Each data set consists of a single line of input. It contains 
 *  the data set number, K, followed by an integer N, (1≤N≤10000). For each data set 
 *  there is one line of output. The single output line consists of the data set number, 
 *  K, followed by a single space followed by three space separated integers S1, S2 and S3 
 *  such that:
 *  S1 = The sum of the first N positive integers.
 *  S2 = The sum of the first N odd integers.
 *  S3 = The sum of the first N even integers.
 *   
 *
 * Solution Summary:
 *
 *  We simply create a seperate loop for S1, S2, and S3. For S1, start the sum at 1 and keep 
 *  adding the next N numbers. For S2, start the sum at 1 and keep adding every second number
 *  N times. And for S3, start the sum at 2, and keep adding every second number N times.
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

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    int P;
    int K, N;
    int counter;
    int num;
    vector <int> inputs;
    int S1, S2, S3;

    cin >> P;

    for(int i = 0; i < P; i++){
        cin >> K >> N;
        inputs.push_back(K);
        inputs.push_back(N);
    }

    for(int i = 0; i < P * 2; i+=2){

        S1 = 0;
        S2 = 0;
        S3 = 0;

        K = inputs[i];
        N = inputs[i+1];
        
        for(int j = 1; j <= N; j++){ //Sum of first N integers
            S1 += j;
        }

        counter = 0;
        num = 1;
        while(counter != N){ //Sum of first N odd integers
            S2 += num;
            counter++;
            num += 2;
        }

        counter = 0;
        num = 2;
        while(counter != N){ //Sum of first N even integers
            S3 += num;
            counter++;
            num += 2;
        }
        cout << K << " " << S1 << " " << S2 << " " << S3 << endl;
    }

    return 0;
}

