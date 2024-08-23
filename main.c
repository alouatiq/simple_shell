#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Task 1: Simple Shell 0.1
 * Task 2: Simple Shell 0.2
 *
 * Return: Exit status of the shell
 */
int main(int argc, char **argv)
{
    /* Placeholder for shell initialization code */
    
    if (argc == 1)
    {
        /* Interactive mode: If no arguments, start the shell in interactive mode */
        shell_interactive();
    }
    else
    {
        /* Non-interactive mode: If arguments are passed, treat as a script file */
        shell_non_interactive(argv[1]);
    }

    return (0);
}
