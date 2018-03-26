/* Kattis problem: 4 THought
 *
 * Topic: (see topic list)
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Come up with an equation that equals input using four 4s and 3 binary expressions from {+, -, *, /}
 *
 * Solution Summary:
 *
 *   There is only 64 possible equations we can create. 
 *	 Iteratively create them all, solve them, then check to see if input is the same as any of those answers
 *
 * Used Resources:
 *
 *   CMPUT 403 code library
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
#include <list>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

map<string, int> var;

int ParseExp(string e){
  int p, x, a, b;
  int count = 0;
 
  for(int i=0; i<e.length(); i++){
    if(e[i] == ' ') {
      e.erase(i,1);// Remove spaces
    }
 }

  for(x = e.size()-1, p = 0; x >= 0; x--){
    p += (e[x] == ')') - (e[x] == '(');
    if(!p && (e[x] == '+' || e[x] == '-')){
      a = ParseExp(e.substr(0,x));
      b = ParseExp(e.substr(x+1));
      // Check overflow - underflow here
      return e[x] == '+' ? a+b : a-b;
    }
  }
  for(x = e.size()-1, p = 0; x >= 0; x--){
    p += (e[x] == ')') - (e[x] == '(');
    if(!p && (e[x] == '*' || e[x] == '/')){
      a = ParseExp(e.substr(0,x));
      b = ParseExp(e.substr(x+1));
      // Check overflow - underflow & div/0 here
      return e[x] == '*' ? a*b : a/b;
    }
  }
  for(x = e.size()-1, p = 0; x >= 0; x--){
    p += (e[x] == ')') - (e[x] == '(');
    if(!p && e[x] == '^'){
      a = ParseExp(e.substr(0,x));
      b = ParseExp(e.substr(x+1));
      // Check overflow here
      return (int)pow((double)a,b);
    }
  }
  if(e[0] == '(') return ParseExp(e.substr(1,e.size()-2));
  if(isdigit(e[0])) return atoi(e.c_str());
  return var[e];
}


int main(){
  int input;
  int numInputs;
  int count = 0;
  int counter_1 = 0;
  int counter_2 = 0;
  string operations[4] = {" + "," - "," * "," / "};
  string expression;

  vector <int> inputs;
  vector <string> equations;
  vector <int> results;



  int numv, i, x; char buff[1000];


  scanf("%d", &numInputs);

  for(int i = 0; i < numInputs; i++){
    scanf("%d", &input);
    inputs.push_back(input);
  }

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        expression = "4" + operations[i] + "4" + operations[j] + "4" + operations[k] + "4";
        equations.push_back(expression);
        count++;
      }
    }
  }

  for(int i = 0; i < count; i++){
  	results.push_back(ParseExp(equations[i]));
  }

  
  while(counter_1 < numInputs){
    counter_2 = 0;
  	while(counter_2 < count){
  		if(inputs[counter_1] == results[counter_2]){
  			printf("%s = %d\n", equations[counter_2].c_str(), inputs[counter_1]);
  			counter_1++;
  		}else if(counter_2 == count - 1){
        printf("no solution\n");
        counter_1++;
      }
  		if (counter_1 == numInputs){
  			counter_2 = count;
  		}
  		counter_2++;
  	}
  }
}
