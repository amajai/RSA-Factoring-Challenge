from helper_func import *

n = 239809320265259
c = list(filter(lambda x: is_quad_residue(n, x), sieve_of_eratosthenes(b_smooth(n)+1)))

# print(sieve_of_eratosthenes(3))
print(b_smooth(239809320265259)//2)
print(sieve_of_eratosthenes(b_smooth(239809320265259)+1))