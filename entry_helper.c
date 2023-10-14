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
	int i;
	ssize_t status;
	char line_str[12];
	char error_msg[BUFFERSIZE];

	command_t builtins[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
		};

	sprintf(line_str, "%d", line_number);

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(buffer, builtins[i].name) == 0)
		{
			builtins[i].func();
			return;
		}
	}

	status = exe(buffer);
	if (status == -1)
	{
		sprintf(error_msg, "%s: %s: %s: not found\n", program_name,
		line_str, buffer);
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
	}
}

/**
 * sigint_handler - handles signals
 * @sig: the signal
 *
 * Return: Nothing
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($)", 4);
	fflush(stdout);
}
