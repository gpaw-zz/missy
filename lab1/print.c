#include "print.h"
#include <string.h>
#include <stdlib.h>

char* itoa(int v, char* s);

char* print(mpz_t x, int d, FILE* f)
{
	char* numberStr = NULL;
	numberStr = mpz_get_str(numberStr, 10, x);
	int n = strlen(numberStr);

	char* ptr = &(numberStr[n-1]);

	int zerosCount = 0;

	while ((*ptr == '0') && (ptr != numberStr))
	{
		--ptr;
		++zerosCount;
	}
	++ptr;
	*ptr = 0;

	if (d == zerosCount)
	{
		printf("%s", numberStr);
	}
	else if (d >= n)
	{
		char formatStr[66000];
		strcpy(formatStr, "0.%.");
		char* a = NULL;
		a = itoa(d, a);

		strcat(formatStr, a);
		strcat(formatStr, "s\n");

		printf(formatStr, numberStr);

	}
	else
	{
		char temp = numberStr[n-d];
		numberStr[n-d] = 0;
		printf("%s.", numberStr);
		numberStr[n-d] = temp;
		printf("%s\n", numberStr+d+1);

	}

	
	return NULL;

}


char* itoa(int v, char* s)
{
	s = (char*)malloc(66000*sizeof(char));

	int i = 0;

	do
	{
		s[i++] = (v % 10) + '0';
		v /= 10; 
	}
	while (v != 0);

	return s;
}
