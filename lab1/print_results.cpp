#include "print_results.h"

using namespace std;

char separator = ',';

string print(mpz_class x, int d)
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

	return number;
}
