IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -g -I$(IDIR) `pkg-config --libs --cflags gtk+-3.0`

_DEPS = sudoku.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = sudoku.o main.o sudokuGUI.o
_CMDOBJ = $(filter-out sudokuGUI.o, $(_OBJ))
_GUIOBJ = $(filter-out main.o, $(_OBJ))
CMDOBJ = $(patsubst %,$(ODIR)/%,$(_CMDOBJ))
GUIOBJ = $(patsubst %,$(ODIR)/%,$(_GUIOBJ))

all: sudoku sudokuGUI

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sudoku: $(CMDOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

sudokuGUI: $(GUIOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

examples: sudoku
	./$^ examples/*

testLeak: sudoku
	valgrind --leak-check=full -v ./$^ examples/*

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f sudoku
	rm -f sudokuGUI
