from collections import defaultdict

n, m = map(int, input().split())
d = defaultdict(list)
for c in range(1, n+1):
    x = input()
    d[x].append(c)

for c in range(m):
    y = input()
    if y in d:
        for l in d[y]:
            print(l, end=' ')
        print()
    else:
        print(-1)