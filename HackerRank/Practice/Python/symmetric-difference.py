m, ml, n, nl = int(input()), set(map(int, input().split())), int(input()), set(map(int, input().split()))
c = nl.difference(ml)
d = ml.difference(nl)
c.update(d)
for i in sorted(c):
    print(i)