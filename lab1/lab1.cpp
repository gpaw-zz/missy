#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

char separator = ',';

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

int main()
{
	mpz_class xi;
	mpz_class avg;
	mpz_class var;
	mpz_class period;
	mpz_class precision;

	vector<mpz_class> periodPattern;

	//dokładność
	int d;	

	//liczba elementów na wejściu
	int n = 0;

	scanf("%d", &d);
	mpz_t temp;
	mpz_init(temp);
	mpz_ui_pow_ui(temp, 10, d);
	precision = mpz_class(temp);

	while ((cin >> xi))
	{
		avg += xi;
		var += xi*xi;
		//periodPattern.push_back(xi);
		++n;
	}
	
	var *= n;
	var -= avg*avg;
	var *= precision;
	var /= n*n;

	avg *= precision;
	avg /= n;

//	print(avg, d);

	return 0;
}
