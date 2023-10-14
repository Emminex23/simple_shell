#include "main.h"

/**
 * parse_command - parses the commands
 * @command: the command
 * @resolved_path_ref: resolved path ref
 *
 * Return: input
 */

char **parse_command(char *command, char **resolved_path_ref)
{
	size_t count = 0, capacity = 64;
	char **input = malloc(sizeof(char *) * capacity);
	char *term = strtok(command, " \t\n");
	char temp_path[BUFFERSIZE];

	if (!input)
		exit(EXIT_FAILURE);

	while (term && count < capacity - 1)
	{
		input[count++] = term;
		term = strtok(NULL, " \t\n");
	}
	input[count] = NULL;

	if (input[0] && input[0][0] != '/' && findpath(input[0], temp_path,
	BUFFERSIZE) != -1)
	{
		*resolved_path_ref = _strdup(temp_path);
		if (!*resolved_path_ref || access(*resolved_path_ref, X_OK)
		== -1)
		{
			free(input);
			return (NULL);
		}
		input[0] = *resolved_path_ref;
	} else if (!input[0] || access(input[0], X_OK) == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}

/**
 * execute_command - executes command
 * @input: the input
 * @resolved_path: the rp
 *
 * Return: int
 */

int execute_command(char **input, char *resolved_path)
{
	pid_t pid;
	int state;

	pid = fork();
	if (pid < 0 || (pid == 0 && execve(input[0], input, environ) == -1))
	{
		free(input);
		if (resolved_path)
			free(resolved_path);
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	}

	if (pid > 0)
		waitpid(pid, &state, 0);

	free(input);
	if (resolved_path)
		free(resolved_path);
	return ((WIFEXITED(state) && WEXITSTATUS(state) != 0) ? -2 : 0);
}
