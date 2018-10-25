CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm -pthread

HELLO = helloworld.c
INCTRAP = incremental_trap.c

all: hello inc_trap
.PHONY: all


hello:	$(HELLO) makefile
	$(CC) $(CFLAGS) $(HELLO) $(LDFLAGS) -o $@ 

inc_trap: $(INCTRAP) makefile
	$(CC) $(CFLAGS) $(INCTRAP) $(LDFLAGS) -o $@

clean:
	rm -f hello int_trap

