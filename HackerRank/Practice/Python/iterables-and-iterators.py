from itertools import combinations

n, s, k = int(input()), ''.join(list(input().split())), int(input())
m = list(combinations(s, k))
total = len(m)
p = 0
for x in m:
    if 'a' in x:
        p+=1
print ("{0:.3f}".format(p/total))