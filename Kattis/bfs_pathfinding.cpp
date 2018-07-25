//Shortest path finding algorithm using BFS


#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct pos{
    int index;  
    int parent;
    int dist; 
};

//Finds neighbours and their indices of each node
void findNeighbours(const unsigned char* pMap, int current, int nMapWidth, int nMapHeight, int* neighbours, int* neighbourIndex){
	if(current - nMapWidth >= 0){
		neighbours[0] = pMap[current - nMapWidth];
		neighbourIndex[0] = current - nMapWidth;
	}
	if((current + 1) % nMapWidth != 0){
		neighbours[1] = pMap[current + 1];
		neighbourIndex[1] = current + 1;
	}
	if(current + nMapWidth <= (nMapWidth * nMapHeight) - 1){
		neighbours[2] = pMap[current + nMapWidth];
		neighbourIndex[2] = current + nMapWidth;
	}
	if((current - 1) % nMapWidth != nMapWidth - 1){ 
		neighbours[3] = pMap[current - 1];
		neighbourIndex[3] = current - 1;
	}
}

int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY, 
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize){

	bool visited[nMapWidth * nMapHeight]; //Keep track of visited nodes
	fill_n(visited, nMapWidth * nMapHeight, false); 

	pos path[nMapWidth * nMapHeight]; //Keep track of nodes and their parents

	

	int start = nStartX + (nStartY * nMapWidth); //Index of the start
	int end = nTargetX + (nTargetY * nMapWidth); //Index of the target

	visited[start] = true; //The first node is visited

	queue<pos> q; 
	
	pos p;
	p.index = start;
	p.parent = 0;
	p.dist = 0;
	q.push(p);

	while(!q.empty()){

		p = q.front(); //deque
		path[p.index] = p;

		if(p.index == end){
			
			if(p.dist > nOutBufferSize){
				return -1;
			}

			pos bread = p;
			for(int i = p.dist - 1; i >= 0; i--){
				pOutBuffer[i] = bread.index;
				bread = path[bread.parent];
			}

			return p.dist;
		}
		
		q.pop();	

		int neighbours[4] = {0, 0, 0, 0};
		int neighbourIndex[4] = {-1, -1, -1, -1};

		findNeighbours(pMap, p.index, nMapWidth, nMapHeight, neighbours, neighbourIndex); //Find traversable neighbours of current node
		
		/*
		cout << "current position: " << p.index << endl;
		cout << (int)neighbours[0] << " " << (int)neighbours[1] << " "  << (int)neighbours[2] << " "  << (int)neighbours[3] << endl;
		cout << neighbourIndex[0] << " " << neighbourIndex[1] << " "  << neighbourIndex[2] << " "  << neighbourIndex[3] << endl;
		*/

		for(int i = 0; i < 4; i++){ //Iterate through neighbours
			if(neighbours[i] == 1 && visited[neighbourIndex[i]] == false){
				visited[neighbourIndex[i]] = true; //Mark as visited
				pos n;
				n.index = neighbourIndex[i];
				n.parent = p.index;
				n.dist = p.dist + 1; //Distance is 1 plus the distance of the parent (Depth in BFS)
				q.push(n); //Enque
			}

		}
	}
	return -1;
}
/**/
int main(){

	unsigned char pMap[] = {
		1, 0,
		0, 1
	};
	int pOutBuffer[50];
	int res = FindPath(0, 0, 1, 1, pMap, 2, 2, pOutBuffer, 50);

 	cout << "Shortest path length: " << res << endl; 
 	cout << "Path taken was: " << endl;
 	for(int i = 0; i < res; i++){
 		cout << pOutBuffer[i] << endl;
 	}

    return 0;
}



