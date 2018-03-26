/* Kattis problem: srednji
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   The first line contains two integers, N (1≤N≤100000) and B (1≤B≤N).
 *   The second line contains N integers separated by spaces, the elements of sequence A.
 *   Output the number of subsequences of A whose median is B.
 *
 * Solution Summary:
 *
 *   For the Median to b B in a subsequence, the subsequence must contain the same amount
 *   of numbers less than B and greater than B. This can be done by iterating through the
 *   numbers from B to the end of the list. If the integer is greater than B, increment a 
 *   sum by 1. If it's less than B, decrement that sum by 1. Add the occurrence of each 
 *   sum to a map. Then check the same sums on the numbers to the left side of B. Except 
 *   this time, check the negative of this sum in the map and add its value to the result.
 *   Adding all such values gives the final result. 
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
  int N; //Length of sequence
  int B; //Median
  int input;
  int posB; //The position of B in the input sequence
  vector<int> V; //vector to store inputs
  map<int, int> M; //Map to hold occurences of sums
  int sum = 0; //Sum of a side
  int R = 0; //Result

  cin >> N >> B;
  for(int i = 0; i < N; i++){
    cin >> input;
    if(input == B){
      posB = i;
    }
    V.push_back(input);
  }

  for(int i = posB; i < N; i++){ //Check all numbers to the right of B
    if(V[i] > B){
      sum++;
    }else if(V[i] < B){
      sum--;
    }
    M[sum]++; //Increment the frequency of that sum
  }

  sum = 0;

  for(int i = posB; i >= 0; i--){ //Check all numbers to the left of B
    if(V[i] > B){
      sum++;
    }else if(V[i] < B){
      sum--;
    }
    R += M[-sum]; //Add the corresponding total occurrence of the negative sum
  }
  /*
  for (auto i = M.begin(); i != M.end(); i++) {
    cout << "key: " << i->first << " value: " << i->second << endl;
  }
  */
  cout << R << endl;
  return 0; //NOTE TO SELF, NEVER FORGET THIS AGAIN
}
