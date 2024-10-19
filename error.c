#include "shell.h"

/**
 * print_error - Prints error messages
 * @msg: Error message to print
 */
void print_error(char *msg)
{
    perror(msg);
}
