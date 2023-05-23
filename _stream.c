#include "shell.h"

/**
 * _stream - read a line from the stream
 *
 * Return: pointer that points to the read line
 */
char *_stream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		const char *error_message = "Allocation error in _stream\n";

		write(STDERR_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		character = custom_getchar();

		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = character;
		}
		i++;

		expand_buffer(&line, &bufsize);
	}
}
