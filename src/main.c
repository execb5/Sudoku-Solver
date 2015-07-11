#include <stdio.h>
#include <stdlib.h>
#include <sudoku.h>

int
main(int argc, const char* argv[])
{
        static const char filename[] = "examples/schema";

        Sudoku* read = readSudokuFromFile(filename);

        Sudoku* hard = readSudokuFromFile("examples/hard");

        printf("Normal puzzle:\n");
        printBoard(read);
        solve(read);
        printBoard(read);
        printf("Hard puzzle:\n");
        printBoard(hard);
        solve(hard);
        printBoard(hard);

        free(read);

        return 0;
}
