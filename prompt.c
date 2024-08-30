#include "shell.h"

void display_prompt(void)
{
    write(STDOUT_FILENO, "($) ", 4);
}
