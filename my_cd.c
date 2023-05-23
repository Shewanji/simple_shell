#include "shell.h"


/**
 * my_cd - change directory of current shell exec env
 * @args: target directory
 *
 * Return: 1 on success, 0 otherwise.
 */
int my_cd(char **args)
{
	if (args[1] == NULL)
	{
		const char *error_message;

		error_message = "Error: expected argument to \"cd\"\n";
		write(STDERR_FILENO, error_message, strlen(error_message));
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error in my_cd: changing directory");
		}
	}
	return (-1);
}
