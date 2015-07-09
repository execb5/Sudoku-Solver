#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Sudoku.h>

int checker[SUDOKU_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

bool
checkChecker(void)
{
        int i;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                if (checker[i] != 1)
                {
                        return false;
                }
        }
        return true;
}

Sudoku*
copyBoard(Sudoku* su)
{
        Sudoku* cp = (Sudoku*) malloc(sizeof(Sudoku));
        if (cp == NULL)
        {
                printf("Failed to allocate memory for a copy.\n");
                exit(EXIT_FAILURE);
        }
        memcpy(cp->board, su->board, SUDOKU_SIZE * SUDOKU_SIZE * sizeof(int));
        return cp;
}

bool
is1stQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 0; i < FIRST_SECTION; i++)
        {
                for (j = 0; j < FIRST_SECTION; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is2ndQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 0; i < FIRST_SECTION; i++)
        {
                for (j = 3; j < SECOND_SECTION; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is3rdQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 0; i < FIRST_SECTION; i++)
        {
                for (j = 6; j < SUDOKU_SIZE; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is4thQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 3; i < SECOND_SECTION; i++)
        {
                for (j = 0; j < FIRST_SECTION; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is5thQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 3; i < SECOND_SECTION; i++)
        {
                for (j = 3; j < SECOND_SECTION; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is6thQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 3; i < SECOND_SECTION; i++)
        {
                for (j = 6; j < SUDOKU_SIZE; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is7thQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 6; i < SUDOKU_SIZE; i++)
        {
                for (j = 0; j < FIRST_SECTION; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is8thQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 6; i < SUDOKU_SIZE; i++)
        {
                for (j = 3; j < SECOND_SECTION; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
        return false;
}

bool
is9thQOk(Sudoku* su)
{
        int i;
        int j;
        for (i = 6; i < SUDOKU_SIZE; i++)
        {
                for (j = 6; j < SUDOKU_SIZE; j++)
                {
                        if (su->board[i][j] == 0)
                        {
                                resetChecker();
                                return false;
                        }
                        checker[su->board[i][j] - 1]++;
                }
        }
        if (checkChecker())
        {
                resetChecker();
                return true;;
        }
        resetChecker();
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
        Sudoku* read = (Sudoku*) malloc(sizeof(Sudoku));
        if (read == NULL)
        {
                printf("Failed to allocate memory before reading a File.\n");
                exit(EXIT_FAILURE);
        }

        FILE* file = fopen ( fileName, "r" );
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
resetChecker(void)
{
        int i;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                checker[i] = 0;
        }
}

void
solve(Sudoku* su)
{

}
