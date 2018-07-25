/* Kattis problem: powers
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   The input has two integers a (1≤a≤10^9) and b (1≤b≤99, b is odd) on a single line.
 *   Output the value of the expression (1^b+2^b+...+a^b) mod a with the given a and b.
 *
 * Solution Summary:
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
  long long a;
  int b;
  long long result = 0;

  cin >> a >> b;

  for(int i = 1; i <= a; i++){
    result += i ^ b;
  } 

  result %= a;
  cout << result << endl;

  return 0;
}
