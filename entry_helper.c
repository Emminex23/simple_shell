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
		perror("my_simple_shell");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_command - handles command
 * @buffer: temp
 *
 * Return: Nothing
 */
void handle_command(char *buffer)
{
	ssize_t status;

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
		_print("command not found\n");
	}
}
