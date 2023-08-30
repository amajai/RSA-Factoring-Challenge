#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>
#include <mpfr.h>

void mpz_sqrt_ceil(mpz_t result, mpz_t x) {
    mpfr_t sqrt_temp;
    
    mpfr_init2(sqrt_temp, 64);
    mpfr_set_z(sqrt_temp, x, MPFR_RNDU); // Round up
    mpfr_sqrt(sqrt_temp, sqrt_temp, MPFR_RNDU);
    mpfr_get_z(result, sqrt_temp, MPFR_RNDU);
    mpfr_clear(sqrt_temp);
}

void fermat_factorization(mpz_t n, mpz_t *factors)
{
    mpz_t limit, a, a2, b, b1, c, b2;
    mpz_inits(limit, a, a2, b, b1, c, b2, NULL);
    mpz_set_ui(limit, 1000);

    if (mpz_cmp_ui(n, 0) <= 0) {
        mpz_init_set(factors[0], n);
        return;
    }
    if (mpz_even_p(n) && mpz_divisible_ui_p(n, 2)) {
        mpz_div_ui(factors[0], n, 2);
        mpz_set_ui(factors[1], 2);
        return;
    }

    mpz_sqrt_ceil(a, n);

    mpz_mul(a2, a, a);
    if(mpz_cmp(a2, n) == 0)
    {
        mpz_set(factors[0], a);
        mpz_set(factors[1], a);
        return;
    }

    mpz_set_ui(c, 0);
    while (mpz_cmp(c, limit) != 0) {
        mpz_sub(b1, a2, n);
        mpz_sqrt(b, b1);
        mpz_mul(b2, b, b);

        if (mpz_cmp(b2, b1) == 0) {
            break;
        } else {
            mpz_add_ui(a, a, 1);
            mpz_add_ui(c, c, 1);
        }
    }

    if (mpz_cmp(c, limit) == 0) {
        // Return NULL or indicate no factors found
        mpz_set_ui(factors[0], 0);
        mpz_set_ui(factors[1], 0);
    } else {
        mpz_add(factors[0], a, b);
        mpz_sub(factors[1], a, b);
    }
    mpz_clears(limit, a, a2, b, b1, c, b2, NULL);
}

