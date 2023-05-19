#include <stdlib.h>

#define TOK_DELIM " \t\r\n\a"
/**
 * split_line
 *
 * Return:
*/
char **split_line(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, *saveptr;

	if (!tokens) exit(EXIT_FAILURE);

	while (*line != '\0')
	{
	while (*line == ' ' || *line == '\t' || *line == '\r' ||
		*line == '\n' || *line == '\a')   line++;

	if (*line == '#' || *line == '\0')  break;

	token = line;
	while (*line != ' ' && *line != '\t' && *line != '\r' &&
		*line != '\n' && *line != '\a' && *line != '#' &&
		*line != '\0') line++;

	if (*line != '\0') *line++ = '\0';

	tokens[i] = token;
	i++;

	if (i >= bufsize)
	{
		bufsize += bufsize;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens) exit(EXIT_FAILURE);
	}
	}

	tokens[i] = NULL;
	return (tokens);
}
