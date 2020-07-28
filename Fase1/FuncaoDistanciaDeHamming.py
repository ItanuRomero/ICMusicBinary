import numpy as np

def hamming_distance(a, b):
r = (1 << np.arange(8))[:,None]
return np.count_nonzero( (a & r) != (b & r) )

def xor(a, b):
    c = (a ^ b)
    count_zero = 0
    print(bin(c))
    while c != 0:
        if c % 2 == 0:
            count_zero += 1
        c = c >> 1
    print(count_zero)
    print(bin(c))


xor(13, 1)


"""
Link de onde foi retirado:
https://living-sun.com/pt/python/702165-fastest-way-to-get-hamming-distance-for-integer-array-python-numpy-binary-xor-hamming-distance.html
ainda precisamos testar.
https://wiki.python.org.br/BitwiseOperators
"""