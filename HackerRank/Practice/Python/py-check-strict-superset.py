s, n = set(map(int, input().split())), int(input())

c = True
for _ in range(n):
    t = set(map(int, input().split()))
    if len(t.difference(s)) >= 1:
        c = False  

print(c)

