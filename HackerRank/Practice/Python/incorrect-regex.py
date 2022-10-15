import re
t = int (input())
for _ in range(t):
    s = input()
    try:
        r = re.compile(s)
    except re.error:
        print(False)
    else:
        print(True)