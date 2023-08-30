#include <stdbool.h>
#include <gmp.h>
#include "main.h"

int is_quad_residue(mpz_t n, mpz_t p) 
{
    mpz_t zero, exponent, result;
    mpz_inits(zero, exponent, result, NULL);
    mpz_set_ui(zero, 0);

    if (mpz_cmp(n, zero) == 0) {
        mpz_clears(zero, exponent, result, NULL);
        return 1; // 0 is a quadratic residue modulo any prime
    }

    mpz_sub_ui(exponent, p, 1);
    mpz_fdiv_q_ui(exponent, exponent, 2);

    mpz_powm(result, n, exponent, p);

    int comparison = mpz_cmp_ui(result, 1);

    mpz_clears(zero, exponent, result, NULL);

    return comparison == 0 ? 1 : 0;
}

