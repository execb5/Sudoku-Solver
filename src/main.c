#include <stdio.h>
#include <stdlib.h>
#include <sudoku.h>

int
main(int argc, const char* argv[])
{
        if (argc > 1)
        {
                int i;
                Sudoku* su;
                for (i = 1; i < argc; i++)
                {
                        printf("%s\n", argv[i]);
                        su = readSudokuFromFile(argv[i]);
                        printBoard(su);
                        solve(su);
                        printBoard(su);
                        printf("\n");
                        printf("-------------------------------------------\n");
                        printf("-------------------------------------------\n");
                }
        }
        else
        {
                printf("USAGE:\n");
                printf("./main <SUDOKU_FILE> <SUDOKU_FILE>...\n");
        }
        return 0;
}
