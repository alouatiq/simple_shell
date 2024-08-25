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
    char *comment_start = strchr(command, '#');
    if (comment_start != NULL) {
        *comment_start = '\0'; /* Terminate the command string at the comment start */
    }
}
