n, el, b, fl = int(input()), set(map(int, input().split())), int(input()), set(map(int, input().split()))
print(len(el.difference(fl)))



"""
The tool .difference() returns a set with all the elements from the set that are not in an iterable.
Sometimes the - operator is used in place of the .difference() tool,
but it only operates on the set of elements in set.
Set is immutable to the .difference() operation (or the - operation).

>> s = set("Hacker")
>> print s.difference("Rank")
set(['c', 'r', 'e', 'H'])

>> print s.difference(set(['R', 'a', 'n', 'k']))
set(['c', 'r', 'e', 'H'])

>> print s.difference(['R', 'a', 'n', 'k'])
set(['c', 'r', 'e', 'H'])

>> print s.difference(enumerate(['R', 'a', 'n', 'k']))
set(['a', 'c', 'r', 'e', 'H', 'k'])

>> print s.difference({"Rank":1})
set(['a', 'c', 'e', 'H', 'k', 'r'])

>> s - set("Rank")
set(['H', 'c', 'r', 'e'])
"""