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
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

//Struct defining each vertex
struct vertex{
    double x, y;
};

//Struct defining each edge as an item with a weight and a start and end point
struct edge {
    long double weight;
    vertex start;
    vertex end;
};



vector<vector<vertex>> listOfSets; //Our disjoint set

//This function joins the set containing A and the set containing B
bool Union(vertex A, vertex B){
    int index1;
    int index2;
    for(int i = 0; i < listOfSets.size(); i++){ //search for A
        for(int j = 0; j < listOfSets[i].size(); j++){
            if(listOfSets[i][j].x == A.x && listOfSets[i][j].y == A.y){
                index1 = i;
                //cout << "element " << A.x << ", " << A.y << " found at: " << j << endl;
            }
        }
    }
    for(int i = 0; i < listOfSets.size(); i++){ //search for B
        for(int j = 0; j < listOfSets[i].size(); j++){
            if(listOfSets[i][j].x == B.x && listOfSets[i][j].y == B.y){
                index2 = i;
                //cout << "element " << B.x << ", " << B.y << " found at: " << j << endl;
            }
        }    
    }

    if(index1 != index2){ //Join the two sets and return true if A and B are in different sets
        listOfSets[index1].insert(listOfSets[index1].end(), listOfSets[index2].begin(), listOfSets[index2].end());
        listOfSets.erase(listOfSets.begin() + index2);
        return true;
    }
    return false;

}

//create N different sets, each one containing a single int from 1 to
void Create(int N){
    for(int k = 0; k < N; k++){
        vector<vertex> set; //a single set
        listOfSets.push_back(set);
    }

}

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
    double x, y;
    
    long double mstWeight = 0;
    


    cin >> numCases;
    cout << fixed << setprecision(2);

    for(int i = 0; i < numCases; i++){
        cin >> numPoints;

        //clear previous edges, vertices and disjoint sets
        
        vector<vertex> vertices; //Exactly what it looks like
    	vector<edge> edges; //Also exactly what it looks like
        listOfSets.clear();

        mstWeight = 0; //Initialize MST weight

        Create(numPoints); //Creat a vector of vectors (disjoint set)

        for(int j = 0; j < numPoints; j++){ //Take in points
            cin >> x >> y; 
            vertex v;
            v.x = x;
            v.y = y;
            vertices.push_back(v);
            listOfSets[j].push_back(v); //fill each vector within a vector with a single vertex
        }
        /*
        for(int i = 0; i < numPoints; i++){
            for(int j = 0; j < listOfSets[i].size(); j++){
                cout << "set number " << i+1 << ": " << listOfSets[i][j].x << ", " << listOfSets[i][j].y << endl;
            }
        }
        */

        for(int j = 0; j < numPoints; j++){ //Calculate Euclidean distance between every point
            for(int k = j+1; k < numPoints; k++ ){
                edge e;
                e.weight = EuclideanDistance(vertices[j].x, vertices[j].y, vertices[k].x, vertices[k].y);
                e.start = vertices[j];
                e.end = vertices[k];
                edges.push_back(e); //Store the edges
            }
        }

        sort(edges.begin(), edges.end(), CompareByWeight); //Sort the edges by weight

        /*
        for(int k = 0; k < edges.size(); k++){
            cout << "Line from " << edges[k].start.x << ", " << edges[k].start.y <<  " to " << 
            edges[k].end.x << ", " << edges[k].end.y << " has a weight of " << edges[k].weight << endl;
        }
        */

        for(int j = 0; j < edges.size(); j++){
            if(Union(edges[j].start, edges[j].end)){ //If the two elements were in different sets,
                mstWeight += edges[j].weight;        //add the weight to the total
            }
        }

        cout << mstWeight << endl;
        if(i != numCases - 1){ //Uva formatting garbage
            cout << endl;
        }
        
    }

        
    return 0;	
}












