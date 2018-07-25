 # UVa problem: 622
 #
 # Topic: Other
 #
 # Level: Challenging
 # 
 # Brief problem description: 
 #
 #   Using the following grammar:
 #	 < expression > := < component > | < component > + < expression >
 # 	 < component > := < f actor > | < f actor > * < component >
 #	 < f actor > := < positiveinteger > | (< expression >)
 #	 write a program which analyses expressions conforming to the rules of this grammar and evaluates
 #	 them, if the analysis has been successfully completed. It may be assumed that there is no overflow of
 #	 float(C)/real(Pascal) numbers range.
 #	 A integer n stating the number of expressions, then consecutive n lines, each containingan expression
 #	 given as a character string.
 #
 #
 # Solution Summary:
 #
 #	Simply use Pythons built-in eval function.
 #
 # Used Resources:
 #
 #   ...
 #
 # I hereby certify that I have produced the following solution myself
 # using only the resources listed above in accordance with the CMPUT
 # 403 collaboration policy.
 #
 #
 # Rishi Barnwal
 #

import math
import sys

numCases = int(input())

for i in range(numCases):
	res = input()

	try:
		eval(res)
		print(eval(res)) 
	except:
		print("ERROR")





