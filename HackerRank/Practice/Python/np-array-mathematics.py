import numpy

n, m = map(int, input().split())
a, b = [], []
for _ in range(n):
    a.append(
        list(map(int, input().split()))
    )
for _ in range(n):
    b.append(
        list(map(int, input().split()))
    )

a = numpy.array(a, int)
b = numpy.array(b, int)

print(a+b)
print(a-b)
print(a*b)
print(a//b)
print(a%b)
print(a**b)


# Basic mathematical functions operate element-wise on arrays.
# They are available both as operator overloads and as functions in the NumPy module.

# import numpy

# a = numpy.array([1,2,3,4], float)
# b = numpy.array([5,6,7,8], float)

# print a + b                     #[  6.   8.  10.  12.]
# print numpy.add(a, b)           #[  6.   8.  10.  12.]

# print a - b                     #[-4. -4. -4. -4.]
# print numpy.subtract(a, b)      #[-4. -4. -4. -4.]

# print a * b                     #[  5.  12.  21.  32.]
# print numpy.multiply(a, b)      #[  5.  12.  21.  32.]

# print a / b                     #[ 0.2         0.33333333  0.42857143  0.5       ]
# print numpy.divide(a, b)        #[ 0.2         0.33333333  0.42857143  0.5       ]

# print a % b                     #[ 1.  2.  3.  4.]
# print numpy.mod(a, b)           #[ 1.  2.  3.  4.]

# print a**b                      #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]
# print numpy.power(a, b)         #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]