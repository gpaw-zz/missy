#include "print.h"
#include <gtest/gtest.h>

class PrintTests : public testing::Test
{

};

void assertPrintEQ(int d, int p, int q, const char* expected)
{
	mpz_t prec;
	mpz_init(prec);

	mpz_ui_pow_ui(prec, 10, d);

	mpz_t x;
	mpz_init(x);
	mpz_set_ui(x, p);
	mpz_mul(x, x, prec);
	mpz_div_ui(x, x, q);

	char* s = NULL;
	FILE* f = NULL;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Expected: " << expected << "; Actual: ";
	print(x, d, f);
	std::cout << std::endl;
	std::cout << std::endl;


	ASSERT_FALSE(true);
}

TEST(PrintTests, 23_przez_1_precyzja_0)
{
	assertPrintEQ(0, 23, 1, "23");
}

TEST(PrintTests, 23_przez_2_precyzja_1)
{
	assertPrintEQ(1, 23, 2, "11.5");
}

TEST(PrintTests, 2_przez_3_precyzja_4)
{
	assertPrintEQ(4, 2, 3, "0.6666");
}

