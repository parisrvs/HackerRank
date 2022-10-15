import math
import os
import random
import re
import sys
from collections import Counter


if __name__ == '__main__':
    s = input()
    l = dict(sorted((Counter(s)).items(), key = lambda x:x[0]))
    l = list(sorted(l.items(), key = lambda x:x[1], reverse=True))
    for i in range(3):
        for j in l[i]:
            print(j, end=' ')
        print()
