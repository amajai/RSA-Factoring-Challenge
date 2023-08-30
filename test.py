from func import *

n = 4
c = list(filter(lambda x: is_quad_residue(n, x), sieve_of_eratosthenes(b_smooth(n)+1)))

# print(sieve_of_eratosthenes(3))
print(len(list(filter(lambda x: is_quad_residue(n, x), sieve_of_eratosthenes(b_smooth(n)+1)))))
print(sieve_of_eratosthenes(b_smooth(49)+1))