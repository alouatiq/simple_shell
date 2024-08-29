#include "shell.h"

int main(void)
{
    char *command;
    
    while (1)
    {
        prompt();  // Display the prompt
        command = read_command();  // Read the command from stdin

        if (command == NULL)  // Handle EOF (Ctrl+D)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        if (strlen(command) == 0)
        {
            free(command);
            continue;  // Ignore empty commands
        }

        execute_command(command);  // Execute the command
        free(command);  // Free the command buffer
    }

    return 0;
}
