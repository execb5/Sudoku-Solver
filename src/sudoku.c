#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sudoku.h>

static void
cloneBoard(Sudoku* dst, Sudoku* src)
{
        int i;
        int j;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                for (j = 0; j < SUDOKU_SIZE; j++)
                {
                        dst->board[i][j] = src->board[i][j];
                }
        }
}

static char*
stripChars(const char *string, const char *chars)
{
        char* newstr = malloc(strlen(string) + 1);
        int counter = 0;

        while(*string)
        {
                if (!strchr(chars, *string))
                {
                        newstr[counter] = *string;
                        counter++;
                }
                string++;
        }

        newstr[counter] = 0;
        return newstr;
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
        if(su->board[row1 + sectorRow][col2 + sectorColumn] == val)
        {
                return false;
        }
        if(su->board[row2 + sectorRow][col1 + sectorColumn] == val)
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
                        if (su->board[i][j] == 0)
                        {
                                printf("|_ _");
                        }
                        else
                        {
                                printf("|_%d_", su->board[i][j]);
                        }
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
                                read->board[i][j] = strtol(ch, NULL, 10);
                                ch = strtok( NULL, "\\ " );
                                j++;
                        }
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

bool
solve(Sudoku* su)
{
        g_remainingThreadQuit = false;
        Sudoku* copy1  = copyBoard(su);
        Sudoku* copy2  = copyBoard(su);
        Sudoku* solved = NULL;

        struct threadWrapper* st1 = (struct threadWrapper*) malloc(sizeof(struct
                                threadWrapper));
        struct threadWrapper* st2 = (struct threadWrapper*) malloc(sizeof(struct
                                threadWrapper));

        st1->sudoku  = copy1;
        st1->reverse = false;
        st1->ans     = &solved;
        st1->id      = 1;

        st2->sudoku  = copy2;
        st2->reverse = true;
        st2->ans     = &solved;
        st2->id      = 2;

        pthread_t thread1;
        pthread_t thread2;
        pthread_attr_t attr;

        pthread_mutex_init(&g_sudoku_mutex, NULL);
        pthread_cond_init (&g_done, NULL);

        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        pthread_create(&thread1, &attr,  threadRoutine, (void*) st1);
        pthread_create(&thread2, &attr,  threadRoutine, (void*) st2);

        pthread_mutex_lock(&g_sudoku_mutex);

        while (!solved)
        {
                pthread_cond_wait(&g_done, &g_sudoku_mutex);
        }

        cloneBoard(su, solved);
        free(solved);

        pthread_mutex_unlock(&g_sudoku_mutex);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        pthread_attr_destroy(&attr);
        pthread_mutex_destroy(&g_sudoku_mutex);
        pthread_cond_destroy(&g_done);

        return true;
}

bool
solveAux(Sudoku* su, int row, int column, struct threadWrapper* ta)
{
        if (g_remainingThreadQuit)
        {
                free(ta->sudoku);
                free(ta);
                
                pthread_exit(NULL);
        }

        if (row == 9)
        {
                return true;
        }
        if (su->board[row][column])
        {
                if (column == 8)
                {
                        if (solveAux(su, row + 1, 0, ta))
                        {
                                return true;
                        }
                }
                else
                {
                        if (solveAux(su, row, column + 1, ta))
                        {
                                return true;
                        }
                }
                return false;
        }

        int nextVal = !ta->reverse ?  1 : 9;
        int until   = !ta->reverse ? 10 : 0;

        while (nextVal != until)
        {
                if (isValid(su, nextVal, row, column))
                {
                        su->board[row][column] = nextVal;
                        if (column == 8)
                        {
                                if (solveAux(su, row + 1, 0, ta))
                                {
                                        return true;
                                }
                        }
                        else
                        {
                                if (solveAux(su, row, column + 1, ta))
                                {
                                        return true;
                                }
                        }
                        su->board[row][column] = 0;
                }
                nextVal = !ta->reverse ? nextVal + 1 : nextVal - 1;
        }
        return false; //Warning of control reches end of non-void function
}

Sudoku*
stringToSudoku(char* string)
{
        Sudoku* su = (Sudoku*) malloc(sizeof(Sudoku));

        char* new = stripChars(string, "\n\\ ");

        int i;
        int j;
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                for (j = 0; j < SUDOKU_SIZE; j++)
                {
                        su->board[i][j] = *new - '0';//I love C <3
                        new++;
                }
        }

        return su;
}

char*
sudokuToString(Sudoku* su)
{
        int i;
        int j;
        char buffer[2];
        char* str = (char*) calloc(163, sizeof(char));//(9 elements + 8 whitespaces + 1 newLine)*9rows + NUL
        for (i = 0; i < SUDOKU_SIZE; i++)
        {
                for (j = 0; j < SUDOKU_SIZE; j++)
                {
                        snprintf(buffer, 2, "%d", su->board[i][j]);
                        strcat(str, buffer);
                        if (j != SUDOKU_SIZE - 1)
                        {
                                strcat(str, "\40");
                        }
                }
                if (i != SUDOKU_SIZE - 1)
                {
                        strcat(str, "\n");
                }
        }
        return str;
}

void*
threadRoutine(void* args)
{
        struct threadWrapper* arguments = (struct threadWrapper*) args;

        solveAux(arguments->sudoku, 0, 0, arguments);

        pthread_mutex_lock(&g_sudoku_mutex);

        if (!g_remainingThreadQuit)
        {
                g_remainingThreadQuit = true;
                Sudoku* solved = copyBoard(arguments->sudoku);
                *(arguments->ans) = solved;
                pthread_cond_signal(&g_done);
        }

        pthread_mutex_unlock(&g_sudoku_mutex);

        free(arguments->sudoku);
        free(arguments);

        pthread_exit(NULL);
}
