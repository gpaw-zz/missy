#include <gtest/gtest.h>
#include "print_results.h"

class PrintTests : public testing::Test
{};

mpz_class& getNum(mpz_class& p, const mpz_class& q, int d)
{
	mpz_t t;
	mpz_init(t);
	mpz_ui_pow_ui(t, 10, d);
	mpz_class precision(t);

	p *= precision;
	p /= q;
	return p;
}

void assertPrintEQ(int d, int p, int q, const std::string& expected)
{
	mpz_class x(p);
	x = getNum(x, mpz_class(q), d);
	std::string s = print(x, d);
	ASSERT_EQ(expected, s);

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

