CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm

SRC = teste_tempo.c
SRC2 = timetest.c
SRC3 = processes.c
all: teste_tempo timetest processes
.PHONY: all

teste_tempo:	$(SRC) makefile
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $@ 

timetest: $(SRC2) makefile
	$(CC) $(CFLAGS) $(SRC2) $(LDFLAGS) -o $@

processes: $(SRC3) makefile
	$(CC) $(CFLAGS) $(SRC3) $(LDFLAGS) -o $@

clean:
	rm -f  teste_tempo timetest threads

