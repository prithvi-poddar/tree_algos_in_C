Name: Prithvi Poddar
Roll no. 17191
ECS-202: ASSIGNMENT-3

Question 2.

	

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