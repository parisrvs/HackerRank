if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    arr = list(arr)
    m = max(arr)

    while max(arr) == m:
        arr.remove(max(arr))
    
    print(max(arr))