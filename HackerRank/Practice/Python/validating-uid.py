import re


t = int(input())

for _ in range(t):
    s = input()
    s = ''.join(sorted(s))
    
    if (len(s) != 10) :
        print('Invalid')
    elif not re.search(r'[A-Z]{2}', s) or not re.search(r'\d\d\d', s) or re.search(r'[^a-zA-Z0-9]', s) or re.search(r'(.)\1', s):
        print('Invalid')
    elif len(set(s)) != 10:
        print('Invalid')
    else:
        print('Valid')
