from func import *

n = 1718944270642558716715
c = list(filter(lambda x: is_quadratic_residue(n, x), sieve_of_eratosthenes(b_smooth(n)+1)))
print(c)