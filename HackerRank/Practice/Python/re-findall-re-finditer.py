import re

s = input()
consonants = '[qwrtypsdfghjklzxcvbnm]'
a = re.findall('(?<=' + consonants +')([aeiou]{2,})' + consonants, s, re.I)
if a:
    print('\n'.join(a))
else:
    print(-1)