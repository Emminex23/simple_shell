#include "main.h"

/**
 * main - Entry point for the program
 *
 * Return: 0 at success
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = BUFFERSIZE;
	ssize_t bytes_read;

	while (1)
	{
		_print("my_simple_shell$ ");
		fflush(stdout);
		bytes_read = getline(&buffer, &bufsize, stdin);

		if (bytes_read == -1)
		{
			handle_read_error();
		}

		if (buffer[bytes_read - 1] == '\n')
		{
			buffer[bytes_read - 1] = '\0';
		}

		if (_strlen(buffer) > 0)
		{
			handle_command(buffer);
		}
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
