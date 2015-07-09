#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Sudoku.h>

Sudoku*
copyBoard(Sudoku* su)
{
        Sudoku* cp = (Sudoku*) malloc(sizeof(Sudoku));
        memcpy(cp->board, su->board, SUDOKU_SIZE * SUDOKU_SIZE * sizeof(int));
        return cp;
}

bool
is1stQOk(Sudoku* su)
{
        return false;
}

bool
is2ndQOk(Sudoku* su)
{
        return false;
}

bool
is3rdQOk(Sudoku* su)
{
        return false;
}

bool
is4thQOk(Sudoku* su)
{
        return false;
}

bool
is5thQOk(Sudoku* su)
{
        return false;
}

bool
is6thQOk(Sudoku* su)
{
        return false;
}

bool
is7thQOk(Sudoku* su)
{
        return false;
}

bool
is8thQOk(Sudoku* su)
{
        return false;
}

bool
is9thQOk(Sudoku* su)
{
        return false;
}

bool
isBoardCorrect(Sudoku* su)
{
        return false;
}

bool
isColumnCorrect(Sudoku* su, int line)
{
        return false;
}

bool
isLineCorrect(Sudoku* su, int line)
{
        return false;
}

void
printBoard(Sudoku* su)
{
        int i;
        int j;
        printf(" _____________________________________\n");
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                for (j = 0; j < SUDOKU_SIZE; j++)
                {
                        printf("|_%d_", su->board[i][j]);
                        if (j == 2 || j == 5)
                        {
                                printf("|");
                        }
                }
                printf("|\n");
                if (i == 2 || i == 5)
                {
                        printf("|-----------||-----------||-----------|\n");
                }
        }
}

void
readSudokuFromFile(char* fileName, Sudoku* su)
{

}

void
solve(Sudoku* su)
{

}

