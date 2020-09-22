SRCS=src/
LIBS=lib/
CC=gcc
CFLAGS=-I$(LIBS)
ODIR=build/
DATA=data/

task: $(SRCS)main.c
	@$(CC) -o $(ODIR)task $(SRCS)main.c $(SRCS)tasks.c $(CFLAGS) -lm

.PHONY: clean
clean:
	@rm -rf $(ODIR)* $(DATA)*
