if __name__ == '__main__':
    l = []
    u = []
    d_even = []
    d_odd = []
    s = input()
    for c in s:
        if c.islower():
            l.append(c)
        elif c.isupper():
            u.append(c)
        elif c.isdigit():
            if (int (c)) % 2 == 0:
                d_even.append(c)
            else:
                d_odd.append(c)
    
    l.sort()
    u.sort()
    d_even.sort()
    d_odd.sort()
    
    l.extend(u)
    l.extend(d_odd)
    l.extend(d_even)

    print(''.join(l))
