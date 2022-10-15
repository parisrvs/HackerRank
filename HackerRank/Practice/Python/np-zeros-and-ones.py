import numpy

s = tuple(map(int, input().split()))
print(numpy.zeros(s, dtype = int))
print(numpy.ones(s, dtype = int))


#########
# zeros #
#########

# The zeros tool returns a new array with a given shape and type filled with 0's.

# import numpy

# print numpy.zeros((1,2))                    #Default type is float
# #Output : [[ 0.  0.]] 

# print numpy.zeros((1,2), dtype = int) #Type changes to int
# #Output : [[0 0]]

########
# ones #
########

# The ones tool returns a new array with a given shape and type filled with 's.

# import numpy

# print numpy.ones((1,2))                    #Default type is float
# #Output : [[ 1.  1.]] 

# print numpy.ones((1,2), dtype = int) #Type changes to int
# #Output : [[1 1]]   