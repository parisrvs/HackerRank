n, nl, b, bl = int(input()), set(map(int, input().split())), int(input()), set(map(int, input().split()))
print(len(nl.intersection(bl)))

"""
The .intersection() operator returns the intersection of a set and the set of elements in an iterable.
Sometimes, the & operator is used in place of the .intersection() operator,
but it only operates on the set of elements in set.
The set is immutable to the .intersection() operation (or & operation).

>> s = set("Hacker")
>> print s.intersection("Rank")
set(['a', 'k'])

>> print s.intersection(set(['R', 'a', 'n', 'k']))
set(['a', 'k'])

>> print s.intersection(['R', 'a', 'n', 'k'])
set(['a', 'k'])

>> print s.intersection(enumerate(['R', 'a', 'n', 'k']))
set([])

>> print s.intersection({"Rank":1})
set([])

>> s & set("Rank")
set(['a', 'k'])
"""