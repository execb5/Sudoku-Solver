#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Sudoku.h>

int
main(int argc, const char* argv[])
{
        static const char filename[] = "schema";

        Sudoku* read = readSudokuFromFile(filename);

        Sudoku test = { { { 0, 5, 0, 0, 6, 0, 0, 0, 1 }
                        , { 0, 0, 4, 8, 0, 0, 0, 7, 0 }
                        , { 8, 0, 0, 0, 0, 0, 0, 5, 2 }
                        , { 2, 0, 0, 0, 5, 7, 0, 3, 0 }
                        , { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
                        , { 0, 3, 0, 6, 9, 0, 0, 0, 5 }
                        , { 7, 9, 0, 0, 0, 0, 0, 0, 8 }
                        , { 0, 1, 0, 0, 0, 6, 5, 0, 0 }
                        , { 5, 0, 0, 0, 3, 0, 0, 6, 0 } } };

        Sudoku* copy = copyBoard(&test);

        printf("Read\n");
        printBoard(read);
        printf("\n------------------------------------\n");
        printf("test\n");
        printBoard(&test);
        printf("\n------------------------------------\n");
        printf("copy\n");
        printBoard(copy);

        free(read);
        free(copy);

        return 0;
}
