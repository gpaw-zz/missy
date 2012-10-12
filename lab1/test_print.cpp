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
	assertPrintEQ(1, 23, 2, "11,5");
}

TEST(PrintTests, 23_przez_2_precyzja_0)
{
	assertPrintEQ(0, 23, 2, "11");
}

TEST(PrintTests, 2_przez_3_precyzja_2)
{
	assertPrintEQ(2, 2, 3, "0,66");
}

TEST(PrintTests, 23_przez_2_precyzja_4)
{
	assertPrintEQ(4, 23, 2, "11,5");
}

TEST(PrintTests, 22_przez_2_precyzja_4)
{
	assertPrintEQ(4, 22, 2, "11");
}

TEST(PrintTests, 0_przez_2_precyzja_4)
{
	assertPrintEQ(4, 0, 2, "0");
}

TEST(PrintTests, 1_przez_200_precyzja_3)
{
	assertPrintEQ(3, 1, 200, "0,005");
}

TEST(PrintTests, 1_przez_2000_precyzja_3)
{
	assertPrintEQ(3, 1, 2000, "0");
}

TEST(PrintTests, 8_przez_3_precyzja_3)
{
	assertPrintEQ(3, 8, 3, "2,666");
}

TEST(PrintTests, 20_przez_7_precyzja_5)
{
	assertPrintEQ(5, 20, 7, "2,85714");
}

TEST(PrintTests, 2_przez_300_precyzja_5)
{
	assertPrintEQ(5, 2, 300, "0,00666");
}

TEST(PrintTests, 2_przez_300_precyzja_2)
{
	assertPrintEQ(2, 2, 300, "0");
}

TEST(PrintTests, 2000_przez_300_precyzja_0)
{
	assertPrintEQ(0, 2000, 300, "6");
}

TEST(PrintTests, 2000_przez_300_precyzja_1)
{
	assertPrintEQ(1, 2000, 300, "6.6");
}

TEST(PrintTests, 2000_przez_2_precyzja_1)
{
	assertPrintEQ(1, 2000, 2, "1000");
}

TEST(PrintTests, 5000_przez_4_precyzja_100)
{
	assertPrintEQ(100, 5000, 4, "1250");
}

