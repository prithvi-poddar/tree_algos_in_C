#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jun  4 15:46:10 2020

@author: prithvi
"""

import numpy as np

def getIndex(arr, key):
    index = 0
    for i in range(len(arr)):
        if(arr[i]==key):
            index = i
    return index


info = [10, 5, 1, 7, 40, 50]
left = [-1, -1, -1, -1, -1, -1]
right = [-1, -1, -1, -1, -1, -1]
root = 0
stack = np.zeros((100))
top = 0
stack[top] = info[0]
top = top+1

for i in range(1,6):
    if (stack[top-1]<info[i]):
        child = i
        parent = getIndex(info, stack[top-1])
        left[parent] = child
        stack[top] = info[i]
        top = top+1
        
    else:
        top = top-1
        last_popped = stack[top]
        stack[top] = 0
        k = top-1
        while (k>=0):
            if(stack[k]<info[i]):
                last_popped = stack[k]
                stack[k] = 0
                top = k
                
                if (top == 0):
                    parent = getIndex(info, last_popped)
                    child = i
                    right[parent] = child
                    break
                
            elif(stack[k]>=info[i]):
                parent = getIndex(info, last_popped)
                child = i
                right[parent] = child
                stack[top] = info[i]
                top = top+1
                break
                
            k = k-1
