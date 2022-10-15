#!/bin/python3

import math
import os
import random
import re
import sys
import bisect as bs

#
# Complete the 'solve' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY tree
#  2. 2D_INTEGER_ARRAY queries
#

union = []
def getroot(x):
    if union[x] < 0:
        return x
    union[x] = getroot(union[x])
    return union[x]

def solve(tree, queries):
    n = len(tree)
    tree.sort(key=lambda x: x[2])
    paths = {}
    for c in range(n+1):
        union.append(-1)
    
    
    for u, v, c in tree:
        u = getroot(u - 1)
        v = getroot(v - 1)
        paths[c] = paths.get(c, 0) + union[u] * union[v]
        if union[u] < union[v]:
            u, v = v, u
        union[v] += union[u]
        union[u] = v

    paths = list(sorted(paths.items()))
    a = [0]
    b =[0]
    for x, y in paths:
        a.append(x)
        b.append(b[-1] + y)
    
    result = []
    for l, r in queries:
        result.append(b[bs.bisect(a, r) - 1] - b[bs.bisect_left(a, l) - 1])
    return result
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    tree = []

    for _ in range(n - 1):
        tree.append(list(map(int, input().rstrip().split())))

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    result = solve(tree, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
