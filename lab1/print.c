#include "print.h"
#include <string.h>
#include <stdlib.h>


char* print(mpz_t x, int d, FILE* f)
{
	char* numberStr = NULL;
	numberStr = mpz_get_str(numberStr, 10, x);
	int n = strlen(numberStr);

	char* ptr = &(numberStr[n-1]);

	int zerosCount = 0;
	int removeZerosCount = d;


	while ((*ptr == '0') && (ptr != numberStr), removeZerosCount--)
	{
		--ptr;
		++zerosCount;
	}
	++ptr;
	*ptr = 0;


	if ((d == zerosCount) || (*numberStr == '0' && (strlen(numberStr) == 1)))
	{
		printf("%s", numberStr);
	}
	else if (d >= n)
	{
		char* formatStr = (char*)malloc((2+d-n+zerosCount+3+1)*sizeof(char));
		strcpy(formatStr, "0.");
		char* a = NULL;

		memset(formatStr+2, '0', d-n+zerosCount);
		*(formatStr+2+d-n+zerosCount) = 0;
		strcat(formatStr, "%s\n");

		printf(formatStr, numberStr);

	}
	else
	{
		char temp = numberStr[n-d];
		numberStr[n-d] = 0;
		printf("%s.", numberStr);
		numberStr[n-d] = temp;
		printf("%s\n", numberStr+n-d);

	}

	
	return NULL;

}

