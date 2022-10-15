from collections import OrderedDict

d = OrderedDict()
N = int(input())

for _ in range(N):
    w = input().strip()
    if w in d:
        d[w] += 1
    else:
        d[w] = 1

print(len(d))
for count in d.values():
    print(count, end=' ')