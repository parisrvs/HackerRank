k, rooms = int(input()), list(map(int, input().split()))
s = set(rooms)
c = ((k*(sum(s))) - sum(rooms))//(k-1)
print(c)