#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sudoku.h>

int
main(int argc, char* argv[])
{
        if (argc > 1)
        {
                int i;
                time_t start;
                time_t stop;
                Sudoku* su;
                for (i = 1; i < argc; i++)
                {
                        printf("%s\n", argv[i]);
                        su = readSudokuFromFile(argv[i]);
                        printBoard(su);
                        time(&start);
                        solve(su);
                        time(&stop);
                        printBoard(su);
                        free(su);
                        printf("Solved in %.0fs", difftime(stop, start));
                        printf("\n");
                        printf("-------------------------------------------\n");
                        printf("-------------------------------------------\n");
                }
        }
        else
        {
                printf("COMMAND LINE USAGE:\n");
                printf("./sudoku <SUDOKU_FILE> <SUDOKU_FILE>...\n");
        }

        pthread_exit(NULL);
}
