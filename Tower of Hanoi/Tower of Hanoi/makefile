WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_HANOI

SRCS = main.c recursion.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o main

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3

test1: main
	./main 3 > output/output1
	diff output/output1 expected/expected1

test2: main
	./main 5 > output/output2


test3: main
	./main 7 > output/output3


clean:
	rm -f main *.o output/output?
