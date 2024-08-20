#include "shell.h"

#define BUFFER_SIZE 1024

char *read_line(void)
{
    char *buffer = malloc(BUFFER_SIZE);
    int position = 0;
    int c;

    if (!buffer)
    {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        if (position >= BUFFER_SIZE)
        {
            BUFFER_SIZE += BUFFER_SIZE;
            buffer = realloc(buffer, BUFFER_SIZE);
            if (!buffer)
            {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}
