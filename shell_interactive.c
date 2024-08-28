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

    while (1)  /* Infinite loop to continuously prompt and execute commands */
    {
        /* Display the prompt */
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        /* Read the input line from stdin */
        read = getline(&line, &len, stdin);
        
        if (read == -1)  /* Check if getline encountered an error or EOF */
        {
            if (read == -1)  /* If read is -1, it could be EOF or an error */
            {
                free(line);  /* Free the allocated memory for line */
                exit(EXIT_SUCCESS);  /* Exit the shell on EOF */
            }
            else
            {
                perror("getline failed");  /* Print an error message if getline fails */
                free(line);  /* Free the allocated memory for line */
                exit(EXIT_FAILURE);  /* Exit with a failure status */
            }
        }
        
        /* Remove the newline character from the input */
        line[read - 1] = '\0';

        /* Check if the user entered "exit" */
        if (_strcmp(line, "exit") == 0)
        {
            free(line);  /* Free the allocated memory for line */
            exit(EXIT_SUCCESS);  /* Exit the shell */
        }

        /* Execute the command entered by the user */
        execute_command(line);
    }

    /* Free allocated memory for line (although this will never be reached) */
    free(line);
}
