#include "shell.h"

/* Task 6: Implement Custom getline */

int _getline(char **buffer, size_t *bufsize)
{
    static char temp_buf[1024];
    static size_t pos;
    static size_t len;
    size_t i = 0;

    if (*buffer == NULL)
    {
        *buffer = malloc(1024);
        if (*buffer == NULL)
        {
            perror("malloc");
            return -1;
        }
        *bufsize = 1024;
    }

    while (1)
    {
        if (pos == len)
        {
            len = read(STDIN_FILENO, temp_buf, 1024);
            pos = 0;

            if (len == 0)  /* EOF */
                return -1;
            else if (len == -1)
            {
                perror("read");
                return -1;
            }
        }

        (*buffer)[i++] = temp_buf[pos++];

        if ((*buffer)[i - 1] == '\n')
        {
            (*buffer)[i] = '\0';
            return i;
        }
    }
}
