/* UVa problem: 10065
 *
 * Topic: Geometry
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	The input file consists of several data blocks. Each data block describes one tile. The first line of a data
 *	block contains an integer N (3 ≤ N ≤ 100) indicating the number of corner points of the tile. Each
 *	of the next N lines contains two integers giving the (x, y) co-ordinates of a corner point (determined
 *	using a suitable origin and orientation of the axes) where 0 ≤ x, y ≤ 1000. Starting from the first point
 *	given in the input the corner points occur in the same order on the boundary of the tile as they appear
 * 	in the input.
 * 
 * Solution Summary:
 *	
 *	Using the Gift-wrapping algorithm, we find the convex hull of the given tile. Then we find the
 *	area of the convex hull and the area of the tile using the Shoelace formula. Lastly, we 
 * 	compute (areaHull-areaTile)/areaHull * 100 to get the percentage of wasted space. 
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Graham_scan
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

//struct describing points
struct point{
	double x;
	double y;
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
	int N;
	int tileNum = 0;
	double xInput;
	double yInput;
	vector <point> points;
	vector <point> hull;

	while(1){
		tileNum++;

		cin >> N;
		if(N == 0){
			break;
		}
		points.clear();
		hull.clear();
		for(int i = 0; i < N; i++){
			cin >> xInput >> yInput;
			point p;
			p.x = xInput;
			p.y = yInput;
			points.push_back(p);
		}

		int index = 0;

    	for(int i = 1; i < points.size(); i++){ //find index of leftmost point
        	if(points[i].x < points[index].x){
            	index = i;              
    		}
    	}
		int p1 = index; //start with the left most point
		int p2;
		do{ 
			hull.push_back(points[p1]);
			p2 = (p1+1)%N; 

			for(int j = 0; j < N; j++){
				//Check to see if any point is more counter-clockwise than p2 by finding the z-coordinate
				if(CoordinateZ(points[p1], points[j], points[p2]) > 0){
					p2 = j;
				}
			}

			p1 = p2; //Set p1 to p2 so it gets added to the hull

		}while(p1 != index); //repeat until we reach the first point again

		/*
		cout << "number of points in hull: " << hull.size() << endl;
		for(int i = 0; i < hull.size(); i++){
			cout << hull[i].x << " " << hull[i].y << endl;
		}
		*/
		
		//calculate areas and percentage
		double areaHull = Area(hull);
		double areaTile = Area(points);
		double wasted; 

		wasted = (areaHull - areaTile)/areaHull * 100;
		
		//cout << "Hull area: " << areaHull << endl;
		//cout << "Tile area: " << areaTile << endl;

		cout << setprecision(2) << fixed;
		cout << "Tile #" << tileNum << endl;
		cout << "Wasted Space = " <<  wasted << " %" << endl << endl;
		
	}
	return 0;
}