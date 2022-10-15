t = int(input())
for _ in range(t):
    count_a = int(input())
    a = set(map(int, input().split()))
    count_b = int(input())
    b = set(map(int, input().split()))
    if a.difference(b):
        print(False)
    else:
        print(True)

