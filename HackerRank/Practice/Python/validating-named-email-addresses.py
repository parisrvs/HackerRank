import re
count = int(input())
for _ in range(count):
    name, email = input().split(' ')
    r = re.match(r'<[A-Za-z](\w|-|\.|_)+@[A-Za-z]+\.[A-Za-z]{1,3}>', email)
    if r:
        print(name, email)