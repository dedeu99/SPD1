CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm -pthread

HELLO = helloworld.c
INCTRAP = incremental_trap.c
INCTRAP2 = incremental_trap2.c
MUTEXES = mutexes.c
DEADLOCK = deadlock.c
NODEADLOCK = no_deadlock.c

all: hello inc_trap inc_trap2 mutexes deadlock no_deadlock
.PHONY: all


hello:	$(HELLO) makefile
	$(CC) $(CFLAGS) $(HELLO) $(LDFLAGS) -o $@ 

inc_trap: $(INCTRAP) makefile
	$(CC) $(CFLAGS) $(INCTRAP) $(LDFLAGS) -o $@

inc_trap2: $(INCTRAP2) makefile
	$(CC) $(CFLAGS) $(INCTRAP2) $(LDFLAGS) -o $@

mutexes: $(MUTEXES) makefile
	$(CC) $(CFLAGS) $(MUTEXES) $(LDFLAGS) -o $@

deadlock: $(DEADLOCK) makefile
	$(CC) $(CFLAGS) $(DEADLOCK) $(LDFLAGS) -o $@

no_deadlock: $(NODEADLOCK) makefile
	$(CC) $(CFLAGS) $(NODEADLOCK) $(LDFLAGS) -o $@



clean:
	rm -f hello inc_trap inc_trap2 mutexes deadlock no_deadlock
