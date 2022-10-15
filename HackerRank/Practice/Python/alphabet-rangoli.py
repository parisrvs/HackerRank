def print_rangoli(size):
    alphabets = "abcdefghijklmnopqrstuvwxyz"
    count = [alphabets[c] for c in range(size)]
    n = list(range(size))
    n = n[:-1]+n[::-1]
    for c in n:
        counter = count[-(c + 1):]
        r = counter[::-1]+counter[1:]
        print("-".join(r).center(size*4-3, "-"))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)