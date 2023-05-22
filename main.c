#include "shell.h"

/**
 * main - function checks if shell is interactive;
 *
 * Return: 0 if successful;
 */
int main(void)
{
	int fileNo;

	fileNo = isatty(STDIN_FILENO);

	if (fileNo == 0)
	{
		no_interactive();
	}
	else
	{
		interactive();
	}

	return (0);
}
