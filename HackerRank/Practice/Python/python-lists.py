if __name__ == '__main__':
    N = int(input())
    l = []
    for c in range(N):
        s = input()
        s = s.split()
        if len(s) == 1:
            if s[0] == "print":
                print(l)
            elif s[0] == "sort":
                l.sort()
            elif s[0] == "pop":
                l.pop()
            elif s[0] == "reverse":
                l.reverse()
        elif len(s) == 3:
            i = int (s[1])
            e = int (s[2])
            l.insert(i, e)
        elif len(s) == 2:
            e = int (s[1])
            t = s[0]
            if t == "remove":
                try:
                    l.remove(e)
                except:
                    pass
            elif t == "append":
                l.append(e)