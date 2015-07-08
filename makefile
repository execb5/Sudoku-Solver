IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -g -I$(IDIR)

_DEPS = sudoku.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = sudoku.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

testLeak: main
	valgrind --leak-check=full -v ./main

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f main
