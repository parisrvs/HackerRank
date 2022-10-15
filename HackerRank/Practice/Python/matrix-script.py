

import math
import os
import random
import re
import sys
from typing import Pattern




first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

a = []
for c in range(m):
    for d in range(n):
        a.append(matrix[d][c])


s = ''.join(a)
pattern = r"(?<=[a-zA-Z0-9])[^a-zA-Z0-9]+(?=[a-zA-Z0-9])"
print(re.sub(pattern,' ',s))