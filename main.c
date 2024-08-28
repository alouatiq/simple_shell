#include "shell.h"

/* Task 0: Betty style compliant code */
/* Task 1: Simple shell 0.1 - Basic shell implementation */
#define BUFFER_SIZE 1024

/**
 * main - Entry point for the simple shell
 * Task 1: Implements the main shell loop
 * Task 2: Handles command lines with arguments
 * Task 11: Handles multiple commands separated by ';'
 *
 * Return: Always 0
 */
int main(void)
{
    char *line;
    int status;

    do {
        prompt();
        line = read_line();
        status = execute(line);

        free(line);
    } while (status);

    return (0);
}

/**
 * prompt - Display the shell prompt
 * Task 1: Simple shell 0.1 - Display a prompt and wait for user input
 */
void prompt(void)
{
    printf("$ ");
}

/**
 * read_line - Read a line of input from the user
 * This function is part of Task 1: Simple shell 0.1 and Task 6: Simple shell 0.1.1
 * It handles user input and the "end of file" condition (Ctrl+D)
 * Uses custom_getline to minimize calls to the read system call
 *
 * Return: Pointer to the input string or NULL on EOF
 */
char *read_line(void)
{
    char *line = NULL;

    line = custom_getline();

    if (line == NULL)
    {
        if (feof(stdin))
        {
            printf("\n");
            return NULL;  // Return NULL on EOF instead of exiting
        }
        else if (errno == EINTR)
        {
            // Interrupted system call, try again
            clearerr(stdin);
            return read_line();
        }
        else
        {
            perror("read_line");
            return NULL;  // Return NULL on error instead of exiting
        }
    }

    return line;
}




