#include <iostream>
#include <vector>
#include <gmp.h>

using namespace std;

int main()
{
	mpz_t x;
	mpz_init(x);

	mpz_t avg;
	mpz_init(avg);

	mpz_t var;
	mpz_init(var);

	mpz_t period;
	mpz_init(period);

	while(mpz_inp_str(x, stdin, 10) != 0)
	{
		mpz_add(avg, avg, x);
		mpz_addmul(var, x, x);

		mpz_out_str(stdout, 10, x);
	}

	return 0;
}
