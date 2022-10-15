n = int(input())
s = set(map(int, input().split()))
for _ in range(int(input())):
    c = input().split()
    if len(c) == 1:
        try:
            s.pop()
        except KeyError:
            pass
    else:
        c, i = c[0], int(c[1])
        if c == "remove":
            try:
                s.remove(i)
            except KeyError:
                pass
        else:
            s.discard(i)

print(sum(s))



"""
>> s = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
>> s.remove(5)
>> print s
set([1, 2, 3, 4, 6, 7, 8, 9])
>> print s.remove(4)
None
>> print s
set([1, 2, 3, 6, 7, 8, 9])
>> s.remove(0)
KeyError: 0


>> s = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
>> s.discard(5)
>> print s
set([1, 2, 3, 4, 6, 7, 8, 9])
>> print s.discard(4)
None
>> print s
set([1, 2, 3, 6, 7, 8, 9])
>> s.discard(0)
>> print s
set([1, 2, 3, 6, 7, 8, 9])
If an element does not exist, discard does not raise a KeyError.


>> s = set([1])
>> print s.pop()
1
>> print s
set([])
>> print s.pop()
KeyError: pop from an empty set
"""