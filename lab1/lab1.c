#include <stdio.h>
#include <gmp.h>


/*using namespace std;

char separator = '.';

void print(mpz_class x, int d)
{
	string number = x.get_str();
	int length = number.length();


	//jeśli precyzja jest większa lub równa długości liczby to trzeba dodać brakujące liczby z przodu
	if (d >= length)
		number.insert(0, d - length + 1, '0');

	//dodanie przecinka
	if (d != 0)
		number.insert(number.length() - d, 1, separator);

	string::iterator endOfString = number.end();
	string::iterator it = endOfString;

	//usuwamy niepotrzebne zera z tyłu i przecinki
	//zawsze zostawiamy pierwszą liczbę
	while (--it, ((*it == '0' || *it == separator ) && it != number.begin()));
	
	++it;
	if (it != endOfString)
	{
		number.erase(it, endOfString);
	}
	cout << number << endl;

}
*/

int main()
{
	mpz_t x;
	mpz_init(x);
	mpz_t avg;
	mpz_init(avg);
	mpz_t var;
	mpz_init(var);
	mpz_t precision;
	mpz_init(precision);

	//dokładność
	int d;	

	//liczba elementów na wejściu
	int n = 0;

	scanf("%d", &d);
	mpz_ui_pow_ui(precision, 10, d);

	while ((mpz_inp_str(x, stdin, 10)) != 0)
	{
		mpz_add(avg, x, avg);
		mpz_addmul(var, x, x);
//		periodPattern.push_back(xi);
		++n;
	}
	
	mpz_mul_ui(var, var, n);
	mpz_t temp;
	mpz_init(temp);
	mpz_mul(temp, avg, avg);
	mpz_sub(var, var, temp);
	mpz_mul(var, var, precision);
	mpz_set_ui(temp, 1);
	mpz_mul_ui(temp, temp, n*n);
	mpz_div(var, var, temp);

	mpz_mul(avg, avg, precision);
	mpz_div_ui(avg, avg, n);

	//print(avg, d);
	
	//print(var, d);


	return 0;
}
