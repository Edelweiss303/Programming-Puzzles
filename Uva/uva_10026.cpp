/* UVa problem: 10026
 *
 * Topic: Sorting
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *   The input begins with a single positive integer on a line by itself indicating the number
 *   of the cases following, each of them as described below. This line is followed by a blank
 *   line, and there is also a blank line between two consecutive inputs. First line of input 
 *   contains an integer N (1 ≤ N ≤ 1000). The next N lines each contain two numbers: the time 
 *   and fine of each task in order. For each test case, the output must follow the description 
 *   below. The outputs of two consecutive cases will be separated by a blank line.You programm 
 *   should print the sequence of jobs with minimal fine. Each job should be represented by its 
 *   number in input. All integers should be placed on only one output line and separated by one
 *   space. If multiple solutions are possible, print the first lexicographically.
 *
 * Solution Summary:
 *  
 *   We simply save the index of every task and sort the tasks with the built-in C++ stable_sort 
 *   function using a custom comparison function. This function compares two tasks t1 and t2 by 
 *   taking the time of one and multiplying it with the fine of the other.  
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
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

//Struct to hold information about each task
struct task{
    int index;
    int time;
    int fine;
};

//Compare two tasks
bool Compare(task t1, task t2){
    return t1.time * t2.fine < t2.time * t1.fine;
}


int main() {
    int numCases;
    int N;
    vector<task> tasks;

    cin >> numCases;

    for(int i = 0; i < numCases; i++){
        tasks.clear();
        cin >> N;
        for(int j = 0; j < N; j++){
            task t;
            t.index = j + 1;
            cin >> t.time >> t.fine;
            tasks.push_back(t);
        }     

        stable_sort(tasks.begin(), tasks.end(), Compare); //Stable_sort keeps lexicographic order for equivalent tasks

        for(int j = 0; j < N; j++){
            cout << tasks[j].index;
            if(j != N - 1){ //Uva formatting garbage
                cout << " ";
            }
        }
        cout << endl;
        if(i != numCases - 1){ //Uva formatting garbage
            cout << endl;
        }
    }

        
    return 0;	
}












