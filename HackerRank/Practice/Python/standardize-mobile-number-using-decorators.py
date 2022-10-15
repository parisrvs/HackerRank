def wrapper(f):
    def fun(l):
        a = []
        for i in l:
            if len(i) == 10:
                x = f"+91 {i[:5]} {i[5:]}"
                a.append(x)
            elif len(i) == 11:
                x = f"+91 {i[1:6]} {i[6:]}"
                a.append(x)
            elif len(i) == 12:
                x = f"+91 {i[2:7]} {i[7:]}"
                a.append(x)
            else:
                x = f"+91 {i[3:8]} {i[8:]}"
                a.append(x)
        f(a)
    return fun

@wrapper
def sort_phone(l):
    print(*sorted(l), sep='\n')

if __name__ == '__main__':
    l = [input() for _ in range(int(input()))]
    sort_phone(l) 


