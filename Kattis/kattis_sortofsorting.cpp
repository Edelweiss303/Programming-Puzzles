/* Kattis problem: sortofsorting
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Write a program that sorts a list of student last names, but the sort only 
 *   uses the first two letters of the name. Nothing else in the name is used 
 *   for sorting. However, if two names have the same first two letters, they 
 *   should stay in the same order as in the input (this is known as a ‘stable 
 *   sort’). Sorting is case sensitive based on ASCII order (with uppercase 
 *   letters sorting before lowercase letters, i.e., A<B<…<Z<a<b<…<z). Input 
 *   consists of a sequence of up to 500 test cases. Each case starts with a 
 *   line containing an integer 1≤n≤200. After this follow n last names made up 
 *   of only letters (a–z, lowercase or uppercase), one name per line. Names have 
 *   between 2 and 20 letters. Input ends when n=0. For each case, print the last 
 *   names in sort-of-sorted order, one per line. Print a blank line between cases.
 *
 * Solution Summary:
 *
 *   Simply use the built in C++ stable sort function with a custom compare function
 *   that only compares the first two letters of a string.
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
#include <algorithm>
#include <vector>

using namespace std;

//Custom sorting function
bool sortOfSorting(const string &a1, const string &b1){
    string a2 = "";
    string b2 = "";

    //First two letters of string a1
    a2.push_back(a1[0]);
    a2.push_back(a1[1]);

    //First two letters of string a2
    b2.push_back(b1[0]);
    b2.push_back(b1[1]);

    return a2 < b2;
}

int main() {

    int n; //Number of names
    vector<int> numNames; //Vector of the number of names
    string name; //Single name
    vector<string> nameList; //Vector of names


    while(cin >> n){
        if(n == 0){
            break;
        }

        numNames.push_back(n);
        
        for(int i = 0; i < n; i++){
            cin >> name;
            nameList.push_back(name);
        }
    }

    for(int i = 0; i < numNames.size(); i++){

        //Sort the vector using the custom sort function
        stable_sort(nameList.begin(), nameList.begin() + numNames[i], sortOfSorting);

        for(int j = 0; j < numNames[i]; j++){ //Print the first numNames[i] names
            cout << nameList[j] << endl;
        }
        cout << endl;

        //Erase the ones that were just printed
        nameList.erase(nameList.begin(), nameList.begin() + numNames[i]);
    }

    return 0;
}



