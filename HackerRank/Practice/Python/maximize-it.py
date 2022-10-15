from itertools import product

k, m = (map(int, input().split()))
l = []
for c in range(k):
    temp = list(map(int, input().split()))
    l.append(temp[1:])

temp = []
l1= []
for c in l:
    for d in c:
        temp.append(d**2)
    l1.append(temp)
    temp = []

AB = list(product(*l1))
A = []
for x in AB:
    y = sum(x)
    z = int(y%m)
    A.append(z)

print(max(A))