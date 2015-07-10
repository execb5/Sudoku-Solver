#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Sudoku.h>

int
main(int argc, const char* argv[])
{
        static const char filename[] = "schema";

        Sudoku* read = readSudokuFromFile(filename);

        Sudoku hard = { { { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
                        , { 0, 0, 0, 0, 0, 3, 0, 8, 5 }
                        , { 0, 0, 1, 0, 2, 0, 0, 0, 0 }
                        , { 0, 0, 0, 5, 0, 7, 0, 0, 0 }
                        , { 0, 0, 4, 0, 0, 0, 1, 0, 0 }
                        , { 0, 9, 0, 0, 0, 0, 0, 0, 0 }
                        , { 5, 0, 0, 0, 0, 0, 0, 7, 3 }
                        , { 0, 0, 2, 0, 1, 0, 0, 0, 0 }
                        , { 0, 0, 0, 0, 4, 0, 0, 0, 9 } } };

        printf("Normal puzzle:\n");
        printBoard(read);
        solve(read);
        printBoard(read);
        printf("Hard puzzle:\n");
        printBoard(&hard);
        solve(&hard);
        printBoard(&hard);

        free(read);

        return 0;
}
