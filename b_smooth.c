#include <stdio.h>
#include <gmp.h>
#include <math.h>
#include "main.h"

/**
 * b_smooth - refers to the upper limit on the size of
 * prime factors that you are trying to find in order to factorize
 * a given composite number. 
 * https://en.wikipedia.org/wiki/Smooth_number
 * 
 * @result: where the b_smooth result is stored.
 * @N: Number to factor
 * Result: Nothing
*/
void b_smooth(mpz_t result, mpz_t N)
{
	double logN_double = log(mpz_get_d(N) + 1);
	double loglogN_double = log(logN_double);
	
	double L_double = exp(sqrt(logN_double * loglogN_double));
	double b_smooth_double = pow(L_double, 1.0 / sqrt(2.0));

	mpz_set_d(result, ceil(b_smooth_double));
}
