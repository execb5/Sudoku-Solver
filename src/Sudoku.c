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

Sudoku*
readSudokuFromFile(const char* fileName)
{
        FILE* file = fopen ( fileName, "r" );
        Sudoku* read = (Sudoku*) malloc(sizeof(Sudoku));
        if (file != NULL)
        {
                char line[LINE_SIZE];
                int i = 0;
                int j = 0;
                while (fgets(line, sizeof line, file) != NULL) //read a line
                {
                        size_t ln = strlen(line) - 1;
                        if (line[ln] == '\n')
                        {
                                line[ln] = '\0'; //removes the trailing newline
                        }
                        
                        char* ch = strtok(line, "\\  ");
                        j = 0;
                        while (ch != NULL)
                        {
                                printf("%s ", ch);
                                read->board[i][j] = strtol(ch, NULL, 10);
                                ch = strtok( NULL, "\\ " );
                                j++;
                        }
                        printf ("\n");
                        i++;
                }
                fclose(file);
        }
        else
        {
                perror(fileName); //why didn't the file open?
        }
        return read;
}

void
solve(Sudoku* su)
{

}

