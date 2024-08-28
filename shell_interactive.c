#include "shell.h"

/**
 * shell_interactive - Runs the shell in interactive mode
 *
 * Task 1: Simple Shell 0.1
 *
 * Description: This function handles the main loop of the shell
 * in interactive mode, where it displays a prompt, waits for input,
 * and then processes the input.
 */
void shell_interactive(void)
{
    char *line = NULL;  /* Pointer to store the input line */
    size_t len = 0;     /* Size of the buffer for getline */
    ssize_t read;       /* Number of characters read by getline */
    char *args[2];      /* Array to hold the command and NULL terminator */

    while (1)  /* Infinite loop to continuously prompt and execute commands */
    {
        /* Display the prompt */
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        /* Read the input line from stdin */
        read = getline(&line, &len, stdin);
        
        if (read == -1)  /* Check if getline encountered an error or EOF */
        {
            free(line);  /* Free the allocated memory for line */
            exit(EXIT_SUCCESS);  /* Exit the shell on EOF */
        }
        
        /* Remove the newline character */
        line[read - 1] = '\0';

        if (_strcmp(line, "exit") == 0)  /* Check if the user entered "exit" */
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        args[0] = line;  /* The command to execute */
        args[1] = NULL;  /* Null terminator for execve */

        /* Execute the command */
        if (execve(args[0], args, NULL) == -1)  /* Command execution */
        {
            perror(args[0]);  /* Print error message if command not found */
        }
    }

    free(line);  /* Free allocated memory (this line is not actually reached) */
}
