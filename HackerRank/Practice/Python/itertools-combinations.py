from itertools import combinations
sk = input().split()
S, k = ''.join(sorted(sk[0])), int (sk[1])

for i in range(1, k+1):
    l = list(combinations(S, i))
    for j in l:
        for m in j:
            print(m, end='')
        print()
