#include "shell.h"

/**
 * remove_comments - Removes comments from the command string
 * @command: The command string possibly containing comments
 *
 * Task 15: Comments
 *
 * Description: This function will remove anything after `#` in a command.
 */

void remove_comments(char *command)
{
    char *comment_start;

    /* Find the position of the `#` character */
    comment_start = strchr(command, '#');
    
    /* If `#` is found and it's not inside quotes, terminate the string at `#` */
    if (comment_start != NULL)
    {
        /* Terminate the command string at the comment start */
        *comment_start = '\0'; /* Replace `#` with null terminator */
    }
}
