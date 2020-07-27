import numpy as np

def hamming_distance(a, b):
r = (1 << np.arange(8))[:,None]
return np.count_nonzero( (a & r) != (b & r) )


"""
Link de onde foi retirado:
https://living-sun.com/pt/python/702165-fastest-way-to-get-hamming-distance-for-integer-array-python-numpy-binary-xor-hamming-distance.html
ainda precisamos testar.
"""