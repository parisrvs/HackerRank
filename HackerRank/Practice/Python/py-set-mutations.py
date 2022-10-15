n, a, count = int(input()), set(map(int, input().split())), int(input())

for _ in range(count):
    x = input().split()
    x, y = x[0], int(x[1])
    z = set(map(int, input().split()))
    if x == "update":
        a.update(z)
    elif x == "intersection_update":
        a.intersection_update(z)
    elif x == "difference_update":
        a.difference_update(z)
    elif x == "symmetric_difference_update":
        a.symmetric_difference_update(z)
print(sum(a))


"""
Update the set by adding elements from an iterable/another set.
>> H = set("Hacker")
>> R = set("Rank")
>> H.update(R)
>> print H
set(['a', 'c', 'e', 'H', 'k', 'n', 'r', 'R'])


Update the set by keeping only the elements found in it and an iterable/another set.
>> H = set("Hacker")
>> R = set("Rank")
>> H.intersection_update(R)
>> print H
set(['a', 'k'])


Update the set by removing elements found in an iterable/another set.
>> H = set("Hacker")
>> R = set("Rank")
>> H.difference_update(R)
>> print H
set(['c', 'e', 'H', 'r'])


Update the set by only keeping the elements found in either set, but not in both.
>> H = set("Hacker")
>> R = set("Rank")
>> H.symmetric_difference_update(R)
>> print H
set(['c', 'e', 'H', 'n', 'r', 'R'])
"""