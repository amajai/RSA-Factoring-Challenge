import math

def trial_division_wheel(n):
    """
    trial_division_wheel - Trial division algorithm in combination with
    wheel of factorization to factor a number.
    
    """
    # Handle small prime divisors
    small_primes = [2, 3, 5]
    for divisor in small_primes:
        if n % divisor == 0:
            nn = n // divisor
            print("{}={}*{}".format(n, nn, divisor))
            return

    # Handle larger prime divisors
    limit = math.isqrt(n) + 1
    divisor = 7
    increment = [4, 2, 4, 2, 4, 6, 2, 6]  # Wheel factorization pattern
    index = 0
    while divisor <= limit:
        if n % divisor == 0:
            nn = n // divisor
            print("{}={}*{}".format(n, nn, divisor))
            return
        divisor += increment[index]
        index = (index + 1) % len(increment)

    return None

