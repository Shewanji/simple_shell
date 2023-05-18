#include "shell.h"

/**
 * read_line - Read a line from standard input
 *
 * Return: Pointer that points to a string with the line content
 */
char *read_line(void)
{
    char *line = NULL;
    size_t buffsize = 0;
    ssize_t countcharNo;

    countcharNo = getline(&line, &buffsize, stdin);
    if (countcharNo == -1)
    {
        if (feof(stdin))
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else
        {
            free(line);
            perror("Error while reading the line from stdin");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}
