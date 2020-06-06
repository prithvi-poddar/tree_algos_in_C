Name: Prithvi Poddar
Roll no. 17191
ECS-202: ASSIGNMENT-3

Question 3.

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