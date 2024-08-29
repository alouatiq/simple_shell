#include "shell.h"
#include <unistd.h>  /* For execve, fork */
#include <stdio.h>   /* For perror */
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

extern char *find_command(char *cmd);
extern void print_command_error(char *cmd);

int execute_command(char **args, char **env)
{
pid_t pid;
int status;
char *command;

command = find_command(args[0]);

if (command == NULL)  /* Command not found */
{
print_command_error(args[0]);
return (0);
}

pid = fork();

if (pid == -1)  /* Error during fork */
{
perror("hsh");
return (0);
}
else if (pid == 0)  /* Child process */
{
if (execve(command, args, env) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else  /* Parent process */
{
wait(&status);
}

return (1);
}

char *find_command(char *cmd)
{
char *path = getenv("PATH");
char *token;
char *full_path;
struct stat st;

if (path == NULL)
return (NULL);

token = strtok(path, ":");
while (token != NULL)
{
full_path = build_path(token, cmd);
if (stat(full_path, &st) == 0)
return (full_path);

free(full_path);
token = strtok(NULL, ":");
}

return (NULL);
}

char *build_path(char *dir, char *cmd)
{
char *full_path;
size_t len = strlen(dir) + strlen(cmd) + 2;

full_path = malloc(len);
if (full_path == NULL)
return (NULL);

strcpy(full_path, dir);
strcat(full_path, "/");
strcat(full_path, cmd);

return (full_path);
}

void print_command_error(char *cmd)
{
fprintf(stderr, "hsh: command not found: %s\n", cmd);
}
