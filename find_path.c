#include "main.h"
/**
 * findpath - find the path of a command
 * @command: the command
 * @path: the path
 * @length: max length of command
 *
 * Return: 0 if command is found in PATH and -1 otherwise
 */
int findpath(const char *command, char *path, size_t length)
{
	char *term, *penv = NULL, *pcopy = NULL;
	unsigned int i, termlen, comlen, plen;
	struct stat buf;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			penv = environ[i] + 5;
			break;
		}
	}
	if (penv == NULL)
		return (-1);
	pcopy = _strdup(penv);
	if (!pcopy)
		return (-1);
	term = strtok(pcopy, ":");
	while (term != NULL)
	{
		termlen = _strlen(term), comlen = _strlen(command);
		plen = termlen + comlen + 1;
		if (plen < length)
		{
			_memcpy(path, term, termlen);
			path[termlen] = '/';
			_memcpy(path + termlen + 1, command, comlen);
			path[plen] = '\0';
			if (access(path, X_OK) == 0 && stat(path, &buf) == 0 &&
			S_ISREG(buf.st_mode))
			{
				free(pcopy);
				return (0);
			}
		}
		term = strtok(NULL, ":");
	}
	free(pcopy);
	return (-1);
}
