def reverse (n):
    rev = 0
    while(n > 0):
        a = n % 10
        rev = rev * 10 + a
        n = n // 10
    return (rev)


if __name__ == '__main__':
    N = int (input())
    l = list (map(int,input().split()))
    m = []
    n = []
    for i in l:
        c = True if i > 0 else False
        d = True if i == reverse(i) else False
        m.append(c)
        n.append(d)
    x = True if any(n) and all(m) else False
    print(x)