#include <stdio.h>
#include <unistd.h>

/**
 * get_parent_pid - Function that prints the parent PID
 *
 * Return: Void
 */
int get_parent_pid(void)
{
	pid_t my_parent_pid = getppid();

	printf("%u\n", my_parent_pid);
	return (0);
}
