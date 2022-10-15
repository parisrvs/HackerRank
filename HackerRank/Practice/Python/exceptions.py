count = int(input())
for _ in range(count):
    try:
        a, b = map(int, input().split())
    except ValueError as e:
        print("Error Code:", e)
    else:
        try:
            print(a//b)
        except ZeroDivisionError as e:
            print("Error Code:", e)
