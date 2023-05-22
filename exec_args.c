#include "shell.h"

/**
 * execute_args - map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_exit
	};

	int i = 0;
	int num_builtins;


    /* empty command was entered */
	if (args[0] == NULL)
		return (-1);

    /* find if the command is a builtin */
	num_builtins = sizeof(builtin_func_list) / sizeof(char *);

    /* if there is a match execute the builtin command */
	for (i = 0; i < num_builtins; i++)
	{
	if (strcmp(args[0], builtin_func_list[i]) == 0)
	{

	int (*builtin_func_ptr)(char **) = builtin_func[i];

	return ((*builtin_func_ptr)(args));
	}
}

/* create a new process */
	return (new_process(args));
}
