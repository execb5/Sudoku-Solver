IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -g -I$(IDIR) `pkg-config --libs --cflags gtk+-2.0`

_DEPS = sudoku.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = sudoku.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sudoku: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

examples: sudoku
	./$^ examples/*

testLeak: sudoku
	valgrind --leak-check=full -v ./$^ examples/*

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f sudoku
