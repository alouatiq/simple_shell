#include "shell.h"

/* Task 6: Implement Custom getline */

int _getline(char **buffer, size_t *bufsize, FILE *stream)
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
            ssize_t read_len = fread(temp_buf, 1, 1024, stream);
            pos = 0;

            if (read_len == 0)  /* EOF */
                return -1;
            else if (ferror(stream))
            {
                perror("fread");
                return -1;
            }
            len = (size_t)read_len;  /* Assign the ssize_t result to size_t */
        }

        (*buffer)[i++] = temp_buf[pos++];

        if ((*buffer)[i - 1] == '\n')
        {
            (*buffer)[i] = '\0';
            return i;
        }
    }
}
