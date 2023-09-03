import sys
from helper_func import *


def main():
    n = len(sys.argv)
    if n == 2:
        file = open(sys.argv[1], 'r')
        lines = file.readlines()
        for line in lines:
            N = int(line.strip())
            B = b_smooth(N)
            base_factors = sieve_of_eratosthenes(B+1)
            rbf = list(filter(lambda x: is_quad_residue(N, x), base_factors))
            factors = trial_division(N, rbf)
            if not factors:
                factors = fermat_factorization(N)
            p, q = factors
            print(f"{N}={p}*{q}")
    else:
        print("Usage: factors <file>")
