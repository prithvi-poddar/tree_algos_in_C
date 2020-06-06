#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findFaultyNodeUtil(int info_[], int left[], int right[], int root, int min, int max);

int findFaultyNode(int info_[], int left[], int right[], int root)
{
    return (findFaultyNodeUtil(info_, left, right, root, -1000, 1000));
}

int findFaultyNodeUtil(int info_[], int left[], int right[], int root, int min, int max)  
{
    if (root == -1)
    {
        return 1;
    }
    if (info_[root] < min || info_[root] > max)
    {
        return info_[root];
    }  
    return 
        findFaultyNodeUtil(info_, left, right, left[root], min, info_[root]-1) &&  
        findFaultyNodeUtil(info_, left, right, right[root], info_[root]+1, max);  
}  

int main()
{
    printf("\n\nEnter the root element: ");
    int root;
    scanf("%d", &root);
    printf("\n***************************************************************");
    printf("\nNow you'll be prompted to enter the subsequent nodes.");
    printf("\nPay attention to the parent node who's child is being asked to enter.\n");
    printf("\nEnter -1 if you are not interested in a child node.");
    printf("\nEnter -2 when you want to end the tree.");
    printf("\n***************************************************************");

    int* info;
    int size = 1;
    int depth = 0;
    info = (int*)calloc(size, sizeof(int));
    int final;

    if (info == NULL)
    {
        printf("Memory not allocated.\n"); 
		exit(0);
    }

    else
    {
        info[0]=root;
        while(1>0)
        {
            depth++;
            size = pow(2,(depth+1))-1;
            info = realloc(info, size*sizeof(int));
            int to_break = 0;

            if(depth==1)
            {
                int child;
                printf("\nEnter left child of root: ");
                scanf("%d", &child);
                if (child==-2)
                {
                    printf("\nTerminating tree");
                    to_break = 1;
                    final = 1;
                    break;
                }
                else
                    info[1] = child;
                
                printf("\nEnter right child of root: ");
                scanf("%d", &child);
                if (child==-2)
                {
                    printf("\nTerminating tree");
                    to_break = 1;
                    final = 2;
                    break;
                }
                else
                    info[2] = child;
            }
            ///////////////////////////////////
            else
            {
                int old = pow(2,(depth))-1;
                int old_old = pow(2,(depth-1))-1;
                int a;
                for(a=(old-old_old-1);a<old; a++)
                {
                    if(info[a]!=-1)
                    {
                        int child;
                        printf("\nEnter left child of %d: ",info[a]);
                        scanf("%d",&child);
                        if (child==-2)
                        {
                            printf("\nTerminating tree.\n");
                            to_break=1;
                            final = (a*2)+1;
                            break;
                        }
                        else
                        {
                            info[(a*2)+1]=child;
                        }
                        
                        printf("\nEnter right child of %d: ",info[a]);
                        scanf("%d",&child);
                        if (child==-2)
                        {
                            printf("\nTerminating tree.\n");
                            to_break=1;
                            final = (a*2)+2;
                            break;
                        }
                        else
                        {
                            info[(a*2)+2]=child;
                        }
                    }
                    else
                    {
                        info[(a*2)+1] = -1;
                        info[(a*2)+2] = -1;
                    }
                }
            }
            if(to_break==1)
                break;
        }
    }
    int Info[final];
    int i;
    int count = 0;
    for(i=0; i<final; i++)
    {
        Info[i]=info[i];
        if(Info[i]!=-1 && Info[i]!=-2)
            count++;
        
    }

    int left[final], right[final];
    int j;
    for(j=0; j<final; j++)
    {
        left[j] = -1;
        right[j] = -1;
    }
    int r=0;
    int k;
    for(k=1; k<final;k++)
    {
        if (Info[k]!=-1 && Info[k]!=-2)
        {
            if((k-1)%2==0)
                left[(k-1)/2] = k;
            else
                right[(k-2)/2] = k;
        }
    }

    // Doing the inorder traversal
    int inorder[count];
    int stack[count*2];
    int flag=0;
    int top=0;
    stack[0]=-1;
    int ptr = r;
    label:
    while(ptr!=-1)
    {
        top++;
        stack[top] = ptr;
        ptr = left[ptr];
    }
    ptr = stack[top];
    top = top-1;
    while(ptr!=-1)
    {
        inorder[flag] = info[ptr];
        flag++;
        if(right[ptr]!=-1)
        {
            ptr = right[ptr];
            goto label;
        }
        ptr = stack[top];
        top = top-1;
    }

    printf("\nPrinting the inorder traversal of your tree: ");
    for(i=0; i<count; i++)
        printf("%d ",inorder[i]);
    printf("\n");
    //Checking if its a binary tree
    int yes = 1;
    for(i=1; i<count; i++)
    {
        if(inorder[i]<inorder[i-1])
        {
            yes = 0;
            printf("\nNO\n");
            break;
        }
    }

    if(yes==1)
    {
        printf("\nYES\n");
    }

    else if (yes == 0)
    {
        int fault = findFaultyNode(Info, left, right, r);
        printf("\nFaulty node: %d\n", fault);
    }
}