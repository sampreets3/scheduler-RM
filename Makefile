SRCS=src/
LIBS=lib/
CC=gcc
CFLAGS=-I$(LIBS)
ODIR=build/
DATA=data/

task: $(SRCS)
	@$(CC) -o $(ODIR)task $(SRCS)main.c $(SRCS)tasks.c $(CFLAGS)



.PHONY: clean
clean:
	@rm -rf $(ODIR)* $(DATA)*
