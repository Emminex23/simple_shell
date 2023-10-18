#include "main.h"

/**
 * custom_getline - reads line from input stream and counts char
 *
 * @lineptr:pointer to memory location of line text to be read
 * @n: buffersize in bytes
 * @stream: input from where line is supposed to be read
 *
 * Return: number of characters read on success or -1 on error
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;
	char *new_lineptr;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFERSIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i + 1 >= *n)
		{
			*n += BUFFERSIZE;
			new_lineptr = (char *)_realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
		{
			(*lineptr)[i] = '\0';
			return (i);
			}
	}
	return (-1);
}
