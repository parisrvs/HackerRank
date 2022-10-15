import re

N = int(input())

for _ in range(N):
   s = input()
   s = re.sub(r"\ \&\&\ ", " and ", s)
   s = re.sub(r"\ \|\|\ ", " or ", s)
   s = re.sub(r"\ \&\&\ ", " and ", s)
   s = re.sub(r"\ \|\|\ ", " or ", s)
   print(s)