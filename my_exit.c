#include "shell.h"

/**
 * my_exit - Causes normal process termination.
 * @args: Array of strings containing the command and its arguments.
 *
 * Return: 0 to terminate the process
 */
int my_exit(char **args)
{
	/* exit with status */
	if (args[1])
	{
		return (atoi(args[1]));
	}
	/* exit success */
	else
	{
		return (0);
	}
}
