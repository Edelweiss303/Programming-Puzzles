/* Kattis problem: pot
 * 
 * Rishi Barnwal
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>

#define LL long long

using namespace std;

LL fast_exp(int b, int n){
  LL res = 1, x = b, p;
  
  for(p = n; p; p >>= 1, x *= x)
    if(p & 1) res *= x;
  
  return res;
}

int main(){
  int N;
  int P;
  int exp;
  LL X = 0;

  cin >> N;

  while(N--){
    cin >> P;
    exp = P % 10;
    P /= 10;
    X += fast_exp(P, exp);
  }

  cout << X << endl;
}
