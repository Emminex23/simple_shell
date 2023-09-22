#include "main.h"

/**
 * main - Entry point for the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 at success
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = BUFFERSIZE;
	ssize_t bytes_read;
	int line_number = 0;

	(void) argc;
	while (1)
	{
		line_number++;
		if (isatty(STDIN_FILENO))
		{
			_print("($)");
		}
		fflush(stdout);
		bytes_read = getline(&buffer, &bufsize, stdin);
		if (bytes_read == -1)
		{
			free(buffer);
			handle_read_error();
			break;
		}
		if (buffer[bytes_read - 1] == '\n')
			buffer[bytes_read - 1] = '\0';
		if (_strlen(buffer) > 0)
			handle_command(buffer, argv[0], line_number);
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
	return (0);
}
