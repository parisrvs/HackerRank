import re
S = input()
k = input()
re_k = re.compile(k)
count = re_k.search(S)
if not count:
    print("(-1, -1)")
else:
    while count:
        print(f"({count.start()}, {count.end() - 1})")
        count = re_k.search(S, count.start() + 1)