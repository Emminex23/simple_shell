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
		printf("my_simple_shell$ ");
		fflush(stdout);
		bytes_read = getline(&buffer, &bufsize, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			} else
			{
				perror("my_simple_shell");
				exit(EXIT_FAILURE);
			}
		}
		if (buffer[bytes_read - 1] == '\n')
		{
			buffer[bytes_read - 1] = '\0';
		}
		if (strlen(buffer) > 0)
		{
			int status = exe(buffer);

			if (status == -1)
			{
				printf("%s: command not found\n", buffer);
			}
		}
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
