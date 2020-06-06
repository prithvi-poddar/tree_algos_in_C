#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getIndex(int arr[], int key, int length)
{
    int j;
    int index = -1;
    //int length = sizeof(arr)/sizeof(arr[0]);
    for (j=0; j<length; j++)
    {
        if(arr[j]==key)
        {
            index = j;
            break;
        }
    }
    return index;
}

preorder(int info[], int left[], int right[], int root, int size)
{
    int stack[size*10];
    int top=0;
    int ptr = root;
    int c;
    for(c=0; c<size*10; c++)
    {
        stack[c]=-1;
    }
    while (ptr != -1)
    {
        printf("%d ", info[ptr]);
        if(right[ptr]!=-1)
        {
            top = top+1;
            stack[top] = right[ptr];
        }
        if(left[ptr]!=-1)
        {
            ptr = left[ptr];
        }
        else
        {
            ptr = stack[top];
            top = top-1;
        }        
    } 
}

int* find(int info[], int left[], int right[], int root, int item)
{
    int loc, ptr, par;
    int *temp = (int*) malloc(sizeof(int) * 2);
    if (item==info[root])
    {
        loc = root;
        par = -1;
        *temp = loc;
        *(temp+1) = par;
        return temp;
    }
    int save;
    if(item<info[root])
    {
        ptr = left[root];
        save = root;
    }
    else
    {
        ptr = right[root];
        save = root;
    }
    while(ptr != -1)
    {
        if (item == info[ptr])
        {
            loc = ptr;
            par = save;
            *temp = loc;
            *(temp+1) = par;
            return temp;
        }
        else if(item<info[ptr])
        {
            save = ptr;
            ptr = left[ptr];
        }
        else
        {
            save=ptr;
            ptr = right[ptr];
        }
    }
    //unsucessful
    loc = -1;
    par = -1;
    *temp = loc;
    *(temp+1) = par;
    return temp;
}



int* casea(int info[], int left[], int right[], int root, int item, int size)
{
    int *target = find(info, left, right, root, item);
    int loc = target[0];
    int par = target[1];
    int child;
    if(left[loc] == -1 && right[loc] == -1)
    {
        child = -1;
    }
    else if(left[loc] != -1)
    {
        child = left[loc];
    }
    else
    {
        child = right[loc];
    }
    
    if (par != -1)
    {
        if (loc == left[par])
        {
            left[par] = child;
        }
        else
        {
            right[par] = child;
        }
    }
    else
    {
        root = child;
    }
    
    preorder(info, left, right, root, size);
    int* to_return = (int*) malloc(sizeof(int) * (1+(2*size)));
    *to_return = root;
    int i;
    for (i=0; i<size; i++)
    {
        to_return[(i+1)]=left[i];
        to_return[(i+1)+size]=right[i];
    }
    return to_return;
}

int* caseb(int info[], int left[], int right[], int root, int item, int size)
{
    int *target = find(info, left, right, root, item);
    int loc = target[0];
    int par = target[1];
    int ptr, save, locs, pars, suc, parsuc;
    ptr = right[loc];
    save = loc;

    while (left[ptr]!= -1)
    {
        save = ptr;
        ptr = left[ptr];
    }
    suc = ptr;
    parsuc = save;
    locs = loc;
    pars = par;
    loc = suc;
    par = parsuc;

    // call casea
    
    int child;
    if(left[loc] == -1 && right[loc] == -1)
    {
        child = -1;
    }
    else if(left[loc] != -1)
    {
        child = left[loc];
    }
    else
    {
        child = right[loc];
    }
    
    if (par != -1)
    {
        if (loc == left[par])
        {
            left[par] = child;
        }
        else
        {
            right[par] = child;
        }
    }
    else
    {
        root = child;
    }
    //casea ends

    loc = locs;
    par = pars;
    if(par!=-1)
    {
        if(loc==left[par])
        {
            left[par]=suc;
        }
        else
        {
            right[par] = suc;
        }
    }
    else
    {
        root = suc;
    }
    left[suc] = left[loc];
    right[suc] = right[loc];
    preorder(info, left, right, root, size);

    int* to_return = (int*) malloc(sizeof(int) * (1+(2*size)));
    *to_return = root;
    int i;
    for (i=0; i<size; i++)
    {
        to_return[(i+1)]=left[i];
        to_return[(i+1)+size]=right[i];
    }
    return to_return;
}



