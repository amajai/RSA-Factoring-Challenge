#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "main.h"

void trial_division(mpz_t n, mpz_t *primes, size_t size, mpz_t *factors)
{
    mpz_t q, p;
    mpz_inits(q, p, NULL);

    int c = 0;

    if (mpz_cmp_ui(n, 1) > 0) {
        if (*primes) {
            for (int i = 0; i < size; i++) {
                mpz_set(q, *primes + i);
                if (mpz_divisible_p(n, q)) {
                    mpz_fdiv_q(p, n, q);
                    break;
                }
                c++;
            }
            if (c == size) {
                mpz_set_ui(factors[0], 0);
                mpz_set_ui(factors[1], 0);
                mpz_clears(q, p, NULL);
                return;
            }
        } else {
            mpz_set_ui(q, 2);
            while (mpz_cmp(q, n) <= 0) {
                if (mpz_divisible_p(n, q)) {
                    mpz_fdiv_q(p, n, q);
                    break;
                }
                mpz_add_ui(q, q, 1);
            }
        }
        mpz_set(factors[0], p);
        mpz_set(factors[1], q);
    }
    mpz_clears(q, p, NULL);
}

