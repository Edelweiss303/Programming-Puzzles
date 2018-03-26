 # UVa problem: 113
 #
 # Topic: Arithmetic
 #
 # Level: easy
 # 
 # Brief problem description: 
 #
 #   Given an integer n >= 1 and an integer p >= 1 you are to write a program that determines (n)sqrt(p), the
 #   positive n-th root of p. In this problem, given such integers n and p, p will always be of the form k
 #   n
 #   for an integer k (this integer is what your program must find).
 #
 #
 # Solution Summary:
 #
 #  Using log laws to turn p^(1/n) into k = e^(ln(p)/n)
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

inputs = []

while(True):
	try:
		n = input("")

		if(n == ""):
			break

		p = input("")

		n = float(n)
		p = float(p)
		inputs.append(n)
		inputs.append(p)

	except EOFError:
		break

for i in range(0, len(inputs), 2):
	n = inputs[i]
	p = inputs[i+1]
	k = math.exp(math.log(p)/n)
	print(int(k))



