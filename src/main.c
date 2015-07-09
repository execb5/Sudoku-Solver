#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Sudoku.h>

#define LINE_SIZE 128

int
main(int argc, const char* argv[])
{
        static const char filename[] = "schema";
        FILE* file = fopen ( filename, "r" );
        if (file != NULL)
        {
                char line[LINE_SIZE];
                while (fgets(line, sizeof line, file) != NULL) //read a line
                {
                        size_t ln = strlen(line) - 1;
                        if (line[ln] == '\n')
                        {
                                line[ln] = '\0'; //removes the trailing newline
                        }
                        
                        char* ch = strtok(line, "\\  ");
                        while (ch != NULL)
                        {
                                printf("%s ", ch);
                                ch = strtok( NULL, "\\ " );
                        }
                        printf ("\n");
                }
                fclose(file);
        }
        else
        {
                perror(filename); //why didn't the file open?
        }

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

        printf("------------------------------------\n");
        printBoard(&test);
        printf("------------------------------------\n");
        printBoard(copy);

        free(copy);

        return 0;
}
