from collections import OrderedDict

d = OrderedDict()
N = int(input())
for _ in range(N):
    order = input().split()
    name, price = ' '.join(order[:-1]), int(order[-1])
    if name in d:
        d[name] += price
    else:
        d[name] = price

for key, value in d.items():
    print(f"{key} {value}")