from itertools import combinations_with_replacement

sk = input().split()
S, k = ''.join(sorted(sk[0])), int (sk[1])

l = list(combinations_with_replacement(S, k))
for x in l:
    for y in range(len(x)):
        print(x[y], end='')
    print()