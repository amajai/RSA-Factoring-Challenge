#ifndef MAIN_H
#define MAIN_H
void trial_division(mpz_t n, mpz_t *primes, size_t size, mpz_t *factors);
int is_quad_residue(mpz_t n, mpz_t p);
void b_smooth(mpz_t result, mpz_t N);
void sieve_of_eratosthenes(mpz_t limit, mpz_t **primes, size_t *num_primes);
void fermat_factorization(mpz_t n, mpz_t *factors);
void mpz_sqrt_ceil(mpz_t result, mpz_t x);
#endif