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

        Sudoku correct = { { { 5, 3, 4, 6, 7, 8, 9, 1, 2 }
                           , { 6, 7, 2, 1, 9, 5, 3, 4, 8 }
                           , { 1, 9, 8, 3, 4, 2, 5, 6, 7 }
                           , { 8, 5, 9, 7, 6, 1, 4, 2, 3 }
                           , { 4, 2, 6, 8, 5, 3, 7, 9, 1 }
                           , { 7, 1, 3, 9, 2, 4, 8, 5, 6 }
                           , { 9, 6, 1, 5, 3, 7, 2, 8, 4 }
                           , { 2, 8, 7, 4, 1, 9, 6, 3, 5 }
                           , { 3, 4, 5, 2, 8, 6, 1, 7, 9 } } };

        Sudoku* copy = copyBoard(&test);

        printf("Read\n");
        printBoard(read);
        printf("\n------------------------------------\n");
        printf("test\n");
        printBoard(&test);
        printf("\n------------------------------------\n");
        printf("copy\n");
        printBoard(copy);
        printf("\n------------------------------------\n");
        printf("correct\n");
        printBoard(&correct);

        printf("correct 1stQOk? %d\n", is1stQOk(&correct));
        printf("test 1stQOk? %d\n", is1stQOk(&test));
        printf("correct 2ndQOk? %d\n", is2ndQOk(&correct));
        printf("test 2ndQOk? %d\n", is2ndQOk(&test));
        printf("correct 3rdQOk? %d\n", is3rdQOk(&correct));
        printf("test 3rdQOk? %d\n", is3rdQOk(&test));
        printf("correct 4thQOk? %d\n", is4thQOk(&correct));
        printf("test 4thQOk? %d\n", is4thQOk(&test));
        printf("correct 5thQOk? %d\n", is5thQOk(&correct));
        printf("test 5thQOk? %d\n", is5thQOk(&test));
        printf("correct 6thQOk? %d\n", is6thQOk(&correct));
        printf("test 6thQOk? %d\n", is6thQOk(&test));
        printf("correct 7thQOk? %d\n", is7thQOk(&correct));
        printf("test 7thQOk? %d\n", is7thQOk(&test));
        printf("correct 8thQOk? %d\n", is8thQOk(&correct));
        printf("test 8thQOk? %d\n", is8thQOk(&test));

        free(read);
        free(copy);

        return 0;
}
