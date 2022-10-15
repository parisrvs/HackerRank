N, cnames, total = int(input()), list(input().split()), 0
for _ in range(N):
    total += int(list(input().split())[cnames.index("MARKS")])
print ("{0:.2f}".format(total/N))