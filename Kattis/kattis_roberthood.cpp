/* Kattis problem: roberthood
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The input starts with a line containing a single positive 
 *	integer C,2≤C≤100000, representing the number of shots for this 
 *	particular contestant. Each following line contains a pair of 
 *	integer coordinates separated by a space, representing the 
 *	x- and y-coordinates of a successful shot. The absolute value of 
 *	any coordinate does not exceed 1000. 
 *	Print the longest distance between any pair of arrows as a 
 *	floating point number on a single line. The answer is considered 
 *	correct if it has a relative or absolute error of less than 10^−6.
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
#include <math.h>

using namespace std;

//This function returns the Euclidean distance between two points
double EuclideanDistance(double x1, double y1, double x2, double y2){ 
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main(){
	int C;
	double x;
	double y;
	vector<double> points;
	vector<double> distances;
	cin >> C;

	for(int i = 0; i < C; i++){
		cin >> x >> y;
		points.push_back(x);
		points.push_back(y);
	}

	for(int i = 0; i < points.size(); i+=2){ //Calculate Euclidean distance between every point
        for(int j = i+2; j < points.size(); j+=2 ){
                distances.push_back(EuclideanDistance(points[i], points[i+1], points[j], points[j+1]));
        }
    }

    cout << *max_element(distances.begin(), distances.end()) << endl;

	return 0;
}