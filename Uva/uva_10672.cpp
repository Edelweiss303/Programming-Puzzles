/* UVa problem: 10672
 *
 * Topic: Graph Traversal 
 *
 * Level: Easy
 * 
 * Brief problem description: 
 *
 *	The input contains a number of cases. Each case starts with the number n 
 *	followed by n lines. Each line contains at least three numbers which are: v 
 *	the number of a vertex, followed by the number of marbles originally placed 
 *	at vertex v followed by a number d which is the number of children of v, 
 *	followed by d numbers giving the identities of the children of v. The input 
 *	is terminated by a case where n = 0 and this case should not be processed.
 *	For each case in the input, output the smallest number of moves of marbles 
 *	resulting in one marble at each vertex of the tree.	
 * 
 * Solution Summary:
 *	
 *	We simply iterate through the leaves of the rooted tree. If a leaf has n marbles,
 *	we transfer n-1 marbles to it's parent and increment the amout of moves by abs(m-1)
 *	since it's possible to move -1 marbles up to the parent. However this will not change 
 *	the total number of marbles in the tree. We then delete this leaf and if the parent of 
 *	this leaf has no more children, it will be considered as another leaf to be processed 
 *  later. 
 *	
 * Used Resources:
 *
 *	https://en.wikipedia.org/wiki/Depth-first_search
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
#include <string>
#include <algorithm>
using namespace std;

//Struct to to hold informate about each vertex
struct vertex{
	int num;
	int marbles;
	int numChildren;
	vector<int> children;
};

vector<vertex> vertices; //Our graph as a vector of vertices

/* Functions for old solution. Incomplete because it most likely would time out

//This function returns a vertex given a number
vertex FindVertexByNumber(int v){
	for(int i = 0; i < vertices.size(); i++){
		if(i == v - 1){
			return vertices[i];
		}
	}
}


int DFS(vertex vert){
	for(int i = 0; i < vert.numChildren; i++){
		vertex child = FindVertexByNumber(vert.children[i]);
		int newMarbles = DFS(child);
		vertices[vert.num-1].marbles += newMarbles;
	}

	if(vert.numChildren == 0 && vert.marbles > 1){
		int transfer = vert.marbles - 1;
		vertices[vert.num-1].marbles = 1;
		moves += transfer;
		return transfer;
	}
	return 0;
}

void Redistribute(vertex vert, int numMarbles){
	for(int i = 0; i < vert.numChildren; i++){
		vertex child = FindVertexByNumber(vert.children[i]);
	}
}
*/


int main() { 

	int n; //Number of vertices
	int v; //Number of the vertex
	int m; //Number of marbles initially in the vertex
	int d; //Number of children of v

	int child; //Number of the child of v
	int moves; //Total number of moves

	vector<int> queue; //queue to hold all the leaves

	while(cin >> n){
		if(n == 0){
			break;
		}
		//Reset moves to zero and clear the queue and graph
		moves = 0;
		vertices.clear();
		queue.clear();

		//Take in the input
		for(int i = 0; i < n; i++){
			cin >> v >> m >> d;
			vertex p;
			p.num = v;
			p.marbles = m;
			p.numChildren = d;
			for(int j = 0; j < d; j++){
				cin >> child;
				p.children.push_back(child);
			}
			vertices.push_back(p);
		}
		
		int parents[10005]; //The parents of vertex i are stored at index i-1
		int outDegree[10005]; //The out degree of vertex i is stored at index i-1

		for(int i = 0; i < n; i++){
			vertex v = vertices[i];
			outDegree[i] = v.numChildren;
			for(int j = 0; j < v.numChildren; j++){
				parents[v.children[j] - 1] = v.num;
			}
		}
		
		//Store the leaves in the queue
		for(int i = 0; i < n; i++){
			if(outDegree[i] == 0){ //A vertex is a leaf if its out degree is zero
				queue.push_back(i+1);
			}
		}

		while(queue.size() > 0){

			int leafNum = queue[0]; //Take the first leaf
			int parentNum = parents[leafNum - 1]; //And its parent

			if(parentNum == 0){
				break;
			}

			outDegree[parentNum - 1]--; //Decrement the out degree of the parent 

			if(outDegree[parentNum - 1] == 0){ //Add the parent to the queue if it doesn't have any children
				queue.push_back(parentNum);
			}

			int leafMarbles = vertices[leafNum - 1].marbles; //Get the marbles in the leaf

			vertices[parentNum - 1].marbles += leafMarbles - 1; //Add leafMarbles - 1 to the parent

			moves += abs(leafMarbles - 1); //Increment the moves by that absolute value of the marbles moved

			queue.erase(queue.begin()); //Erase the first vertex from the queue;
		}

		/*
		for(int i = 0; i < queue.size(); i++){
			cout << queue[i].num << " ";
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			cout << parents[i] << " ";
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			cout << outDegree[i] << " ";
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			cout << vertices[i].num << " " << vertices[i].marbles << " " << vertices[i].numChildren << " ";
			for(int j = 0; j < vertices[i].numChildren; j++){
				cout << vertices[i].children[j] << " ";
			}
			cout << endl;
		}
		*/
		cout << moves << endl;
	}

    return 0;  
}  