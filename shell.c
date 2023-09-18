#include "main.h"

/**
 * exe - executes input command from console
 *
 * @command: input command
 *
 * Return: 0 on success
 */

void exe(char* command)
{
	pid_t pid; /*pid data type*/
	int state;

	pid = fork(); /*forks child process, parent returns PID and child returns 0*/
	if (pid < 0) /* results in error must be 0 or positive integer*/
	{
		perror("Failed fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /*child process*/
	{
		char* input[(MAX / 2) + 1]; /*string - defines size of array, array holds indivi. args of command, program expects half of buffer size + 1 for null character*/
		int count = 0;

		char* term = strtok(command, "\t\n"); /* splits command "terms" wherever theres a tab or new line*/
		while (term != NULL)
		{
			input[count] = term;
			term++;
			term = strtok(NULL, "\t\n"); /*remebers where it left off in splitting string*/
		}
		input[count] = NULL;

		if (count == 0)
		{
			exit(EXIT_SUCCESS); /* no command and exits child process*/
		}

		if (execvp(input[0], input) == -1)
		{
			perror("Execution of command failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &state, 0); /*retrieves exit status of child process - pid returned from fork, waitpid will update state to status of terminated child pid, 0 = wait till child process terminated*/
	}
}

/*
 * main
 */

int main(void)
{
	printf("SimpleShell$ ");
}


