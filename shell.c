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
	int state;

	char *input[MAX]; /*Array holds the command and its argument*/
	int count = 0;
	char *term = strtok(command, " \t\n");

	while (term != NULL && count < (MAX - 1))
	{
		input[count] = term;
		count++;
		term = strtok(NULL, " \t\n");
	}
	input[count] = NULL; /* indicates the end of arguments*/
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
	} else
	{
		waitpid(pid, &state, 0);
		if (WIFEXITED(state) && WEXITSTATUS(state) == 0)
		{
			return (0);
		}
		return (-1);
	}
	return (0);
}
