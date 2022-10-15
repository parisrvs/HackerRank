import numpy

a = list(map(int, input().split()))
b = list(map(int, input().split()))

a = numpy.array(a)
b = numpy.array(b)

print(numpy.inner(a, b))
print(numpy.outer(a, b))


#########
# inner #
#########

# The inner tool returns the inner product of two arrays.

# import numpy

# A = numpy.array([0, 1])
# B = numpy.array([3, 4])

# print numpy.inner(A, B)     #Output : 4

#########
# outer #
#########

# The outer tool returns the outer product of two arrays.

# import numpy

# A = numpy.array([0, 1])
# B = numpy.array([3, 4])

# print numpy.outer(A, B)     #Output : [[0 0]
#                             #          [3 4]]