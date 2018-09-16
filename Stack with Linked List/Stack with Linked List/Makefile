iWARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFALGS = 

SRCS = stack.c main.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o main

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testall: test1 test2 test3

testadd: main 	
	test1
	test2
	test3

test1: main
	./main input/input1 > output1
	diff -i -w output1 expected/expected1

test2: main
	./main input/input2 > output2
	diff -i -w output2 expected/expected2

test3: main
	./main input/input3 > output3
	diff -i -w output3 expected/expected3

clean: # remove all machine generated files
	rm -f hw04 *.o 
