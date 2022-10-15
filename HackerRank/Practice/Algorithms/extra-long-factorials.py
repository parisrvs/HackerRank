#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'extraLongFactorials' function below.
#
# The function accepts INTEGER n as parameter.
#

def factorial(c):
    if c == 1:
        return 1
    else:
        return c * factorial(c-1)


def extraLongFactorials(n):
    f = factorial(n)
    print(f"{f}")
    # Write your code here

if __name__ == '__main__':
    n = int(input().strip())

    extraLongFactorials(n)
