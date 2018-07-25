/* UVa problem: 11955
 *
 * Topic: Geometry
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *  The solution is to be printed as an equation of the form (x − h)^2 + (y − k)^2 = r^2
 *  and an equation of the form x^2 + y^2 + cx + dy − e = 0. Each line of input to your 
 *  program will contain the x and y coordinates of three points, in the order Ax, Ay, Bx, 
 *  By, Cx, Cy. These coordinates will be real numbers separated from each other by one 
 *  or more spaces. Your program must print the required equations on two lines using the 
 *  format given in the sample below. Your computed values for h, k, r, c, d, and e in 
 *  Equations 1 and 2 above are to be printed with three digits after the decimal point. 
 *  Plus and minus signs in the equations should be changed as needed to avoid multiple 
 *  signs before a number. Plus, minus, and equal signs must be separated from the 
 *  adjacent characters by a single space on each side. No other spaces are to appear in 
 *  the equations. Print a single blank line after each equation pair.
 *
 * Solution Summary:
 *	 
 *  Calculate the perpendicular bisector for 2 of the 3 edges in the triangle and
 *  get the intersection of those 2 lines. Then use that to get the radius. This
 *  gives us our circle equation.
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
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

//Struct for each point
struct point{
    double x;
    double y;
};

point midPoint(double x1, double y1, double x2, double y2){
    point p;
    p.x = (x1 + x2)/2;
    p.y = (y1 + y2)/2;
    return p;

}


int main() {

    double Ax, Ay;
    double Bx, By;
    double Cx, Cy;
	string xOperation;
    string yOperation;
    string eOperation;

    while(cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy){
        point ABmid = midPoint(Ax, Ay, Bx, By); //Midpoint of line AB
        point BCmid = midPoint(Bx, By, Cx, Cy); //Midpoint of line BC

        double slopeAB = -(Bx-Ax)/(By-Ay); //Slope of the bisector of line AB
        double slopeBC = -(Cx-Bx)/(Cy-By); //Slope of the bisector of line BC                             

        double ABk = ABmid.y - (slopeAB * ABmid.x); //Get the k in y = mx + k for line AB
        double BCk = BCmid.y - (slopeBC * BCmid.x); //Get the k in y = mx + k for line BC

        double centreX = (BCk - ABk) / (slopeAB - slopeBC); //Get x coordinate of circle 
        double centreY = (slopeAB * centreX) + ABk; //Get y coordinate of circle

        double r = sqrt(pow(centreX - Ax, 2) + pow(centreY - Ay, 2)); //Calculate Euclidean distance between the
                                                                      //centre and any point to get the radius


        //SO MUCH FORMATTING TRASH D:< 
        if(centreX < 0){
            xOperation = " + "; 
        }else{
            xOperation = " - ";
        }

        if(centreY < 0){
            yOperation = " + "; 
        }else{
            yOperation = " - ";
        }

        centreX = abs(centreX);
        centreY = abs(centreY);

        printf("(x%s%.3f)^2 + (y%s%.3f)^2 = %.3f^2\n", xOperation.c_str(), centreX, yOperation.c_str(), centreY, r);
        
        r = pow(centreX, 2) + pow(centreY, 2) - pow(r, 2);
        if(r < 0){
            eOperation = " - ";
        }else{
            eOperation = " + ";
        }

        centreX *= 2;
        centreY *= 2;

        r = abs(r);
        printf("x^2 + y^2%s%.3fx%s%.3fy%s%.3f = 0\n\n", xOperation.c_str(), centreX, yOperation.c_str(), centreY, eOperation.c_str(), r);
    }

   return 0;
}