int* del(int info[], int left[], int right[], int root, int item, int size)
{
    int *tar = find(info, left, right, root, item);
    int loc = tar[0];
    int par = tar[1];
    if (loc == -1)
    {
        printf("\nItem not in tree\n");
        return 0;
    }
    if(right[loc]!=-1 && left[loc]!=-1)
    {
        caseb(info,left,right,root,item,size);
    }
    else
    {
        casea(info,left,right,root,item,size);
    }
}

int* findNodesInRange(int info[], int low, int high, int size)
{
    int count = 0;
    int i, j;
    for(i=low; i<=high; i++)
    {
        for(j=0; j<size; j++)
        {
            if (i==info[j])
                count++;
        }
    }
    int *nodes = (int*) malloc(sizeof(int) * (count+1));
    int c = 1;
    int a, b;
    *nodes = count;
    for(a=low; a<=high; a++)
    {
        for (b=0; b<size; b++)
        {
            if (a==info[b])
            {
                *(nodes+c)=a;
                c++;
            }
        }
    }
    return nodes;
}


int main()
{
    printf("Enter the number of nodes in your tree: ");
    int size;
    scanf("%d", &size);
    int info[size];
    printf("Enter the preorder traversal\nPress enter after typing each element:\n");
    int a;
    for (a=0;a<size;a++)
    {
        scanf("%d", &info[a]);
    }
    int root=0;
    int left[size];
    int right[size];
    int x;
    for(x=0; x<size; x++)
    {
        left[x]=-1;
        right[x]=-1;
    }
    //step 1
    int stack[size*10];
    int top=0;
    int c;
    for(c=0; c<size*10; c++)
    {
        stack[c]=NULL;
    }
    //step 2
    stack[top]=info[0];
    //step 3,4,5
    int i;
    for (i=1; i<size; i++)
    {
        int last_popped;
        while(stack[0]!=NULL && info[i]>stack[top])
        {
            last_popped = stack[top];
            stack[top] = NULL;
            top = top-1;
            if (stack[top]>=info[i])
            {
                int child = i;
                int parent = getIndex(info, last_popped, size);
                right[parent]=child;
                top = top+1;
                stack[top] = info[i];
                break;
            }
        }
        if (info[i]<stack[top])
        {
            int child = i;
            int parent = getIndex(info, stack[top], size);
            left[parent] = child;
            top = top+1;
            stack[top] = info[i];
        }
    }
    //del(info, left, right, root, 5, size);

    printf("\nEnter the lower bound of the range of nodes you want to remove:");
    int lower;
    scanf("%d", &lower);
    printf("\nEnter the upper bound of the range of nodes you want to remove:");
    int upper;
    scanf("%d", &upper);
    printf("\n***PLEASE REMEMBER THAT THE LAST PREORDER TRAVERSAL THAT IS PRINTED IS THE FINAL ANSWER***\n");

    int* finds = findNodesInRange(info,lower,upper,size);
    int length = finds[0];
    int matched_nodes[length];
    int l;
    printf("\nThe following nodes will be removed: ");
    for (l=0; l<length; l++)
    {
        matched_nodes[l] = finds[l+1];
        printf("%d, ",matched_nodes[l]);
    }
    int g;
    for (g=0; g<length; g++)
    {
        printf("\nRemoving %d from the tree, the preorder traversal is: ",matched_nodes[g]);
        int* returned = del(info, left, right, root, matched_nodes[g], size);
        root = returned[0];
        int z;
        for(z=0; z<size; z++)
        {
            left[z]=returned[z+1];
            right[z] = returned[z+1+size];
        }
    }

    printf("\n\n");
}