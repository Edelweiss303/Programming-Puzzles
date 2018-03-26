/* UVa problem: 811
 *
 * Topic: Geometry
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	The input contains several test cases, each of which describes a hypothetical forest. Each test case
 *	begins with a line containing a single integer n, 2 ≤ n ≤ 15, the number of trees in the forest. The trees
 *	are identified by consecutive integers 1 to n. Each of the subsequent lines contains 4 integers xi, yi, vi, li
 *	that describe a single tree. (xi, yi) is the position of the tree in the plane, vi is its value, and li is the
 *	length of fence that can be built using the wood of the tree. vi and li are between 0 and 10,000.
 *	The input ends with an empty test case (n = 0).
 *	For each test case, compute a subset of the trees such that, using the wood from that subset, the
 *	remaining trees can be enclosed in a single fence. Find the subset with a minimum value. If more than
 *	one such minimum-value subset exists, choose one with the smallest number of trees.
 * 
 * Solution Summary:
 *	
 *
 * Used Resources:
 *
 *	 https://en.wikipedia.org/wiki/Graham_scan
 *	 https://en.wikipedia.org/wiki/Gift_wrapping_algorithm
 * 	 https://en.wikipedia.org/wiki/Shoelace_formula
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
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//Struct to for x,y coordinates
struct point{
	int x;
	int y;
};

//Struct containing info for each tree;
struct tree{
	point p;
	int y;
	int v;
	int l;
};

//This function computes the z-coordinate of the cross product of the two vectors, p1p2 and p1p3
double CoordinateZ(point p1, point p2, point p3){
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

//This function computes the area using the Shoelace formula
double Area(vector<point> p){

    double area = 0.0;

    int j = p.size() - 1;
    for (int i = 0; i < p.size(); i++){
        area += (p[j].x + p[i].x) * (p[j].y - p[i].y);
        j = i;
    }
    return abs(area / 2.0);
}



int main(){
	int n; //Number of trees
	int forrestNum = 0;
	int x_i;
	int y_i;
	int v_i;
	int l_i;
	vector <tree> trees;
	vector <int> treesToCut;
	int extraWood;

	while(1){
		forrestNum++;
		cin >> n;
		if(n == 0){
			break;
		}

		vector <bool> combinations(n, false);

		trees.clear();
		for(int i = 0; i < n; i++){
			cin >> x_i >> y_i >> v_i >> l_i;
			tree t;
			t.p.x = x_i;
			t.p.y = y_i;
			t.v = v_i;
			t.l = l_i;
			trees.push_back(t);
		}

		if(n == 2){
			if(trees[0].v < trees[1].v){
				extraWood = trees[0].v;
				treesToCut.push_back(1);
			}else{
				extraWood = trees[1].v;
				treesToCut.push_back(2);
			}
		}else{
			for(int i = 1; i <= n - 1; i++){

			}
		}
		
	}
	return 0;
}