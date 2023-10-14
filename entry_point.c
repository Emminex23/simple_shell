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
	int line_number = 0;
	ssize_t bytes_read;
	(void) argc;
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		perror("Error settiing signal handler");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_number++;
		if (isatty(STDIN_FILENO))
		{
			_print("($) ");
			fflush(stdout);
		}
		bytes_read = getline(&buffer, &bufsize, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				handle_read_error();
			} else
			{
				free(buffer);
				exit(EXIT_SUCCESS);
			}
		}
		if (bytes_read > 0 && buffer[bytes_read - 1] == '\n')
			buffer[bytes_read - 1] = '\0';
		if (buffer[0] == '\0')
			continue;
		handle_command(buffer, argv[0], line_number);
		if (!isatty(STDIN_FILENO) && feof(stdin))
			break;
	}
	free(buffer);
	return (0);
}
