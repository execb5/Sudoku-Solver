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
                if (checker[i] > 1)
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
freePos(Sudoku* su, int y, int x)
{
        if (su->board[y][x] == 0)
        {
                return true;
        }
        return false;
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
        bool solved = true;
        solved = solved && is1stQOk(su);
        solved = solved && is2ndQOk(su);
        solved = solved && is3rdQOk(su);
        solved = solved && is4thQOk(su);
        solved = solved && is5thQOk(su);
        solved = solved && is6thQOk(su);
        solved = solved && is7thQOk(su);
        solved = solved && is8thQOk(su);
        solved = solved && is9thQOk(su);
        int i;
        for (i = 0; i < SUDOKU_SIZE; i++) {
                solved = solved && isColumnCorrect(su, i);
                solved = solved && isLineCorrect(su, i);
        }
        return solved;
}

bool
isColumnCorrect(Sudoku* su, int column)
{
        int i;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                if (su->board[i][column] == 0)
                {
                        continue;
                }
                checker[su->board[i][column] - 1]++;
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
isLineCorrect(Sudoku* su, int line)
{
        int i;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                if (su->board[line][i] == 0)
                {
                        continue;
                }
                checker[su->board[line][i] - 1]++;
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
isValid(Sudoku* su, int val, int row, int column)
{
        int sectorRow    = (row / 3) * 3;
        int sectorColumn = (column / 3) * 3;
        int row1         = (row + 2) % 3;
        int col1         = (column + 2) % 3;
        int row2         = (row + 4) % 3;
        int col2         = (column + 4) % 3;
        int i;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                if (su->board[i][column] == val)
                {
                        return false;
                }
                if (su->board[row][i] == val)
                {
                        return false;
                }
        }
        if(su->board[row1 + sectorRow][col1 + sectorColumn] == val)
        {
                return false;
        }
        if(su->board[row2 + sectorRow][col1 + sectorColumn] == val)
        {
                return false;
        }
        if(su->board[row1 + sectorRow][col2 + sectorColumn] == val)
        {
                return false;
        }
        if(su->board[row2 + sectorRow][col2 + sectorColumn] == val)
        {
                return false;
        }
        return true;
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

bool
solve(Sudoku* su)
{
        return solveAux(su, 0, 0);
}

bool
solveAux(Sudoku* su, int row, int column)
{
        if (row == 9)
        {
                return true;
        }
        if (su->board[row][column])
        {
                if (column == 8)
                {
                        if (solveAux(su, row + 1, 0))
                        {
                                return true;
                        }
                }
                else
                {
                        if (solveAux(su, row, column + 1))
                        {
                                return true;
                        }
                }
        }
        int nextVal;
        for (nextVal = 1; nextVal < 10; nextVal++)
        {
                if (isValid(su, nextVal, row, column))
                {
                        su->board[row][column] = nextVal;
                        if (column == SUDOKU_SIZE - 1)
                        {
                                if (solveAux(su, row + 1, 0))
                                {
                                        return true;
                                }
                        }
                        else
                        {
                                if (solveAux(su, row, column + 1))
                                {
                                        return true;
                                }
                        }
                        su->board[row][column] = 0;
                }
        }
        return false; //Warning of control reches end of non-void function
}

bool
write(Sudoku* su, int val, int row, int column)
{
        if (su->board[row][column] == 0)
        {
                su->board[row][column] = val;
                return true;
        }
        return false;
}
