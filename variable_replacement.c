#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * handle_variable_replacement - Replaces variables in the command string
 * @command: The command string that may contain variables
 *
 * Task 14: Simple Shell 1.0+ (Handle variables replacement)
 *
 * Description: This function scans the command string for variables and
 * replaces them with their corresponding values. It handles special variables
 * such as `$?` (exit status of the last command), `$$` (process ID of the shell),
 * and any environment variables.
 */
void handle_variable_replacement(char *command)
{
    char *result = NULL;
    char *temp = command;
    size_t len = 0;
    pid_t pid = getpid();
    char pid_str[12]; /* Enough to hold the string representation of a PID */
    int status = 0;   /* Replace with the actual exit status of the last command */
    char status_str[12]; /* To hold the string representation of the exit status */

    sprintf(pid_str, "%d", pid);       /* Convert PID to string */
    sprintf(status_str, "%d", status); /* Convert exit status to string */

    while (*temp)
    {
        if (*temp == '$')
        {
            if (*(temp + 1) == '?') /* Replace $? with the last exit status */
            {
                len += strlen(status_str);
                result = realloc(result, len + 1);
                strcat(result, status_str);
                temp += 2; /* Skip over $? */
            }
            else if (*(temp + 1) == '$') /* Replace $$ with the current PID */
            {
                len += strlen(pid_str);
                result = realloc(result, len + 1);
                strcat(result, pid_str);
                temp += 2; /* Skip over $$ */
            }
            else /* Replace with environment variable value */
            {
                char *env_var_name = strtok(temp + 1, " ");
                char *env_var_value = getenv(env_var_name);

                if (env_var_value)
                {
                    len += strlen(env_var_value);
                    result = realloc(result, len + 1);
                    strcat(result, env_var_value);
                    temp += strlen(env_var_name) + 1; /* Skip over $ and the variable name */
                }
                else
                {
                    len += strlen(env_var_name) + 1;
                    result = realloc(result, len + 1);
                    strcat(result, "$");
                    strcat(result, env_var_name);
                    temp += strlen(env_var_name) + 1; /* Skip over $ and the variable name */
                }
            }
        }
        else
        {
            len++;
            result = realloc(result, len + 1);
            strncat(result, temp, 1);
            temp++;
        }
    }

    strcpy(command, result);
    free(result);
}
