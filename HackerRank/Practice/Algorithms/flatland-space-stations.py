#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the flatlandSpaceStations function below.
def flatlandSpaceStations(n, c):
    if n == len(c):
        return 0
    c.sort()
    temp = []
    for a, b in zip(c[1:], c):
        temp.append(a-b)
    
    diff = max(temp) if len(c) > 1 else 0
    maxi = max(diff//2, c[0], n-1-c[-1])
    return maxi 
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    c = list(map(int, input().rstrip().split()))

    result = flatlandSpaceStations(n, c)

    fptr.write(str(result) + '\n')

    fptr.close()
