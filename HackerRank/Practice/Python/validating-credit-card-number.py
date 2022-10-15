import re

pattern = re.compile(
    r"^"
    r"(?!.*(\d)(-?\1){3})"
    r"[456]"
    r"\d{3}"
    r"(?:-?\d{4}){3}"
    r"$"
)


n = int(input())
for _ in range(n):
    s = input()
    if pattern.search(s):
        print("Valid")
    else:
        print("Invalid")