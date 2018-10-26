CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm -pthread

HELLO = helloworld.c
INCTRAP = incremental_trap.c
INC = incremental.c
MUTEXES = mutexes.c
DEADLOCK = deadlock.c
NODEADLOCK = no_deadlock.c
CONDS = conditionals.c

all: hello inc_trap inc mutexes deadlock no_deadlock conditionals
.PHONY: all


hello:	$(HELLO) makefile
	$(CC) $(CFLAGS) $(HELLO) $(LDFLAGS) -o $@ 

inc_trap: $(INCTRAP) makefile
	$(CC) $(CFLAGS) $(INCTRAP) $(LDFLAGS) -o $@

inc: $(INC) makefile
	$(CC) $(CFLAGS) $(INC) $(LDFLAGS) -o $@

mutexes: $(MUTEXES) makefile
	$(CC) $(CFLAGS) $(MUTEXES) $(LDFLAGS) -o $@

deadlock: $(DEADLOCK) makefile
	$(CC) $(CFLAGS) $(DEADLOCK) $(LDFLAGS) -o $@

no_deadlock: $(NODEADLOCK) makefile
	$(CC) $(CFLAGS) $(NODEADLOCK) $(LDFLAGS) -o $@

conditionals: $(CONDS) makefile
	$(CC) $(CFLAGS) $(CONDS) $(LDFLAGS) -o $@



clean:
	rm -f hello inc_trap inc mutexes deadlock no_deadlock conditionals
