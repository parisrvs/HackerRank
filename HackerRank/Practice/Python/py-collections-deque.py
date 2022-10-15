from collections import deque

d = deque()
for _ in range(int(input())):
    s = input().split()
    if len(s) == 1:
        if s[0] == 'pop':
            d.pop()
        elif s[0] == 'popleft':
            d.popleft()
    else:
        s, i = s[0], s[1]
        if s == "append":
            d.append(i)
        elif s == "appendleft":
            d.appendleft(i)

for item in d:
    print(item, end=' ')
print()