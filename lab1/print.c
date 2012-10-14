#include "print.h"
#include <string.h>
#include <stdlib.h>


char* print(mpz_t x, int d, FILE* f)
{
	char* numberStr = NULL;
	numberStr = mpz_get_str(numberStr, 10, x);
	int n = strlen(numberStr);

	char* zerosPtr = &(numberStr[n-1]);

	int zerosCount = 0;
	int maxRemovedZeros = d;


	//usunięcie niepotrzebnych zer z tyłu
	//usuwamy maksymalnie d zer
	//nie usuwamy pierwszej cyfry
	//po tej operacji zostaje n-zerosCount liczb
	while ((*zerosPtr == '0') && (zerosPtr != numberStr) && (zerosCount < d))
	{
		--zerosPtr;
		++zerosCount;
	}
	//w tym miejscu kończymy napis
	*(zerosPtr+1) = 0;


	//jeżeli liczba nie posiada części ułamkowej
	if ((d == zerosCount) || (numberStr[0] == '0' && (strlen(numberStr) == 1)))
	{
		printf("%s", numberStr);
	}
	//jeżeli liczba nie posiada części całkowitej
	else if (d >= n)
	{
		char* formatStr = (char*)malloc((2+d-n+zerosCount+3+1)*sizeof(char));
		strcpy(formatStr, "0.");

		memset(formatStr+2, '0', d-n+zerosCount);
		*(formatStr+2+d-n+zerosCount) = 0;
		strcat(formatStr, "%s\n");

		printf(formatStr, numberStr);
	}
	//jeżeli liczba posiada część całkowitą i ułamkową
	else
	{
		//wydzielenie części całkowitej
		char temp = numberStr[n-d];
		numberStr[n-d] = 0;
		//wypisanie części całkowitej
		printf("%s.", numberStr);

		//wypisanie części ułamkowej
		numberStr[n-d] = temp;
		printf("%s\n", numberStr+n-d);
	}

	
	return NULL;

}

