/* Kattis problem: A Rational sequence 2 
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   F(1)=1/1,F(2)=1/2,F(3)=2/1,F(4)=1/3,F(5)=3/2,F(6)=2/3,…
 *   Write a program which finds the value of n for which F(n) is p/q for inputs p and q.
 *
 * Solution Summary:
 *
 *   Calculate the depth of the tree first by tracing p/q to the root node
 *   Use this depth to find n by multiplying it by 2 or multiplying it by 2 and adding 2
 *   
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
#include <fstream>
#include <vector>

using namespace std;

/*
 * 
 */
struct fraction{
    int n;
    int d;
};

int main(int argc, char** argv) {
    int length;
    scanf("%d", &length);
    int position = 1;
    int k;
    struct fraction data[length];
    struct fraction rational;
    
    for(int i=0; i<length; i++){
        scanf("%d %d/%d",&k, &rational.n, &rational.d);
        data[i] = rational;
    }
    
    for(int i=0; i<length; i++){
        
        int layers = 0;
        vector<int> children;
        
        
        while(data[i].n != data[i].d){
            if(data[i].n < data[i].d){
                data[i].d -= data[i].n;
                children.push_back(1);
            }else if(data[i].n > data[i].d) {
                data[i].n -= data[i].d;
                children.push_back(2);
            }
            layers++;
        }
        
        position = 1;
        for(int j=layers-1;j >= 0; j--){
            if(children[j] == 1){
                position = (position * 2);
            }else if(children[j] ==2){
                position = (position * 2) + 1;
            }
        }
        printf("%d %d\n", i+1, position);
    }
    return 0;
}

