/* UVa problem: 623
 *
 * Topic: Other
 *
 * Level: Challenging
 * 
 * Brief problem description: 
 *  
 *  Your task is to write a programs which calculates a factorial of a given number.
 *  Any number of lines, each containing value n for which you should provide value of n!
 *  2 lines for each input case. First should contain value n followed by character ‘!’. The second should
 *  contain calculated value n!.
 *  Assumptions:
 *  • Value of a number n which factorial should be calculated of does not exceed 1000 (although 500!
 *  is the name of the problem, 500 is a small limit).
 *  • Mind that visually big number of case 4 is broken after 80 characters, but this is not the case in
 *  the real output file.
 *
 * Solution Summary:
 *  
 *   Initialize a BigInteger array with value 1 and then iteratively add the last element multiplied 
 *   by i into the array.
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

        BigInteger[] factorials = new BigInteger[1005]; //Initialize BigInteger Array
        factorials[0] = BigInteger.valueOf(1); //Insert 1

        for(int i = 1; i <= 1000; i++){
            factorials[i] = factorials[i-1].multiply(BigInteger.valueOf(i));
        }

        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            System.out.printf("%d!\n", n);
            System.out.println(factorials[n]);
        }

        sc.close();
    }
}