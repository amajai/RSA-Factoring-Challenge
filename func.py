import math


def trial_division(n, lst=[]):
    c = 0
    if n > 1:
        if lst:
            for q in lst:
                if n % q == 0:
                    p = n // q
                    break
                c += 1
            if c == len(lst):
                return None
            return p, q
        else:
            for q in range(2, (n//2)+1):
                if n % q == 0:
                    p = n // q
                    break
            return p, q


def b_smooth(N):
    """Smoothness bound formula"""

    L = math.exp(math.sqrt(math.log(N+1) * math.log(math.log(N+1))))
    b_smooth = L ** (1 / math.sqrt(2))
    return math.ceil(b_smooth)


def sieve_of_eratosthenes(limit):
    """Sieve of Eratosthenes"""
    primes = []
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False

    for num in range(2, int(limit**0.5) + 1):
        if is_prime[num]:
            primes.append(num)
            length = len(range(num*num, limit+1, num))
            is_prime[num*num: limit+1: num] = [False] * length

    for num in range(int(limit**0.5) + 1, limit + 1):
        if is_prime[num]:
            primes.append(num)
    return primes


def is_quad_residue(n, p):
    """Euler's Criteria for Quadratic Residues"""
    if n % p == 0:
        return True  # 0 is a quadratic residue modulo any prime
    return pow(n, (p - 1) // 2, p) == 1


def fermat_factorization(n):
    """Fermat's factorization method"""
    limit = 1000
    c = 0

    if n <= 0:
        return [n]

    if n and 1 == 0:
        return [n / 2, 2]

    a = math.ceil(math.sqrt(n))

    if a * a == n:
        return [a, a]

    while c != limit:
        b1 = a * a - n
        b = int(math.sqrt(b1))
        if (b * b == b1):
            break
        else:
            a += 1
            c += 1

    if c == limit:
        return None

    return a-b, a + b
