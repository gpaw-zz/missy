# -*- coding: utf-8 -*-

import math
import random
import sys
import string

def print_usage():
	print "Użycie:"
	print "python test_gen.py [nazwa_testu] [d] [n] [r] [szablon_okresu]"
	print "Liczby będą mniejsze niż 2^r"
	print "[szablon_okresu] to wzorzec w postaci np. 12,11,45,12,11,56 "
	print "Nie oznacza to, że wzorzec będzie dokładnie taki, "
	print "ale że na pozycjach (w tym przypadku)np. 1 i 4 będzie ta sama liczba, "
	print "oraz na pozycjach 2 i 5 będzie ta sama liczba"
	print ""
	print "Jeżeli szablon_okresu jest pusty to okresem jest n"
	print ""
	print "Wyniki będą w pliku wyniki_[nazwa_testu]"


def get_numbers_with_period(n, r, period):
	exp = int(random.random()*r)
	number = int(random.random()*(2 ** (exp)))

	#przemnożenie okresu przez liczbę
	period = [(int(x)+1)*number for x in period]
	period_length = len(period)

	#wyrównanie jeżeli period_length nie jest wielokrotnością długości okresu
	if n % period_length != 0:
		n = (n/period_length)*period_length
		print "Nowy n %s (podany nie był wielokrotnością okresu)" %(n)

	for i in range(0, n/period_length):
		numbers.extend(period)
	
	return numbers, n, period_length

def get_numbers(n, r):
	
	numbers = []
	for i in range(0,n):
		exp = int(random.random()*r)
		number = int(random.random()*(2 ** (exp)))
		numbers.append(number)
	return numbers



if __name__ == "__main__":
	if len(sys.argv) < 5:
		print_usage()
		exit()

	testname = sys.argv[1]
	d = sys.argv[2]
	n = int(sys.argv[3])
	r = int(sys.argv[4])

	numbers = []
	period_length = n
	if len(sys.argv) == 6:
		period = sys.argv[5].split(',')
		numbers, n, period_length = get_numbers_with_period(n, r, period)
	else:
		numbers = get_numbers(n, r)	


	file = open(testname, 'w')
	results = open('wyniki_' + testname, 'w')



	for number in numbers:
		file.write("%s\n" % (number))
	file.close()

	#zapisywanie wyników
	avg = float(sum(numbers)) / len(numbers)
	var = float(sum([x*x for x in numbers]))/len(numbers) - avg**2

	results.write("%s\n%s\n%s\n" % (avg, var, period_length))
	results.close()
