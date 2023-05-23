#include "shell.h"

/**
 * no_interactive - Unix command line 4 non-interactive shell
 *
 * Return: void
 */
void no_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = _stream();
		args = split_line(line);

		status = execute_args(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
