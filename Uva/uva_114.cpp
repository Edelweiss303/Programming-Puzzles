/* UVa problem: 114
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	 Your program should simulate one game of pinball. There are several input lines that describe the
 * 	 game. The first line gives integers m and n, separated by a space. This describes a cartesian grid where
 *	 1 ≤ x ≤ m and 1 ≤ y ≤ n on which the game is “played”. It will be the case that 2 < m < 51 and
 *	 2 < n < 51. The next line gives the integer cost for hitting a wall. The next line gives the number of
 * 	 bumpers, an integer p ≥ 0. The next p lines give the x position, y position, value, and cost, of each 
 * 	 bumper, as four integers per line separated by space(s). The x and y positions of all bumpers will be 
 * 	 in the range of the grid. The value and cost may be any integer (i.e., they may be negative; a negative 
 * 	 cost adds lifetime to a ball that hits the bumper). The remaining lines of the file represent the balls. 
 * 	 Each line represents one ball, and contains four integers separated by space(s): the initial x and y 
 * 	 position of the ball, the direction of movement, and its lifetime. The position will be in range (and 
 * 	 not on top of any bumper or wall). The direction will be one of four values: 0 for increasing x (right), 
 *	 1 for increasing y (up), 2 for decreasing x (left), and 3 for decreasing y (down). The lifetime will be 
 *	 some positive integer. There should be one line of output for each ball giving an integer number of 
 * 	 points accumulated by that ball in the same order as the balls appear in the input. After all of these 
 * 	 lines, the total points for all balls should be printed.
 *
 * Solution Summary:
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

int m, n; //m x n grid
int wallCost, p; //cost of hitting wall and number of bumpers
int moves[4] = {0, 3, 2, 1};
vector<bumper> bumperList; //List of bumpers

struct bumper{
	int x, y;
	int val;
	int cost;
}

int findBumper(int x, int y){
	for(int i = 0; i < bumperList.size()){
		if(bumperList[i].x = x && bumperList[i].y = y){
			return bumperList[i].val, bumperList[i].cost;
		}
	}
}
int right(int x, y, score, life){
	if(arena[x+1][y] = 0){
		life--;
		return life;

	}else(arena[x+1][y] = 1){
		life--;

		if(life == 0){
			return life;
		}

		int val, cost = findBumper(x+1, y);
		score += val;
		life -= cost;
		if(life < 1){
			return life, score;
		}else{
			
		}
	}
}
int down(){

}
int left(){

}
int up(){

}
int movement(int x, int y, vector<vector<int>> arena){
	if(arena[x][y] == 0){

	}else if(arena[x][y] == 1){

	}else if(arena[x][y] == 2){

	}
}

using namespace std;
int main(){
	
	int x, y; //position of bumper or ball
	int val, bumpCost; //value of a bumper and cost of hitting bumper
	
	int dir, life; //Direction of ball and its lifetime
	vector<int> scores; //List of scores

	cin >> m >> n;

	vector<vector<int>> pinball(m, vector<int>(n, 0)); //initialize m x n grid of zeroes 

	//Set all the walls of the grid to 2
	fill(pinball[0].begin(), pinball[0].end(), 2);
	fill(pinball[m-1].begin(), pinball[m-1].end(), 2);
	for(int i = 0; i < m; i++){
		pinball[i][0] = 2;
		pinball[i][n-1] = 2;
	}

	cin >> cost >> p;

	for(int i = 0; i < p; i++){
		cin >> x >> y >> val >> bumpCost;
		pinball[x][y] = 1; // the grid at (x,y) has a bumper
		bumper b;
		b.x = x;
		b.y = y;
		b.val = val;
		b.cost = bumpCost;
		bumperList.push_back(b);
	}

	while(cin >> x >> y >> dir >> lifetime){
		int score = 0;
		int location = pinball[x][y];
		while(lifetime > 0){

			if(dir == 0){
				pinball[x+1][y];

			}else if(dir == 1){
				pinball[x][y+1];
			
			}else if(dir == 2){
				pinball[x-1][y];

			}else if(dir == 3){
				pinball[x][y-1];

			}
		}
	}
	return 0;
}