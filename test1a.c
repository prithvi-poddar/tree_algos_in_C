#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodes
{
     int data;
     int left;
     int right;
}node;

node createNode(int value)
{
     node newNode;
     newNode.data = value;
     newNode.left = -1;
     newNode.right = -1;
     return (newNode);
}

int totalTrees(int num)
{
     int roots[num+1];
     int i;
     for(i=0; i<num+1; i++)
          roots[i]=0;
     roots[0]=1;
     roots[1]=1;
     int j;
     for(i=2; i<=num; i++)
     {
          for(j=1; j<=i; j++)
          {
               roots[i]=roots[i] + (roots[i-j]*roots[j-1]);
          }
     }
     return roots[num];
}

node* generateTrees(int start, int end)
{
     int length = totalTrees(end);
     int count = 0;
     node* list = malloc(sizeof(node)*length);
     int i, j, k, l;
     for(i=start; i<=end; i++)
     {
          node* left = generateTrees(start, i-1);
          node* right = generateTrees(i+1, end);


          int left_length = totalTrees(i-1);
          int right_legth = totalTrees(end-i);

          node leftSub[left_length];
          for(l=0; l<left_length; l++)
               leftSub[l] = left[l];
          
          node rightSub[right_legth];
          for(l=0; l<right_legth; l++)
               rightSub[l] = right[l];

          for(j=0; j<left_length; j++)
          {
               node Left = leftSub[j];
               for (k=0; k<right_legth; k++)
               {
                    node Right = rightSub[k];
                    node newNode;
                    newNode.data = i;
                    newNode.left = Left.data;
                    newNode.right = Right.data;
                    list[count] = newNode;
                    count++;
               }
          }
     }
     return list;
}

/*void preorder(node root)
{
    if (root.data != -1)
    {
        printf("%d ", root.data);
        preorder(root.left);
     preorder(root->right);
}*/

int main()
{
     printf("Enter the number of nodes N: ");
     int n;
     scanf("%d",&n);
     int total = totalTrees(n);
     printf("\nTotal number of structurally unique trees with %d nodes are: %d\n",n, total);

     /*node *out = generateTrees(1,n);
     int i;
     for(i=0; i<total; i++)
     {
          node* output = out;
          preorder(output[i]);
     }*/
}