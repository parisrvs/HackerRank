for _ in range(int(input())):
    a, blocks = int(input()), list(map(int, input().split()))
    index_min = blocks.index(min(blocks))
    l, r = blocks[:index_min], blocks[(index_min + 1):]
    print("Yes") if l == sorted(l, reverse=True) and r == sorted(r) else print("No")