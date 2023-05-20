#include "shell.h"

/**
 * new_process - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("error in new_process: forking");
		return (0);  /* Return 0 to indicate failure */
	}
	else if (pid == 0)
	{
	/* child process */
		char *envp[] = { NULL };  /* NULL-terminated environment variable list */

	if (execve(args[0], args, envp) == -1)
	{
		perror("error in new_process: execve");
		exit(EXIT_FAILURE);
	}
	}
	else
	{
	/* parent process */
	do {
		if (waitpid(pid, &status, WUNTRACED) == -1)
		{
			perror("error in new_process: waitpid");
			return (0);  /* Return 0 to indicate failure */
		}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);  /* Return 1 to indicate success */
}

