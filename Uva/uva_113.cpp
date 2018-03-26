 /* UVa problem: 113
 *
 * Topic: Arithmetic
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given an integer n >= 1 and an integer p >= 1 you are to write a program that determines (n)sqrt(p), the
 *   positive n-th root of p. In this problem, given such integers n and p, p will always be of the form k
 *   n
 *   for an integer k (this integer is what your program must find).
 *
 *
 * Solution Summary:
 *
 *  Using log laws to turn p^(1/n) into k = e^(ln(p)/n)
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

#include<stdio.h>
#include<math.h>
double n;
double p;
double k;
int main(){
    while (scanf("%lf%lf", &n, &p) == 2){
    	k = exp(log(p)/n);
        printf("%.0lf\n", k);
    }
    return 0;
}