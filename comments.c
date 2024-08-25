#include "shell.h"

void remove_comments(char *command)
{
    char *comment_start = strchr(command, '#');
    if (comment_start != NULL) {
        *comment_start = '\0'; /* Terminate the command string at the comment start */
    }
}
