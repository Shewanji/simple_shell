#include "shell.h"

/**
 * custom_getchar - read a character from standard input
 * Return: The character read from the standard input as an integer,
 * or EOF if an error occurs or end-of-file is reached
 */
int custom_getchar(void)
{
	static char buffer[BUFSIZ];
	static char *buffer_ptr = buffer;
	static int buffer_count;

	if (buffer_count == 0)
	{
		ssize_t bytes_read = read(STDIN_FILENO, buffer, BUFSIZ);

		if (bytes_read <= 0)
		{
		/* Error or end-of-file */
			return (EOF);
		}
		buffer_count = bytes_read;
		buffer_ptr = buffer;
	}

	int result = (int)(*buffer_ptr);

	buffer_ptr++;
	buffer_count--;

	return (result);
}
