CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm -pthread

EX1 = ex1.c
EX2 = ex2.c
EX3 = ex3.c
all: ex2
.PHONY: all


ex2:	$(EX2) makefile
	$(CC) $(CFLAGS) $(EX2) $(LDFLAGS) -o $@ 



clean:
	rm -f EX1

