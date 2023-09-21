#include "main.h"
/**
 * handle_read_error - handles error
 *
 * Return: Nothing
 */
void handle_read_error(void)
{
	if (feof(stdin))
	{
		_print("\n");
		exit(EXIT_SUCCESS);
	} else
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_command - handles command
 * @buffer: temp
 * @program_name: name of the prog
 * @line_number: num of line
 *
 * Return: Nothing
 */
void handle_command(char *buffer, char *program_name, int line_number)
{
	ssize_t status;
	char line_str[12];
	int i, len = 0;
	int temp = line_number;

	do {
		len++;
		temp /= 10;
	} while (temp);

	for (i = len - 1; i >= 0; i--)
	{
		line_str[i] = (line_number % 10) + '0';
		line_number /= 10;
	}
	line_str[len] = '\0';

	if (_strcmp(buffer, "exit") == 0)
	{
		exit_shell();
	}
	if (_strcmp(buffer, "env") == 0)
	{
		print_env();
		return;
	}
	status = exe(buffer);
	if (status == -1)
	{
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line_str, len);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, buffer, _strlen(buffer));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
