#include "shell.h"
/**
 * expand_buffer - Expands the buffer size if needed
 * @line: Pointer to the buffer
 * @bufsize: Pointer to the current buffer size
 *
 * Return: void
 */
void expand_buffer(char **line, int *bufsize)
{
	if (*bufsize >= BUFSIZ)
	{
		*bufsize += BUFSIZ;
		*line = realloc(*line, *bufsize);

		if (*line == NULL)
		{
			const char *error_message = "Reallocation error in read_stream\n";

			write(STDERR_FILENO, error_message, strlen(error_message));
			exit(EXIT_FAILURE);
		}
	}
}
