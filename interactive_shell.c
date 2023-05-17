#include "shell.h"
#include <unistd.h>

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;
	char prompt[] = "simple_shell$ ";
	size_t prompt_length = sizeof(prompt) - 1;

	do {
		write(STDOUT_FILENO, prompt, prompt_length); /* print prompt symbol */
		line = read_line(); /* read line from stdin */
		args = split_line(line); /* tokenize line */
		status = execute_args(args);
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}

