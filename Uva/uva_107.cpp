/* UVa problem: 107
 *
 * Topic: Arithmetic
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   The input consists of a sequence of cat-in-hat specifications. Each specification is a single line consisting
 *   of two positive integers, separated by white space. The first integer is the height of the initial cat, and
 *   the second integer is the number of worker cats.
 *   The number of cats inside each (non-smallest) cat’s hat is a constant, N. The height of these
 *   cats-in-a-hat is 1/(N+1) times the height of the cat whose hat they are in.
 *   The smallest cats are of height one.
 *   For each input line (cat-in-hat specification), print the number of cats that are not working, followed
 *   by a space, followed by the height of the stack of cats.
 *
 * Solution Summary:
 *	 The sum of all the cats can be represented by the series N^0 + N^1 + N^2 + ... + N^k.
 *	 The sum of heights can be represented by the serue N^0(initialHeight/(N+1)^0) + 
 *   N^1(initialHeight/(N+1)^1) + ... + N^k(initialHeight/(N+1)^k).
 *   It follows that the sum of the non-working cats is N^0 + N^1 + ... + N^(k-1).
 *   Since we know the height of the final cats is one, then initialHeight/(N+1)^k must equal 1.
 * 	 We can iterate through N and continually multiply (N+1) with itself until the result reaches the initialHeight.
 * 	 This method doesn't solve for two cases. The first where the input is 1 1. In this case, 0 1 is printed. The other
 * 	 case is when the number of workers is 1 but the initial height isn't. In this case, we know that the initial height
 *   is a power of 2 so we just iterate through powers of 2 until we reach the initial height. Here, N is always 1.
 * 	 The final step is to calculate the sum of the two series and print them. 
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
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

long int height; //Initial Height
long int working; //Number of working cats
int N = 0; //Number of cats within each hat
int k = 0; //Exponent such that N^k = working
long int result; //Result of (N+1)^k
int range = 25; //Limit of k of which to iterate through
vector <long int> inputs; //Vector of inputs

int main(int argc, char** argv) {
    
    //Read in input
    while(cin >> height >> working){
    	if(height == 0 && working == 0){
    		break;
    	}
        inputs.push_back(height);
        inputs.push_back(working);
    }
    

    for(int i = 0; i < inputs.size(); i+=2){
        height = inputs[i];
        working = inputs[i+1];
        if(height == 1 && working == 1){ //The special case of input being 1 1.
            cout << 0 << " " << 1 << endl;
            continue;
        }else if(working == 1){ //The special case of working cats being 1 and initial heights not.
            N = working;
            for(int i = 0; i < range; i++){ //Iterate through powers of 2 up until range.
                if(pow(2, i) == height){ //Stop if 2^i = initial height.
                    k = i;
                    break;
                }
            }
        }else{
            result = 1;
            N = 2;
            k = 0;
            while(1){
                result *= (N+1); //Multiply by (N+1) at each step.
                k++; //Increment k.
                if(result == height && pow(N, k) == working){ //Stop if N^k = working cats and the result = initial height.
                    break;
                }
                if(k == range){ //Reset k and increment N if range is reached.
                    result = 1;
                    N++;
                    k = 0;    
                }
            }  
        }
        if(working == 1){
            cout << k << " " << N*(height-working)+height << endl; //If number of working cats is 1, then the number of 
        }else{                                                     //cats in each hat is 1. Making the number of non-working cats k.
            cout << (1-working)/(1-N) << " " << N*(height-working)+height << endl; //Using simple algebra, these are the sums of the 
        }                                                                          //two series shown above.
    }                  
    return 0;
}

