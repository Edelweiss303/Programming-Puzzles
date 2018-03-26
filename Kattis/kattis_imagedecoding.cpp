/* Kattis problem: imagedecoding
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Input consists of a sequence of up to 10 images. Each image starts with a line containing an integer 
 *	 1≤n≤100 indicating the number of scanlines in the image. The following n lines each contain one 
 *	 scanline. Each scanline starts with either ‘.’ or ‘#’, indicating the value of the first pixel on the scanline. 
 * 	 Following this are up to 100 integers each in the range [1,100] indicating the lengths of each 
 *	 subsequent run of pixels. Each scanline has at most 1000 total pixels (the sum of the integers on the line). 
 *	 Each run uses only one pixel value, which alternates between ‘.’ and ‘#’ with each run. 
 *	 Input ends with a line containing just the number 0.
 *	 For each image, decode and output image according to run-length encoding. 
 *	 In other words, for each scanline, expand each run of pixels of length y into y copies of that pixel value.
 *
 * Solution Summary:
 *
 *   We take in the first line as an integer numLines. We then take the next numLines lines as input and 
 *	 iteratively print the corresponding symbol (# or .) however many number of times it says on that line. 
 *	 Also check to make sure all printed lines are the same length.
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

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int numLines; //Number of lines in an image
string inputLine; //The lines with pixel print lengths
char pixels[2] = {'#', '.'}; //The two possible pixels
int n; //Index of pixels
int m; //Number of times to prin # or .
int start = 0; //Index for lines vector indicating where to start 
int length; //Length of printed line
int firstLength; //Length of the first printed line
bool error; //Boolean to check whether or not the image has an error
vector <string> lines; //Vector of all the lines with pixel print lengths
vector <int> imageSizes; //Vector of all the numbers of lines in an image

int main(int argc, char** argv) {
    while(1){
    	cin >> numLines; //Take in number of lines
    	imageSizes.push_back(numLines);

        if(numLines == 0){
        	break;
        }
    	for(int i = 0; i <= numLines; i++){ //Take in the next numLines 
        	getline(cin, inputLine);
        	lines.push_back(inputLine);
    	}
    }

    for(int i = 0; i < imageSizes.size(); i++){ //Iterate through each image

    	if(i != 0 && i != imageSizes.size() - 1){ //Formatting garbage because Kattis is dumb
    		cout <<endl;
    	}

    	if(imageSizes[i] == 0){ //0 indicates end of input
    		break;
    	}

    	lines.erase(lines.begin() + start); //Erase the first part of every image because it's just a blank line
    	error = false; //Set error to false
    	for(int j = start; j < imageSizes[i] + start; j++){ //Iterate through each line of each image
    		length = 0;

    		if(lines[j][0] == '#'){ //Check the first character and assign index accordingly 
    			n = 0;
    		}else if(lines[j][0] == '.'){
    			n = 1;
    		}

    		lines[j].erase(0,2); //Erase the first character of each line (# or .) since we don't need it
    		stringstream stream(lines[j]); //Put that line in a stream and parse for integers
    		while(stream >> m){
    			length += m;
    			for(int k = 0; k < m; k++){
    				cout << pixels[n]; //Print the pixel m number of times
    			}

    			if(n == 0){ //Alternate pixels
    				n = 1;
    			}else if(n == 1){
    				n = 0;
    			}
    		}

    		if(j == start){
    			firstLength = length; //Assign the length of the first line
    		}

    		if(firstLength != length){ //Check to see if any lines are different from the first line
    			error = true; //If they are, the image has an error	
    		}
    		cout << endl;

    	}
    	if(error == true){
    		cout << "Error decoding image" << endl;
    	}

    	start += imageSizes[i]; //Increment the new starting point for the lines vector
    }  
    return 0;
}

