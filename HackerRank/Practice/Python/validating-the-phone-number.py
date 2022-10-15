import re
count = int(input())
for _ in range(count):
    number = input()
    if re.match(r'[789]\d{9}$', number):
        print('YES')  
    else:  
        print('NO')