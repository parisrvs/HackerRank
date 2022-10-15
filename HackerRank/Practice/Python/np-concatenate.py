import numpy

n, m, p = map(int, input().split())
a, b = [], []
for _ in range(n):
    a.append(
        list(map(int, input().split()))
    )

for _ in range(m):
    b.append(
        list(map(int, input().split()))
    )

array_1 = numpy.array(a)
array_2 = numpy.array(b)

print(numpy.concatenate((array_1, array_2), axis = 0))


###############
# Concatenate #
###############

# Two or more arrays can be concatenated together using the concatenate function with a tuple of the arrays to be joined:

# import numpy

# array_1 = numpy.array([1,2,3])
# array_2 = numpy.array([4,5,6])
# array_3 = numpy.array([7,8,9])

# print numpy.concatenate((array_1, array_2, array_3))    

# #Output
# [1 2 3 4 5 6 7 8 9]
# If an array has more than one dimension, it is possible to specify the axis along which multiple arrays are concatenated. By default, it is along the first dimension.

# import numpy

# array_1 = numpy.array([[1,2,3],[0,0,0]])
# array_2 = numpy.array([[0,0,0],[7,8,9]])

# print numpy.concatenate((array_1, array_2), axis = 1)   

# #Output
# [[1 2 3 0 0 0]
#  [0 0 0 7 8 9]]    