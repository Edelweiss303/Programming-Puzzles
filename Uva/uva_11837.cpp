/* UVa problem: 11837
 *
 * Topic: Strings
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *	 The input consists of several test cases. The first line of a test case contains two integers M and T
 *	 (1 ≤ M ≤ 10^5, 1 ≤ T ≤ 10^4, T ≤ M), indicating the number of notes in the song suspected of having
 *	 been plagiarized and in the suspect snippet. Each of the next two lines contains M and T notes,
 *	 respectively, indicating the notes of the song and of the suspect snippet.
 *	 Notes in each line are separated by one space; each note is one among ‘A’, ‘B’, ‘C’, ‘D’, ‘E’, ‘F’ or ‘G’,
 *	 possibly followed by an accidental sign: ‘#’ for sharp or ‘b’ for flat.
 * 	 The last test case is followed by a line containing only two zeros separated by a blank space.
 * 	 For each test case your program must print a single line containing one character, ‘S’ in case the song
 * 	 has been plagiarized by the text, or ‘N’ in case the song has not been plagiarized by the text.
 *
 * Solution Summary:
 *
 *	 First calculate the number of semi-tones between each note in the song and the suspect snippet. Put these
 *	 in seperate vectors then implement the KMP algorithm. Create a partial match table of the snippet to 
 *	 figure out how much to backtrack in the event of a mismatch between iterative comparisons of a note 
 *	 of the song and the suspect snippet.
 *	
 * Used Resources:
 *	
 * 	 https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
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

using namespace std;

//This function takes a note as input and returns its corresponding semi-tone
int SemiTone(string note){
	if(note == "A"){
		return 1;
	}else if(note == "A#" || note == "Bb"){
		return 2;	
	}else if(note == "B" || note == "Cb"){
		return 3;
	}else if(note == "B#" || note == "C"){
		return 4;	
	}else if(note == "C#" || note == "Db"){
		return 5;	
	}else if(note == "D"){
		return 6;	
	}else if(note == "D#" || note == "Eb"){
		return 7;	
	}else if(note == "E" || note == "Fb"){
		return 8;	
	}else if(note == "E#" || note == "F"){
		return 9;	
	}else if(note == "F#" || note == "Gb"){
		return 10;	
	}else if(note == "G"){
		return 11;	
	}else if(note == "G#" || note == "Ab"){
		return 12;	
	}
	return 0; //To get rid of the stupid compiler warning. It should never return 0.
}

/*
List of possible notes and their corresponding semi-tones
A = 1
A# = 2
Bb = 2
B = 3
B# = 4
Cb = 3
C = 4
C# = 5
Db = 5
D = 6
D# = 7
Eb = 7
E = 8
E# = 9
Fb = 8
F = 9
F# = 10
Gb = 10
G = 11
G# = 12
Ab = 12
*/
int main(){
	int M; //Number of original notes
	int T; //Number of potentially plagiarised notes
	string note; //Current input
	vector<int> song; //The original notes stored as is
	vector<int> songTones; //The semi-tones between all the notes of the original song
	vector<int> snippet; //The suspect snippet notes stored as is
	vector<int> snippetTones; //The semi-tones between all the notes of the suspect snippet
	string R;

	while(1){

		cin >> M >> T;

		if(M == 0 && T == 0){
			return 0;
		}

		
		R = "N"; //Initialize result
		//clear all vectors
		song.clear();
		songTones.clear();
		snippet.clear();
		snippetTones.clear();

		for(int i = 0; i < M; i++){ //Take in the original song
			cin >> note;
			song.push_back(SemiTone(note));
		}

		for(int i = 1; i < M; i++){ //Get all the semi-tones between the notes of the original song
			if(song[i-1] - song[i] > 0){
				songTones.push_back(song[i-1] - song[i] - 12);
			}else{
				songTones.push_back(song[i-1] - song[i]);
			}
		}

		for(int i = 0; i < T; i++){ //Take in the suspect snippet
			cin >> note;
			snippet.push_back(SemiTone(note));
		}

		for(int i = 1; i < T; i++){ //Get all the semi-tones between the notes of the suspect snippet
			if(snippet[i-1] - snippet[i] > 0){
				snippetTones.push_back(snippet[i-1] - snippet[i] - 12);
			}else{
				snippetTones.push_back(snippet[i-1] - snippet[i]);
			}
		}
		/*
		for(int i = 0; i < M; i++){
			cout << songTones[i] << " ";
		}
		cout << endl;

		for(int i = 0; i < T-1; i++){
			cout << snippetTones[i] << " ";
		}
		cout << endl;
		*/

		vector<int> matchTable; //The partial match table
    	int j = -1; //First entry is -1, so we don't backtrack if the snippet is of size 1
    	matchTable.push_back(j);
    
    	for(int i = 0; i < T - 1; i++) { 
        	while (j >= 0 && snippetTones[i] != snippetTones[j]){
        		j = matchTable[j];
        	}
        	j++;
        	matchTable.push_back(j); //Add next value of J to table
    	}
    	
    	/*
    	for(int i = 0; i < T - 1; i++){
			cout << matchTable[i] << " ";
		}
		cout << endl;
		*/

    	j = 0;
    	for (int i = 0; i < M - 1; i++){
        	while (j >= 0 && songTones[i] != snippetTones[j]){ //Compare values from the song and the snippet
            	j = matchTable[j]; //Backtrack if they are not equal
        	}
        	j++;
        	if (j == T - 1) { //If J is the same as the length of the table, it is plagiarized 
        		R = "S";
        	}
    	}
    	cout << R << endl;	
	}
	return 0;
}