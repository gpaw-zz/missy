#include "print.h"
#include <gtest/gtest.h>

class PrintTests : public testing::Test
{

};

void assertPrintEQ(int p, int q, int d, const char* expected)
{
	mpz_t prec;
	mpz_init(prec);

	mpz_ui_pow_ui(prec, 10, d);

	mpz_t x;
	mpz_init(x);
	mpz_set_ui(x, p);
	mpz_div_ui(x, x, q);
	mpz_mul(x, x, prec);

	char* s = NULL;

	print(x, d, s);

	ASSERT_EQ(expected, s);
}

TEST(PrintTests, 23_przez_1_precyzja_0)
{
	assertPrintEQ(23, 1, 0, "23");
}
