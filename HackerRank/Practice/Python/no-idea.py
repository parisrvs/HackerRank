n, m = map(int, input().split())
nl = list(map(int, input().split()))
a = set(map(int, input().split()))
b = set(map(int, input().split()))
h = 0
for c in nl:
    if c in a:
        h += 1
    elif c in b:
        h -= 1
print(h)