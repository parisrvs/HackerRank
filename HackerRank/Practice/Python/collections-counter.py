from collections import Counter

x = int(input())
l = Counter(list(map(int, input().split())))

cost = 0
n = int(input())
for _ in range(n):
    temp = list(map(int, input().split()))
    shoesize, price = temp[0], temp[1]
    if shoesize in l and l[shoesize]:
        l[shoesize] -= 1
        cost += price

print(cost)


