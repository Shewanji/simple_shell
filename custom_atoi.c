#include "shell.h"

/**
 * custom_atoi - Converts a string to an integer.
 * @str: The input string.
 *
 * Return: The converted integer value.
 */
int custom_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Handling leading whitespace */
	while (str[i] == ' ')
		i++;

	/* Handling optional sign */
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	/* Calculating the integer value */
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}
