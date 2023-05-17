#include <fcntl.h>
#include <unistd.h>

/**
 * createFile - Creates a file with the given filename.
 * @filename: The name of the file to be created.
 */
void createFile(const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 666);

	if (fd == -1)
	{
		write(STDOUT_FILENO, "Create file fail\n", sizeof("Create file fail\n"));

		return;
	}

	write(STDOUT_FILENO, "File created\n", sizeof("File created\n"));

	close(fd);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	const char *filename = "example_file";

	createFile(filename);

	return (0);
}

