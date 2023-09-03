#ifndef MAIN_H
#define MAIN_H
void trial_division(mpz_t n, mpz_t *primes, size_t size, mpz_t *factors);
int is_quad_residue(mpz_t n, mpz_t p);
void b_smooth(mpz_t result, mpz_t N);
void sieve_of_eratosthenes(mpz_t limit, mpz_t **primes, size_t *num_primes);
void fermat_factorization(mpz_t n, mpz_t *factors);
void mpz_sqrt_ceil(mpz_t result, mpz_t x);
void pollards_rho(const mpz_t n, mpz_t *factors, unsigned long max_iter);
int trial_division_wheel(const mpz_t n, mpz_t *factors, long trial_limit);
void pollard_p1(const mpz_t n, mpz_t *factors, long max_iter);
#endif