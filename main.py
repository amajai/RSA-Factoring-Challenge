import sys
from prime import isprime
from func import *

def main():
    n = len(sys.argv)
    if n == 2:
        file = open(sys.argv[1], 'r')
        lines = file.readlines()
        for line in lines:
            N = int(line.strip())
            B = b_smooth(N)
            base_factors = sieve_of_eratosthenes(B + 1)
            r_base_factors =  list(filter(lambda x: is_quadratic_residue(N, x), base_factors))
            factors = trial_division(N, r_base_factors)
            if not factors:
                factors = fermat_factorization(N)
            p, q = factors
            print(f"{N}={p}*{q}")
    else:
        print("Usage: factors <file>")