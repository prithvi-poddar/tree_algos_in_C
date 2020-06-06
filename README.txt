Name: Prithvi Poddar
Roll no. 17191
ECS-202: ASSIGNMENT-3

Question 1.

	Part 1.
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

	Part 2:

	->First the user is asked to enter the number of elements in the tree.
	->Then the user has to input the elements one by one as mentioned in the instructions on screen.
	->The code then constructs the binary search tree from the preorder traversal using the following algorithm:
		ALGORITHM: Construct BST from preorder traversal
		PARAMETERS: pre[], root
		1. Create an empty stack
		2. Make the first value as root. Push it to the stack
		3. for all elements in pre[]:
			a.Keep on popping while the stack is not empty and the next value is greater than stack’s top value. 
			  Make this value as the right child of the last popped node. Push the new node to the stack.
			b.If the next value is less than the stack’s top value, make this value as the left child of the stack’s top node 
			  Push the new node to the stack.

	->The user then inputs the range of nodes to be deleted.
	->Using the algorithm given in the book, the nodes in that range are removed one by one and the corresponding preorder traversals are printed.

	P.S. While removing the nodes, the algorithm prints out the preorder traversal after each node is removed. The final answer is the last traversal that is printed. 

Question 2.

->The code starts taking the input in the following way:

suppose:                        0
                              /   \
							 /     \
                            1       2
                           /  \    /  \
                          3    4  5    6
If this is your tree then the nodes are taken in order 0, 1, 2, 3, 4, 5, 6
->The code tells you which node to enter by referrering to its parent.
->enter -1 if you dont want to enter a node and -2 to trminate the tree.
->The tree gets stored in the code in a linked list representation and the array 'info' represents a complete binary tree with mising nodes saved as -1.
->We then generate the inorder traversal of the entered tree. If the traversal is in strictly ascending order then the tree is a binary search tree.
->If the traversal is not ascending then we set out to find the node that is breaking the bst structure.
->We use the MIN, MAX techniue to find the faulty node.
The algorithm is as follows:
	1: The root lies between -infinity to infinity.
	2: check if the value of the left child of the root lie betwee -infinity and root.
	3: check if the value of the right child of the root lies between root and infinity.
	4: repeat step 2. and 3. recursively for the subsequent subtrees.
	5: If any node doesn't satisfy the above condition then return that node and find its depth from the 'info' array as the info array is a complete bst.
