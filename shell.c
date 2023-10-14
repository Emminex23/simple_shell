#include "main.h"
/**
 * exe - executes input command from console
 * @command: input command
 *
 * Return: 0 on success, -1 on failure
 */
int exe(char *command)
{
	char *resolved_path = NULL;
	char **input = parse_command(command, &resolved_path);

	if (!input)
		return (-1);
	return (execute_command(input, resolved_path));
}
