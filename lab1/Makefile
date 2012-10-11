ifeq ($(OS),Windows_NT)
	NAME := lab1.exe
else
	NAME := lab1.out
endif

all:
	g++ -lgmpxx -lgmp lab1.cpp -o $(NAME)

simple_test: all
	python test_gen.py simple_test.txt 3 20 15
	./$(NAME) < simple_test.txt > results.txt
	vimdiff results.txt wyniki_simple_test.txt

print_tests:
	g++ -lpthread -lgmpxx -lgmp -lgtest_main -lgtest test_print_results.cpp print_results.cpp print_results.h -o test_print_results.out
	./test_print_results.out
print_tests_debug:
	g++ -g -lpthread -lgmpxx -lgmp -lgtest_main -lgtest test_print_results.cpp print_results.cpp print_results.h -o test_print_results.out

