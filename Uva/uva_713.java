/* UVa problem: 713
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *
 *	Reversed number is a number written in arabic numerals but the order of digits is reversed. The
 *	first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the
 *	tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the
 *	number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed
 *	number never has any trailing zeros.
 *	ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and
 *	output their reversed sum. Of course, the result is not unique because any particular number is a
 *	reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must
 *	assume that no zeros were lost by reversing (e.g. assume that the original number was 12).
 *	The input consists of N cases. The first line of the input contains only positive integer N. Then follow
 *	the cases. Each case consists of exactly one line with two positive integers separated by space. These
 *	are the reversed numbers you are to add. Numbers will be at most 200 characters long.
 *	For each case, print exactly one line containing only one integer — the reversed sum of two reversed
 *	numbers. Omit any leading zeros in the output.
 *
 * Solution Summary:
 *	
 *	Use Javas BigInteger library to compute the addition of large numbers.
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

import java.util.Scanner;
import java.math.BigInteger;

public class Main{  
 public static void main(String[] args){  

   Scanner sc1 = new Scanner(System.in);
   int N = sc1.nextInt();

   while(N != 0){ 

   	String string1 = sc1.next();
   	String string2 = sc1.next();  
   	
   	//Reverse the strings  
   	string1 = new StringBuilder(string1).reverse().toString();
   	string2 = new StringBuilder(string2).reverse().toString();

   	//Remove leading zeroes
   	while(string1.charAt(0) == '0'){
   		string1 = string1.substring(1);
   	} 

   	while(string2.charAt(0) == '0'){
   		string2 = string2.substring(1);
   	} 

   	//Convert them to BigIntegers
   	BigInteger integer1 = new BigInteger(string1);
   	BigInteger integer2 = new BigInteger(string2);

   	//Get the result of the addition into a string
   	String result = (integer1.add(integer2)).toString();

   	//Reverse the result
   	result = new StringBuilder(result).reverse().toString();

   	//Remove leading zeroes
   	while(result.charAt(0) == '0'){
   		result = result.substring(1);
   	}

   	//Print the result
   	System.out.println(result);

   	N--;
	}
	sc1.close();
 }  
}   
