#include <stdio.h>
#include <unistd.h>

/**
 * get_pid - Functtion that prints the PID
 *
 * Return: Void
 */
int get_pid(void)
{
	pid_t my_pid = getpid();

	printf("%u\n", my_pid);
	return (0);
}
