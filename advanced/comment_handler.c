#include "../shell.h"

/**
 * remove_comments - Remove comments from the command
 * @command: Command string to process
 * Return: Command string with comments removed
 */
char *remove_comments(char *command)
{
    char *comment_start = strchr(command, '#');
    if (comment_start)
    {
        // Check if # is at the start or has a space before it
        if (comment_start == command || *(comment_start - 1) == ' ')
        {
            *comment_start = '\0';
        }
    }
    return command;
}