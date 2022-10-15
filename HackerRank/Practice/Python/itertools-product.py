from itertools import product

A, B = list(map(int, input().split())), list(map(int, input().split()))
AB = list(product(A, B))

for i in AB:
    print(i, end=' ')
print()
