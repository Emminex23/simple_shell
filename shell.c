#include "main.h"
/**
 * exe - executes input command from console
 * @command: input command
 *
 * Return: 0 on success, -1 on failure
 */
int exe(char *command)
{
	pid_t pid; /*pid data type*/
	int state, count = 0;
	char *input[MAX]; /*Array holds the command and its argument*/
	char resolved_path[BUFFERSIZE];

	char *term = strtok(command, " \t\n");

	while (term != NULL && count < (MAX - 1))
	{
		input[count] = term;
		count++;
		term = strtok(NULL, " \t\n");
	}
	input[count] = NULL; /* indicates the end of arguments*/
	if (input[0][0] != '/')
	{
		if (findpath(input[0], resolved_path, BUFFERSIZE) == -1)
		{
			return (-1);
		}
		input[0] = resolved_path;
	}
	if (access(input[0], X_OK) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execve(input[0], input, environ) == -1)
		{
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &state, 0);
	return ((WIFEXITED(state) && WEXITSTATUS(state) != 0) ? -1 : 0);
}
