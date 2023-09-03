#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
 * pollard_rho - a probabilistic algorithm used to factorize integers. It
 * is based on the idea of finding non-trivial factors by looking for cycles
 * in a sequence of numbers.
 * https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
 * 
 * @n: Number to factorize
 * @factors: array of size 2 (x,y) to save the factor result in
 * @max_iter: Set a max limit on how long it loops for every number.
 * 
 * Result: Nothing
*/
void pollards_rho(const mpz_t n, mpz_t *factors, unsigned long max_iter)
{
	gmp_randstate_t state;
	gmp_randinit_default(state);
	gmp_randseed_ui(state, time(NULL));
	mpz_t x, y, c, d, nn, abs_diff;
	mpz_inits(x, y, c, d, nn, abs_diff, NULL);
	unsigned long i;

	mpz_urandomm(x, state, n);
	mpz_set(y, x);
	mpz_urandomm(c, state, n);

	for (i = 0; i < max_iter; ++i) {
		mpz_mul(x, x, x);
		mpz_add(x, x, c);
		mpz_mod(x, x, n);

		mpz_mul(y, y, y);
		mpz_add(y, y, c);
		mpz_mod(y, y, n);
		mpz_mul(y, y, y);
		mpz_add(y, y, c);
		mpz_mod(y, y, n);

		mpz_sub(abs_diff, x, y);
		mpz_abs(abs_diff, abs_diff);

		mpz_gcd(d, abs_diff, n);
		if (mpz_cmp_ui(d, 1) > 0) {
			mpz_divexact(nn, n, d);
			if (mpz_cmp(nn, d) > 0)
			{
				mpz_set(factors[0], nn);
				mpz_set(factors[1], d);
			}
			else
			{
				mpz_set(factors[0], d);
				mpz_set(factors[1], nn);
			}
			mpz_clears(x, y, c, d, nn, abs_diff, NULL);
			gmp_randclear(state);
			return;
		}
	}
	if (i >= max_iter)
	{
		mpz_set_ui(factors[0], 0);
		mpz_set_ui(factors[1], 0);     
		mpz_clears(x, y, c, d, nn, abs_diff, NULL);
		gmp_randclear(state);
		return;         
	}
	mpz_set(factors[0], n);
	mpz_set_ui(factors[1], 1);
	mpz_clears(x, y, c, d, nn, abs_diff, NULL);
	gmp_randclear(state);
	return;
}
