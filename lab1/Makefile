ifeq ($(OS),Windows_NT)
	NAME := lab1.exe
else
	NAME := lab1.out
endif

CC := gcc
LIBS := -lgmp
SOURCE := lab1.c
PRINT_TESTS := test_print.cpp print.c print.h
TEST_OUT := test_print.out

all:
	$(CC) $(LIBS) $(SOURCE) -o $(NAME)

simple_test: all
	python test_gen.py simple_test.txt 3 20 10
	./$(NAME) < simple_test.txt > results.txt
	vimdiff results.txt wyniki_simple_test.txt

medium_test: all
	python test_gen.py medium_test.txt 7 1000 20
	./$(NAME) < medium_test.txt > results.txt
	vimdiff results.txt wyniki_medium_test.txt

hard_test: all
	python test_gen.py hard_test.txt 100 10000 64
	./$(NAME) < hard_test.txt > results.txt
	vimdiff results.txt wyniki_hard_test.txt

perf_test: all
	python test_gen.py perf_test.txt 32000 16800000 140
	time ./$(NAME) < perf_test.txt > results.txt
	vimdiff results.txt wyniki_perf_test.txt

period_simple_test: all
	python test_gen.py period_simple_test.txt 3 20 10 1,2,3
	./$(NAME) < period_simple_test.txt > results.txt
	vimdiff results.txt wyniki_period_simple_test.txt

period_medium_test: all
	python test_gen.py period_medium_test.txt 7 1000 20 1,2,3,1,2,4
	./$(NAME) < period_medium_test.txt > results.txt
	vimdiff results.txt wyniki_period_medium_test.txt

period_hard_test: all
	python test_gen.py period_hard_test.txt 100 10000 64 1
	./$(NAME) < period_hard_test.txt > results.txt
	vimdiff results.txt wyniki_period_hard_test.txt

print_tests:
	g++ -lpthread $(LIBS) -lgtest_main -lgtest $(PRINT_TESTS) -o $(TEST_OUT)
	./$(TEST_OUT)
print_tests_debug:
	$(CC) -g -lpthread $(LIBS) -lgtest_main -lgtest test_print_results.cpp print_results.cpp print_results.h -o test_print_results.out

