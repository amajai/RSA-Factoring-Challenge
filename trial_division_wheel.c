#include <stdio.h>
#include <gmp.h>
#include <math.h>
#include "main.h"

/**
 * trial_division_wheel - Trial division algorithm in combination with
 * wheel of factorization to factor a number.
 * https://en.wikipedia.org/wiki/Wheel_factorization
 * 
 * @n: Number to factor
 * @factors: array of size 2 (x,y) to save the factor result in
 * @trial_limit: Set a max limit on how long it loops for every number.
 * Result: 1, if factors are found.
 * 0, no factors found.
*/
int trial_division_wheel(const mpz_t n, mpz_t *factors, long trial_limit)
{
	mpz_t nn, limit, divisor;
	mpz_inits(nn, limit, divisor, NULL);
	mpz_sqrt(limit, n);
	mpz_add_ui(limit, limit, 1);

	// Handle small prime divisors
	int small_primes[] = {2, 3, 5};
	for (int i = 0; i < sizeof(small_primes) / sizeof(small_primes[0]); ++i) {
		if (mpz_divisible_ui_p(n, small_primes[i])) {
			mpz_divexact_ui(nn, n, small_primes[i]);
			mpz_set(factors[0], nn);
			mpz_set_ui(divisor, small_primes[i]);
			mpz_set(factors[1], divisor);
			mpz_clears(nn, limit, divisor, NULL);
			return (1);
		}
		trial_limit -= 1;
	}

	// Handle larger prime divisors
	mpz_set_ui(divisor, 7);
	int increment[] = {4, 2, 4, 2, 4, 6, 2, 6};  // Wheel factorization pattern
	int index = 0;
	while (mpz_cmp(divisor, limit) <= 0 && trial_limit > 0) {
		if (mpz_divisible_p(n, divisor)) {
			mpz_divexact(nn, n, divisor);
			mpz_set(factors[0], nn);
			mpz_set(factors[1], divisor);
			mpz_clears(nn, limit, divisor, NULL);
			return (1);
		}
		mpz_add_ui(divisor, divisor, increment[index]);
		index = (index + 1) % (sizeof(increment) / sizeof(increment[0]));
		trial_limit--;
	}
	if (trial_limit > 0)
	{
		mpz_set(factors[0], n);
		mpz_set_ui(factors[1], 1);
		mpz_clears(nn, limit, divisor, NULL);
		return (1);
	}
	mpz_set_ui(factors[0], 0);
	mpz_set_ui(factors[1], 0);
	mpz_clears(nn, limit, divisor, NULL);
	return (0);
}
