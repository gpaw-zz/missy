#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

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
	mpz_ui_pow_ui(temp, 10, d);
	precision = mpz_class(temp);


	while ((cin >> xi))
	{
		avg += xi;
		var += xi*xi;
		periodPattern.push_back(xi);
		++n;
	}
	

	avg /= n;
	cout << avg << endl;


	return 0;
}
