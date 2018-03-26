/* Kattis problem: tolower
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *  Anthony is participating in a programming contest today! He’s excellent at 
 *  algorithms; he can design and implement the solution to even the hardest 
 *  problems in the programming contest in minutes. Unfortunately, parsing inputs 
 *  is his greatest weakness. Specifically, he really struggles with problems which 
 *  require him to convert strings to lowercase. When Anthony is given a string, he 
 *  only converts the first character of the string to lowercase. The first line of 
 *  the input contains two integers P and T, 1≤P,T≤50. The next PT lines contain the 
 *  test data for all the problems in the contest. Every line contains exactly one 
 *  nonempty string composed of only English characters. Test cases are grouped by 
 *  problems, so the first T lines represent all the test cases for problem 1, the 
 *  next T lines represent all the test cases for problem 2, and so on. It is 
 *  guaranteed that the total number of characters in the test cases does not exceed 
 *  50000. Output a single integer denoting the number of problems Anthony will solve 
 *  during the contest.
 *   
 *
 * Solution Summary:
 *
 *  Simply iterate through ever letter (starting at the second) of every test case of 
 *  every problem. If the letter is uppercase, move on to the next problem's test cases. 
 *  Otherwise increment the count. 
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

    int P, T;
    int count = 0;
    string testCase;
    vector<string> testCases; 
    vector<vector<string>> problems;

    cin >> P >> T;

    for(int i = 0; i < P; i++){
        testCases.clear();
        for(int j = 0; j < T; j++){
            cin >> testCase;
            testCases.push_back(testCase); //Take in all the test cases
        }
        problems.push_back(testCases); //Take in those test cases as problems
    }


    /*
    for(int i = 0; i < P * T; i++){
        cout << inputs[i] << endl;
    }
    */
    
    for(int i = 0; i < P; i++){
        bool isCapital = false;
        for(int j = 0; j < T; j++){
            testCase = problems[i][j];
            //cout << testCase << endl;
            for(int k = 1; k < testCase.length(); k++){ //k = 1 because we ignore the first letter
                //cout << testCase[k] << endl;
                if(isupper(testCase[k])){ //if the letter is uppercase, break out of the loop
                    isCapital = true;
                    break;
                }
            }
            if(isCapital){ //Same idea, if it is capital, brake out of the loop
                break;
            }
        }
        if(!isCapital){ //increment count if all the letters were lowercase
            count++;
        }
    }
    

    cout << count << endl;

    return 0;
}

