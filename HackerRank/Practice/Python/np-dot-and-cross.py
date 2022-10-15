import numpy

n = int(input())
a, b = [], []
for _ in range(n):
    a.append(
        list(map(int, input().split()))
    )
for _ in range(n):
    b.append(
        list(map(int, input().split()))
    )

a = numpy.array(a)
b = numpy.array(b)
print(numpy.dot(a, b))


#######
# dot #
#######

# The dot tool returns the dot product of two arrays.

# import numpy

# A = numpy.array([ 1, 2 ])
# B = numpy.array([ 3, 4 ])

# print numpy.dot(A, B)       #Output : 11

#########
# cross #
#########

# The cross tool returns the cross product of two arrays.

# import numpy

# A = numpy.array([ 1, 2 ])
# B = numpy.array([ 3, 4 ])

# print numpy.cross(A, B)     #Output : -2