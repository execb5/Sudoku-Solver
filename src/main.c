#include <stdio.h>
#include <string.h>

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
                        
                        char* ch = strtok(line, "\ ");
                        while (ch != NULL)
                        {
                                printf("%s ", ch);
                                ch = strtok ( NULL, "\ " );
                        }
                        printf ("\n");
                }
                fclose(file);
        }
        else
        {
                perror(filename); //why didn't the file open?
        }
        return 0;
}
