def isprime(n):
    isprime = True
    if n > 1:
        for i in range(2, (n//2)+1):
            if n % i == 0:
                isprime = False
                break
        return isprime
    else:
        return False