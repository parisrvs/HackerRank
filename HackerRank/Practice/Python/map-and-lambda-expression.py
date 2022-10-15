cube = lambda x: x**3

def fibonacci(n):
    if n == 1:
        return [0,]
    elif n == 0:
        return []
    else:
        l = [0, 1]
        for c in range(2, n):
            l.append(l[c-1]+l[c-2])
        return l
    

if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))