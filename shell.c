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
	size_t count = 0;
	int state;
	char *input[64], *term = strtok(command, " \t\n");
	char resolved_path[BUFFERSIZE];

	while (term != NULL && count < (sizeof(input) / sizeof(char *) - 1))
	{
		input[count] = term;
		count++;
		term = strtok(NULL, " \t\n");
	}
	input[count] = NULL; /* indicates the end of arguments*/
	if (input[0][0] != '/')
	{
		if (findpath(input[0], resolved_path, BUFFERSIZE) == -1)
			return (-1);
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
	} else
	{
		waitpid(pid, &state, 0);
		if (WIFEXITED(state) && WEXITSTATUS(state) != 0)
			return (-2);  /* Execution failure */
	}
	return (0);  /* Success */
}
