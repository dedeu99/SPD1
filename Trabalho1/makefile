CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm -pthread

CORRIDA = corrida.c

all: corrida
.PHONY: all


corrida:	$(CORRIDA) makefile
	$(CC) $(CFLAGS) $(CORRIDA) $(LDFLAGS) -o $@ 



clean:
	rm -f corrida

