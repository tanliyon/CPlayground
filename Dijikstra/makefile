WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_DIJIKSTRA -DTEST_GRAPH -DTEST_MINHEAP

SRCS = main.c graph.c minheap.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o main

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3

test1: main
	./main inputs/test1.txt

clean:
	rm -f main *.o output/output?
