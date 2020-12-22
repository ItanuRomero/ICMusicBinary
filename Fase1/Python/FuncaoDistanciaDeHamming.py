import numpy as np
from sys import getsizeof


def hamming_distance(a, b):
    r = (1 << np.arange(8))[:, None]
    return np.count_nonzero((a & r) != (b & r))


# iterar acima desta:
def xor(a, b):
    print(getsizeof(a))
    c = (a ^ b)
    count_zero = 0
    print(bin(c))
    if c == 0:
        print(getsizeof(c))
    while c != 0:
        if c % 2 == 0:
            count_zero += 1
        c = c >> 1
    print(count_zero)
    print(bin(c))


xor(5, 5)

"""
Link de onde foi retirado:
https://living-sun.com/pt/python/702165-fastest-way-to-get-hamming-distance-for-integer-array-python-numpy-binary-xor-hamming-distance.html
ainda precisamos testar.
https://wiki.python.org.br/BitwiseOperators
"""
