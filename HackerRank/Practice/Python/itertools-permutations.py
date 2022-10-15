from itertools import permutations

sk = input().split()
S, k = ''.join(sorted(sk[0])), int (sk[1])
l = list(permutations(S, k))
for i in l:
    for j in range(k):
        print(i[j], end='')
    print()