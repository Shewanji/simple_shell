#include "shell.h"


/**
 * resizeTokens - Resizes the tokens array if necessary.
 * @tokens: Pointer to the pointer that holds the array of tokens.
 * @bufsize: Pointer to the variable that holds the current buffer size.
 * @i: The index being checked.
 */

void resizeTokens(char ***tokens, int *bufsize, int i)
{
	if (i >= *bufsize)
	{
		*bufsize += *bufsize;
		*tokens = realloc(*tokens, (*bufsize) * sizeof(char *));
		if (!(*tokens))
			exit(EXIT_FAILURE);
	}
}

/**
 * split_line - Splits a string into tokens.
 * @line: The string to be split.
 *
 * Return: An array of tokens.
 */

char **split_line(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		exit(EXIT_FAILURE);

	while (*line != '\0')
	{
		while (*line == ' ' || *line == '\t' || *line == '\r' ||
		       *line == '\n' || *line == '\a')
			line++;

		if (*line == '#' || *line == '\0')
		{
			break;
		}

		token = line;
		while (*line != ' ' && *line != '\t' && *line != '\r' &&
		       *line != '\n' && *line != '\a' && *line != '#' &&
		       *line != '\0')
			line++;

		if (*line != '\0')
			*line++ = '\0';

		tokens[i] = token;
		i++;

		resizeTokens(&tokens, &bufsize, i);
	}

	tokens[i] = NULL;
	return (tokens);
}
