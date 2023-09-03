#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>
#include "main.h"

/**
 * sieve_of_eratosthenes -  a classical and efficient algorithm used to
 * find all prime numbers up to a specified limit.
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * 
 * @limit: Range of prime numbers upto the limit value.
 * @primes: array to store the prime numbers
 * @num_primes: number of primes count
 * Result: Nothing
*/
void sieve_of_eratosthenes(mpz_t limit, mpz_t **primes, size_t *num_primes)
{
	mpz_t num_sqrt, num, multiple, next_prime;
	mpz_inits(num_sqrt, num, multiple, next_prime, NULL);
	mpz_sqrt(num_sqrt, limit);
	bool *is_prime;
	size_t prime_idx;

	is_prime = malloc((mpz_get_ui(limit) + 1) * sizeof(bool));
	for (unsigned long long i = 0; i <= mpz_get_ui(limit); ++i) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	mpz_init(next_prime);
	mpz_set_ui(next_prime, 2);

	while (mpz_cmp(next_prime, num_sqrt) <= 0) {
		if (is_prime[mpz_get_ui(next_prime)]) {
			mpz_set_ui(num, mpz_get_ui(next_prime));
			mpz_mul(multiple, num, num);
			
			while (mpz_cmp(multiple, limit) <= 0) {
				is_prime[mpz_get_ui(multiple)] = false;
				mpz_add(multiple, multiple, num);
			}
		}
		mpz_add_ui(next_prime, next_prime, 1);
	}

	*num_primes = 0;
	for (unsigned long long i = 2; i <= mpz_get_ui(limit); ++i) {
		if (is_prime[i]) {
			(*num_primes)++;
		}
	}

	*primes = malloc((*num_primes) * sizeof(mpz_t));
	prime_idx = 0;
	for (unsigned long long i = 2; i <= mpz_get_ui(limit); ++i) {
		if (is_prime[i]) {
			mpz_init_set_ui((*primes)[prime_idx], i);
			prime_idx++;
		}
	}

	mpz_clears(num_sqrt, num, multiple, next_prime, NULL);
	free(is_prime);
}

