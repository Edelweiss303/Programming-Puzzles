/* UVa problem: 10655
 *
 * Topic: Arithmetic
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *   The input file contains several lines of inputs. Each line except the last 
 *   line contains 3 non-negative integers p, q and n. Here p denotes the value 
 *   of a+b and q denotes the value of ab.
 *   For each line of input except the last one produce one line of output. 
 *   This line contains the value of a^n + b^n. 
 *
 * Solution Summary:
 *
 *   We know that any number in the Fibonacci sequence is the sum of the two 
 *   previous numbers in the sequence. So F(n) = F(n-1) + F(n-2). 
 *   There is also a Fibonacci proof using matrices that states that 
 *   ([[1, 1],[1, 0]]^n)*[[F(1)],[F(0)]] = [[F(n)],[F(n-1)]]
 *   If we treat a^n + b^n as results in a sequence of the same manner, we get
 *   F(n) = a^n + b^n for n >= 0. Multiplying this by P (a + b), we get 
 *   p * F(n) = a^(n+1) + b^(n+1) + ab^n + ba^n for n >= 1. Which can be factored and
 *   rearranged to F(n+1) = p * F(n) - q * F(n-1). Knowing this, we can put
 *   p and -q as the first row in the matrix proof of the Fibonacci sequence so that
 *   we get ([[p, -q],[1, 0]]^n)*[[F(1)],[F(0)]] = [[F(n+1)],[F(n)]]
 *   It follows that we just have to perform the above computation and then print out F(n).
 *
 * Used Resources:
 *
 *   This proof from stackexchange: 
 *   https://math.stackexchange.com/questions/61997/proof-of-this-result-related-to-fibonacci-numbers-beginpmatrix11-10-end
 *  
 *   Problem was discussed in club meeting but solution was not given.
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
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//This function multiplies 2 2x2 matrices and stores the answer back in A
void multiplySquare(long long A[2][2], long long B[2][2]){
    
    long long result[2][2];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            result[i][j] = 0;
            for (int k = 0; k < 2; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
 
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            A[i][j] = result[i][j]; 
        }
    }
}

//This function takes a 2x2 matrix and recursively raises it
//to the nth power using the multiplySquare function.
//Here, A and B are the same matrix.
void power(long long A[2][2], long long B[2][2], long long n){
   
    if(n == 0){ //Return identity matrix if n = 0.
            A[0][0] = 1;
            A[0][1] = 0;
            A[1][0] = 0;
            A[1][1] = 1;
            
    }else if(n % 2 == 0) { 
        power(A, B, n/2); //Take A to the power of n/2 to save time.
        multiplySquare(A, A);
    }
    else {
        power(A, B, (n - 1)/2); //Take A to the power of n/2 to save time.
        multiplySquare(A, A);
        multiplySquare(A, B); //Multiply by matrix B one more time if n is an odd number.
    }
    
}
//This function multiplies a 2x2 matrix with a 2x1 matrix and stores the answer back in B.
void multiply(long long A[2][2], long long B[2][1]){
    
    long long result[2][1];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 1; j++){
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
 
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 1; j++){
            B[i][j] = result[i][j]; 
        }
    }
}



long long p; //a+b
long long q; //a*b
long long n; //Exponent to raise by (a^n + b^n)
size_t inputCount = 2; //Number of spaces in input
string inputString; //Current input
long f_0 = 2; //a^0 + b^0 = 2
long f_1; //p = a + b

vector <long long> inputs;


int main(int argc, char** argv) {
    
    //Read in input
    while(inputCount == 2){
        getline(cin, inputString);
        stringstream stream(inputString); 
        inputCount = count(inputString.begin(), inputString.end(), ' '); //Parse the lines for spaces to count how many ints
        while(1) {
            stream >> p >> q >> n;
            if(!stream){
                break;
            }
            inputs.push_back(p);
            inputs.push_back(q);
            inputs.push_back(n);
        }
    }
        
    for(int i = 0; i < inputs.size(); i+=3){
        p = inputs[i];
        q = inputs[i + 1];
        n = inputs[i + 2];
        f_1 = p;
        long long matrixA[2][2] = {{1, 1}, {1, 0}};
        long long matrixA_temp[2][2] = {{p, -q}, {1, 0}}; //Copy of matrixA since the result of multiplication stores values in matrixA
        long long matrixB[2][1] = {{f_1}, {f_0}};
        
        if(p == 0 && q == 0){
            cout << 0 << endl;
        }else{
            power(matrixA, matrixA_temp, n); //Take matrix A and raise it to the nth power.
            cout << matrixA[0][0] << " " << matrixA[0][1] << endl;
            cout << matrixA[1][0] << " " << matrixA[1][1] << endl;
            multiply(matrixA, matrixB); //Multiply the result with matrixB.
            cout << matrixB[1][0] << endl; //Print the result.
        }   
    }
    return 0;
}