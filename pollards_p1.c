#include <stdio.h>
#include <gmp.h>
#include "main.h"


/**
 * gcd - Find the greatest common denominator for 2 numbers
 * @result: where the gcd result is stored.
 * @x: first number
 * @y: second number
 * 
 * Result: Nothing
*/
void gcd(mpz_t result, const mpz_t x, const mpz_t y) 
{
	mpz_t a, b, t;
	mpz_inits(a, b, t, NULL);

	mpz_set(a, x);
	mpz_set(b, y);

	while (mpz_cmp_ui(b, 0) != 0) {
		mpz_set(t, b);
		mpz_mod(b, a, b);
		mpz_set(a, t);
	}
	mpz_set(result, a);
	mpz_clears(a, b, t, NULL);
}

/**
 * pollard_p1 - It is a variation of Pollard's Rho algorithm and is
 * designed to find factors of a number N where N-1 has only small
 * prime factors.
 * https://en.wikipedia.org/wiki/Pollard%27s_p_%E2%88%92_1_algorithm
 * 
 * @n: Number to factorize
 * @factors: array of size 2 (x,y) to save the factor result in
 * @max_iter: Set a max limit on how long it loops for every number.
 * 
 * Result: Nothing
*/
void pollard_p1(const mpz_t n, mpz_t *factors, long max_iter)
{
	mpz_t a, p, x, q;
	mpz_inits(a, p, x, q, NULL);
	mpz_set_ui(a, 2);
	unsigned long i;

	i = 2;
	while (i <= max_iter) {
		mpz_powm_ui(a, a, i, n);
		mpz_sub_ui(x, a, 1);
		gcd(p, x, n);

		// Check if factor obtained
		if (mpz_cmp_ui(p, 1) > 0 && mpz_cmp(p, n) < 0) {
			mpz_divexact(q, n, p);
			if (mpz_cmp(p,q) > 0)
			{
				mpz_set(factors[0], p);
				mpz_set(factors[1], q);
			}
			else
			{
				mpz_set(factors[0], q);
				mpz_set(factors[1], p);
			}
			mpz_clears(a, p, x, q, NULL);
			return;
		}
		i++;
	}
	mpz_set(factors[0], n);
	mpz_set_ui(factors[1], 1);
	mpz_clears(a, p, x, q, NULL);
	return;
}
