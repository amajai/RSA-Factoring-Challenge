#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "main.h"

int main(int ac, char **av) {
    char buffer[2048];
    FILE *fd;
    mpz_t n, B;
    mpz_inits(n, B, NULL);
    mpz_t factors[2];
    mpz_t *primes;
    size_t num_primes = 0;

    if (ac != 2)
        return (1);

    fd = fopen(av[1], "r");
    if (fd == NULL)
        return (1);
    for (int i = 0; i < 2; ++i)
        mpz_init(factors[i]);
    while (fgets(buffer, sizeof(buffer), fd) != NULL)
    {
        mpz_set_ui(factors[0], 0);
        mpz_set_ui(factors[1], 0);
        mpz_set_str(n, buffer, 10);

        trial_division_wheel(n, factors, 100);
        if (mpz_cmp_ui(factors[1], 0) == 0)
        {
            pollard_p1(n, factors, 100);
        }
        gmp_printf("%Zd=%Zd*%Zd\n", n, factors[0], factors[1]);
    }
    for (int i = 0; i < 2; ++i)
        mpz_clear(factors[i]);
    mpz_clears(n, B, NULL);
    fclose(fd);
    return (0);
}
