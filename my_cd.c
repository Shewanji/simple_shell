#include "shell.h"

/**
 * my_cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int my_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Error:expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error in my_cd: changing directory\n");
		}
	}
	return (-1);
}
