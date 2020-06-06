Name: Prithvi Poddar
Roll no. 17191
ECS-202: ASSIGNMENT-3

Question 1.

	
	->First we calculate the number of unique bst's.
	->To do that, suppose i is the root. Then (1,...,i-1)will fall in the left subtree and (i+1,...,n) will fall in the right subtree.
	  So (i-1)*(n-i) will be the number of unique bsts with i as the root. Now calculate this value for all i from 1 to N and add them.
	  ALGORITH: number of bst
	  PARAMETERS: n 
	  1. Initialize array of length n+1
	  2. array[0]:=array[1]:=1
	  3. for i in range(2, n+1):
	  		a. for j in range (1, i+1):
				array[i] = array[i] + (array[i-j]*array[j-1])
	  4. return array[n]

	->BUG: To generate all the possible trees, we use the following algorithm:
			Choose every node to be the root once and then generate the subsequent left and right sub trees recursively.
			Then for each left sub tree we iterate over all the right sub trees and then connect them to the node.
	->BUG: I wasn't able to implement the geneating algorithm. Tried using C structure to define the structure
		   of a node but wasn't able to get the output due to pointer mismatch.

	-> The code only outputs the total number of possible trees.