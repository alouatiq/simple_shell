#include "../shell.h"

/**
 * print_error - Print an error message
 * @info: Pointer to the info_t structure
 * @estr: Error string to print
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(estr);
    _eputchar('\n');
}

/**
 * _eputs - Print a string to stderr
 * @str: String to print
 */
void _eputs(const char *str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] != '\0')
    {
        _eputchar(str[i]);
        i++;
    }
}

/**
 * _eputchar - Write a character to stderr
 * @c: Character to write
 * Return: 1 on success, -1 on error
 */
int _eputchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(2, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return (1);
}

/**
 * print_d - Print an integer to a file descriptor
 * @input: Integer to print
 * @fd: File descriptor to write to
 * Return: Number of characters printed
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
    int i, count = 0;
    unsigned int _abs_, current;

    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;

    current = _abs_;
    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_abs_ / i)
        {
            __putchar('0' + current / i);
            count++;
        }
        current %= i;
    }
    __putchar('0' + current);
    count++;

    return (count);
}
