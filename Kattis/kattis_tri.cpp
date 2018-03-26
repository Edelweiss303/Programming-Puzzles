/* Kattis problem: tri 
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   The first line of input contains three integers less than 100, separated by spaces. 
 * 	 The input data will guarantee that a solution, although not necessarily unique, will always exist.
 * 	 On a single line, output a valid equation containing the three integers (in the same order), 
 * 	 an equals sign and one of the four operations. If there are multiple solutions, output any of them.
 *
 * Solution Summary:
 *
 *  Since there are only 8 permutations we need to check, two for each operation, we can simply check them
 *  all with a bunch of if statements.   
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



int main() {
    int x, y, z;    

   scanf("%d %d %d", &x, &y, &z);

    if(x + y == z){
    	printf("%d+%d=%d\n", x, y, z);
    }else if(x == y + z){
    	printf("%d=%d+%d\n", x, y, z);
    }else if(x - y == z){
    	printf("%d-%d=%d\n", x, y, z);
    }else if(x == y - z){
    	printf("%d=%d-%d\n", x, y, z);
    }else if(x * y == z){
    	printf("%d*%d=%d\n", x, y, z);
    }else if(x == y * z){
    	printf("%d=%d*%d\n", x, y, z);
    }else if(x / y == z){
    	printf("%d/%d=%d\n", x, y, z);
    }else if(x == y / z){
    	printf("%d=%d/%d\n", x, y, z);
    }

    return 0;
}

