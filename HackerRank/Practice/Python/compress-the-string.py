from itertools import groupby

S = input()
for key, value in groupby(S):
    l = list(value)
    print(f"({len(l)}, {key})", end = ' ')
print()