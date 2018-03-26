/* UVa problem: 10034
 *
 * Topic: Graph Algorithms
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   The input begins with a single positive integer on a line by itself indicating the number of the cases
 *   following, each of them as described below. This line is followed by a blank line, and there is also a
 *   blank line between two consecutive inputs.
 *   The first line contains 0 < n ≤ 100, the number of freckles on Dick’s back. For each freckle, a line
 *   follows; each following line contains two real numbers indicating the (x, y) coordinates of the freckle
 *   Your program prints a single real number to two decimal places: the minimum total length of ink
 *   lines that can connect all the freckles.
 *
 * Solution Summary:
 *  
 *    Implement Kruskal's algorithm to find the weight of the minimum spanning tree.
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
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

//Struct defining each edge as an item with a weight and a start and end point
struct edge {
    long double weight;
    int start;
    int end;
};

//Comparison function to sort the vector of edges by the edge weight
bool CompareByWeight(const edge& a, const edge& b){
    return a.weight < b.weight;
}


//This function returns the Euclidean distance between two points
long double EuclideanDistance(long double x1, long double y1, long double x2, long double y2){ 
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}


int main(int argc, char** argv) {
    int numCases;
    int numPoints;
    long double x;
    long double y;
    vector<long double> points;
    vector<edge> edges;
    


    cin >> numCases;

    for(int i = 0; i < numCases; i++){
        cin >> numPoints;
        //clear previous edges and points 
        edges.clear(); 
        points.clear();

        for(int j = 0; j < numPoints; j++){ //Take in points
            cin >> x >> y; 
            points.push_back(x);
            points.push_back(y);

        }
        

        for(int j = 0; j < points.size(); j+=2){ //Calculate Euclidean distance between every point
            for(int k = j+2; k < points.size(); k+=2 ){
                edge e;
                e.weight = EuclideanDistance(points[j], points[j+1], points[k], points[k+1]);
                e.start = j/2 + 1;
                e.end = k/2 + 1;
                edges.push_back(e); //Store the edges
            }
        }

        sort(edges.begin(), edges.end(), CompareByWeight); //Sort the edges by weight

        int START; 
        int END;

        vector<int> MST;

        MST.push_back(edges[0].start);
        MST.push_back(edges[0].end);
        long double totalWeight = edges[0].weight;

        
        /*
        cout << "Number of edges: " << edges.size() << endl;
        cout << "First Edge weight: " << edges[0].weight << endl;
        cout << "MST Size: " << MST.size() << endl;
        

        for(int k = 0; k < edges.size(); k++){
            cout << "The line from " << edges[k].start << " to " << 
            edges[k].end << " has a weight of " << edges[k].weight << endl;
        }
        */

        for(int j = 1; j < edges.size(); j++){
        }
        
    }

        
    return 0;	
}












